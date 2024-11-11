from S1E9 import Character


class Baratheon(Character):
    """Represents a member of the Baratheon family.

    Args:
        Character (class): The base class for all characters.
    """
    def __init__(self, first_name, is_alive=True):
        """Initializes a Baratheon character with specific attributes.

        Args:
            first_name (str): The first name of the character.
            is_alive (bool, optional): Indicates if the character is alive. \
Defaults to True.
        """
        super().__init__(first_name=first_name, is_alive=is_alive)
        self.family_name = "Baratheon"
        self.eyes = "brown"
        self.hairs = "dark"

    def __str__(self) -> str:
        """Returns a string representation of the Baratheon character.

        Returns:
            str: A string containing \
the family name, eye color, and hair color.
        """
        return f"('{self.family_name}', '{self.eyes}', '{self.hairs}')"

    def __repr__(self) -> str:
        """Returns a detailed string representation of the Baratheon character.

        Returns:
            str: A string representation of \
the Baratheon character for debugging.
        """
        return f"Vector: {self}"

    def die(self):
        """Sets the character's status to deceased."""
        self.is_alive = False


class Lannister(Character):
    """Represents a member of the Lannister family.

    Args:
        Character (class): The base class for all characters.
    """
    def __init__(self, first_name, is_alive=True):
        """Initializes a Lannister character with specific attributes.

        Args:
            first_name (str): The first name of the character.
            is_alive (bool, optional): Indicates if the character is alive. \
Defaults to True.
        """
        super().__init__(first_name=first_name, is_alive=is_alive)
        self.family_name = "Lannister"
        self.eyes = "blue"
        self.hairs = "light"

    def __str__(self) -> str:
        """Returns a string representation of the Lannister character.

        Returns:
            str: A string containing \
the family name, eye color, and hair color.
        """
        return f"('{self.family_name}', '{self.eyes}', '{self.hairs}')"

    def __repr__(self) -> str:
        """Returns a detailed string representation of the Lannister character.

        Returns:
            str: A string representation of \
the Lannister character for debugging.
        """
        return f"Vector: {self}"

    def die(self):
        """Sets the character's status to deceased."""
        self.is_alive = False

    @classmethod
    def create_lannister(cls, first_name, is_alive=True):
        """Creates and returns a new Lannister character.

        Args:
            first_name (str): The first name of the character.
            is_alive (bool, optional): Indicates if the character is alive. \
Defaults to True.

        Returns:
            Lannister: A new instance of the Lannister class.
        """
        return cls(first_name=first_name, is_alive=is_alive)
