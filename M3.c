#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <math.h>
#include <string.h>
#define N 8 //define N for the length of the array
#define Len 41 //define Len for the length of the input
#define X
#ifdef X
void print_histo(char str[]);//prototypes
int main()
{
	char str[Len];//define str
	printf("Enter a string please: ");
	fgets(str, Len, stdin);
	if (str[strlen(str) - 1] == '\n') //remove \n from the end of the string
		str[strlen(str) - 1] = '\0';
	while (str[strlen(str)-1] != '!')//take input until he end with '!'
	{
		printf("invalid input, dosent end with !\n");
		printf("Enter a new string please: ");
		fgets(str, Len, stdin);
		if (str[strlen(str) - 1] == '\n') //remove \n from the end of the string
			str[strlen(str) - 1] = '\0';
	}
	print_histo(str);//call print_histo
	return 0;
}
void print_histo(char str[])//fun get str and print his histogram
{
	int j, i, arr[N] = { 0 }, ch,t=0; //define variables: arr as a counter array,ch for print the abc,t to run on the arr
	for (i = 0; i < strlen(str); i++)//add to the arr the number of any letter 
	{
		if (str[i] >= 97 && str[i] <= 97 + N)
		{
			arr[str[i] - 97]++;
		}
	}
	ch = 97;//ch=a for thr first print
	for (j = 0; j < N; j++)//run on arr and print
	{
		printf("%c:", ch);//print the abc
		ch++;
		for (i = 0; i < arr[t]; i++)//print number of times the letter appear with *
		{
			printf("*");
		}
		t++;//take t to next index in arr
		printf("\n");

	}
}
#endif // X2
