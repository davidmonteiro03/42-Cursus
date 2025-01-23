function createPieChart(ctx, type, data_labels, data_datasets_data) {
	const root = document.documentElement;

	const goodColor = getComputedStyle(root).getPropertyValue('--ft-medium-success-color').trim();
	const badColor = getComputedStyle(root).getPropertyValue('--ft-medium-danger-color').trim();
	Chart.defaults.font.size = 15;

	new Chart(ctx, {
		type: type,
		data: {
			labels: data_labels,
			datasets: [
				{
					data: data_datasets_data,
					backgroundColor: [goodColor, badColor],
					borderColor: [goodColor, badColor],
					borderWidth: 0,
				},
			],
		},
		options: {
			maintainAspectRatio: true,
			responsive: true,
		},
	});
}
