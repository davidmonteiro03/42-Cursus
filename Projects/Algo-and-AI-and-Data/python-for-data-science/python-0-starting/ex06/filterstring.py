from ft_filter import ft_filter
import sys


def main():
    argc: int = len(sys.argv)
    try:
        assert argc == 3, "the arguments are bad"
        try:
            n = int(sys.argv[2])
            words = sys.argv[1].split()
            result = list(ft_filter(lambda str: (len(str) > n), words))
            print(result)
        except Exception:
            raise AssertionError("arguments are bad")
    except AssertionError as error:
        print(f"AssertionError: {error}")


if __name__ == "__main__":
    main()
