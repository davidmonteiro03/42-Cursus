import cv2 as ocv
from PIL import Image as img
import numpy as np


def ft_invert(array: list) -> list:
    """
    Inverts the colors of an image.

    Args:
        array (list): A 3D list representing the image in RGB format.

    Returns:
        list: A 3D list representing the image with \
inverted colors in BGR format.
    """
    original_image = img.fromarray(array)
    original_array = np.array(original_image)
    inverted_array = 255 - original_array
    inverted_array = inverted_array * 1
    ocv.imshow('Invert', inverted_array)
    return inverted_array


def ft_red(array: list) -> list:
    """
    Applies a red filter to the image by zeroing out \
the green and blue channels.

    Args:
        array (list): A 3D list representing the image in RGB format.

    Returns:
        list: A 3D list representing the image with only the red channel.
    """
    original_image = img.fromarray(array)
    original_array = np.array(original_image)
    red_array = original_array.copy()
    red_array[:, :, 0] = 0
    red_array[:, :, 1] = 0
    ocv.imshow('Red', red_array)
    return red_array


def ft_green(array: list) -> list:
    """
    Applies a green filter to the image by zeroing out \
the red and blue channels.

    Args:
        array (list): A 3D list representing the image in RGB format.

    Returns:
        list: A 3D list representing the image with only the green channel.
    """
    original_image = img.fromarray(array)
    original_array = np.array(original_image)
    green_array = original_array.copy()
    green_array[:, :, 0] = 0
    green_array[:, :, 2] = 0
    ocv.imshow('Green', green_array)
    return green_array


def ft_blue(array: list) -> list:
    """
    Applies a blue filter to the image by zeroing out \
the red and green channels.

    Args:
        array (list): A 3D list representing the image in RGB format.

    Returns:
        list: A 3D list representing the image with only the blue channel.
    """
    original_image = img.fromarray(array)
    original_array = np.array(original_image)
    blue_array = original_array.copy()
    blue_array[:, :, 1] = 0
    blue_array[:, :, 2] = 0
    ocv.imshow('Blue', blue_array)
    return blue_array


def ft_grey(array: list) -> list:
    """
    Converts the image to grayscale.

    Args:
        array (list): A 3D list representing the image in RGB format.

    Returns:
        list: A 2D list representing the grayscale image.
    """
    original_image = img.fromarray(array)
    original_array = np.array(original_image)
    grey_array = (original_array[:, :, 0] / 3 +
                  original_array[:, :, 1] / 3 +
                  original_array[:, :, 2] / 3).astype(np.uint8)
    ocv.imshow('Grey', grey_array)
    return grey_array
