import sys

argc: int = len(sys.argv)
try:
    assert argc <= 2, "more than one argument is provided"
    if argc == 2:
        try:
            tmp: int = int(sys.argv[1])
            print("I'm Even." if tmp % 2 == 0 else "I'm Odd.")
        except Exception:
            raise AssertionError("argument is not an integer")
except AssertionError as error:
    print(f"AssertionError: {error}")
