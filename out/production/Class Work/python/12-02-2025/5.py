class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

class Employee(Person):
    def __init__(self, name, age, salary):
        super().__init__(self, name, age)
        self.salary = salary
        
class Student(Person):
    def __init__(self, name, age, grade):
        super().__init__(name, age)
        self.grade = grade
        
class Intern(Employee, Student):
    def __init__(self, name, age, salary, grade):
        Employee.__init__(self, name, age, salary)
        Student.__init__(self, name, age, grade)

# person = Person("John", 25)
# employee = Employee("Jane", 30, 50000)
# student = Student("Jim", 20, "A")
intern = Intern("Jill", 22, 30000, "B")

# print("\nPerson:", person.name, person.age)
# print("Employee:", employee.name, employee.age, employee.salary)
# print("Student:", student.name, student.age, student.grade)
print("Intern:", intern.name, intern.age, intern.salary, intern.grade)

# Print the Method Resolution Order (MRO) for Intern class
print("\nMethod Resolution Order for Intern class:")
print(Intern.__mro__)