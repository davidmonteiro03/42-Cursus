async function loadElement(event, component, app, url, page = '') {
	if (event === undefined || event === null) { return 1; }
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	if (component === undefined || component === null || url === undefined || url === null) { return 1; }
	let csrftoken = Cookies.get('csrftoken');
	if (csrftoken === undefined || csrftoken === null) return 1;
	const response = await fetch(`${projectURL}${app}${url}${page}`, {
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
		if (json_data.html !== undefined && json_data.html !== null && json_data.html !== '') component.innerHTML = json_data.html;
		return 0;
	} catch (error) { return 1; }
}
