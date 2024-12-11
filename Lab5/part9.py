def add_student(class_list, student_name):
    class_list.append(student_name)
    print(f"{student_name} is added to the class.")

def remove_student(class_list, student_name):
    if student_name in class_list:
        class_list.remove(student_name)
        print(f"{student_name} is removed from the class.")
    else:
        print(f"{student_name} is not in the class list.")

def display_students(class_list):
    if class_list:
        print("List of students in the class:")
        for student in class_list:
            print(student)
    else:
        print("No students in the class yet.")

# Driver
class_list = []
add_student(class_list, "Talha")
add_student(class_list, "Salman")
add_student(class_list, "Alee")
display_students(class_list)
remove_student(class_list, "Talha")
display_students(class_list)