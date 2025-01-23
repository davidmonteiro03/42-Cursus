async function getStatsData(event) {
	if (event === undefined || event === null) { return null; }
	try {
		event.preventDefault();
	} catch (error) { return null; }
	let csrftoken = Cookies.get('csrftoken');
	if (csrftoken === undefined || csrftoken === null) { return null; }
	const response = await fetch(`${projectURL}/game/get-stats/`, {
		method: 'POST',
		headers: { 'X-CSRFToken': csrftoken, },
	});
	const response_text = await response.text();
	if (!response.ok) {
		try {
			const json_data = JSON.parse(response_text);
			showErrors(event, json_data);
			return null;
		} catch (error) { return null; }
	}
	try {
		const json_data = JSON.parse(response_text);
		return json_data;
	} catch (error) { return null; }
}
