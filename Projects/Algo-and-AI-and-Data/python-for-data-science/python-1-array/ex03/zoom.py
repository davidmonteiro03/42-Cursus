from load_image import ft_load
from PIL import Image as img
import numpy as np
import cv2 as ocv


def main():
    loaded = ft_load("animal.jpeg")
    print(loaded)
    image = img.fromarray(loaded)
    cropped = image.crop((220, 0, 425, 205))
    shape = np.array(cropped)
    print(f"New shape after slicing: {cropped.size}")
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
