#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct student //define struct student
{
	char* name;
	long id;
	float grade_matam;
	char labs[5];
	char grade_hw;
}student;
typedef struct university //define struct university
{
	student* stud_arr;
	int num_studnets;
}university;
void input1(FILE* f, university* uni);//prototypes
void output2(FILE* f,university uni);
void output3(FILE* f, university uni);
void output4(FILE* f, university uni);
void output5(FILE* f, university uni);
void end6(FILE* f);
int main()
{
	FILE* f; //define variables
	university uni;
	int sel,i;
	printf("Option 1: input students information\nOption 2: print students data\nOption 3: print students data with final grade \nOption 4: print statistics data\nOption 5: print students above average\nOption 6: end\n");//take first input
	printf("Select option: ");
	scanf("%d", &sel);
	while (sel != 1)//make sure first input is 1
	{
		printf("first select must be option 1, please try again: \n");
		printf("Option 1\nOption 2\nOption 3\nOption 4\nOption 5\nOption 6\n");
		printf("Select option: ");
		scanf("%d", &sel);
	}
	f = fopen("input.txt", "r");//open  f for read and check open file succeed
	if (f == NULL)
	{
		printf("open file didint succeed");
		exit(1);
	}
	input1(f, &uni);//call input1
	fclose(f);
	printf("Option 1: input students information\nOption 2: print students data\nOption 3: print students data with final grade \nOption 4: print statistics data\nOption 5: print students above average\nOption 6: end\n");//take first input
	printf("Select option: ");
	scanf("%d", &sel); //take second input
	while (sel != 6)//run until input(sel) is 6
	{
		switch (sel) //check cases on sel
		{
		case 1: 
		{
			printf("Option 1 available one time try another option:\n\n");
			break;
		}
		case 2: 
		{
			f = fopen("output.txt", "a");//open  f and check open file succeed
			if (f == NULL)
			{
				printf("open file didint succeed");
				exit(1);
			}
			output2(f, uni);//call output2
			fclose(f);
			break;
		}
		case 3: 
		{
			f = fopen("output.txt", "a");//open  f and check open file succeed
			if (f == NULL)
			{
				printf("open file didint succeed");
				exit(1);
			}
			output3(f, uni);//call output3
			fclose(f);
			break;
		}
		case 4: 
		{
			f = fopen("output.txt", "a");//open f and check open file succeed
			if (f == NULL)
			{
				printf("open file didint succeed");
				exit(1);
			}
			output4(f, uni);//call output4
			fclose(f);
			break;
		}
		case 5: 
			f = fopen("output.txt", "a");//open f and check open file succeed
			if (f == NULL)
			{
				printf("open file didint succeed");
				exit(1);
			}
			output5(f, uni);//call output5
			fclose(f);
			break;
		default:
			printf("error\n");
			break;

		}
		printf("Option 1: input students information\nOption 2: print students data\nOption 3: print students data with final grade \nOption 4: print statistics data\nOption 5: print students above average\nOption 6: end\n");//take first input
		printf("Select option: ");
		scanf("%d", &sel);//take another input
	}
	f = fopen("output.txt", "a");//open f and check open file succeed
	if (f == NULL)
	{
		printf("open file didint succeed");
		exit(1);
	}
	end6(f, uni);//call end6
	fclose(f);
	printf("Finish");
	for (i = 0; i < uni.num_studnets; i++)//free dynamic allocation
	{
		free(uni.stud_arr[i].name);
	}
	free(uni.stud_arr);
	return 0;
}
void input1(FILE* f, university* uni)//get address of university and file and take input from file
{
	int size = 1, labnum, i, j = 0; //define variables
	student* temp;
	char name[99];//name for help dynamic allocation later
	uni->stud_arr = (student*)malloc(size * sizeof(student)); //dynamic allocation for stud_arr
	if (uni->stud_arr == NULL)//check dynamic allocation succeed
	{  
		printf("Not enough memory");
		exit(1);
	}
	while (fscanf(f,"%s%ld%f%d", name, &uni->stud_arr[j].id, &uni->stud_arr[j].grade_matam, &labnum) != EOF)//take input until end of file
	{
    	uni->stud_arr[j].name = (char*)malloc((strlen(name)) + 1);//ynamic allocation for student name
		if ((uni->stud_arr[j].name) == NULL)//check dynamic allocation succeed
		{
			printf("Not enough memory");
			free(uni->stud_arr);//if we didint succeed free arr
			exit(1);
		}
		strcpy(uni->stud_arr[j].name, name);//copy name to stud_arr
		for (i = 4; i >= 0; i--)//inset labs number(0/1)to the array
		{
			uni->stud_arr[j].labs[i] = labnum % 10;
			labnum = labnum /10;
		}
		size = size + 1;
		temp = (student*)realloc(uni->stud_arr, (size) * sizeof(student));//realloc to stud_arr for next input
		if (temp != NULL)
			uni->stud_arr = temp;
		else
		{
			free(uni->stud_arr);
			exit(1);
		}
		j++;//bigger j for next input

	}
	uni->num_studnets = j;//put the number of students in the uni
	return uni;
}
void output2(FILE* f,university uni)//get university and file and print output to file
{
	int i, j, counter = 0;
	fprintf(f, "\nOption 2\n");
	for (i = 0; i < uni.num_studnets; i++)//run on students and check labs final grade
	{
		for (j = 0; j < 5; j++)
		{
			if (uni.stud_arr[i].labs[j] == 1)
				counter++;
		}
		if (counter >= 3)
			uni.stud_arr[i].grade_hw = 1;
		else
			uni.stud_arr[i].grade_hw = 0;
		counter = 0;
		fprintf(f,"Student %d: %s %ld %.2f %d\n", i + 1, uni.stud_arr[i].name, uni.stud_arr[i].id, uni.stud_arr[i].grade_matam, uni.stud_arr[i].grade_hw);//print data to file
	}
}
void output3(FILE* f, university uni)//get university and file and print output to file
{
	int i, j, counter = 0;
	float finalgrade;
	fprintf(f, "\nOption 3\n");
	fprintf(f, "BEFORE:\n");
	for (i = 0; i < uni.num_studnets; i++)//run on students and check labs final grade
	{
		for (j = 0; j < 5; j++)
		{
			if (uni.stud_arr[i].labs[j] == 1)
				counter++;
		}
		if (counter >= 3)
			uni.stud_arr[i].grade_hw = 1;
		else
			uni.stud_arr[i].grade_hw = 0;
		counter = 0;
		fprintf(f,"Student %d: %s %ld %.2f %d\n", i + 1, uni.stud_arr[i].name, uni.stud_arr[i].id, uni.stud_arr[i].grade_matam, uni.stud_arr[i].grade_hw);//print data to file
	}
	fprintf(f, "\nAFTER:\n");
	for (i = 0; i < uni.num_studnets; i++)//calc final grade for evey student
	{
		if (uni.stud_arr[i].grade_matam < 55)
			finalgrade = uni.stud_arr[i].grade_matam;
		else
			if (uni.stud_arr[i].grade_hw == 1)
				finalgrade = (uni.stud_arr[i].grade_matam * 0.85) + (100 * 0.15);
			else
				finalgrade = (uni.stud_arr[i].grade_matam * 0.85) + (0 * 0.15);
		fprintf(f, "Student %d: %s %ld %.2f %d final: %.2f\n", i + 1, uni.stud_arr[i].name, uni.stud_arr[i].id, uni.stud_arr[i].grade_matam, uni.stud_arr[i].grade_hw, finalgrade);//print data to file
	}
}
void output4(FILE* f, university uni)//get university and file and print output to file
{
	int i; //define variables
	float sum = 0, avg, dif = 0, sd, maxgrade = uni.stud_arr[0].grade_matam, mingrade = uni.stud_arr[0].grade_matam;
	fprintf(f, "\nOption 4\n");
	for (i = 0; i < uni.num_studnets; i++)//calc max grade and min grade and sum for average
	{
		sum = sum + uni.stud_arr[i].grade_matam;
		if (uni.stud_arr[i].grade_matam > maxgrade)
			maxgrade = uni.stud_arr[i].grade_matam;
		if (uni.stud_arr[i].grade_matam < mingrade)
			mingrade = uni.stud_arr[i].grade_matam;
	}
	avg = sum / uni.num_studnets;//calc the averge
	fprintf(f,"The average is: %.2f\n", avg);
	for (i = 0; i < uni.num_studnets; i++)//calc the Standard Deviation
	{
		dif = dif + pow((uni.stud_arr[i].grade_matam - avg),2);
	}
	sd = sqrt(dif / uni.num_studnets);
	fprintf(f, "The Standard Deviation is: %.2f\n", sd);//print all data to file
	fprintf(f, "The number of students is: %d\n", uni.num_studnets);
	fprintf(f, "The range is: %.2f - %.2f\n", maxgrade,mingrade);
}
void output5(FILE* f, university uni) //get university and file and print output to file
{
	int i;
	float sum = 0,avg;
	fprintf(f, "\nOption 5\n");
	for (i = 0; i < uni.num_studnets; i++)//calc the avg
	{
		sum = sum + uni.stud_arr[i].grade_matam;
	}
	avg = sum / uni.num_studnets;
	fprintf(f,"Students above average:\n");//prinr to file student above average
	for (i = 0; i < uni.num_studnets; i++)
	{
		if (uni.stud_arr[i].grade_matam > avg)
			fprintf(f,"name: %s id: %ld\n", uni.stud_arr[i].name, uni.stud_arr[i].id);
	}

}
void end6(FILE* f)//get university and file and print output to file
{
	fprintf(f, "\nOption 6\n");
	fprintf(f, "End of program");//print to file the end message
}










