#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <math.h>
#define N 4
#define X
#ifdef X2
void printArray(long arr[], int size); //prototypes
int getFirstDigit(long num);
void buildNum(long* src, int firstdigit);
void shift_circular_left(int arr[], int size);
int main()
{
	long i,arr[N]; //define variables
	printf("Enter array: ");
	for (i = 0; i < N; i++) //input
	{
		scanf("%ld", &arr[i]);
	}
	printf("Array before shift circular left: ");
	printArray(arr, N); //call printArray for print the array before shift_circular_left
	shift_circular_left(arr, N); //call shift_circular_left on our array
	printf("\nArray after shift circular left : ");
	printArray(arr, N);//call printArray for print the array after shift_circular_left
	return 0;
}
void printArray(long arr[], int size)//fun printArray get tha array and his suze and prints him
{
	int i;
	for (i = 0; i < N; i++) 
	{
		printf("%ld ", arr[i]);
	}
}
int getFirstDigit(long num)//fun that get number and return his first left digit
{
	while (num>9)
	{
		num = num / 10;
	}
	return num;
}
void buildNum(long* src, int firstdigit)//fun that get pointer to number and first digit and bulid the new number
{
	long newnum=0,i=0; //define variables: newnum for save the calc of the new number

	while (*src > 9) //calc newnum
	{
		newnum += (*src % 10) * pow(10, i);
		*src = *src / 10;
		i++;
	}
	newnum *= 10;
	newnum += firstdigit; //add to newnum firstdigit
	*src = newnum; //change the place in the array to newnum
}
void shift_circular_left(int arr[], int size) //fun get array and size and do shift_circular_left on him
{
	int i,first; //define variables: first for save arr[0] first digit
	first = getFirstDigit(arr[0]);
	for ( i = 0; i < size-1; i++)//build num for every index besides the last one
	{
		buildNum(&arr[i], getFirstDigit(arr[i + 1]));
	}
	buildNum(&arr[size - 1], first);//build num for the last index
}

#endif // X
