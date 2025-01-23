async function PlayerVsPlayerPlayGame(event) {
	if (event === undefined || event === null) return 1;
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	const gameAction = document.getElementById('gameAction');
	try {
		gameAction.innerHTML = '';

		const gameWidth = gameAction.clientWidth;
		const gameHeight = gameAction.clientHeight;

		renderer = new THREE.WebGLRenderer();
		renderer.shadowMap.enabled = true;
		renderer.shadowMap.type = THREE.PCFSoftShadowMap;
		renderer.setClearColor(0x000000, 0);
		renderer.setSize(gameWidth, gameHeight);
		gameAction.appendChild(renderer.domElement);

		const scene = new THREE.Scene();
		const camera = new THREE.PerspectiveCamera(75, gameWidth / gameHeight, 0.1, 1000);
		const lightIntensity = 0.5;
		const lightColor = 0xffffff;
		const cameraZoom = 1.2;

		const fieldWidth = gameAction.clientWidth / 2;
		const fieldHeight = fieldWidth / 2;
		const gameDepth = fieldWidth * 0.03;
		const wallStroke = gameDepth / 2;
		const wallConfig = { color: 0x555555 };
		const wallSizes = { width: fieldWidth, height: wallStroke, depth: gameDepth };
		const ballRadius = gameDepth / 2;
		const padelsSize = { width: wallStroke, height: fieldHeight / 5, depth: gameDepth };
		const gameSpeed = gameDepth / 6;
		const maxPoints = gameData.config.max_points;
		let fieldConfig = {};

		try {
			if (gameData.config.field.file === undefined) throw new Error();
			fieldConfig = await loadFieldTexture(gameData.config.field.file, fieldWidth, fieldHeight);
		} catch (error) {
			fieldConfig = gameData.config.field;
		}
		const camera2DPOV = { x: 0, y: 0, z: fieldHeight / cameraZoom };
		const camera3DPOV = { x: 0, y: -fieldHeight / 2 / cameraZoom, z: fieldHeight / cameraZoom };
		const camera2DTarget = { x: 0, y: 0, z: 0 };
		const camera3DTarget = { x: 0, y: 0, z: 0 };
		const cameraPOVs = [camera2DPOV, camera3DPOV];
		const cameraTargets = [camera2DTarget, camera3DTarget];

		let switchCamera = 0;

		let currCameraPOV = cameraPOVs[switchCamera];
		let currCameraTarget = cameraTargets[switchCamera];

		camera.position.set(currCameraPOV.x, currCameraPOV.y, currCameraPOV.z);
		camera.lookAt(currCameraTarget.x, currCameraTarget.y, currCameraTarget.z);

		let ballSpeed = gameSpeed;
		let padelSpeed = gameSpeed;
		let acceleration = fieldWidth / 10000;

		let scoreHome = 0;
		let scoreAway = 0;

		let ball_dir = { x: 1, y: 1 };

		// Field and walls
		const field = createPlane(fieldWidth, fieldHeight, fieldConfig);
		const topWall = createBox(wallSizes.width, wallSizes.height, wallSizes.depth,
			wallConfig, 0, (fieldHeight - wallSizes.height) / 2, wallSizes.depth / 2);
		const bottomWall = createBox(wallSizes.width, wallSizes.height, wallSizes.depth,
			wallConfig, 0, -(fieldHeight - wallSizes.height) / 2, wallSizes.depth / 2);

		const extremes = {
			top: fieldHeight / 2,
			bottom: -fieldHeight / 2,
			left: -fieldWidth / 2,
			right: fieldWidth / 2
		};

		// Lights
		const mainLight = createLight(lightColor, lightIntensity, 0, 0, fieldHeight * 2);
		const topLight = createLight(lightColor, lightIntensity, 0, fieldHeight, fieldHeight);
		const bottomLight = createLight(lightColor, lightIntensity, 0, -fieldHeight, fieldHeight);
		const leftLight = createLight(lightColor, lightIntensity, -fieldHeight, 0, fieldHeight);
		const rightLight = createLight(lightColor, lightIntensity, fieldHeight, 0, fieldHeight);

		// Ball
		const ball = createSphere(ballRadius, 32, 32, gameData.config.ball, 0, 0, ballRadius);

		// Padels
		const leftPadel = createBox(padelsSize.width, padelsSize.height, padelsSize.depth, gameData.config.left_padel, -(fieldWidth - padelsSize.width) / 2, 0, padelsSize.depth / 2);
		const rightPadel = createBox(padelsSize.width, padelsSize.height, padelsSize.depth, gameData.config.right_padel, (fieldWidth - padelsSize.width) / 2, 0, padelsSize.depth / 2);

		scene.add(mainLight, topLight, bottomLight, leftLight, rightLight,
			field, topWall, bottomWall, ball, leftPadel, rightPadel);

		const numbers = [];
		const numbersStr = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine'];
		for (let i = 0; i < 10; i++) {
			const number = document.createElement('div');
			number.classList.add('game-text', numbersStr[i]);
			numbers.push(number.cloneNode(true));
		}

		let keyboard = {};

		document.addEventListener('keydown', function (e) {
			keyboard[e.code] = true;

			if (e.code === 'KeyC') {
				switchCamera = (switchCamera + 1) % 2;
				currCameraPOV = cameraPOVs[switchCamera];
				currCameraTarget = cameraTargets[switchCamera];
				camera.position.set(currCameraPOV.x, currCameraPOV.y, currCameraPOV.z);
				camera.lookAt(currCameraTarget.x, currCameraTarget.y, currCameraTarget.z);
				renderer.render(scene, camera);
			}
		});

		document.addEventListener('keyup', function (e) { keyboard[e.code] = false; });

		function showWinner() {
			document.getElementById('gameInfoModalLabel').textContent = gameData.config.winner;
			document.getElementById('gameInfoModalBody').innerHTML = '';
			const winnerMain = document.createElement('div');
			winnerMain.classList.add('d-flex', 'justify-content-center', 'align-items-center', 'w-100', 'ft_span');
			if (scoreHome > scoreAway) {
				winnerMain.textContent = gameData.players.home_player.alias_name;
			}
			else if (scoreHome < scoreAway) {
				winnerMain.textContent = gameData.players.away_player.alias_name;
			}
			winnerMain.style.fontFamily = 'Bitstream Vera Mono';
			document.getElementById('gameInfoModalBody').appendChild(winnerMain.cloneNode(true));
		}

		let lock = false;
		let modalOpen = false;
		let endOfGame = false;
		let pause = false;
		let gameTimestamp = Date.now();

		function gameResume(event, id) {
			closeModal(event, id);
			pause = false;
			updateScoreDiv(scoreHome, scoreAway, numbers);
			updateAliasNames(gameData.players.home_player.alias_name, gameData.players.away_player.alias_name);
		}

		function gamePause(event, id) {
			openModal(event, id);
			pause = true;
		}

		async function SaveGame(event) {
			if (event === undefined || event === null) { return 1; }
			try {
				event.preventDefault();
			} catch (error) { return 1; }
			let csrftoken = Cookies.get('csrftoken');
			if (csrftoken === undefined || csrftoken === null) { return 1; }
			const response = await fetch(`${projectURL}/game/save-game/`, {
				method: 'POST',
				headers: { 'X-CSRFToken': csrftoken, },
				body: JSON.stringify({
					home_player_alias_name: gameData.players.home_player.alias_name,
					home_player_score: scoreHome,
					away_player_alias_name: gameData.players.away_player.alias_name,
					away_player_score: scoreAway,
					timestamp: gameTimestamp
				}),
			});
			const response_text = await response.text();
			if (!response.ok) {
				try {
					const json_data = JSON.parse(response_text);
					return showErrors(event, json_data);
				} catch (error) { return 1; }
			}
			try {
				const json_data = JSON.parse(response_text);
				changeStatusAndTitle(event, json_data);
				return 0;
			} catch (error) { return 1; }
		}

		window.gameResume = gameResume;
		window.gamePause = gamePause;

		updateScoreDiv(scoreHome, scoreAway, numbers);
		updateAliasNames(gameData.players.home_player.alias_name, gameData.players.away_player.alias_name);

		async function gameLoop() {
			if (lock || pause) return;

			lock = true;

			if (modalOpen) {
				gamePause(event, 'gameInfoModal');
				modalOpen = false;
				lock = false;
				return;
			}

			if (endOfGame) {
				await SaveGame(event);
				gameClose(event);
				await changePage(event, currentApp, currentPage, false);
				return;
			}

			if (scoreHome === maxPoints || scoreAway === maxPoints) {
				gameTimestamp = Date.now();
				showWinner();
				modalOpen = true;
				endOfGame = true;
				lock = false;
				return;
			}

			if (keyboard.KeyW) { moveBoxUp(leftPadel, padelSpeed, ball, ball_dir, topWall); }
			if (keyboard.KeyS) { moveBoxDown(leftPadel, padelSpeed, ball, ball_dir, bottomWall); }

			if (keyboard.ArrowUp) { moveBoxUp(rightPadel, padelSpeed, ball, ball_dir, topWall); }
			if (keyboard.ArrowDown) { moveBoxDown(rightPadel, padelSpeed, ball, ball_dir, bottomWall); }

			const ballHitX = moveSphereX(ball, ball_dir, ballSpeed, [topWall, bottomWall, leftPadel, rightPadel]);
			const ballHitY = moveSphereY(ball, ball_dir, ballSpeed, [topWall, bottomWall, leftPadel, rightPadel]);

			ballSpeed += ballHitX || ballHitY ? acceleration : 0;
			padelSpeed = ballSpeed;

			let home_scored = ball.position.x - ballRadius > extremes.right + padelsSize.width;
			let away_scored = ball.position.x + ballRadius < extremes.left - padelsSize.width;
			let someone_scored = home_scored || away_scored;
			if (someone_scored) {
				ball.position.set(0, 0, ballRadius);
				ball_dir.x = -ball_dir.x;
				ballSpeed = gameSpeed;
				padelSpeed = gameSpeed;
				scoreHome += home_scored;
				scoreAway += away_scored;
				updateScoreDiv(scoreHome, scoreAway, numbers);
			}

			renderer.render(scene, camera);
			lock = false;
		}

		renderer.setAnimationLoop(gameLoop);

		return 0;
	} catch (error) { return 1; }
}

async function PlayerVsPlayerConfigUser(event) {
	if (event === undefined || event === null) { return 1; }
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	let csrftoken = Cookies.get('csrftoken');
	if (csrftoken === undefined || csrftoken === null) { return 1; }
	const form_data = new FormData(event.target);
	const response = await fetch(`${projectURL}/game/p-vs-p-config-user/`, {
		method: 'POST',
		headers: { 'X-CSRFToken': csrftoken, },
		body: form_data,
	});
	const response_text = await response.text();
	if (!response.ok) {
		try {
			const json_data = JSON.parse(response_text);
			return showErrors(event, json_data, 'gameplayervsplayerconfiguser_error');
		} catch (error) { return 1; }
	}
	try {
		const json_data = JSON.parse(response_text);
		removeError(event, 'gameplayervsplayerconfiguser_error');
		gameData.players = json_data;
		await gameNavigate(event, 'p-vs-p-config-game/');
		return 0;
	} catch (error) { return 1; }
}

async function PlayerVsPlayerConfigGame(event) {
	if (event === undefined || event === null) { return 1; }
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	let csrftoken = Cookies.get('csrftoken');
	if (csrftoken === undefined || csrftoken === null) { return 1; }
	const form_data = new FormData(event.target);
	const response = await fetch(`${projectURL}/game/p-vs-p-config-game/`, {
		method: 'POST',
		headers: { 'X-CSRFToken': csrftoken, },
		body: form_data,
	});
	const response_text = await response.text();
	if (!response.ok) {
		try {
			const json_data = JSON.parse(response_text);
			return showErrors(event, json_data, 'playervsplayerconfiggame_error');
		} catch (error) { return 1; }
	}
	try {
		const json_data = JSON.parse(response_text);
		removeError('playervsplayerconfiggame_error');
		gameData.config = json_data;
		try {
			if (json_data.field.map === undefined || json_data.field.map === null) { throw new Error() }
			gameData.config.field.file = form_data.get('field_image');
		} catch (error) { }
		await gameNavigate(event, 'game/');
		PlayerVsPlayerPlayGame(event);
		return 0;
	} catch (error) { return 1; }
}