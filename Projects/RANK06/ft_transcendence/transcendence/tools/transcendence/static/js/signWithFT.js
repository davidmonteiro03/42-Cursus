async function signWithFT(event) {
	if (event === undefined || event === null) return 1;
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	let csrftoken = Cookies.get('csrftoken');
	if (csrftoken === undefined || csrftoken === null) return 1;
	const response = await fetch(`${projectURL}/control/sign-with-ft/`, {
		method: 'POST',
		headers: { 'X-CSRFToken': csrftoken, },
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
		if (json_data.authorization_url !== null && json_data.authorization_url !== undefined && json_data.authorization_url !== '') {
			window.location.href = json_data.authorization_url;
		}
		return 0;
	} catch (error) { return 1; }
}
