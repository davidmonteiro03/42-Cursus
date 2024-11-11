import numpy as np


def slice_me(family: list, start: int, end: int) -> list:
    """Slice a list from the start index to the end index and \
print the shapes before and after slicing.

    Args:
        family (list): The list to be sliced.
        start (int): The starting index for the slice.
        end (int): The ending index for the slice.

    Returns:
        list: The sliced list.
    """
    if type(family) is not list or \
       type(start) is not int or \
       type(end) is not int:
        return None
    shape = np.shape(family)
    sliced = family[slice(start, end, 1)]
    new_shape = np.shape(sliced)
    print(f"My shape is : {shape}")
    print(f"My new shape is : {new_shape}")
    return sliced
