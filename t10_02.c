// NIM - Name
// NIM - Name

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_DORMS 100

// Structure definitions
typedef struct {
    char id[20];
    char name[50];
    int year;
    char gender[10];
    char dorm_name[50];
} Student;

typedef struct {
    char name[50];
    int capacity;
    char gender[10];
    int resident_count;
} Dorm;

// Global variables
Student students[MAX_STUDENTS];
int student_count = 0;

Dorm dorms[MAX_DORMS];
int dorm_count = 0;

// Function prototypes
void store_student_data();
void store_dorm_data();

// Main function
int main() {
    // Example input
    strcpy(students[0].id, "12S21007");
    strcpy(students[0].name, "Dame Sitinjak");
    students[0].year = 2021;
    strcpy(students[0].gender, "female");
    strcpy(students[0].dorm_name, "unassigned");
    student_count = 1;

    strcpy(students[1].id, "12S21008");
    strcpy(students[1].name, "Tuani Manurung");
    students[1].year = 2021;
    strcpy(students[1].gender, "male");
    strcpy(students[1].dorm_name, "unassigned");
    student_count = 2;

    // Example output
    store_student_data();
    store_dorm_data();

    return 0;
}

// Function definitions

void store_student_data() {
    FILE *file = fopen("./storage/student-repository.txt", "w");
    if (file == NULL) {
        printf("Error opening student repository file for writing.\n");
        exit(1);
    }

    for (int i = 0; i < student_count; i++) {
        fprintf(file, "%s|%s|%d|%s|%s\n", students[i].id, students[i].name, students[i].year, students[i].gender, students[i].dorm_name);
    }

    fclose(file);
}

void store_dorm_data() {
    FILE *file = fopen("./storage/dorm-repository.txt", "w");
    if (file == NULL) {
        printf("Error opening dormitory repository file for writing.\n");
        exit(1);
    }

    for (int i = 0; i < dorm_count; i++) {
        fprintf(file, "%s|%d|%s|%d\n", dorms[i].name, dorms[i].capacity, dorms[i].gender, dorms[i].resident_count);
    }

    fclose(file);
}

