#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRADES_FILE "all_std.txt"
#define MAX_LINE_LENGTH 80

int read_data_from_file(char* fille_name, FILE* output_file, int num_stud);
void get_student_average(char* line, FILE* output_file);
void report_data_summary(int num_stud);
FILE* open_output_file(char* open_mode);