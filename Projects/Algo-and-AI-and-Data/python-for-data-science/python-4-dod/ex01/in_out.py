def square(x: int | float) -> int | float:
    """
    Calculate the square of a number.

    Args:
        x (int | float): The number to be squared.

    Returns:
        int | float: The square of the number.
    """
    return x * x


def pow(x: int | float) -> int | float:
    """
    Calculate the power of a number raised to itself.

    Args:
        x (int | float): The base number.

    Returns:
        int | float: The result of the base number raised \
to the power of itself.
    """
    return x ** x


def outer(x: int | float, function) -> object:
    """
    Create a closure that applies a function \
to a number and updates the number.

    Args:
        x (int | float): The initial number.
        function (callable): The function to apply to the number.

    Returns:
        object: A function that applies the given function \
to the number and updates the number.
    """
    def inner() -> float:
        """
        Apply the function to the number and update the number.

        Returns:
            float: The result of applying the function to the number.
        """
        nonlocal x
        x = function(x)
        return x
    return inner
