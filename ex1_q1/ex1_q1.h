#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int read_data_from_file(char* fille_name, FILE* output_file, int num_stud);
void get_average_for_student(char* line, FILE* output_file);
void report_data_summary(int num_stud);