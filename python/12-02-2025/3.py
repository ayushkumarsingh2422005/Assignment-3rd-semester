class Vector:
    def __init__(self, x, y):
        """Initialize Vector with x and y coordinates"""
        self.x = x
        self.y = y
    
    def __add__(self, other):
        """Overload the + operator to add two Vector objects"""
        if isinstance(other, Vector):
            return Vector(self.x + other.x, self.y + other.y)
        else:
            raise TypeError("Unsupported operand type. Both operands must be Vector objects")
    
    def __str__(self):
        """Return string representation of the Vector"""
        return f"({self.x}, {self.y})"


# Demonstrate vector addition
def main():
    # Create two vector objects
    v1 = Vector(2, 3)
    v2 = Vector(3, 4)
    
    # Add the vectors using the overloaded + operator
    v3 = v1 + v2
    
    # Print the vectors and their sum
    print(f"Vector 1: {v1}")
    print(f"Vector 2: {v2}")
    print(f"Sum of vectors: {v3}")


if __name__ == "__main__":
    main()
