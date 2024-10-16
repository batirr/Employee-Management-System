//Rabia Batýr 040190076

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for employee information
struct Employee {
    char name[50];
    int employee_id;
    char position[50];
    float salary;
    struct Employee* next;
};

// Global variable for the head of the linked list
struct Employee* head = NULL;

// Function declarations
void addEmployee();
void deleteEmployee();
void searchEmployee();
void displayEmployees();
int checkDuplicate(const char* name);
void freeMemory(struct Employee* node);
int validateInput(const char* input);

// Function to add a new employee to the linked list
// malloc function is used in C to dynamically allocate memory
void addEmployee() {
    struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee)); 

    if (newEmployee == NULL) {
        fprintf(stderr, "Memory allocation failed. Exiting.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter employee name: ");
    scanf("%s", newEmployee->name);

    // Check for duplicates
    if (checkDuplicate(newEmployee->name)) {
        fprintf(stderr, "Employee with the same name already exists. Try again.\n");
        free(newEmployee);
        return;
    }

    printf("Enter employee ID: ");
    scanf("%d", &newEmployee->employee_id);

    printf("Enter employee position: ");
    scanf("%s", newEmployee->position);

    printf("Enter employee salary: ");
    scanf("%f", &newEmployee->salary);
	// After the new employee's information is received from the user, this information is saved in the new employee's struct.
    // Then this new employee is added to the linked list
    newEmployee->next = head;
    head = newEmployee;

    printf("Employee added successfully.\n");
}

// Function to delete an employee from the linked list
void deleteEmployee() {
    char targetName[50];
    printf("Enter the name of the employee to delete: ");
    scanf("%s", targetName);

    struct Employee* current = head;
    struct Employee* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, targetName) == 0) { 
		// With strcmp, the name of the currently processed employee (current->name) and the target name (targetName) are compared.
            // Employee found
            if (prev == NULL) {
                // Deleting the head node
                head = current->next;
            } else {
                prev->next = current->next;
            }
			// free function
            freeMemory(current);
            printf("Employee deleted successfully.\n");
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Employee not found.\n");
}

// Function to search for an employee in the linked list
void searchEmployee() {
    char targetName[50];
    printf("Enter the name of the employee to search: ");
    scanf("%s", targetName);

    struct Employee* current = head;

    while (current != NULL) {
        if (strcmp(current->name, targetName) == 0) {
            // Employee found
            printf("Employee Information:\n");
            printf("Name: %s\n", current->name);
            printf("Employee ID: %d\n", current->employee_id);
            printf("Position: %s\n", current->position);
            printf("Salary: %.2f\n", current->salary);
            return;
        }

        current = current->next;
    }

    printf("Employee not found.\n");
}

// Function to display all employees in the linked list
void displayEmployees() {
    struct Employee* current = head;

    while (current != NULL) {
        printf("Name: %s | ID: %d | Position: %s | Salary: %.2f\n",
               current->name, current->employee_id, current->position, current->salary);

        current = current->next;
    }
}

// Function to check for duplicate entries
int checkDuplicate(const char* name) {
    struct Employee* current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            // Duplicate found
            return 1;
        }

        current = current->next;
    }

    return 0;
}

// Function to deallocate memory when deleting an employee
void freeMemory(struct Employee* node) {
    free(node);
}

// Function for input validation
int validateInput(const char* input) {
    // Implement input validation as needed
    // Return 1 for valid input, 0 for invalid input
    return 1;
}

int main() {
	// Main function creates the menu
    int choice;

    do {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Delete Employee\n");
        printf("3. Search Employee\n");
        printf("4. Display Employees\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                displayEmployees();
                break;
            case 5:
                // Free all allocated memory before exiting
                while (head != NULL) {
                    struct Employee* temp = head;
                    head = head->next;
                    freeMemory(temp);
                }
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

