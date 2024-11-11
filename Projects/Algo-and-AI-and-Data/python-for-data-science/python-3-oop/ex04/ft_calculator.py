class calculator:
    """A simple calculator class to perform vector operations."""
    @staticmethod
    def dotproduct(V1: list[float], V2: list[float]) -> None:
        """Calculates the dot product of two vectors and prints the result.

        Args:
            V1 (list): The first vector.
            V2 (list): The second vector.
        """
        result: int = sum([a * b for a, b in zip(V1, V2)])
        print(f"Dot product is: {result}")

    @staticmethod
    def add_vec(V1: list[float], V2: list[float]) -> None:
        """Adds two vectors element-wise and prints the result.

        Args:
            V1 (list): The first vector.
            V2 (list): The second vector.
        """
        result: list[float] = [float(a) + float(b) for a, b in zip(V1, V2)]
        print(f"Add Vector is : {result}")

    @staticmethod
    def sous_vec(V1: list[float], V2: list[float]) -> None:
        """Subtracts the second vector from the \
first vector element-wise and prints the result.

        Args:
            V1 (list): The first vector.
            V2 (list): The second vector.
        """
        result: list[float] = [float(a) - float(b) for a, b in zip(V1, V2)]
        print(f"Sous Vector is: {result}")
