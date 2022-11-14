#include "ex1_q1.h"

int main(int agrc, char* argv[]) {
    int num_stud = 0;
    FILE* output_file = NULL;
    char* input_file_name;

    output_file = open_output_file(argv[1]);

    for (int i = 2; i < agrc; i++) {
        input_file_name = argv[i];
        num_stud = read_data_from_file(input_file_name, output_file, num_stud);
    }

    fclose(output_file);
    report_data_summary(num_stud);
}
FILE* open_output_file(char* open_mode) {
    FILE* output_file = NULL;

    if (strcmp(open_mode, "-t") == 0) {
        output_file = fopen(GRADES_FILE, "w");
        fseek(output_file, 0, SEEK_SET);
    }
    else if (strcmp(open_mode, "-a") == 0) {
        output_file = fopen(GRADES_FILE, "a");
    }

    return output_file;
}

int read_data_from_file(char* fille_name, FILE* output_file,int num_stud) {
    FILE* file = fopen(fille_name, "r");
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        get_student_average(line, output_file);
        num_stud++;
    }

    fclose(file);

    return num_stud;
}
void get_student_average(char* line, FILE* output_file) {
    int sum_of_grades = 0, counter = 0, grade = 0;
    char* token = strtok(line, " ");
    char* student_name = token;
    double avg=0.0;

    while (token != NULL) {
        token = strtok(NULL, " ");
        if (token != NULL) {
            counter++;
            sscanf(token, "%d", &grade);
            sum_of_grades += grade;
        }
    }

    avg = (double)sum_of_grades / (counter);
    fprintf(output_file, "%s", student_name);
    fprintf(output_file," %.1f\n", avg);
}
void report_data_summary(int num_stud) {
    fprintf(stderr, "grade calculation for %d students is done\n", num_stud);
}


