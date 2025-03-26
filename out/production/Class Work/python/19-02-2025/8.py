from abc import ABC, abstractmethod
import sympy as sp

class InverseTrigonometrySolver(ABC):
    @abstractmethod
    def solve_equation(self, equation):
        pass

class ArcSinSolver(InverseTrigonometrySolver):
    def solve_equation(self, equation):
        x = sp.Symbol('x')
        equation = sp.sympify(equation)
        solutions = sp.solve(equation, x)
        return solutions

class ArcTanSolver(InverseTrigonometrySolver):
    def solve_equation(self, equation):
        x = sp.Symbol('x')
        equation = sp.sympify(equation)
        solutions = sp.solve(equation, x)
        return solutions

if __name__ == "__main__":
    user_equation = input("Enter an inverse trigonometric equation: ")
    
    if 'asin' in user_equation or 'acos' in user_equation:
        solver = ArcSinSolver()
    elif 'atan' in user_equation:
        solver = ArcTanSolver()
    else:
        print("Unsupported equation type.")
        exit()
    
    print(f"Solution for {user_equation} = 0:", solver.solve_equation(user_equation))
