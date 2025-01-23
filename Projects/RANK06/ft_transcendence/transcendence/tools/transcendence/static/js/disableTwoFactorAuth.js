async function disableTwoFactorAuth(event) {
	if (event === undefined || event === null) { return 1; }
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	let csrftoken = Cookies.get('csrftoken');
	if (csrftoken === undefined || csrftoken === null) { return 1; }
	const response = await fetch(`${projectURL}/control/disable-two-factor-auth/`, {
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
		await changePage(event, '/control/', 'index/', false);
		changeStatusAndTitle(event, json_data);
		return 0;
	} catch (error) { return 1; }
}
