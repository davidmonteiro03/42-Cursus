def give_bmi(height: list[int | float],
             weight: list[int | float]) -> list[int | float]:
    """Calculate the Body Mass Index (BMI) for a list of heights and weights.

    Args:
        height (list[int | float]): A list of heights in meters.
        weight (list[int | float]): A list of weights in kilograms.

    Raises:
        Exception: If the height and weight lists are not of the same size.

    Returns:
        list[int | float]: A list of BMI values calculated \
from the given heights and weights.
    """
    if type(height) is not list[int | float] or \
       type(weight) is not list[int | float]:
        return None
    try:
        if len(height) != len(weight):
            raise Exception("The list must be the same size.")
        result: list[int | float] = list[int | float]()
        for h, w in zip(height, weight):
            result.append(w / (h ** 2))
        return result
    except Exception as e:
        print(f"Error: {e}")
        return None


def apply_limit(bmi: list[int | float],
                limit: int) -> list[bool]:
    """Apply a limit to a list of BMI values and \
return a list of booleans indicating if each BMI exceeds the limit.

    Args:
        bmi (list[int | float]): A list of BMI values.
        limit (int): The BMI limit to compare against.

    Returns:
        list[bool]: A list of booleans where each boolean indicates \
if the corresponding BMI value exceeds the limit.
    """
    if type(bmi) is not list[int | float] or type(limit) is not int:
        return None
    result: list[bool] = list[bool]()
    for b in bmi:
        result.append(b > limit)
    return result
