#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 5//define number of stations
#define M 6//number of hours
#define K 10//number of Drivers
void hasDuplicateszerosInRows(int bus[][M]);//set function for 1.1
void hasDuplicatesInCol(int bus[][M]);//set function for 1.2
void hastriopathinmat(int bus[][M]);//set function for 1.3
int main()
{
    //int bus[N][M] =  {{6, 3, 0, 0, 0, 5},
      //                {6, 6, 2, 7, 8, 4},
        //              {6, 0, 6, 2, 1, 7},
          //            {0, 4, 3, 2, 5, 0},
            //          {0, 0, 0, 3, 0, 8}};
    
   int bus[N][M]={{6, 3, 8, 0, 0, 5},//set matrix
                    {6, 6, 6, 6, 8, 4},
                  {4, 5, 2 , 1 ,1, 7 },
                 { 0, 4, 1, 2, 5, 0 },
       { 0, 1, 7, 3, 2, 8 }}; 
    int i, j;
    int startedhour = 10;
    for (i = 0; i < M; i++)//For the tabular order
    {
        if (i == 0)//For the tabular order
            printf("             [%d:00]", startedhour);//printing the times
        else if (i == M - 1)//For the tabular order
            printf(" [%d:00]", startedhour);//
        else
         printf("   [%d:00]      ", startedhour);//
        startedhour++;
    }
    for (i = 0; i < N; i++)//For the tabular order
    {
        printf("\n[Station(%d)]:\t", i + 1);//printing the stations
        for (j = 0; j < M; j++)//For the tabular order
        {
            if(j==0 || j==M-1)//For the tabular order
             printf("%d\t", bus[i][j]);//
            else
                printf("  %d      \t", bus[i][j]);//
        }
        printf("\n\n");
    }
    printf("The stations with no collection for more than two hours are:\n");
    hasDuplicateszerosInRows(bus);//caling for the first function 1.1
    printf("The drivers that have two or more stations in one hour are:\n");
    hasDuplicatesInCol(bus);//caling for the sec function 1.2
    printf("The drivers that drive three hours in a row are:\n");
    hastriopathinmat(bus);//caling for the thrd function 1.3
    return 0;
}

void hasDuplicateszerosInRows(int bus[][M])
{
    int row, col, counter = 0, otherCol, num;//Setting Variables
    for (row = 0; row < N; row++)//runing on the matrix rows
    {
        for (col = 0; col < M; col++)////runing on the matrix cols
        {
            num = bus[row][col];//runing all the elements and set it for num
            for (otherCol = col + 1; otherCol < M; otherCol++)//runing for the next col
            {
                if (num == bus[row][otherCol] && num == 0 && bus[row][otherCol] == 0 
                    && otherCol - col == 1)//if there is sequence of 2 (0 after 0) diffrent cols - but next to each other
                {
                    printf("\nStation Number: (%d)\n\n", row + 1);//printing the number of the station (doing this^^) on table
                    counter++;//make counter of the station doing this +1
                    row++;//get to the next row ----> for *************(Avoid duplications)******************
                }
            }
        }
    }
    if (counter == 0)//if there is no station doing this on table ..printing
    {
        printf("No one of the stations\n");
    }
}


void hasDuplicatesInCol(int bus[][M])
{
    //Setting Variables
    int row, col, counter = 0, otherRow, num, arr[K] = {0};//arr to *************(Avoid duplications)******************

    for (row = 0; row < N; row++)//runing on the matrix rows
    {
        for (col = 0; col < M; col++)//runing on the matrix cols
        {
            num = bus[row][col];//runing all the elements and set it for num
            for (otherRow = row + 1; otherRow < N; otherRow++)//runing for the next row
            {//if there is 2 numbers the same, in the same col (rows not necessary close each other)
                if (num == bus[otherRow][col] && num != 0 && bus[otherRow][col] != 0 &&
                    arr[num - 1] != 1) //for avoid duplications
                {
                    arr[num - 1] = 1;  //for avoid duplications
                    printf("\nDriver Number: (%d)\n\n", num);//printing the driver number doing that on table
                    counter++;
                }
            }
        }
    }
    
    if (counter == 0)//if there is no Driver doing this on table ..printing
    {
        printf("No one of the Drivers\n");
    }
}

void hastriopathinmat(int bus[][M])
{
    //Setting Variables
    int row, col,v,t, counter = 1, otherCol, num, otherOtherCol ,arr[K] = {0};//arr to *************(Avoid duplications)******************
    for (row = 0; row < N; row++)//runing on the matrix rows
    {
        for (col = 0; col < M; col++)//runing on the matrix cols
        {
            num = bus[row][col];//runing all the elements and set it for num
            for (otherCol = col + 1; otherCol < M; otherCol++)////runing for the next col
            //if there is number of the next col
            {
                for (otherOtherCol = otherCol + 1; otherOtherCol < M; otherOtherCol++)////runing for the next next col
            //if there is number of the next col
                {
                    for (t = 0; t < N; t++)//runing again on the matrix rows twice, 
                       // Because they do not have to be in the same row
                    {
                        for (v = 0; v < N; v++)//the secound runing
                        {
                            if (num == bus[t][otherCol] && num == bus[v][otherOtherCol] && num != 0 && bus[t][otherCol] != 0 &&
                                bus[v][otherOtherCol] != 0 && otherCol - col == 1 && otherOtherCol - otherCol == 1 && otherOtherCol - col == 2 &&
                                arr[num - 1] != 1)//*************(Avoid duplications)******************
                                //check if there is trios path not matter if in the same row... the 3 cols must be next to each other
                            {
                                printf("\nDriver Number: (%d)\n\n", num);//printing the driver number doing that on table
                                arr[num - 1] = 1;// *************(Avoid duplications)******************
                                counter++;

                            }
                        }
                    }
                }
            }
        }
    }
    if (counter == 0)//if there is no Driver doing this on table ..printing
    {
        printf("No one of the Drivers\n");
    }
}

//the end
