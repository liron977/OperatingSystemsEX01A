#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
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
//int main(int agrc, char *argv[]) {
//    FILE* outputFile = fopen("all_std.txt", "w");
//    int amountOfFilles = sizeof(argv);
//    char* inputFileName;
//    if (strcmp(argv[1], "-t") == 0) {
//           outputFile = fopen("all_std.txt", "w");
//           resize_file("all_std.txt", 0);
//           fseek(outputFile, 0, SEEK_SET);
//    }
//    else  if (strcmp(argv[1], "-a") == 0) {
//        outputFile = fopen("all_std.txt", "a");
//    }
//    for (int i = 1; i < amountOfFilles; i++) {
//        inputFileName = argv[i];
//       readDataFromFile(inputFileName, outputFile);
//    }
//}
int main() {
    char* argv[] = {0,"-a","test1.txt"};
   
    FILE* outputFile = fopen("all_std.txt", "w");
    int amountOfFilles = sizeof(argv)/(sizeof(char*));
    char* inputFileName;
    if (strcmp(argv[1], "-t") == 0) {
        outputFile = fopen("all_std.txt", "w");
        fseek(outputFile, 0, SEEK_SET);
    }
    else  if (strcmp(argv[1], "-a") == 0) {
        outputFile = fopen("all_std.txt", "a");
    }
    for (int i = 2; i < amountOfFilles; i++) {
        inputFileName = argv[i];
        readDataFromFile(inputFileName, outputFile);
    }
    fclose(outputFile);
}
