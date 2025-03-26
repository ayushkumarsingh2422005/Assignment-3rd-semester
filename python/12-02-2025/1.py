class Vehical:  # Spelling error: Should be "Vehicle"
    def __init__(self, name, model, color):
        self.name = name
        self.model = model
        self.color = color

    def display(self):
        print(f"Name: {self.name}, Model: {self.model}, Color: {self.color}")

class Car(Vehical):
    def __init__(self, name, model, color, price):
        super().__init__(name, model, color)
        self.price = price

    def display(self):
        super().display()
        print(f"Price: {self.price}")

class Truck(Vehical):
    def __init__(self, name, model, color, tyres):
        super().__init__(name, model, color)
        self.tyres = tyres

    def display(self):
        super().display()
        print(f"Total number of tyres: {self.tyres}")

class Tractor(Car, Truck):
    def __init__(self, name, model, color, price, tyres):
        # Initialize the Vehicle class once
        Vehical.__init__(self, name, model, color)
        # Set specific attributes
        self.price = price
        self.tyres = tyres

    def display(self):
        # Call Vehicle's display once
        Vehical.display(self)
        # Print specific attributes
        print(f"Price: {self.price}")
        print(f"Total number of tyres: {self.tyres}")

t = Tractor("Tractor", "2025", "Red", 500000, 4)
t.display()