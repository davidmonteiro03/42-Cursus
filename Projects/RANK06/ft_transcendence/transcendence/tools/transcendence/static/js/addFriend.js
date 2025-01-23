async function addFriend(event) {
	if (event === undefined || event === null) { return 1; }
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	let csrftoken = Cookies.get('csrftoken');
	if (csrftoken === undefined || csrftoken === null) { return 1; }
	const form_data = new FormData(event.target);
	const response = await fetch(`${projectURL}/control/add-friend/`, {
		method: 'POST',
		headers: { 'X-CSRFToken': csrftoken, },
		body: form_data,
	});
	const response_text = await response.text();
	if (!response.ok) {
		try {
			const json_data = JSON.parse(response_text);
			return showErrors(event, json_data, 'addfriend_error');
		} catch (error) { return 1; }
	}
	try {
		const json_data = JSON.parse(response_text);
		removeError('addfriend_error');
		await changePage(event, currentApp, currentPage, false);
		changeStatusAndTitle(event, json_data);
		return 0;
	} catch (error) { return 1; }
}
