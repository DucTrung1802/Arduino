#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "Student.h"

struct student
{
	char name[50];
	char sex[15];
	int age;
	float math, physics, chemistry;
	float average;
	char level[20];
};

void nl(int n)
{
	for (int i = 1; i <= n; i++)
	{
		printf("\n");
	}
}

void instruction()
{
	nl(1);
	for (int i = 0; i < 76; i++)
	{ //first star line
		printf("*");
	}
	nl(1);
	printf("****\t\t\tSTUDENT INFORMATION SYSTEM\t\t\t****");
	nl(1);
	printf("****\t\t1. Input information\t\t\t\t\t****");
	nl(1);
	printf("****\t\t2. Check information\t\t\t\t\t****");
	nl(1);
	printf("****\t\t3. Sort in descending order of avarage mark\t\t****");
	nl(1);
	printf("****\t\t4. Classify student\t\t\t\t\t****");
	nl(1);
	printf("****\t\t5. Export to new text file\t\t\t\t****");
	nl(1);
	printf("****\t\t6. Append data to existed text file\t\t\t****");
	nl(1);
	printf("****\t\t0. Exit program\t\t\t\t\t\t****");
	nl(1);
	printf("****\t\t\t\t\t\t\t\t\t****");
	nl(1);
	for (int i = 0; i < 76; i++)
	{ //last star line
		printf("*");
	}
}

void inputInfo(struct student *&stu, int &n, int &typed)
{
	printf("\nYou chose: INPUT INFORMATION");
	do
	{
		printf("\nEnter the numbers of students: ");
		scanf("%d", &n);
	} while (n < 1);
	stu = (struct student *)calloc(n, sizeof(struct student));

	for (int i = 0; i < n; i++)
	{
		printf("\n**** Student %d ****", i + 1); //NAME
		printf("\nNAME: ");
		fflush(stdin);
		fgets((stu + i)->name, sizeof((stu + i)->name), stdin);
		fflush(stdin);

		do
		{ //SEX
			printf("SEX (Male/Female/Different), only the first character of the choice: ");
			scanf("%s", &(stu + i)->sex);
		} while (!(strcmp((stu + i)->sex, "M") == 0 || strcmp((stu + i)->sex, "F") == 0 || strcmp((stu + i)->sex, "D") == 0 || strcmp((stu + i)->sex, "m") == 0 || strcmp((stu + i)->sex, "f") == 0 || strcmp((stu + i)->sex, "d") == 0));

		do
		{ //AGE
			printf("AGE: ");
			scanf("%d", &(stu + i)->age);
		} while ((stu + i)->age > 100 || (stu + i)->age < 1);

		do
		{ // MATH SCORE
			printf("MATHEMATICS score: ");
			scanf("%f", &(stu + i)->math);
		} while (!((stu + i)->math == -1 || ((stu + i)->math >= 0 && (stu + i)->math <= 10)));

		do
		{ // PHYSICS SCORE
			printf("PHYSICS score: ");
			scanf("%f", &(stu + i)->physics);
		} while (!((stu + i)->physics == -1 || ((stu + i)->physics >= 0 && (stu + i)->physics <= 10)));

		do
		{ // CHEMISTRY SCORE
			printf("CHEMISTRY score: ");
			scanf("%f", &(stu + i)->chemistry);
		} while (!((stu + i)->chemistry == -1 || ((stu + i)->chemistry >= 0 && (stu + i)->chemistry <= 10)));

		printf("*******************");
		nl(1);
	}

	typed = true;
	printf("\nINPUT INFORMATION COMPLETE!");
	printf("\n\nPress any key to continue...");
	getch();

	typed = 2;
}

void checkInfo(struct student *&stu, int n, int &typed)
{
	if (typed < 2)
	{
		printf("\nYou must (Input information) first!");
		printf("\n\nPress any key to continue...");
		getch();
		return;
	}

	printf("\nYou chose: CHECK INFORMAITON");

	for (int i = 0; i < n; i++)
	{
		printf("\n\n**** Student %d ****", i + 1);

		printf("\nNAME: "); //NAME
		puts((stu + i)->name);

		if (strcmp((stu + i)->sex, "M") == 0 || strcmp((stu + i)->sex, "m") == 0 || strcmp((stu + i)->sex, "MALE") == 0)
		{
			strcpy((stu + i)->sex, "MALE");
		}
		else if (strcmp((stu + i)->sex, "F") == 0 || strcmp((stu + i)->sex, "f") == 0 || strcmp((stu + i)->sex, "FEMALE") == 0)
		{
			strcpy((stu + i)->sex, "FEMALE");
		}
		else
		{
			strcpy((stu + i)->sex, "DIFFERENT");
		}

		printf("SEX: %s\t\tAGE: %d", (stu + i)->sex, (stu + i)->age);

		printf("\n\nSCORES: ");

		if ((stu + i)->math == -1)
		{ //MATH
			printf("\nMATHEMATICS SCORE: ABSENT");
		}
		else
		{
			printf("\nMATHEMATICS SCORE: %.2f", (stu + i)->math);
		}

		if ((stu + i)->physics == -1)
		{ //PHYSICS
			printf("\nPHYSICS SCORE: ABSENT");
		}
		else
		{
			printf("\nPHYSICS SCORE: %.2f", (stu + i)->physics);
		}

		if ((stu + i)->chemistry == -1)
		{ //CHEMISTRY
			printf("\nCHEMISTRY SCORE: ABSENT");
		}
		else
		{
			printf("\nCHEMISTRY SCORE: %.2f", (stu + i)->chemistry);
		}

		printf("\n*******************");
		nl(1);
	}

	printf("\nCHECK INFORMATION COMPLETE!");
	printf("\n\nPress any key to continue...");
	getch();

	typed = 3;
}

void sort(struct student *&stu, int n, int &typed)
{
	struct student *temp;

	if (typed < 3)
	{
		printf("\nYou must (Check information) first!");
		printf("\n\nPress any key to continue...");
		getch();
		return;
	}

	printf("\nYou chose: SORT IN DESCENDING ORDER OF AVARAGE MARK");

	temp = (struct student *)malloc(sizeof(student));

	for (int i = 0; i < n; i++)
	{
		(stu + i)->average = ((stu + i)->math + (stu + i)->physics + (stu + i)->chemistry) / 3;
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int k = i + 1; k < n; k++)
		{
			if ((stu + i)->average < (stu + k)->average)
			{
				memcpy(temp, (stu + i), sizeof(student));
				memcpy((stu + i), (stu + k), sizeof(student));
				memcpy((stu + k), temp, sizeof(student));
			}
		}
	}

	for (int j = 0; j < n; j++)
	{
		printf("\n\n\n**** RANK %d ****", j + 1);
		printf("\nNAME: ");
		puts((stu + j)->name);
		if ((stu + j)->average == -1)
		{
			printf("\nAVERAGE SCORE: ABSENT ALL");
		}
		else
		{
			printf("AVERAGE SCORE: %.2f", (stu + j)->average);
			printf("\n*****************");
		}
	}

	printf("\n\nSORT INFORMATION COMPLETE!");
	printf("\n\nPress any key to continue...");
	getch();

	typed = 4;
}

void classify(struct student *&stu, int n, int &typed)
{
	if (typed < 4)
	{
		printf("\nYou must (Sort in descending order of avarage mark) first!");
		printf("\n\nPress any key to continue...");
		getch();
		return;
	}

	printf("\nYou chose: CLASSIFY STUDENT");

	for (int i = 0; i < n; i++)
	{
		(stu + i)->average = ((stu + i)->math + (stu + i)->physics + (stu + i)->chemistry) / 3;
	}

	for (int i = 0; i < n; i++)
	{
		printf("\n\n**** Student %d ****", i + 1);

		printf("\nNAME: "); //NAME
		puts((stu + i)->name);

		printf("SCORES: ");

		if ((stu + i)->math == -1)
		{ //MATH
			printf("\nMATHEMATICS SCORE: ABSENT");
		}
		else
		{
			printf("\nMATHEMATICS SCORE: %.2f", (stu + i)->math);
		}

		if ((stu + i)->physics == -1)
		{ //PHYSICS
			printf("\nPHYSICS SCORE: ABSENT");
		}
		else
		{
			printf("\nPHYSICS SCORE: %.2f", (stu + i)->physics);
		}

		if ((stu + i)->chemistry == -1)
		{ //CHEMISTRY
			printf("\nCHEMISTRY SCORE: ABSENT");
		}
		else
		{
			printf("\nCHEMISTRY SCORE: %.2f", (stu + i)->chemistry);
		}

		printf("\n\nAVERAGE SCORE: %.2f", (stu + i)->average); //AVERAGE

		if ((stu + i)->average >= 9.5 && (stu + i)->average <= 10)
		{
			strcpy((stu + i)->level, "EXCELLENT");
		}
		else if ((stu + i)->average >= 8.5 && (stu + i)->average < 9.5)
		{
			strcpy((stu + i)->level, "VERY GOOD");
		}
		else if ((stu + i)->average >= 7 && (stu + i)->average < 8.4)
		{
			strcpy((stu + i)->level, "GOOD");
		}
		else if ((stu + i)->average >= 5.5 && (stu + i)->average < 7)
		{
			strcpy((stu + i)->level, "AVERAGE");
		}
		else if ((stu + i)->average >= 4 && (stu + i)->average < 5.5)
		{
			strcpy((stu + i)->level, "BELOW AVERAGE");
		}
		else
		{
			strcpy((stu + i)->level, "FAIL");
		}

		printf("\nDEGREE CLASSIFICATION: ");
		puts((stu + i)->level);
		printf("\n*****************");
	}

	printf("\n\nCLASSIFY INFORMATION COMPLETE!");
	printf("\n\nPress any key to continue...");
	getch();

	typed = 5;
}

void exportFile(struct student *&stu, int n, int &typed, FILE *&fptr)
{
	if (typed < 5)
	{
		printf("\nYou must (Classify student) first!");
		printf("\n\nPress any key to continue...");
		getch();
		return;
	}

	printf("\nYou chose: EXPORT TO TEXT FILE");
	printf("\nEnter the name of file: ");
	char name_file[255];
	scanf("%s", &name_file);

	fptr = fopen(name_file, "w");

	if (fptr == NULL)
	{
		printf("\nOCCURED ERROR WHILE OPENING FILE!");
		exit(1);
	}

	for (int i = 0; i < n; i++)
	{
		fprintf(fptr, "**** Student %d ****", i + 1);

		fprintf(fptr, "\nNAME: "); //NAME
		fprintf(fptr, "%s", (stu + i)->name);

		fprintf(fptr, "SEX: %s\t\tAGE: %d", (stu + i)->sex, (stu + i)->age); //SEX + AGE

		fprintf(fptr, "\n\nSCORES: ");

		if ((stu + i)->math == -1)
		{ //MATH
			fprintf(fptr, "\nMATHEMATICS SCORE: ABSENT");
		}
		else
		{
			fprintf(fptr, "\nMATHEMATICS SCORE: %.2f", (stu + i)->math);
		}

		if ((stu + i)->physics == -1)
		{ //PHYSICS
			fprintf(fptr, "\nPHYSICS SCORE: ABSENT");
		}
		else
		{
			fprintf(fptr, "\nPHYSICS SCORE: %.2f", (stu + i)->physics);
		}

		if ((stu + i)->chemistry == -1)
		{ //CHEMISTRY
			fprintf(fptr, "\nCHEMISTRY SCORE: ABSENT");
		}
		else
		{
			fprintf(fptr, "\nCHEMISTRY SCORE: %.2f", (stu + i)->chemistry);
		}

		fprintf(fptr, "\nAVERAGE SCORE: %.2f", (stu + i)->average);
		fprintf(fptr, "\nDEGREE CLASSIFICATION: ");
		fputs((stu + i)->level, fptr);

		fprintf(fptr, "\n*******************\n\n\n");
		nl(1);
	}

	fclose(fptr);

	printf("\nEXPORT SUCCESSFULLY TO \"%s\"", name_file);
}

void appendData(struct student *&stu, int n, int &typed, FILE *&fptr)
{
	if (typed < 5)
	{
		printf("\nYou must (Classify student) first!");
		printf("\n\nPress any key to continue...");
		getch();
		return;
	}

	printf("\nYou chose: APPEND DATA TO EXISTED TEXT FILE");

	printf("\nEnter the file name: ");
	char name_file[255];
	scanf("%s", &name_file);

	fptr = fopen(name_file, "r");

	int row = 0;
	char buff[500];
	while (fgets(buff, 500, fptr))
	{
		row = row + 1;
	}

	fclose(fptr);

	fptr = fopen(name_file, "a");

	if (fptr == NULL)
	{
		printf("\nOCCURED ERROR WHILE OPENING FILE!");
		exit(1);
	}

	for (int i = 0; i < n; i++)
	{
		fprintf(fptr, "**** Student %d ****", i + (row / 13) + 1);

		fprintf(fptr, "\nNAME: "); //NAME
		fprintf(fptr, "%s", (stu + i)->name);

		fprintf(fptr, "SEX: %s\t\tAGE: %d", (stu + i)->sex, (stu + i)->age); //SEX + AGE

		fprintf(fptr, "\n\nSCORES: ");

		if ((stu + i)->math == -1)
		{ //MATH
			fprintf(fptr, "\nMATHEMATICS SCORE: ABSENT");
		}
		else
		{
			fprintf(fptr, "\nMATHEMATICS SCORE: %.2f", (stu + i)->math);
		}

		if ((stu + i)->physics == -1)
		{ //PHYSICS
			fprintf(fptr, "\nPHYSICS SCORE: ABSENT");
		}
		else
		{
			fprintf(fptr, "\nPHYSICS SCORE: %.2f", (stu + i)->physics);
		}

		if ((stu + i)->chemistry == -1)
		{ //CHEMISTRY
			fprintf(fptr, "\nCHEMISTRY SCORE: ABSENT");
		}
		else
		{
			fprintf(fptr, "\nCHEMISTRY SCORE: %.2f", (stu + i)->chemistry);
		}

		fprintf(fptr, "\nAVERAGE SCORE: %.2f", (stu + i)->average);
		fprintf(fptr, "\nDEGREE CLASSIFICATION: ");
		fputs((stu + i)->level, fptr);

		fprintf(fptr, "\n*******************\n\n\n");
		nl(1);
	}

	fclose(fptr);

	printf("\nAPPEND SUCCESSFULLY TO \"%s\"", name_file);
}


