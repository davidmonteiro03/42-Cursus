function updateScoreDiv(s_home, s_away, numbers) {
	try {
		const score_home = document.getElementById('score_home');
		const score_away = document.getElementById('score_away');
		score_home.innerHTML = '';
		score_away.innerHTML = '';
		const scoreHomeStr = s_home.toString();
		const scoreAwayStr = s_away.toString();
		for (let i = 0; i < scoreHomeStr.length; i++) { score_home.appendChild(numbers[parseInt(scoreHomeStr[i])].cloneNode(true)); }
		for (let i = 0; i < scoreAwayStr.length; i++) { score_away.appendChild(numbers[parseInt(scoreAwayStr[i])].cloneNode(true)); }
	} catch (error) { }
}

function updateAliasNames(p_home, p_away) {
	try {
		const player_home = document.getElementById('player_home');
		const player_away = document.getElementById('player_away');
		player_home.textContent = p_home;
		player_away.textContent = p_away;
		player_home.style.fontFamily = 'Bitstream Vera Mono';
		player_away.style.fontFamily = 'Bitstream Vera Mono';
	} catch (error) { }
}
