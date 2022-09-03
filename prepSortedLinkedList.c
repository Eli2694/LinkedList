#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

void GeneralList();
void GenerateXList();
void PrintList();
void FreeList();
struct Item* Findval(int val);
struct item* ChangeVal(int oldVal,int newVal);
void ResetList();


struct Item
{
	int Val;
	struct Item* next;
	struct Item* prev;
};

struct Item* HEAD = NULL;
struct Item* TAIL = NULL;


int main_prepForSortedLinkedList()
{
	// Creation of the linked list and printing it
	GeneralList();
	//GenerateXList();
	PrintList();
	//--------------------------------------------
	// Checking if the value exists in the list and if so then it can be replaced
	int val, newVal;
	printf("Enter Val: \n");
	scanf("%d", &val);
	Findval(val);
	printf("Enter new val: \n");
    scanf("%d", &newVal);
	ChangeVal(val, newVal);
	//----------------------------------------------------------------------------
	//Release of a linked list and acknowledgment of its release
	FreeList();
    ResetList();
	// ---------------------------------------------------------
	return 0;
}

void GeneralList()
{
	struct Item* old = NULL;
	struct Item* current;
	

	//time_t i = time();
	//srand(i);

	for (int j = 0; j < 10; j++)
	{
		current = (struct Item*)malloc(sizeof(struct Item));

		//int ranNum = rand() % 10 +1;
		//current->Val = ranNum;
		current->Val = j;

		if (!HEAD)
		{
			HEAD = current;
			TAIL = current;
			HEAD->prev = NULL;
			HEAD->next = NULL;
		}
		else
		{

			TAIL = current;
			TAIL->next = NULL;
			current->prev = old;
			old->next = current;

		}
		old = current;
	}

}

void GenerateXList()
{
	struct Item* Curr;
	struct Item* Old = NULL;

	time_t t = time();
	srand(t);
	int len = rand() % 10 +1;

	for (int i = 0; i < len; i++)
	{
		Curr = (struct Item*)malloc(sizeof(struct Item));
		int randomNumber = rand();
		Curr->Val = randomNumber;

		if (!HEAD)
		{
			HEAD = Curr;
			TAIL = Curr;
			Curr->prev = NULL;
			Curr->next = NULL;
		}
		else
		{
			// Second iteration and beyond
			Old->next = Curr;
			TAIL = Curr;
			Curr->prev = Old;
			Curr->next = NULL;
		}
		Old = Curr;
	}

}

void PrintList()
{
	struct Item* Print = HEAD;
	while (Print != NULL)
	{
		printf("%d\n", Print->Val);
		Print = Print->next;
	}
	
}

void FreeList()
{
	struct Item* release = NULL;
	struct Item* Curr = HEAD;
	while (Curr != NULL)
	{
		release = Curr;
		Curr = Curr->next;
		free(release);
	}
	// Without the comparison to NULL the pointer has a strange address
	HEAD = NULL;
	TAIL->next = NULL;
}

struct Item* Findval(int val)
{
	struct Item* ret = NULL;
	struct Item* curr = HEAD;
	while (curr != NULL)
	{
		if (curr->Val == val)
		{
			ret = curr;
			return ret;
		}
		curr = curr->next;
	}
	return ret;
}

struct item* ChangeVal(int oldVal , int newVal)
{
	struct Item* ret = Findval(oldVal);
	if (ret != NULL)
	{
		ret->Val = newVal;
		return ret;
	}
	return 0;
}

void ResetList()
{
	//Is there a linked list?
	struct Item* Exists = NULL;
	struct Item* Curr = HEAD;
	if (Curr == NULL)
	{
		printf("Linked list does not exists");
		return;
	}
	else
	{
		while (Curr != NULL)
		{
			Exists = Curr;
			Curr = Curr->next;
			free(Exists);
		}
		// Without the comparison to NULL the pointer has a strange address
		HEAD = NULL;
		TAIL->next = NULL;
	}
}

