students = {
    "Student1": {"Maths": 85, "Science": 92, "English": 87},
    "Student2": {"Maths": 90, "Science": 88, "English": 95},
    "Student3": {"Maths": 78, "Science": 95, "English": 80},
    "Student4": {"Maths": 82, "Science": 95, "English": 80}
}

def avgSubjectWise(students):
    subject_averages = {}
    for student, marks in students.items():
        for subject, individual_marks in marks.items():
            subject_averages[subject] = subject_averages[subject]+individual_marks if subject in subject_averages.keys() else individual_marks
    for subject, total_marks in subject_averages.items():
        subject_averages[subject] = total_marks / len(students)
    return subject_averages

print(avgSubjectWise(students))