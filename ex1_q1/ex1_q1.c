#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void readDataFromFile(char* filleName, FILE* outputFile);
void getAverageForStudent(char* line, FILE* outputFile);

void readDataFromFile(char* filleName, FILE* outputFile) {
    FILE* file = fopen(filleName, "r");
    char line[80];
    while (fgets(line, sizeof(line), file)) {
        getAverageForStudent(line,outputFile);
    }
    fclose(file);
}
void getAverageForStudent(char* line, FILE* outputFile) {
    int sumOfGrades = 0;
    char* token = strtok(line, " ");
    int index = 0;
    char* studentName = token;
    int grade = 0;
    while (token != NULL) {
        token = strtok(NULL, " ");
        if (token != NULL) {
            index++;
            sscanf(token, "%d", &grade);
            sumOfGrades += grade;
        }
    }
    double avg = (double)sumOfGrades / (index);
    fprintf(outputFile, "%s", studentName);
    fprintf(outputFile," %.2f\n", avg);
}
int main(int agrc, char *argv[]) {
    FILE* outputFile = NULL;
    char* inputFileName;
    if (strcmp(argv[1], "-t") == 0) {
           outputFile = fopen("all_std.txt", "w");
           fseek(outputFile, 0, SEEK_SET);     
    }
    else  if (strcmp(argv[1], "-a") == 0) {
        outputFile = fopen("all_std.txt", "a");
    }
    for (int i = 2; i < agrc; i++) {
        inputFileName = argv[i];
       readDataFromFile(inputFileName, outputFile);
    }
   fclose(outputFile);
}
//int main() {
//    char* argv[] = {0,"-t","test1.txt","test2.txt","test3.txt" };
//    FILE* outputFile = NULL;
//    int amountOfFilles = sizeof(argv)/(sizeof(char*));
//    char* inputFileName;
//    if (strcmp(argv[1], "-t") == 0) {
//        outputFile = fopen("all_std.txt", "w");
//        fseek(outputFile, 0, SEEK_SET);
//    }
//    else  if (strcmp(argv[1], "-a") == 0) {
//        outputFile = fopen("all_std.txt", "a");
//        fseek(outputFile, 0,SEEK_END);
//    }
//    for (int i = 2; i < amountOfFilles; i++) {
//        inputFileName = argv[i];
//        readDataFromFile(inputFileName, outputFile);
//    }
//    fclose(outputFile);
//}
