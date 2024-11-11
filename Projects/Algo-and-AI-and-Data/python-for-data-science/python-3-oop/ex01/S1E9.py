from abc import ABC, abstractmethod


class Character(ABC):
    """
    Abstract base class representing a character in the game.

    This class should be inherited by any character class in the game.
    It enforces the implementation of methods to handle the character's death.

    Args:
        ABC (class): Inherits from Python's Abstract Base Class (ABC) module.
    """
    @abstractmethod
    def __init__(self, first_name, is_alive=True):
        """
        Initializes a new instance of the Character class.

        Args:
            first_name (str): The first name of the character.
            is_alive (bool, optional): The status of the character's life. \
Defaults to True.
        """
        self.first_name = first_name
        self.is_alive = is_alive

    @abstractmethod
    def die(self):
        """
        Abstract method to handle the character's death.
        """
        pass


class Stark(Character):
    """
    Represents a character from the Stark family.

    Inherits from the Character class and implements the required methods.

    Args:
        Character (class): Inherits from the Character class.
    """
    def __init__(self, first_name, is_alive=True):
        """
        Initializes a new instance of the Stark class.

        Args:
            first_name (str): The first name of the Stark character.
            is_alive (bool, optional): The status of the character's life. \
Defaults to True.
        """
        super().__init__(first_name, is_alive)

    def die(self):
        """
        Handles the character's death by setting is_alive to False.
        """
        self.is_alive = False
