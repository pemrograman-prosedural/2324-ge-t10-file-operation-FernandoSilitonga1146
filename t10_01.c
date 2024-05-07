// 12S23002 - Fernando Silitonga
// 12S23002 - Andrey Jonathan

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"

#define _SIZE 255

void readDormsFromFile(Dorm **dorms, unsigned short *totalDorm);
void readStudentsFromFile(Student **students, unsigned short *totalStudent);
void processCommands(Dorm *dorms, unsigned short totalDorm, Student *students, unsigned short totalStudent);

int main(int _argc, char **_argv)
{
    Dorm *dorms = NULL;
    Student *students = NULL;
    unsigned short totalDorm = 0;
    unsigned short totalStudent = 0;

    readDormsFromFile(&dorms, &totalDorm);
    readStudentsFromFile(&students, &totalStudent);

    processCommands(dorms, totalDorm, students, totalStudent);

    // Free allocated memory
    free(dorms);
    free(students);

    return 0;
}

void readDormsFromFile(Dorm **dorms, unsigned short *totalDorm) {
    char line[_SIZE];
    char *token;
    char *delim = "#";

    FILE *reader = fopen("./storage/dorm-repository.txt", "r");
    if (reader == NULL) {
        perror("Error opening dorm file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, _SIZE, reader) != NULL) {
        line[strcspn(line, "\r\n")] = 0;
        token = strtok(line, "|");
        char *name = token;
        token = strtok(NULL, "|");
        unsigned short capacity = atoi(token);
        token = strtok(NULL, "|");
        char *gender = token;

        *dorms = (Dorm *)realloc(*dorms, (*totalDorm + 1) * sizeof(Dorm));

        if (strcmp(gender, "male") == 0)
            (*dorms)[*totalDorm] = create_dorm(name, capacity, GENDER_MALE);
        else if (strcmp(gender, "female") == 0)
            (*dorms)[*totalDorm] = create_dorm(name, capacity, GENDER_FEMALE);

        (*totalDorm)++;
    }

    fclose(reader);
}

void readStudentsFromFile(Student **students, unsigned short *totalStudent) {
    char line[_SIZE];
    char *token;
    char *delim = "#";

    FILE *reader = fopen("./storage/student-repository.txt", "r");
    if (reader == NULL) {
        perror("Error opening student file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, _SIZE, reader) != NULL) {
        line[strcspn(line, "\r\n")] = 0;
        token = strtok(line, "|");
        char *id = token;
        token = strtok(NULL, "|");
        char *name = token;
        token = strtok(NULL, "|");
        char *year = token;
        token = strtok(NULL, "|");
        char *gender = token;

        *students = (Student *)realloc(*students, (*totalStudent + 1) * sizeof(Student));

        if (strcmp(gender, "male") == 0)
            (*students)[*totalStudent] = create_student(id, name, year, GENDER_MALE);
        else if (strcmp(gender, "female") == 0)
            (*students)[*totalStudent] = create_student(id, name, year, GENDER_FEMALE);

        (*totalStudent)++;
    }

    fclose(reader);
}

void processCommands(Dorm *dorms, unsigned short totalDorm, Student *students, unsigned short totalStudent) {
    char line[_SIZE];
    char *delim = "#";

    while (1) {
        printf("Enter a command: ");
        fgets(line, _SIZE, stdin);
        line[strcspn(line, "\r\n")] = 0;

        if (strcmp(line, "---") == 0)
            break;
        else if (strcmp(line, "student-print-all") == 0) {
            for (short i = 0; i < totalStudent; i++) {
                printStudent(students[i]);
            }
        } else if (strcmp(line, "dorm-print-all") == 0) {
            for (short i = 0; i < totalDorm; i++) {
                print_dorm(dorms[i]);
            }
        } else if (strcmp(line, "student-print-all-detail") == 0) {
            for (short i = 0; i < totalStudent; i++) {
                printStudentDetails(students[i]);
            }
        } else if (strcmp(line, "dorm-print-all-detail") == 0) {
            for (short i = 0; i < totalDorm; i++) {
                printDormDetails(dorms[i]);
            }
        } else {
            char *token = strtok(line, delim);

            if (strcmp(token, "student-add") == 0) {
                // Add student
            } else if (strcmp(token, "dorm-add") == 0) {
                // Add dorm
            } else if (strcmp(token, "assign-student") == 0) {
                // Assign student
            } else if (strcmp(token, "move-student") == 0) {
                // Move student
            } else if (strcmp(token, "dorm-empty") == 0) {
                // Empty dorm
            }
        }
    }
}
