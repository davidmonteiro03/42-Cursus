from typing import Any


def callLimit(limit: int):
    """
    Decorator to limit the number of times a function can be called.

    Args:
        limit (int): The maximum number of times the function can be called.

    Raises:
        AssertionError: If the function is called \
more than the specified limit.

    Returns:
        Callable: A decorator that limits the number of calls to the function.
    """
    count = 0

    def callLimiter(function):
        """
        Inner decorator function that wraps the original function.

        Args:
            function (Callable): The function to be limited.

        Returns:
            Callable: The wrapped function with call limit.
        """
        def limit_function(*args: Any, **kwds: Any):
            """
            The function that enforces the call limit.

            Args:
                *args (Any): Positional arguments for the function.
                **kwds (Any): Keyword arguments for the function.

            Raises:
                AssertionError: If the function is called \
more than the specified limit.

            Returns:
                Any: The result of the function call \
if within limit, otherwise None.
            """
            try:
                nonlocal count
                if count < limit:
                    count += 1
                    return function(*args, **kwds)
                else:
                    raise AssertionError(f"{function} call too many times")
            except AssertionError as e:
                print(f"Error: {e}")
                return None
        return limit_function
    return callLimiter
