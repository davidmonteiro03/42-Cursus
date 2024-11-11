import shutil


def ft_tqdm(lst: range) -> None:
    """A custom function to replicate the command tqdm

    Args:
        lst (range): The range of items to iterate over.

    Yields:
        int: The next item in the range.

    This function displays a progress bar in the terminal \
while iterating over the given range.
    """
    size: int = len(lst)
    for i, item in enumerate(lst):
        perc = f"{(i + 1) / size:4.0%}"
        status = f"{i + 1}/{size}"
        bar_width = shutil.get_terminal_size().columns - 33 - len(status)
        progress = (bar_width - 3) * (i + 1) // size
        bar = f"[{'=' * progress}>{' ' * (bar_width - 3 - progress)}]"
        output = f"\r{perc}|{bar}| {status}"
        print(output, end="", flush=True)
        yield item
    print()
