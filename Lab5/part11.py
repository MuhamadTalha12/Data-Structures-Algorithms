def search_student(class_list, student_name):
    is_found = False
    for z in range(len(class_list)):
        if class_list[z] == student_name:
            is_found = True
            print(f'{student_name} found in class list at index {z}')
    if not is_found:
        print('No such student found in list.')

# Driver
class_list = ['John', 'Leo', 'Salman', 'Uzair', 'Charlie', 'Talha', 'Evil']
search_student(class_list, 'Salman')
search_student(class_list, 'Talha')