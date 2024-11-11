import sys


def ft_input():
    """Prompt the user for input and return the input as a string.

    Returns:
        str: The user input followed by a newline character. \
If an EOFError occurs, returns an empty string.
    """
    stdin: str = ""
    try:
        stdin = str(input("What is the text to count?\n"))
        stdin += "\n"
    except EOFError:
        pass
    return stdin


def main():
    argc: int = len(sys.argv)
    punct_set: str = r""""!#$%&'()*+,-./:;<=>?@[\]^_`{|}~"""
    try:
        assert argc <= 2, "more than one argument is provided"
        if argc == 2:
            text: str = sys.argv[1]
        else:
            text: str = ft_input()
        upper = sum(1 for char in text if char.isupper())
        lower = sum(1 for char in text if char.islower())
        punct = sum(1 for char in text if char in punct_set)
        space = sum(1 for char in text if char.isspace())
        digit = sum(1 for char in text if char.isdigit())
        print(f"The text contains {len(text)} characters:")
        print(f"{upper} upper letters")
        print(f"{lower} lower letters")
        print(f"{punct} punctuation marks")
        print(f"{space} spaces")
        print(f"{digit} digits")
    except AssertionError as error:
        print(f"AssertionError: {error}")


if __name__ == "__main__":
    main()
