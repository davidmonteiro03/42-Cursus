import random
import string
from dataclasses import dataclass, field


def generate_id() -> str:
    """
    Generate a random 15-character string consisting of lowercase letters.

    Returns:
        str: A random 15-character string.
    """
    return "".join(random.choices(string.ascii_lowercase, k=15))


@dataclass
class Student:
    """
    A class to represent a student.

    Attributes:
        name (str): The first name of the student.
        surname (str): The surname of the student.
        active (bool): The active status of the student.
        login (str): The login name of the student.
        id (str): The unique ID of the student.
    """
    name: field
    surname: field
    active: field
    login: field
    id: field

    def __init__(self, name, surname, active=True):
        """
        Initialize a new student with a name, surname, and active status.

        Args:
            name (str): The first name of the student.
            surname (str): The surname of the student.
            active (bool, optional): The active status of the student. \
Defaults to True.
        """
        self.name = name
        self.surname = surname
        self.active = active
        self.login = self.name[0] + self.surname
        self.id = generate_id()
