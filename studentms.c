#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for student node
struct Student {
    int id;
    char name[50];
    float marks;
    struct Student *next;
};

struct Student *head = NULL;

// Function to add a student
void addStudent(int id, char name[], float marks) {
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->marks = marks;
    newStudent->next = head;
    head = newStudent;
    printf("✅ Student added successfully!\n");
}

// Function to display all students
void displayStudents() {
    struct Student *temp = head;
    if (temp == NULL) {
        printf("No students found!\n");
        return;
    }
    printf("\n---- Student List ----\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Marks: %.2f\n", temp->id, temp->name, temp->marks);
        temp = temp->next;
    }
}

// Function to delete a student by ID
void deleteStudent(int id) {
    struct Student *temp = head, *prev = NULL;
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("❌ Student with ID %d not found!\n", id);
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("🗑️  Student deleted successfully!\n");
}

// Main function
int main() {
    int choice, id;
    char name[50];
    float marks;

    while (1) {
        printf("\n=== Student Management System ===\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Delete Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf(" %[^\n]", name);
                printf("Enter Marks: ");
                scanf("%f", &marks);
                addStudent(id, name, marks);
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteStudent(id);
                break;

            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
