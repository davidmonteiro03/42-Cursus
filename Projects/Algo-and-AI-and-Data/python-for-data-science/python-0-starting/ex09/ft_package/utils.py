def count_in_list(lst: list[any], item: any) -> int:
    """Count the occurrences of an item in a list.

    Args:
        lst (list[any]): The list in which to count \
the occurrences of the item.
        item (any): The item to count in the list.

    Returns:
        int: The number of times the item appears in the list.
    """
    return lst.count(item)
