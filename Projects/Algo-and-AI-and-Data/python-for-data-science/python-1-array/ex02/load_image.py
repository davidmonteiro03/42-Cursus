import cv2 as ocv


def ft_load(path: str) -> list:
    """Load an image from the specified file path and return it as a list.

    Args:
        path (str): The file path to the image.

    Returns:
        list: The loaded image as a list. \
If the path is not a string, returns None.
    """
    if type(path) is not str:
        return None
    image = ocv.cvtColor(ocv.imread(path), ocv.COLOR_BGR2RGB)
    print(f"The shape of image is: {image.shape}")
    return image
