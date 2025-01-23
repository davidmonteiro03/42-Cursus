function createLight(color = 0xffffff, intensity = 0.5, x = 0, y = 0, z = 0) {
	const light = new THREE.DirectionalLight(color, intensity);
	light.position.set(x, y, z);
	light.castShadow = true;
	return light;
}

function createPlane(width = 1, height = 1, config = {}) {
	const planeGeometry = new THREE.PlaneGeometry(width, height);
	const planeMaterial = new THREE.MeshStandardMaterial(config);
	const plane = new THREE.Mesh(planeGeometry, planeMaterial);
	plane.receiveShadow = true;
	return plane;
}

function createSphere(radius = 1, widthSegments = 32, heightSegments = 32, config = {}, x = 0, y = 0, z = 0) {
	const sphereGeometry = new THREE.SphereGeometry(radius, widthSegments, heightSegments);
	const sphereMaterial = new THREE.MeshStandardMaterial(config);
	const sphere = new THREE.Mesh(sphereGeometry, sphereMaterial);
	sphere.position.set(x, y, z);
	sphere.castShadow = true;
	return sphere;
}

function createBox(width = 1, height = 1, depth = 1, config = {}, x = 0, y = 0, z = 0) {
	const boxGeometry = new THREE.BoxGeometry(width, height, depth);
	const boxMaterial = new THREE.MeshStandardMaterial(config);
	const box = new THREE.Mesh(boxGeometry, boxMaterial);
	box.position.set(x, y, z);
	box.castShadow = true;
	return box;
}
