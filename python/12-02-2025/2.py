from abc import ABC, abstractmethod
import math

class Shape(ABC):
    @abstractmethod
    def area(self):
        """Calculate the area of the shape"""
        pass

class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius
    
    def area(self):
        return math.pi * self.radius ** 2

class Rectangle(Shape):
    def __init__(self, length, width):
        self.length = length
        self.width = width
    
    def area(self):
        return self.length * self.width

# Create instances and calculate areas
def main():
    # Create a circle with radius 5
    circle = Circle(5)
    print(f"Circle area: {circle.area():.2f}")
    
    # Create a rectangle with length 4 and width 6
    rectangle = Rectangle(4, 6)
    print(f"Rectangle area: {rectangle.area()}")

if __name__ == "__main__":
    main()
