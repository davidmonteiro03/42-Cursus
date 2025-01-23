function gameClose(event) {
	if (event === undefined || event === null) return 1;
	try {
		event.preventDefault();
	} catch (error) { return 1; }
	try {
		renderer.setAnimationLoop(null);
		renderer.dispose();
		const gameAction = document.getElementById('gameAction');
		gameAction.removeChild(renderer.domElement);
		renderer = null;
		return 0;
	} catch (error) { return 1; }
}
