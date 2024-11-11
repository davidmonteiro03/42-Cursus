from S1E7 import Baratheon, Lannister


class King(Baratheon, Lannister):
    """Represents a King who is a member of both \
the Baratheon and Lannister families.

    Args:
        Baratheon (class): The Baratheon family class.
        Lannister (class): The Lannister family class.
    """
    def set_eyes(self, eyes):
        """Sets the eye color of the King.

        Args:
            eyes (str): The eye color to set.
        """
        self.eyes = eyes

    def set_hairs(self, hairs):
        """Sets the hair color of the King.

        Args:
            hairs (str): The hair color to set.
        """
        self.hairs = hairs

    def get_eyes(self):
        """Gets the eye color of the King.

        Returns:
            str: The eye color of the King.
        """
        return self.eyes

    def get_hairs(self):
        """Gets the hair color of the King.

        Returns:
            str: The hair color of the King.
        """
        return self.hairs
