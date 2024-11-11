def NULL_not_found(object: any) -> int:
    """Identify the type of a given object and \
print a message based on its type.

    Args:
        object (any): The object to identify.

    Returns:
        int: Returns 0 if the type is identified, otherwise returns 1.
    """
    ret: int = 0
    if object is None:
        print(f"Nothing: {object} {type(object)}")
    elif type(object) is float:
        print(f"Cheese: {object} {type(object)}")
    elif type(object) is int:
        print(f"Zero: {object} {type(object)}")
    elif type(object) is bool:
        print(f"Fake: {object} {type(object)}")
    elif len(object) == 0:
        print(f"Empty: {type(object)}")
    else:
        print("Type not found")
        ret = 1
    return ret
