# Chirality Detector (Inheritance & Abstract Class)
# Define an abstract class Molecule with a method is_chiral(). Implement subclasses:
# ● Alkane (single bonds)
# ● Alcohol (OH group)
# Each subclass should check if the molecule has a chiral center by analyzing the bonding
# structure.

from abc import ABC, abstractmethod

class Molecule(ABC):
    @abstractmethod
    def is_chiral(self):
        pass

class Alkane(Molecule):
    def __init__(self, bonds):
        self.bonds = bonds
    
    def is_chiral(self):
        return False
    
class Alcohol(Molecule):
    def __init__(self, bonds):
        self.bonds = bonds
    
    def is_chiral(self):
        return False
    




