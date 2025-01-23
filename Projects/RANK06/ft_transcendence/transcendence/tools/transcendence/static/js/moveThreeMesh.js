function moveBoxUp(box, speed, ball, ball_dir, top_wall) {
	box.updateMatrixWorld();
	const boxHeight = box.geometry.parameters.height;
	const boxBounding = new THREE.Box3().setFromObject(box);
	boxBounding.max.y += speed;
	const boxNewUp = boxBounding.max.y;
	const topWallBounding = new THREE.Box3().setFromObject(top_wall);
	if (boxNewUp >= topWallBounding.min.y && boxBounding.intersectsBox(topWallBounding)) {
		box.position.y = topWallBounding.min.y - boxHeight / 2;
		return;
	}
	ball.updateMatrixWorld();
	const ballBounding = new THREE.Box3().setFromObject(ball);
	if (boxBounding.intersectsBox(ballBounding)) {
		ball_dir.y = 1;
		ball.position.y += speed;
		return;
	}
	box.position.y += speed;
}

function moveBoxDown(box, speed, ball, ball_dir, bottom_wall) {
	box.updateMatrixWorld();
	const boxHeight = box.geometry.parameters.height;
	const boxBounding = new THREE.Box3().setFromObject(box);
	boxBounding.min.y -= speed;
	const boxNewDown = boxBounding.min.y;
	const bottomWallBounding = new THREE.Box3().setFromObject(bottom_wall);
	if (boxNewDown <= bottomWallBounding.max.y && boxBounding.intersectsBox(bottomWallBounding)) {
		box.position.y = bottomWallBounding.max.y + boxHeight / 2;
		return;
	}
	ball.updateMatrixWorld();
	const ballBounding = new THREE.Box3().setFromObject(ball);
	if (boxBounding.intersectsBox(ballBounding)) {
		ball_dir.y = -1;
		ball.position.y -= speed;
		return;
	}
	box.position.y -= speed;
}

function moveSphereX(sphere, direction, speed, obstacles = []) {
	sphere.updateMatrixWorld();
	const sphereRadius = sphere.geometry.boundingSphere?.radius || sphere.geometry.parameters.radius;
	const sphereBounding = new THREE.Box3().setFromObject(sphere);
	if (direction.x > 0) {
		sphereBounding.max.x += speed;
		for (const obstacle of obstacles) {
			obstacle.updateMatrixWorld();
			const obstacleBounding = new THREE.Box3().setFromObject(obstacle);
			if (!sphereBounding.intersectsBox(obstacleBounding)) continue;
			else {
				direction.x = -direction.x;
				sphere.position.x = obstacleBounding.min.x - sphereRadius;
				return 1;
			}
		}
		sphere.position.x += speed;
	}
	else if (direction.x < 0) {
		sphereBounding.min.x -= speed;
		for (const obstacle of obstacles) {
			obstacle.updateMatrixWorld();
			const obstacleBounding = new THREE.Box3().setFromObject(obstacle);
			if (!sphereBounding.intersectsBox(obstacleBounding)) continue;
			else {
				direction.x = -direction.x;
				sphere.position.x = obstacleBounding.max.x + sphereRadius;
				return 1;
			}
		}
		sphere.position.x -= speed;
	}
	return 0;
}

function moveSphereY(sphere, direction, speed, obstacles = []) {
	sphere.updateMatrixWorld();
	const sphereRadius = sphere.geometry.boundingSphere?.radius || sphere.geometry.parameters.radius;
	const sphereBounding = new THREE.Box3().setFromObject(sphere);
	if (direction.y > 0) {
		sphereBounding.max.y += speed;
		for (const obstacle of obstacles) {
			obstacle.updateMatrixWorld();
			const obstacleBounding = new THREE.Box3().setFromObject(obstacle);
			if (!sphereBounding.intersectsBox(obstacleBounding)) continue;
			else {
				direction.y = -direction.y;
				sphere.position.y = obstacleBounding.min.y - sphereRadius;
				return 1;
			}
		}
		sphere.position.y += speed;
	}
	else if (direction.y < 0) {
		sphereBounding.min.y -= speed;
		for (const obstacle of obstacles) {
			obstacle.updateMatrixWorld();
			const obstacleBounding = new THREE.Box3().setFromObject(obstacle);
			if (!sphereBounding.intersectsBox(obstacleBounding)) continue;
			else {
				direction.y = -direction.y;
				sphere.position.y = obstacleBounding.max.y + sphereRadius;
				return 1;
			}
		}
		sphere.position.y -= speed;
	}
	return 0;
}
