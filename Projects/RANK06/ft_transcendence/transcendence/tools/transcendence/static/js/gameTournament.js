async function Tournament(event) {
	if (event === undefined || event === null) { return 1; }
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	try {
		const playersCopy = gameData.tour.players;
		const playersKeys = Object.keys(playersCopy);

		const playersLength = playersKeys.length;

		if (playersLength === 1) {
			gameData.players = { 'home_player': playersCopy[playersKeys[0]], 'away_player': { 'alias_name': 'AI', 'padel_color': '#000000' } };
			gameData.config = gameData.tour.config;
			gameData.config.left_padel = { color: gameData.players.home_player.padel_color };
			gameData.config.right_padel = { color: gameData.players.away_player.padel_color };
			delete gameData.players.home_player.padel_color;
			delete gameData.players.away_player.padel_color;
			delete gameData.config.host;
			delete gameData.tour;
			await gameNavigate(event, 'game/');
			PlayerVsAIPlayGame(event);
			return 0;
		}
		if (playersLength === 2) {
			gameData.players = { 'home_player': playersCopy[playersKeys[0]], 'away_player': playersCopy[playersKeys[1]] };
			gameData.config = gameData.tour.config;
			gameData.config.left_padel = { color: gameData.players.home_player.padel_color };
			gameData.config.right_padel = { color: gameData.players.away_player.padel_color };
			delete gameData.players.home_player.padel_color;
			delete gameData.players.away_player.padel_color;
			delete gameData.config.host;
			delete gameData.tour;
			await gameNavigate(event, 'game/');
			PlayerVsPlayerPlayGame(event);
			return 0;
		}

		gameData.tour.rounds = 1;

		await MatchMaking(event);

		let homePlayer = gameData.tour.games[0][0];
		let awayPlayer = gameData.tour.games[0][1];

		await gameNavigate(event, 'game/');

		const gameAction = document.getElementById('gameAction');

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
		const maxPoints = gameData.tour.config.max_points;
		let fieldConfig = {};

		try {
			if (gameData.tour.config.field.file === undefined) throw new Error();
			fieldConfig = await loadFieldTexture(gameData.tour.config.field.file, fieldWidth, fieldHeight);
		} catch (error) {
			fieldConfig = gameData.tour.config.field;
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

		let ball_dir = { x: 1, y: 1 };

		let scoreHome = 0;
		let scoreAway = 0;

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
		const ball = createSphere(ballRadius, 32, 32, gameData.tour.config.ball, 0, 0, ballRadius);

		// Padels
		const leftPadel = createBox(padelsSize.width, padelsSize.height, padelsSize.depth, { color: homePlayer.padel_color }, -(fieldWidth - padelsSize.width) / 2, 0, padelsSize.depth / 2);
		const rightPadel = createBox(padelsSize.width, padelsSize.height, padelsSize.depth, { color: awayPlayer.padel_color }, (fieldWidth - padelsSize.width) / 2, 0, padelsSize.depth / 2);

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

		function showNextGame() {
			document.getElementById('gameInfoModalLabel').textContent = gameData.tour.config.next_game;
			document.getElementById('gameInfoModalBody').innerHTML = '';
			const nextGameMain = document.createElement('div');
			const nextGameHomePlayer = document.createElement('div');
			const nextGameVsDiv = document.createElement('div');
			const nextGameAwayPlayer = document.createElement('div');
			nextGameMain.classList.add('d-flex', 'flex-row', 'justify-content-center', 'align-items-center', 'w-100');
			nextGameHomePlayer.classList.add('d-flex', 'justify-content-center', 'align-items-center', 'w-100', 'ft_span');
			nextGameVsDiv.classList.add('d-flex', 'justify-content-center', 'align-items-center', 'ft_span', 'mx-3');
			nextGameAwayPlayer.classList.add('d-flex', 'justify-content-center', 'align-items-center', 'w-100', 'ft_span');
			nextGameHomePlayer.textContent = homePlayer.alias_name;
			nextGameVsDiv.textContent = 'X';
			nextGameAwayPlayer.textContent = awayPlayer.alias_name;
			nextGameHomePlayer.style.fontFamily = 'Bitstream Vera Mono';
			nextGameAwayPlayer.style.fontFamily = 'Bitstream Vera Mono';
			nextGameMain.appendChild(nextGameHomePlayer.cloneNode(true));
			nextGameMain.appendChild(nextGameVsDiv.cloneNode(true));
			nextGameMain.appendChild(nextGameAwayPlayer.cloneNode(true));
			nextGameMain.style.fontFamily = 'Bitstream Vera Mono';
			document.getElementById('gameInfoModalBody').appendChild(nextGameMain.cloneNode(true));
		}

		function showNextRound() {
			document.getElementById('gameInfoModalLabel').textContent = gameData.tour.round.event;
			document.getElementById('gameInfoModalBody').innerHTML = '';
			const nextRoundDiv = document.createElement('div');
			nextRoundDiv.classList.add('d-flex', 'flex-column', 'justify-content-center', 'align-items-center', 'w-100');

			const tmpPlayersArray = Object.keys(gameData.tour.players);
			if (tmpPlayersArray.length > 0) {
				const byesDiv = document.createElement('div');
				const byesTitleDiv = document.createElement('div');
				const byesBodyDiv = document.createElement('div');
				byesDiv.classList.add('d-flex', 'flex-column', 'justify-content-center', 'align-items-center', 'w-100');
				byesTitleDiv.classList.add('d-flex', 'justify-content-start', 'align-items-center', 'w-100', 'ft_subtitle', 'text-start');
				byesTitleDiv.textContent = gameData.tour.config.players_auto_next_round;
				byesBodyDiv.classList.add('d-flex', 'flex-column', 'justify-content-center', 'align-items-center', 'w-100');
				for (let key in gameData.tour.players) {
					const playerDiv = document.createElement('div');
					playerDiv.classList.add('d-flex', 'justify-content-start', 'align-items-center', 'w-100', 'ft_span', 'mt-2');
					playerDiv.textContent = gameData.tour.players[key].alias_name;
					playerDiv.style.fontFamily = 'Bitstream Vera Mono';
					byesBodyDiv.appendChild(playerDiv.cloneNode(true));
				}
				byesDiv.appendChild(byesTitleDiv.cloneNode(true));
				byesDiv.appendChild(byesBodyDiv.cloneNode(true));
				nextRoundDiv.appendChild(byesDiv.cloneNode(true));
			}

			const matchesDiv = document.createElement('div');
			const matchesTitleDiv = document.createElement('div');
			const matchesBodyDiv = document.createElement('div');
			matchesDiv.classList.add('d-flex', 'flex-column', 'justify-content-center', 'align-items-center', 'w-100');
			if (tmpPlayersArray.length > 0) {
				matchesDiv.classList.add('mt-3');
			}
			matchesTitleDiv.classList.add('d-flex', 'justify-content-start', 'align-items-center', 'w-100', 'ft_subtitle', 'text-start');
			matchesBodyDiv.classList.add('d-flex', 'flex-column', 'justify-content-center', 'align-items-center', 'w-100');
			for (let i = 0; i < gameData.tour.games.length; i++) {
				const matchDiv = document.createElement('div');
				const matchHomePlayerDiv = document.createElement('div');
				const matchVsDiv = document.createElement('div');
				const matchAwayPlayerDiv = document.createElement('div');
				matchDiv.classList.add('d-flex', 'flex-row', 'justify-content-center', 'align-items-center', 'w-100', 'mt-2');
				matchHomePlayerDiv.classList.add('d-flex', 'justify-content-center', 'align-items-center', 'w-100', 'ft_span');
				matchVsDiv.classList.add('d-flex', 'justify-content-center', 'align-items-center', 'ft_span');
				matchAwayPlayerDiv.classList.add('d-flex', 'justify-content-center', 'align-items-center', 'w-100', 'ft_span');
				matchHomePlayerDiv.textContent = gameData.tour.games[i][0].alias_name;
				matchVsDiv.textContent = 'X';
				matchAwayPlayerDiv.textContent = gameData.tour.games[i][1].alias_name;
				matchHomePlayerDiv.style.fontFamily = 'Bitstream Vera Mono';
				matchAwayPlayerDiv.style.fontFamily = 'Bitstream Vera Mono';
				matchHomePlayerDiv.classList.add('w-100', 'text-truncate');
				matchAwayPlayerDiv.classList.add('w-100', 'text-truncate');
				matchDiv.appendChild(matchHomePlayerDiv.cloneNode(true));
				matchDiv.appendChild(matchVsDiv.cloneNode(true));
				matchDiv.appendChild(matchAwayPlayerDiv.cloneNode(true));
				matchesBodyDiv.appendChild(matchDiv.cloneNode(true));
			}
			matchesTitleDiv.textContent = gameData.tour.config.matches;
			matchesDiv.appendChild(matchesTitleDiv.cloneNode(true));
			matchesDiv.appendChild(matchesBodyDiv.cloneNode(true));
			nextRoundDiv.appendChild(matchesDiv.cloneNode(true));
			document.getElementById('gameInfoModalBody').appendChild(nextRoundDiv.cloneNode(true));
		}

		function showWinner() {
			document.getElementById('gameInfoModalLabel').textContent = gameData.tour.config.winner;
			document.getElementById('gameInfoModalBody').innerHTML = '';
			const winnerMain = document.createElement('div');
			winnerMain.classList.add('d-flex', 'justify-content-center', 'align-items-center', 'w-100', 'ft_span');
			winnerMain.textContent = scoreHome > scoreAway ? homePlayer.alias_name : awayPlayer.alias_name;
			winnerMain.style.fontFamily = 'Bitstream Vera Mono';
			document.getElementById('gameInfoModalBody').appendChild(winnerMain.cloneNode(true));
		}

		let goToNextGame = false;
		let goToNextRound = false;
		let matchMake = false;
		let endOfTournament = false;
		let lock = false;
		let modalOpen = true;
		let pause = false;
		let tournamentTimestamp = Date.now();

		function gameResume(event, id) {
			closeModal(event, id);
			pause = false;
			updateScoreDiv(scoreHome, scoreAway, numbers);
			updateAliasNames(homePlayer.alias_name, awayPlayer.alias_name);
		}

		function gamePause(event, id) {
			openModal(event, id);
			pause = true;
		}

		async function SaveTournament(event) {
			if (event === undefined || event === null) { return 1; }
			try {
				event.preventDefault();
			} catch (error) { return 1; }
			let csrftoken = Cookies.get('csrftoken');
			if (csrftoken === undefined || csrftoken === null) { return 1; }
			const response = await fetch(`${projectURL}/game/save-tournament/`, {
				method: 'POST',
				headers: { 'X-CSRFToken': csrftoken, },
				body: JSON.stringify({
					done_games: gameData.tour.done_games,
					timestamp: tournamentTimestamp,
					winner: scoreHome > scoreAway ? homePlayer.alias_name : awayPlayer.alias_name
				})
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

		showNextRound();

		gameData.tour.done_games = [];

		async function gameLoop() {
			if (lock || pause) return;

			lock = true;

			if (modalOpen) {
				gamePause(event, 'gameInfoModal');
				modalOpen = false;
				lock = false;
				return;
			}

			if (endOfTournament) {
				await SaveTournament(event);
				gameClose(event);
				await changePage(event, currentApp, currentPage, false);
				return;
			}

			if (matchMake) {
				gameData.tour.rounds++;
				await MatchMaking(event);
				if (gameData.tour.games.length > 0) {
					goToNextRound = true;
				}
				else {
					showWinner();
					modalOpen = true;
					endOfTournament = true;
				}
				matchMake = false;
				lock = false;
				return;
			}

			if (goToNextRound) {
				homePlayer = gameData.tour.games[0][0];
				awayPlayer = gameData.tour.games[0][1];
				ball.position.x = 0;
				ball.position.y = 0;
				leftPadel.position.y = 0;
				rightPadel.position.y = 0;
				leftPadel.material.color.set(homePlayer.padel_color);
				rightPadel.material.color.set(awayPlayer.padel_color);
				scoreHome = 0;
				scoreAway = 0;
				showNextRound();
				modalOpen = true;
				goToNextRound = false;
				lock = false;
				return;
			}

			if (goToNextGame) {
				homePlayer = gameData.tour.games[0][0];
				awayPlayer = gameData.tour.games[0][1];
				ball.position.x = 0;
				ball.position.y = 0;
				leftPadel.position.y = 0;
				rightPadel.position.y = 0;
				leftPadel.material.color.set(homePlayer.padel_color);
				rightPadel.material.color.set(awayPlayer.padel_color);
				scoreHome = 0;
				scoreAway = 0;
				showNextGame();
				modalOpen = true;
				goToNextGame = false;
				lock = false;
				return;
			}

			if (scoreHome === maxPoints || scoreAway === maxPoints) {
				gameData.tour.done_games.push({
					home_player_alias_name: homePlayer.alias_name,
					home_player_score: scoreHome,
					away_player_alias_name: awayPlayer.alias_name,
					away_player_score: scoreAway,
					type: gameData.tour.round.id,
					round: gameData.tour.rounds,
					timestamp: Date.now()
				});
				if (scoreHome > scoreAway) {
					gameData.tour.players[homePlayer.alias_name] = homePlayer;
				}
				else if (scoreHome < scoreAway) {
					gameData.tour.players[awayPlayer.alias_name] = awayPlayer;
				}
				gameData.tour.games.shift();
				if (gameData.tour.games.length > 0) {
					goToNextGame = true;
				}
				else {
					matchMake = true;
				}
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

async function TournamentConfig(event) {
	if (event === undefined || event === null) { return 1; }
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	let csrftoken = Cookies.get('csrftoken');
	if (csrftoken === undefined || csrftoken === null) { return 1; }
	const form_data = new FormData(event.target);
	const response = await fetch(`${projectURL}/game/tournament-config/`, {
		method: 'POST',
		headers: { 'X-CSRFToken': csrftoken, },
		body: form_data,
	});
	const response_text = await response.text();
	if (!response.ok) {
		try {
			const json_data = JSON.parse(response_text);
			return showErrors(event, json_data, 'tournamentconfig_error');
		} catch (error) { return 1; }
	}
	try {
		const json_data = JSON.parse(response_text);
		removeError('tournamentconfig_error');
		gameData.tour = {};
		gameData.tour.config = json_data;
		gameData.tour.players = {};
		gameData.tour.host = json_data.host;
		gameData.tour.players[json_data.host.alias_name] = json_data.host;
		try {
			if (json_data.field.map === undefined || json_data.field.map === null) { throw new Error() }
			gameData.tour.config.field.file = form_data.get('field_image');
		} catch (error) { }
		await gameNavigate(event, 'tour-check-players/');
		return 0;
	} catch (error) { return 1; }
}

async function TournamentCheckPlayer(event) {
	if (event === undefined || event === null) { return 1; }
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	let csrftoken = Cookies.get('csrftoken');
	if (csrftoken === undefined || csrftoken === null) { return 1; }
	const form_data = new FormData(event.target);
	const response = await fetch(`${projectURL}/game/tournament-check-player/`, {
		method: 'POST',
		headers: { 'X-CSRFToken': csrftoken, },
		body: form_data,
	});
	const response_text = await response.text();
	const tmp = document.getElementById('tournamentcheckplayer_success');
	tmp.innerHTML = '';
	tmp.classList.remove('mt-3');
	if (!response.ok) {
		try {
			const json_data = JSON.parse(response_text);
			return showErrors(event, json_data, 'tournamentcheckplayer_error');
		} catch (error) { return 1; }
	}
	try {
		const json_data = JSON.parse(response_text);
		removeError(event, 'tournamentcheckplayer_error');
		const span = document.createElement('span');
		span.classList.add('ft_mini_span');
		span.textContent = json_data.status;
		delete json_data.status;
		gameData.tour.players[json_data.alias_name] = json_data;
		tmp.appendChild(span);
		tmp.classList.add('mt-3');
		return 0;
	} catch (error) { return 1; }
}
