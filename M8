#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node //define struct food
{
	double price;
	char* foodname;
	int quantity;
	struct node* next;
}food;
typedef struct node //define struct food
{
	char* foodname;
	int foodamount;
	double price;
	struct node* next;
}tabledish;
typedef struct List //define List struct
{
	 food* head;
	 food* tail;
}foodList;
typedef struct List//define List struct
{
	 tabledish* head;
}List;

void Error_Msg(char* str); //prototypes
void CreateProducts(foodList* flist);
void AddItems(foodList* flist, char* ProductName, int quantity);
void OrderItem(List* arr[], food* head, char* ProductName, int quantity,int TableNumber);
void RemoveItem(List* arr[], int TableNumber);
void RemoveTable(List* arr[], int TableNumber);
int main()
{
	int i;
	FILE* f;
	foodList flist;
	List arr[50];
	int instruction,quantity,tablenum;
	char pname[50];
	if ((f = fopen("Instructions.txt", "rt")) == NULL)
		Error_Msg("input error");
	while (f != EOF)//take input until end of file
	{
		rewind(f);
		fscanf(f, "%d", &instruction);
		switch (instruction)
		{
		case 1:
			CreateProducts(&flist);
			break;
		case 2:
			fscanf(f,"%s%d", pname,&quantity);
			AddItems(&flist, pname, quantity);
			break;
		case 3:
			fscanf(f,"%d%s%d",&tablenum, pname, &quantity);
			OrderItem(&arr, &flist, pname, quantity,tablenum);
			break;
		case 4:
			fscanf(f, "%d", &tablenum);
			RemoveItem(&arr, tablenum);
			break;
		case 5:
			fscanf(f, "%d", &tablenum);
			RemoveTable(&arr, tablenum);
			break;
		default:
			break;
		}

	}
	fclose(f);
	return 0;
}
void Error_Msg(char* str)
{
	printf("\n%s", str);
	exit(1);
}
void CreateProducts(foodList* flist)
{
	int i, j = 0, count = 1, size = 1, flag = 0;//define variables
	FILE* f;
	char name[51];
	char** names,**tempo;
	food* temp = NULL,*p=NULL;
	p = flist->head;
	if ((f = fopen("Manot.txt", "rt")) == NULL)
	{
		Error_Msg("input error");
		exit(1);
	}
	names = (char**)malloc(size * sizeof(char*));//define arr with dynamic allocation
	if (names == NULL)//check dynamic allocation succeed
	{
		printf("allocation didint succeed");
		exit(1);
	}
	temp = (food*)malloc(sizeof(food));//dynamic allocation temp
	if (temp == NULL)//check dynamic allocation succeed
	{
		printf("allocation didint succeed");
		exit(1);
	}
	temp->next = NULL;
	while (fscanf(f, "%s %lf %d", name, &temp->price, &temp->quantity) != EOF)//take input until end of file
	{
		names[j] = name;
		j++;
		size = size + 1;
		tempo = (char**)realloc(names,size * sizeof(char*));
		if (tempo != NULL)
			names = tempo;
		else
		{
			free(temp);
			for ( i = 0; i < count-1; i++)
			{
				temp = p;
				p = p->next;
				free(temp->foodname);
				free(temp);
			}
			free(names);
			printf("allocation didint succeed");
			exit(1);
		}
		for (i = 0; i <size-2 ; i++)
		{
			if (strcmp(names[i], name) == 0)
			{
				flag = 1;
				break;
			}	
		}
		if (temp->price <= 0 || temp->quantity <= 0 || flag == 1)
		{
			free(temp);
			for (i = 0; i < count - 1; i++)
			{
				temp = p;
				p = p->next;
				free(temp->foodname);
				free(temp);
			}
			free(names);
			printf("product name exsist or price dont positive or quantity dont positive");
			exit(1);
		}
		temp->foodname = (char*)malloc((strlen(name)) + 1); //dynamic allocation for name in
		if ((temp->foodname) == NULL)//check dynamic allocation succeed
		{
			free(temp);
			for (i = 0;i < count - 1; i++)
			{
				temp = p;
				p = p->next;
				free(temp->foodname);
				free(temp);
			}
			free(names);
			printf("allocation didint succeed");
			exit(1);
		}
		strcpy(temp->foodname, name);//copy name to arr
		if (flist->head == NULL)
		{
			flist->head = temp;
			flist->tail = temp;
		}
		else
			flist->tail->next = temp;
		flist->tail = temp;
		temp = (food*)malloc(sizeof(food));//another dynamic allocation temp
		if (temp == NULL) // check dynamic allocation succeed
		{
			for (i = 0; i < count ; i++)
			{
				temp = p;
				p = p->next;
				free(temp->foodname);
				free(temp);
			}
			free(names);
		}
		temp->next = NULL;
		count++;
	}
	flist->tail->next = NULL;
	fclose(f);
	printf("The kitchen was created");
}
void AddItems(foodList* flist, char* ProductName, int quantity)
{
	food* temp = flist->head;
	int flag = 0;
	if (quantity <= 0)
	{
		Error_Msg("The quantity must be positive number");
		exit(1);
	}
	while (temp != EOF)
	{
		if (strcmp(temp->foodname, ProductName) == 0)
		{
			temp->quantity += quantity;
			flag = 1;
			break;
		}
		temp = temp->next;
	}
	if (flag == 0)
	{
		Error_Msg("The product is not in stock");
		exit(1);
	}	
}
void OrderItem(List* arr[], foodList* flist, char* ProductName, int quantity, int TableNumber)
{
	tabledish* temp;
	food* p;
	int flag = 0;
	p = flist->head;
	if (TableNumber>49||TableNumber<0)
	{
		printf("table dont exsisit");
		exsit(1);
	}
	if (quantity <= 0)
	{
		Error_Msg("The quantity must be positive number");
		exit(1);
	}
	while (p != NULL)
	{
		if (strcmp(ProductName, p->foodname) == 0)
		{
			flag = 1;
			break;
		}
		p = p->next;
	}
	if (flag == 1)
	{
		temp = (tabledish*)malloc(sizeof(tabledish));
		if ((temp) == NULL)//check dynamic allocation succeed
		{
			printf("Not enough memory");
			exit(1);
		}
		temp->foodname = (char*)malloc((strlen(ProductName)) + 1); //dynamic allocation for name in
		if ((temp->foodname) == NULL)//check dynamic allocation succeed
		{
			printf("Not enough memory");
			free(temp);
			exit(1);
		}
		strcpy(temp->foodname, ProductName);//copy name to arr
	}
	else
	{
		printf("product doesnt exsisit on menue");
		exit(1);
	}
	temp->foodamount = quantity;
	temp->price = p->price;
	temp->next = arr[TableNumber]->head;
	arr[TableNumber]->head = temp;
	p->quantity = p->quantity - quantity;
}
void RemoveItem(List* arr[], int TableNumber)
{
	tabledish* temp;
	if (arr[TableNumber]->head==NULL)
	{
		printf("table number %d dont have any active order", TableNumber);
	}
	temp = arr[TableNumber]->head;
	arr[TableNumber]->head = arr[TableNumber]->head->next;
	printf("%d Pasta was returned to the kitchen from table number %d", arr[TableNumber]->head->foodamount, TableNumber);
	free(temp);
	
}
void RemoveTable(List* arr[], int TableNumber)
{
	tabledish* temp,*p;
	double sum = 0;
	temp = arr[TableNumber]->head;
	p = arr[TableNumber]->head;
	while (temp!=NULL)
	{
		printf("%s%d,", temp->foodname, temp->foodamount);
		sum = sum + (temp->foodamount * temp->price);
		temp = temp->next;
		free(p);
		p = temp;
	}
	arr[TableNumber]->head = NULL;
	printf("%lf nis+%lf nis for tips, please!", sum, 0.15 * sum);
}
