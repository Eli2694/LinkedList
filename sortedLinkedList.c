#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

void GeneralList();
void GenerateXList();
void PrintList();
void FreeList();

struct Item
{
	int Val;
	struct Item* next;
	struct Item* prev;
};

struct Item* HEAD = NULL;
struct Item* TAIL = NULL;


int main()
{
	//GeneralList();
	GenerateXList();
	PrintList();
	FreeList();
	return 0;
}

void GeneralList()
{
	struct Item* old = NULL;
	struct Item* current;
	

	time_t i = time();
	srand(i);

	for (int j = 0; j < 10; j++)
	{
		current = (struct Item*)malloc(sizeof(struct Item));

		int ranNum = rand() % 10;
		current->Val = ranNum;

		if (!HEAD)
		{
			HEAD = current;
			TAIL = current;
			current->prev = NULL;
			HEAD->next = NULL;
		}
		else
		{

			TAIL = current;
			current->next = NULL;
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
	struct Item* release = HEAD;
	struct Item* Curr = HEAD;
	while (Curr != NULL)
	{
		release = Curr;
		Curr = Curr->next;
		free(release);
		
	}

}