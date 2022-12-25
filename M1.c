#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <math.h>
#define N 8 //define N for the length of the array
#define X
#ifdef X2
int max_len_negative(int arr[],int len); //prototypes
int main()
{
	int arr[N],flag=0,i,maxlen=0, clen; //define variables: flag for check that input isnt zeros, max len saves the max length negatives, clen save the current array length of nagatives
	printf("Enter the array ");
	for (i = 0; i < N; i++) //input
	{
		scanf("%d", &arr[i]);
		if (arr[i] != 0)
			flag++; //if the input isnt 0 flag=flag+1
	}
	clen = max_len_negative(arr, N); //call max_len_negative
	if (clen > maxlen) //check if current len negatives bigger than maxlen 
	{
		maxlen = clen;
	}
	while (flag != 0) //while input isnt all zero
	{
		flag = 0; //zero flag for next input
		printf("Enter the array ");
		for (i = 0; i < N; i++) //input all over again
		{
			scanf("%d", &arr[i]);
			if (arr[i] != 0)
				flag++;
		}
		clen = max_len_negative(arr, N);
		if (clen > maxlen)
		{
			maxlen = clen;
		}
	}
	printf("Maximal negative sequence length is: %d", maxlen);
	
	return 0;
}
int max_len_negative(int arr[],int len) // fun that return max length negatives in the array
{
	int i, maxlen = 0, sum=0; //define variables: maxlen for save the max length negatives in the array and sum for counting every sequence of negatives in the array
	for (i = 0; i < len; i++)
	{
		if (arr[i] < 0)
		{
			sum++; //sums the sequence of negatives
			
		}
		else
			if (sum > maxlen) //check if the current sequence bigger than max sequence
			{
				maxlen = sum;
				sum = 0;
			}
	}
	if (sum > maxlen) //check if the current sequence bigger than max sequence
	{
		maxlen = sum;
	}
	return maxlen;

}
#endif // X
