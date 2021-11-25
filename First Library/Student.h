#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>

void nl(int n);

void instruction();

void inputInfo(struct student *&stu, int &n, int &typed);

void checkInfo(struct student *&stu, int n, int &typed);

void sort(struct student *&stu, int n, int &typed);

void classify(struct student *&stu, int n, int &typed);

void exportFile(struct student *&stu, int n, int &typed, FILE *&fptr);

void appendData(struct student *&stu, int n, int &typed, FILE *&fptr);


#endif