#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <math.h>
#include <stdlib.h>
#define x
#ifdef x2
typedef struct fraction // define fraction struct
{
	int mone;
	int mehane;
}fraction;
void printsum(fraction arr[],int size);//prototype
int main()
{
	double sum = 0;//define variables:sum count all fraction
	int realsize = 2, insize = 0,i,mone,mehane;//realsize and insize for realloc,mone,mehane for input
	fraction* arr,*temp;
	arr=(fraction*)malloc(realsize * sizeof(fraction));//define arr with dynamic allocation
	if (arr == NULL)//check dynamic allocation succeed
	{
		printf("Not enough memory");
		exit(1);
	}
	printf("Enter fractions by pairs of integers(0 0 to finish):");
	printf("\n%d (mone mehane): ", insize + 1);//take first input
	scanf("%d%d", &mone, &mehane);
	while (1)
	{
		if (mone == 0 && mehane == 0)//check input isnt 0 0
			break;
		if (mehane != 0)//check that mehane not zero
		{
			if (realsize == insize)//chcek when we need to bigger the array
			{
				realsize *= 2;
				temp = (fraction*)realloc(arr, realsize * sizeof(fraction));
				if (temp != NULL)
					arr = temp;
				else
				{
					free(arr);
					exit(1);
				}
			}
			arr[insize].mone = mone;//put the input in arr
			arr[insize].mehane = mehane;
			insize++;//take inside next step in array
		}
		else
			printf("cannot divide by 0, please try again:");//print if mehane is zero
		printf("\n%d (mone mehane): ", insize + 1);//another input
		scanf("%d%d", &mone, &mehane);
	}
	printsum(arr,insize);//call printsum
	free(arr);
	return 0;
}

void printsum(fraction arr[], int size)
{
	int i, count = 0, smone, smehane, flag = 0;//define variables:count save the number of complete number we have.smone,smehane save the fraction after reduction, flag for enter while after
	fraction sum;//sum save fraction final way
	fraction* sarr; //sarr copy arr
	sarr = (fraction*)malloc(size * sizeof(fraction));//dynamic allocation for sarr
	if (sarr == NULL)//check dynamic allocation succeed
	{
		printf("Not enough memory");
		exit(1);
	}
	sum.mone = arr[0].mone;//define sum to arr[0]
	sum.mehane = arr[0].mehane;
	for (i = 0; i < size; i++)//copy arr to sarr
	{
		sarr[i] = arr[i];
	}
	for (i = 1; i < size ; i++)//sum all arr
	{
		
		{
			sum.mone = (sarr[i].mone * sarr[i - 1].mehane) + (sarr[i - 1].mone * sarr[i].mehane);//calc sum with common denominator
			sum.mehane = sarr[i].mehane * sarr[i - 1].mehane;
			sarr[i].mone = sum.mone; //put in sarr[i] the calc for next calc
			sarr[i].mehane = sum.mehane;
		}
	}
	do//reduction the fraction
	{
		flag = 0;
		for (i = 2; i <= sum.mone; i++)
		{
			if (sum.mone % i == 0 && sum.mehane % i == 0)
			{
				sum.mone = sum.mone / i;
				sum.mehane = sum.mehane / i;
				flag++;
			}
		}
	} while (flag != 0);
	smone = sum.mone;//save the result for the last print
	smehane = sum.mehane;
	while (sum.mone >= sum.mehane)//calc second type print 
	{
		count++;
		sum.mone -= sum.mehane;
	}


	for (i = 0; i < size ; i++)//do the print required
	{
		printf("%d/%d", arr[i].mone, arr[i].mehane);
		if (i < size -1)
			printf("+");
	}
	printf("=%d/%d=%d and %d/%d", smone, smehane, count, sum.mone, sum.mehane);
	free(sarr);
}

#endif // x
