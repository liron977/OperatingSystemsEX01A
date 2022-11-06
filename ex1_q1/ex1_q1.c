#include "ex1_q1.h"
#define GRADES_FILE "all_std.txt"

int read_data_from_file(char* fille_name, FILE* output_file,int num_stud) {
    FILE* file = fopen(fille_name, "r");
    char line[80];
    while (fgets(line, sizeof(line), file)) {
        get_average_for_student(line, output_file);
        num_stud++;
    }
    fclose(file);
    return num_stud;
}
void get_average_for_student(char* line, FILE* output_file) {
    int sum_of_grades = 0;
    char* token = strtok(line, " ");
    int index = 0;
    char* student_name = token;
    int grade = 0;
    while (token != NULL) {
        token = strtok(NULL, " ");
        if (token != NULL) {
            index++;
            sscanf(token, "%d", &grade);
            sum_of_grades += grade;
        }
    }
    double avg = (double)sum_of_grades / (index);
    fprintf(output_file, "%s", student_name);
    fprintf(output_file," %.2f\n", avg);
}
int main(int agrc, char *argv[]) {
    int num_stud = 0;
    FILE* output_file = NULL;
    char* input_file_name;
    if (strcmp(argv[1], "-t") == 0) {
        output_file = fopen(GRADES_FILE, "w");
           fseek(output_file, 0, SEEK_SET);
    }
    else  if (strcmp(argv[1], "-a") == 0) {
        output_file = fopen(GRADES_FILE, "a");
    }
    for (int i = 2; i < agrc; i++) {
        input_file_name = argv[i];
        num_stud= read_data_from_file(input_file_name, output_file, num_stud);
    }
   fclose(output_file);
   report_data_summary(num_stud);
}
void report_data_summary(int num_stud) {
    fprintf(stderr, "grade calculation for %d students is done\n",num_stud);
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
