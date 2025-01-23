async function loadFieldTexture(file, field_width, field_height) {
	return new Promise((resolve, reject) => {
		const reader = new FileReader();
		reader.onload = function (e) {
			const image = new Image();
			image.src = e.target.result;
			image.onload = function () {
				const texture = new THREE.Texture(image);
				texture.needsUpdate = true;
				texture.wrapS = THREE.ClampToEdgeWrapping;
				texture.wrapT = THREE.ClampToEdgeWrapping;
				texture.encoding = THREE.sRGBEncoding;
				const imageAspect = image.width / image.height;
				const fieldAspect = field_width / field_height;
				if (imageAspect > fieldAspect) {
					texture.repeat.set(fieldAspect / imageAspect, 1);
					texture.offset.x = (1 - texture.repeat.x) / 2;
				} else {
					texture.repeat.set(1, imageAspect / fieldAspect);
					texture.offset.y = (1 - texture.repeat.y) / 2;
				}
				resolve({ map: texture, transparent: true });
			};
			image.onerror = reject;
		};
		reader.onerror = reject;
		reader.readAsDataURL(file);
	});
}
