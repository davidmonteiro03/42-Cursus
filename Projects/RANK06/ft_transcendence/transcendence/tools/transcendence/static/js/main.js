
let navbar = null;
let content = null;
let modal = null;
let footer = null;
let currentApp = '/';
let currentPage = 'index/';
let projectURL = null;
let webSocketURL = null;
let webSocket = null;
let gameData = null;
let renderer = null;

function changeStatusAndTitle(event, json_data) {
	if (event === undefined || event === null) return 1;
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	if (json_data.title !== undefined && json_data.title !== null && json_data.title !== '') { document.title = json_data.title; }
	if (json_data.status !== undefined && json_data.status !== null && json_data.status !== '') { console.log(json_data.status); }
	return 0;
}

function showErrors(event, errors, id = null) {
	if (event === undefined || event === null) return 1;
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	if (errors === undefined || errors === null || errors === '') return 1;
	const component = id !== undefined && id !== null && id !== '' ? document.getElementById(id) : null;
	if (component !== undefined && component !== null && component !== '') {
		component.innerHTML = '';
		component.classList.add('d-flex', 'flex-column', 'justify-content-center', 'align-items-center', 'w-100');
	}
	for (let key in errors) {
		console.warn(errors[key]);
		if (component !== undefined && component !== null && component !== '') {
			const span = document.createElement('span');
			span.classList.add('ft_error', 'w-100', 'mt-3');
			span.textContent = errors[key];
			component.appendChild(span);
		}
	}
	return 1;
}

function removeError(event, id = null) {
	if (event === undefined || event === null) return 1;
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	const component = id !== undefined && id !== null && id !== '' ? document.getElementById(id) : null;
	if (component === undefined || component === null || component === '') return 1;
	try {
		component.innerHTML = '';
		component.classList.remove('d-flex', 'flex-column', 'justify-content-center', 'align-items-center', 'w-100');
	} catch (error) { return 1; }
	return 0;
}

function openModal(event, id) {
	if (event === undefined || event === null) return 1;
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	const modalElement = document.getElementById(id);
	if (modalElement === undefined || modalElement === null) return 1;
	const modalInstance = bootstrap.Modal.getInstance(modalElement) || new bootstrap.Modal(modalElement);
	if (modalInstance === undefined || modalInstance === null) return 1;
	modalInstance.show();
	return 0;
}

function closeModal(event, id) {
	if (event === undefined || event === null) return 1;
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	const modalElement = document.getElementById(id);
	if (modalElement === undefined || modalElement === null) return 1;
	const modalInstance = bootstrap.Modal.getInstance(modalElement) || new bootstrap.Modal(modalElement);
	if (modalInstance === undefined || modalInstance === null) return 1;
	modalInstance.hide();
	return 0;
}

function closeAllModals(event) {
	if (event === undefined || event === null) return 1;
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	const allModals = document.querySelectorAll('.modal');
	allModals.forEach(modal => {
		closeModal(event, modal.id);
	});
	return 0;
}

function getRoute(app = '/', page = 'index/') {
	let route = app;
	if (page == 'index/')
		return route;
	route += page;
	return route;
}

async function changePage(event, app = '/', page = 'index/', restricted = true, up_history = true) {
	if (event === undefined || event === null) return 1;
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	let status = 0;
	if (restricted === true && currentApp === app && currentPage === page) return status;
	closeAllModals(event);
	const oldRoute = getRoute(currentApp, currentPage);
	status = await loadElement(event, navbar, app, 'navbar/');
	status = await loadElement(event, content, app, 'content/', page);
	if (status == 0) {
		currentApp = app;
		currentPage = page;
	}
	const newRoute = getRoute(currentApp, currentPage);
	status = await loadElement(event, modal, app, 'modal/');
	status = await loadElement(event, footer, app, 'footer/');

	if (currentApp === '/' && currentPage === 'index/') {
		try {
			const statsDiv = document.getElementById('stats');

			statsDiv.classList.add('d-flex', 'flex-row', 'justify-content-evenly', 'align-items-center', 'w-100', 'mt-3');

			const statsData = await getStatsData(event);

			if (statsData.game.data_datasets_data[0] !== 0 || statsData.game.data_datasets_data[1] !== 0) {
				const gameStatsDiv = document.createElement('div');
				const gameStatsTitleDiv = document.createElement('span');
				const gameStatsBodyDiv = document.createElement('div');
				const gameStatsCanvas = document.createElement('canvas');
				const gameStats = gameStatsCanvas.getContext('2d');

				gameStatsDiv.classList.add('d-flex', 'flex-column', 'justify-content-center', 'align-items-center', 'flex-x-fillm');
				gameStatsTitleDiv.classList.add('ft_span', 'neon_effects');
				gameStatsBodyDiv.classList.add('d-flex', 'justify-content-center', 'align-items-center', 'flex-x-fill', 'mt-2');

				gameStatsTitleDiv.textContent = statsData.game.title;
				gameStatsBodyDiv.appendChild(gameStatsCanvas);
				gameStatsDiv.appendChild(gameStatsTitleDiv);
				gameStatsDiv.appendChild(gameStatsBodyDiv);
				statsDiv.appendChild(gameStatsDiv);

				createPieChart(gameStats, "pie", statsData.game.data_labels, statsData.game.data_datasets_data);
			}

			if (statsData.tournament.data_datasets_data[0] !== 0 || statsData.tournament.data_datasets_data[1] !== 0) {
				const tournamentStatsDiv = document.createElement('div');
				const tournamentStatsTitleDiv = document.createElement('span');
				const tournamentStatsBodyDiv = document.createElement('div');
				const tournamentStatsCanvas = document.createElement('canvas');
				const tournamentStats = tournamentStatsCanvas.getContext('2d');

				tournamentStatsDiv.classList.add('d-flex', 'flex-column', 'justify-content-center', 'align-items-center', 'flex-x-fill');
				tournamentStatsTitleDiv.classList.add('ft_span', 'neon_effects');
				tournamentStatsBodyDiv.classList.add('d-flex', 'justify-content-center', 'align-items-center', 'flex-x-fill', 'mt-2');

				tournamentStatsTitleDiv.textContent = statsData.tournament.title;
				tournamentStatsBodyDiv.appendChild(tournamentStatsCanvas);
				tournamentStatsDiv.appendChild(tournamentStatsTitleDiv);
				tournamentStatsDiv.appendChild(tournamentStatsBodyDiv);
				statsDiv.appendChild(tournamentStatsDiv);

				createPieChart(tournamentStats, "pie", statsData.tournament.data_labels, statsData.tournament.data_datasets_data);
			}

			if (statsData.point.data_datasets_data[0] !== 0 || statsData.point.data_datasets_data[1] !== 0) {
				const pointStatsDiv = document.createElement('div');
				const pointStatsTitleDiv = document.createElement('span');
				const pointStatsBodyDiv = document.createElement('div');
				const pointStatsCanvas = document.createElement('canvas');
				const pointStats = pointStatsCanvas.getContext('2d');

				pointStatsDiv.classList.add('d-flex', 'flex-column', 'justify-content-center', 'align-items-center', 'flex-x-fill');
				pointStatsTitleDiv.classList.add('ft_span', 'neon_effects');
				pointStatsBodyDiv.classList.add('d-flex', 'justify-content-center', 'align-items-center', 'flex-x-fill', 'mt-2');

				pointStatsTitleDiv.textContent = statsData.point.title;
				pointStatsBodyDiv.appendChild(pointStatsCanvas);
				pointStatsDiv.appendChild(pointStatsTitleDiv);
				pointStatsDiv.appendChild(pointStatsBodyDiv);
				statsDiv.appendChild(pointStatsDiv);

				createPieChart(pointStats, "pie", statsData.point.data_labels, statsData.point.data_datasets_data);
			}

		} catch (error) { }
	}
	if (up_history === true && oldRoute !== newRoute)
		history.pushState({ app: currentApp, page: currentPage }, null, newRoute);
	if (app === '/game/') { gameData = { history: [], currentPage: 'index/' }; }
	else { gameClose(event); delete gameData; }
	return status;
}

async function updateSocket() {
	if (webSocket !== undefined && webSocket !== null) webSocket.close();
	webSocket = new WebSocket(webSocketURL);
	webSocket.onmessage = async function (event) {
		if (currentApp === '/control/' && currentPage === 'friends/') {
			await loadElement(event, content, currentApp, 'content/', currentPage);
		}
	};
	return 0;
}

document.addEventListener('DOMContentLoaded', async function (event) {
	if (event === undefined || event === null) return 1;
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	projectURL = `${window.location.protocol}//${window.location.host}`;
	webSocketURL = `wss://${window.location.host}/ws/`;
	navbar = document.getElementById('navbar');
	content = document.getElementById('content');
	modal = document.getElementById('modal');
	footer = document.getElementById('footer');
	await changePage(event, currentApp, currentPage, false);
	openModal(event, 'configurePasswordModal');
	openModal(event, 'twoFactorAuthVerifyLoginModal');
	window.onpopstate = async function (event) {
		event.preventDefault();
		if (event.state === null) {
			newApp = '/';
			newPage = 'index/';
		}
		else {
			newApp = event.state.app;
			newPage = event.state.page;
		}
		closeAllModals(event);
		changePage(event, newApp, newPage, true, false);
		const newRoute = getRoute(newApp, newPage);
		history.replaceState({ app: newApp, page: newPage }, null, newRoute);

	};
	await updateSocket();
	Starfield.setup({
		auto: false,
		originX: this.documentElement.clientWidth / 2,
		originY: this.documentElement.clientHeight / 2,
	});
	return 0;
});
