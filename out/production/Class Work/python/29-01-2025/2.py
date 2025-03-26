def gpaToGrade(gpa):
    if gpa >= 4.0:
        return "A+"
    elif 3.7 <= gpa < 4.0:
        return "A"
    elif 3.4 <= gpa < 3.7:
        return "A-"
    elif 3.0 <= gpa < 3.4:
        return "B+"
    elif 2.7 <= gpa < 3.0:
        return "B"
    elif 2.4 <= gpa < 2.7:
        return "B-"
    elif 2.0 <= gpa < 2.4:
        return "C+"
    elif 1.7 <= gpa < 2.0:
        return "C"
    elif 1.4 <= gpa < 1.7:
        return "C-"
    else:
        return "F"


gpa = [5.0, 4.7, 3.4, 3.0, 2.7, 2.4, 2.0, 1.7, 1.4, 0.0]
grade = list(map(lambda x: gpaToGrade(x), gpa))
print(grade)