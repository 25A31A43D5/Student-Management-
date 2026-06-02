#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Student {
    int id;
    char name[50];
    float marks;
};

struct Student students[MAX];
int count = 0;

// Function Declarations
void addStudent();
void displayStudents();
void searchStudent();

int main() {
    int choice;

    while (1) {
        printf("\n========== Student Management System ==========\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                printf("Exiting Program...\n");
                exit(0);

            default:
                printf("Invalid Choice! Try Again.\n");
        }
    }

    return 0;
}

void addStudent() {
    if (count >= MAX) {
        printf("Student limit reached!\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%d", &students[count].id);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Student Marks: ");
    scanf("%f", &students[count].marks);

    count++;

    printf("Student Added Successfully!\n");
}

void displayStudents() {
    int i;

    if (count == 0) {
        printf("\nNo Student Records Found!\n");
        return;
    }

    printf("\n========== Student Records ==========\n");

    for (i = 0; i < count; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("ID    : %d\n", students[i].id);
        printf("Name  : %s\n", students[i].name);
        printf("Marks : %.2f\n", students[i].marks);
    }
}

void searchStudent() {
    int searchId, i;
    int found = 0;

    printf("\nEnter Student ID to Search: ");
    scanf("%d", &searchId);

    for (i = 0; i < count; i++) {
        if (students[i].id == searchId) {
            printf("\nStudent Found!\n");
            printf("ID    : %d\n", students[i].id);
            printf("Name  : %s\n", students[i].name);
            printf("Marks : %.2f\n", students[i].marks);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student Not Found!\n");
    }
}
