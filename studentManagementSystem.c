#include <stdio.h>

#define MAX_STUDENTS 100
#define SUBJECTS 3

// Function declarations
void addStudent(
    int rollNumbers[],
    char names[][50],
    float marks[][SUBJECTS],
    int *count
);

void viewStudents(
    int rollNumbers[],
    char names[][50],
    float marks[][SUBJECTS],
    int count
);

void searchStudent(
    int rollNumbers[],
    char names[][50],
    float marks[][SUBJECTS],
    int count
);

void calculateAverage(
    float marks[][SUBJECTS],
    int count
);

int main() {
    int rollNumbers[MAX_STUDENTS];
    char names[MAX_STUDENTS][50];
    float marks[MAX_STUDENTS][SUBJECTS];

    int count = 0;
    int choice;

    do {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student\n");
        printf("4. Calculate Average Marks\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                addStudent(
                    rollNumbers, names, marks, &count
                );
                break;

            case 2:
                viewStudents(
                    rollNumbers, names, marks, count
                );
                break;

            case 3:
                searchStudent(
                    rollNumbers, names, marks, count
                );
                break;

            case 4:
                calculateAverage(marks, count);
                break;

            case 5:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}

// Add a new student
void addStudent(
    int rollNumbers[],
    char names[][50],
    float marks[][SUBJECTS],
    int *count
) {
    if (*count >= MAX_STUDENTS) {
        printf("Student limit reached!\n");
        return;
    }

    printf("Enter roll number: ");
    if (scanf("%d", &rollNumbers[*count]) != 1) {
        printf("Invalid roll number.\n");
        return;
    }

    // Check for duplicate roll number
    for (int i = 0; i < *count; i++) {
        if (rollNumbers[i] == rollNumbers[*count]) {
            printf("Roll number already exists!\n");
            return;
        }
    }

    printf("Enter student name (one word): ");
    if (scanf("%49s", names[*count]) != 1) {
        printf("Invalid name.\n");
        return;
    }

    for (int j = 0; j < SUBJECTS; j++) {
        printf("Enter marks for subject %d (0-100): ", j + 1);

        if (scanf("%f", &marks[*count][j]) != 1 ||
            marks[*count][j] < 0 ||
            marks[*count][j] > 100) {
            printf("Invalid marks. Student not added.\n");
            return;
        }
    }

    (*count)++;

    printf("Student added successfully!\n");
}

// Display all students
void viewStudents(
    int rollNumbers[],
    char names[][50],
    float marks[][SUBJECTS],
    int count
) {
    if (count == 0) {
        printf("No students found.\n");
        return;
    }

    printf("\n--- All Students ---\n");

    for (int i = 0; i < count; i++) {
        printf("\nRoll Number: %d\n", rollNumbers[i]);
        printf("Name: %s\n", names[i]);

        for (int j = 0; j < SUBJECTS; j++) {
            printf("Subject %d Marks: %.2f\n",
                   j + 1, marks[i][j]);
        }
    }
}

// Search student using roll number
void searchStudent(
    int rollNumbers[],
    char names[][50],
    float marks[][SUBJECTS],
    int count
) {
    int roll;
    int found = 0;

    printf("Enter roll number to search: ");

    if (scanf("%d", &roll) != 1) {
        printf("Invalid roll number.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (rollNumbers[i] == roll) {
            printf("\nStudent Found!\n");
            printf("Roll Number: %d\n", rollNumbers[i]);
            printf("Name: %s\n", names[i]);

            for (int j = 0; j < SUBJECTS; j++) {
                printf("Subject %d Marks: %.2f\n",
                       j + 1, marks[i][j]);
            }

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

// Calculate average marks for each student
void calculateAverage(
    float marks[][SUBJECTS],
    int count
) {
    if (count == 0) {
        printf("No students available.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        float total = 0;

        for (int j = 0; j < SUBJECTS; j++) {
            total += marks[i][j];
        }

        printf("Student %d Average: %.2f\n",
               i + 1, total / SUBJECTS);
    }
}