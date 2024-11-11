def all_thing_is_obj(object: any) -> int:
    """Identify the type of an object and print a message based on its type.

    Args:
        object (any): The object to identify.

    Returns:
        int: Always returns 42.
    """
    if type(object) is list:
        print(f"List : {type(object)}")
    elif type(object) is tuple:
        print(f"Tuple : {type(object)}")
    elif type(object) is set:
        print(f"Set : {type(object)}")
    elif type(object) is dict:
        print(f"Dict : {type(object)}")
    elif type(object) is str:
        print(f"{object} is in the kitchen : {type(object)}")
    else:
        print("Type not found")
    return 42
