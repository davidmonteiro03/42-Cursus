class calculator:
    """A simple calculator class to perform basic arithmetic \
operations on a list of numbers.

    Attributes:
        object (list): A list of numbers to perform operations on.
    """
    def __init__(self, object):
        """Initializes the calculator with a list of numbers.

        Args:
            object (list): A list of numbers.
        """
        self.object = object

    def __add__(self, object) -> None:
        """Adds a number to each element in the list.

        Args:
            object (int or float): The number to add to \
each element in the list.
        """
        try:
            self.object = [num + object for num in self.object]
            print(self.object)
        except Exception as e:
            print(f"Exception: {e}")

    def __mul__(self, object) -> None:
        """Multiplies each element in the list by a number.

        Args:
            object (int or float): The number to multiply \
each element in the list by.
        """
        try:
            self.object = [num * object for num in self.object]
            print(self.object)
        except Exception as e:
            print(f"Exception: {e}")

    def __sub__(self, object) -> None:
        """Subtracts a number from each element in the list.

        Args:
            object (int or float): The number to subtract from \
each element in the list.
        """
        try:
            self.object = [num - object for num in self.object]
            print(self.object)
        except Exception as e:
            print(f"Exception: {e}")

    def __truediv__(self, object) -> None:
        """Divides each element in the list by a number.

        Args:
            object (int or float): The number to divide each \
element in the list by.
        """
        try:
            self.object = [num / object for num in self.object]
            print(self.object)
        except Exception as e:
            print(f"Exception: {e}")
