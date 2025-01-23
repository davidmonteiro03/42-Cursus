async function gameCheckData(event) {
	if (event === undefined || event === null) { return 1; }
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	let csrftoken = Cookies.get('csrftoken');
	if (csrftoken === undefined || csrftoken === null) { return 1; }
	const response = await fetch(`${projectURL}/game/check-data/`, {
		method: 'POST',
		headers: { 'X-CSRFToken': csrftoken, },
		body: JSON.stringify(gameData),
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
		let file = null;
		try {
			if (gameData.tour.config.field.file !== undefined && gameData.tour.config.field.file !== null && gameData.tour.config.field.file !== '') { file = gameData.tour.config.field.file; }
		} catch (error) {
			try {
				if (gameData.config.field.file !== undefined && gameData.config.field.file !== null && gameData.config.field.file !== '') { file = gameData.config.field.file; }
			} catch (error) { }
		}
		gameData = json_data;
		try {
			if (file !== undefined && file !== null && file !== '') { gameData.tour.config.field.file = file; }
		} catch (error) {}
		return 0;
	} catch (error) { return 1; }
}

async function gameNavigate(event, page = 'index/') {
	if (event === undefined || event === null) { return 1; }
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	try {
		game = document.getElementById('game');
		if (game === undefined || game === null) { return 1; }
		if (gameData.currentPage === page) { return 0; }
		if (page === 'index/') { await loadElement(event, content, '/game/', 'content/', 'index/'); }
		else { await loadElement(event, game, '/game/', 'content/', page); }
		if (page !== 'game/') { gameClose(event); }
		gameData.history.push(page);
		gameData.currentPage = page;
		return 0;
	} catch (error) { return 1; }
}

async function gameNavigateBack(event) {
	if (event === undefined || event === null) { return 1; }
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	try {
		game = document.getElementById('game');
		if (game === undefined || game === null) { return 1; }
		gameData.history.pop();
		const gameHistoryLength = gameData.history.length;
		if (gameHistoryLength === 0) {
			await loadElement(event, content, '/game/', 'content/', 'index/');
			gameData.currentPage = 'index/';
		}
		else {
			let page = gameData.history[gameHistoryLength - 1];
			if (page !== 'game/') { gameClose(event); }
			if (page === 'index/') {
				await loadElement(event, content, '/game/', 'content/', 'index/');
				gameData.currentPage = 'index/';
			}
			else {
				await loadElement(event, game, '/game/', 'content/', page);
				gameData.currentPage = page;
			}
		}
		await gameCheckData(event);
		return 0;
	} catch (error) { return 1; }
}
