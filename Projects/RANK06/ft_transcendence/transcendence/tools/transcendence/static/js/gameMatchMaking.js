async function MatchMaking(event) {
	if (event === undefined || event === null) { return 1; }
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	let csrftoken = Cookies.get('csrftoken');
	if (csrftoken === undefined || csrftoken === null) { return 1; }
	const response = await fetch(`${projectURL}/game/match-making/`, {
		method: 'POST',
		headers: { 'X-CSRFToken': csrftoken, },
		body: JSON.stringify(gameData.tour),
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
		gameData.tour.games = json_data.games;
		gameData.tour.round = json_data.round;
		gameData.tour.players = {};
		if (json_data.byes !== undefined && json_data.byes !== null) {
			for (let key in json_data.byes) {
				gameData.tour.players[key] = json_data.byes[key];
			}
		}
		return 0;
	} catch (error) { return 1; }
}
