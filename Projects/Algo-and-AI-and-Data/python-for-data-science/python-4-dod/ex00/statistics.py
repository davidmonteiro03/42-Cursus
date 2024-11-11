from typing import Any


def ft_mean(data: list[Any]) -> Any:
    """
    Calculate the mean of a list of numbers.

    Args:
        data (list[Any]): A list of numerical values.

    Returns:
        Any: The mean of the list.
    """
    return sum(data) / len(data)


def ft_percentile(data: list[Any], k: float) -> Any:
    """
    Calculate the k-th percentile of a list of numbers.

    Args:
        data (list[Any]): A list of numerical values.
        k (float): The percentile to calculate (0-100).

    Returns:
        Any: The k-th percentile value.
    """
    tmp = sorted(data)
    n = len(tmp)
    p = (n - 1) * k / 100
    i = int(p)
    d = p - i
    if i + 1 < n:
        return tmp[i] + d * (tmp[i + 1] - tmp[i])
    return tmp[i]


def ft_var(data: list[Any]) -> Any:
    """
    Calculate the variance of a list of numbers.

    Args:
        data (list[Any]): A list of numerical values.

    Returns:
        Any: The variance of the list.
    """
    n = len(data)
    mean = ft_mean(data)
    devs = [item - mean for item in data]
    sumd = sum([dev ** 2 for dev in devs])
    return sumd / n


def ft_std(data: list[Any]) -> Any:
    """
    Calculate the standard deviation of a list of numbers.

    Args:
        data (list[Any]): A list of numerical values.

    Returns:
        Any: The standard deviation of the list.
    """
    return ft_var(data) ** 0.5


def trunc_dec(value: Any) -> Any:
    """
    Truncate a decimal value if it is an integer.

    This function checks if the given value is equal \
to its integer representation.
    If it is, the function returns the integer value. \
Otherwise, it returns the original value.

    Args:
        value (Any): The value to be checked and potentially truncated. \
It is expected to be a number.

    Returns:
        Any: The integer value if the input is an integer, \
otherwise the original value.
    """
    return int(value) if value == int(value) else value


def print_mean(data: list[Any]) -> None:
    """
    Print the mean of a list of numbers.

    Args:
        data (list[Any]): A list of numerical values.
    """
    try:
        mean = ft_mean(data)
        print(f"mean : {trunc_dec(mean)}")
    except Exception:
        print("ERROR")


def print_median(data: list[Any]) -> None:
    """
    Print the median of a list of numbers.

    Args:
        data (list[Any]): A list of numerical values.
    """
    try:
        median = ft_percentile(data, 50)
        print(f"median : {trunc_dec(median)}")
    except Exception:
        print("ERROR")


def print_quartile(data: list[Any]) -> None:
    """
    Print the first and third quartiles of a list of numbers.

    Args:
        data (list[Any]): A list of numerical values.
    """
    try:
        quartile = [float(ft_percentile(data, 25)),
                    float(ft_percentile(data, 75))]
        print(f"quartile : {quartile}")
    except Exception:
        print("ERROR")


def print_std(data: list[Any]) -> None:
    """
    Print the standard deviation of a list of numbers.

    Args:
        data (list[Any]): A list of numerical values.
    """
    try:
        std = float(ft_std(data))
        print(f"std : {std}")
    except Exception:
        print("ERROR")


def print_var(data: list[Any]) -> None:
    """
    Print the variance of a list of numbers.

    Args:
        data (list[Any]): A list of numerical values.
    """
    try:
        var = float(ft_var(data))
        print(f"var : {var}")
    except Exception:
        print("ERROR")


def ft_statistics(*args: Any, **kwargs: Any) -> None:
    """
    Calculate and print various statistics for a list of numbers.

    Args:
        *args (Any): A variable number of numerical values.
        **kwargs (Any): Keyword arguments specifying which statistics to print.
                        Options are \
"mean", "median", "quartile", "std", and "var".
    """
    if kwargs:
        for kwarg in kwargs.values():
            if kwarg == "mean":
                print_mean(list(args))
            elif kwarg == "median":
                print_median(list(args))
            elif kwarg == "quartile":
                print_quartile(list(args))
            elif kwarg == "std":
                print_std(list(args))
            elif kwarg == "var":
                print_var(list(args))
