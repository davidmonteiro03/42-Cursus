from load_image import ft_load
from PIL import Image as img
import numpy as np
import cv2 as ocv


def main():
    loaded = ft_load("animal.jpeg")
    image = img.fromarray(loaded)
    cropped = image.crop((220, 0, 425, 205))
    shape = np.array(cropped)
    print(f"The shape of image is: {cropped.size}")
    print(shape)
    rotated = cropped.transpose(img.ROTATE_90)
    shape = np.array(rotated)
    print(f"New shape after Transpose: {rotated.size}")
    print(shape)
    ocv.imshow('Zoom', shape)
    while True:
        if ocv.getWindowProperty('Zoom', ocv.WND_PROP_VISIBLE) < 1:
            break
        if ocv.waitKey(1) & 0xFF == 27:
            break
    ocv.destroyAllWindows()


if __name__ == "__main__":
    main()
