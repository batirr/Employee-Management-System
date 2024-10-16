Project Title: Employee Management System using Linked Lists
This C program is designed as a simple Employee Management System, built using linked lists. It lets users perform key operations such as adding, deleting, searching, and displaying employee details. At the start of the program, the head variable is set to NULL, marking the beginning of our linked list.

The main function serves as a menu for the user, guiding them through the various actions available. Depending on the user's selection, the program jumps to the corresponding function to handle the requested task.

Adding an Employee
When a user chooses to add a new employee, the addEmployee function comes into play. This function creates a new Employee structure and prompts the user to enter the required details. Before adding this new entry to the list, it calls the checkDuplicate function to ensure there isn't already an employee with the same name. If a duplicate is detected, the process is halted, and the memory allocated for the new employee is properly freed to avoid leaks. If no duplicate is found, the new employee is added to the linked list, and the head is updated.

Deleting an Employee
To delete an employee, the deleteEmployee function is used. The program asks the user to specify the name of the employee they wish to remove. It then scans the linked list for the matching entry, and if the employee is found, removes them from the list while freeing up the allocated memory.

Searching for an Employee
The searchEmployee function helps in locating a specific employee. Once the user provides the employee's name, the program traverses the linked list, and if the employee is present, their details are displayed on the screen.

Displaying All Employees
For displaying the full list of employees, the displayEmployees function is called. It goes through the linked list and prints out the details of each employee.

Duplicate Check
The checkDuplicate function plays a crucial role in maintaining data integrity by checking if an employee with the same name already exists in the list. If a duplicate is found, it returns 1; otherwise, it returns 0.

Freeing Memory
The freeMemory function is used to ensure that all memory allocated for the employees is properly released, preventing any memory leaks.

Input Validation
The validateInput function can be called when needed to make sure that the data provided by the user is valid and meets the expected criteria.

Program Termination
When the user decides to exit the program, all memory allocated to the employees in the linked list is released, allowing the program to close cleanly and efficiently.

This system provides a straightforward way to manage employee data using the dynamic capabilities of linked lists, making it easy to add or remove entries without having to restructure the entire dataset.
