#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include<time.h>

#pragma warning(disable:4996)

struct Item
{
	int val;
	struct Item* prev;
	struct Item* next;
};

//Beginning of the linked-list and the end;
struct Item* head = NULL;
struct Item* tail = NULL;

// Functions - Specification
struct Item* InserNewItem(int val);
struct Item* Creation(int val,struct Item* Item);
void printList();
int* vaLocation(struct Item* ret);
void release();



int main()
{
	for (int i = 0; i < 10; i++)
	{
		//Random Numbers
		/* srand(time(NULL));
		int rNum = rand() % 10;*/

		// User Input
		int num;
		printf("Enter Val\n");
		scanf("%d", &num);

		//Call to functions
		struct Item* ret = InserNewItem(num); // creating an organ for the list
		Creation(num, ret); // list creation
	}

	printList();
	release();
	
	return 0;
}
struct Item* InserNewItem(int val)
{
	//Creating a member of a linked list
	struct Item* organ = NULL;
	struct Item* ret = NULL;
	organ = (struct Item*)malloc(sizeof(struct Item)); // borrowing a memory from heap
	organ->val = val; // inserting val to struct 
	organ->prev = NULL;
	organ->next = NULL;
	ret = organ;
	return ret; // returning address
	//I returned an address of a memory cell with a value in - int val
}

struct Item* Creation(int val, struct Item* ret)
{
	struct Item* Curr = ret;
	if (head == NULL)
	{
		//At the beginning of the linked list - its beginning must be determined
		head = Curr;
		head->prev = NULL;
		head->next = NULL;
		tail = Curr;
	}
	else
	{
		//The new value is less than the val in the head
		if (Curr->val < head->val)
		{
			Curr->next = head;
			Curr->prev = NULL;
			head->prev = Curr;
			head = Curr;
		}
		else if (Curr->val > tail->val)
		{
			//The new value is bigger than the val in the tail
			Curr->prev = tail;
			Curr->next = NULL;
			tail->next = Curr;
			tail = Curr;
		}
		else if (Curr->val > head->val && Curr->val < tail->val)
		{
			vaLocation(ret);
		}
	}
	
}

int* vaLocation(struct Item* ret)
{
	struct Item* move = head;
	while (move != NULL)
	{
		if (ret->val < move->val)
		{
			ret->next = move;
			ret->prev = move->prev;
			move->prev->next = ret;
			move->prev = ret;
			return;
		}
		
		move = move->next;
	}
}

void printList()
{
	struct Item* curr = head;
	while (curr != NULL)
	{
		printf("%d,", curr->val);
		curr = curr->next;
	}
}

void release()
{
	struct Item* curr = head;
	struct Item* LinkedList = NULL;
	while (curr != NULL)
	{
		LinkedList = curr;
		curr = curr->next;
		free(LinkedList);
	}
}

