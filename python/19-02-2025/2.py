import math


class Momentum:
    def __init__(self, mass, velocity):
        self.mass = mass
        self.velocity = velocity
    
    def momentum(self):
        return self.mass * self.velocity
    

class RelativisticMomentum(Momentum):
    __c = 3 * 10**8
    def __init__(self, mass, velocity):
        super().__init__(mass, velocity)
    
    def momentum(self):
        return self.mass * self.velocity / math.sqrt(1 - self.velocity**2 / self.__c**2)

def main():
    momentum = Momentum(10, 10)
    relativistic_momentum = RelativisticMomentum(10, 10)
    print(momentum.momentum())
    print(relativistic_momentum.momentum())

if __name__ == "__main__":
    main()

