#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <math.h>
#include <stdlib.h>
#define N 3
#define x
#ifdef x
typedef struct unit
{
	char code[10];
	char* name;
	int sold;
}unit;
int main()
{
	int i,maxsold,minsold,maxsoldin,minsoldin;
    char name[20];
	unit* arr;
    unit** pointers;
    unit* temp;
	arr = (unit*)malloc(N * sizeof(unit));
	if (arr == NULL)
	{
		printf("Not enough memory");
		exit(1);
	}
    for (i = 0; i < N; i++)//run on arr
    {
        printf("Enter unit code: ");
        scanf("%s", arr[i].code);
        printf("Enter your name: ");
        scanf("%s", name);//input name
        arr[i].name = (char*)malloc((strlen(name)) + 1);//dynamic allocation for name in arr 
        if ((arr[i].name) == NULL)//check dynamic allocation succeed
        {
            printf("Not enough memory");
            free(arr);//if we didint succeed free arr
            exit(1);
        }
        strcpy(arr[i].name, name);//copy name to arr
        printf("Enter number of products sold: ");//input 
        scanf("%d",&arr[i].sold);
    }	
    pointers = (unit**)malloc(N * sizeof(unit*));
    if (pointers == NULL)
    {
        printf("Not enough memory");
        exit(1);
    }
    for (i = 0; i < N; i++)
    {
        pointers[i] = &arr[i];
    }
    i = 0;
    maxsold = arr[i].sold;
    maxsoldin = 0;
    minsoldin = 0;
    for (i = 1; i < N; i++)
    {
        if (arr[i].sold > maxsold)
        {
            maxsold = arr[i].sold;
            maxsoldin = i;
        }
    }
    temp = pointers[0];
    pointers[0] = &arr[maxsoldin];
    pointers[maxsoldin] = temp;
    printf("The best unit is:%s with code: %s\n", pointers[0]->name, pointers[0]->code);
    i = 0;
    minsold = arr[i].sold;
    for (i = 1; i < N; i++)
    {
        if (arr[i].sold < minsold)
        {
            minsold = arr[i].sold;
            minsoldin = i;
        }
    }
    temp = pointers[1];
    pointers[1] = &arr[minsoldin];
    pointers[minsoldin] = temp;
    printf("The worst unit is:%s with code: %s\n", pointers[1]->name, pointers[1]->code);
    return 0;
}
#endif // x
