#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

/*
struct place
{
	int val;
	struct place* next;
};

void writeNewFile();
void save();
void Load();
void freeMemoryAllocRoot();
void Targil4();

struct place* head = NULL; // exercises 3 -6
struct place* root = NULL; // exercise 7 


void Targil1()
{

	struct MyStruct
	{
		int id;
		short symbol;
	};
	printf("Enter Number Of Structures: ");
	int numStruct;
	scanf("%d", &numStruct);
	struct MyStruct* sample = (struct MyStruct*)malloc(sizeof(struct MyStruct) * numStruct);
	struct MyStruct* currentSample;
	currentSample = sample;

	if (!sample)
	{
		//error
		return;
	}

	for (int i = 0; i < numStruct; i++)
	{
		printf("Enter id: ");
		int id;
		scanf("%d", &id);
		printf("Enter symbol: ");
		short symbol;
		scanf("%hi", &symbol);

		currentSample->id = id;
		currentSample->symbol = symbol;
		currentSample++;

	}

	FILE* f = fopen("c:\\C-Class-Exercises\\linkedlist1-mavo.bin", "w");
	fwrite(&sample, sizeof(struct MyStruct), numStruct, f);
	fclose(f);
	free(sample);
}

void Targil2()
{
	struct naser
	{
		int id;
		int a;
		int b;

	};

	struct naser* ptr = malloc(sizeof(struct naser));
	struct naser* start;
	start = ptr;
	int sum = 0;
	FILE* f = fopen("c:\\C-Class-Exercises\\week3class1.bin", "r");
	if (!f)
	{
		//error
		return;
	}
	else
	{

		while (fread(ptr, sizeof(struct naser), 1, f))
		{
			sum = sum + ptr->id;
		}
	}
	printf("%d", sum);
	fclose(f);
	free(start);
}

void Targil3()
{
	

	int userInput;
	printf("Enter any number except 100 to create a list: \n");
	scanf("%d", &userInput);
	
	struct place* currentPlace;
	struct place* prevPlace = NULL;
	while (userInput != 100)
	{
		currentPlace = malloc(sizeof(struct place));
		if (head == NULL)
		{
			head = currentPlace;
		}
		else
		{
			prevPlace->next = currentPlace; // store the address of the memory
		}

		printf("Enter Val:");
		scanf("%d", &currentPlace->val);

		currentPlace->next = NULL; // represent the end of the list
		

		printf("Enter any number except 100 to create a list: \n");
		scanf("%d", &userInput);

		prevPlace = currentPlace; // preparation for the next heap memory
	}

	
	
}

void Targil4()
{
	struct place* currentPlace = head;
	while (currentPlace != NULL)
	{
		printf("number: %d\n", currentPlace->val);
		currentPlace = currentPlace->next;
	}
}

void Targil5()
{
	//find44
	struct place* currentPlace = head;
	int count44 = 0;
	while (currentPlace != NULL)
	{
		if (currentPlace->val == 44)
		{
			count44++;
		}
		currentPlace = currentPlace->next;
	}

	printf("count 44 : %d\n", count44);
}

void Targil6(int id)
{
	
	int Iteration = 1;
	struct place* currentItem = head;
	while (currentItem != NULL)
	{
		if (currentItem->val == id)
		{
			printf("position in the list: %d\n", Iteration);
		}
		Iteration++;
		currentItem = currentItem->next;
	}
}

void Targil7() {
	//save
	FILE* f = fopen("c:\\C-Class-Exercises\\Load.bun", "w");
	if (!f)
	{
		//error
		exit(1);
	}
}

void freeMemoryAllocHead()
{
	struct place* current = head;
	struct place* release = head;
	while (current != NULL)
	{
		release = current;
		free(release);
		current = current->next;
	}
	
}



int main_linkedlistexercises()
{

	//Targil1();
	//Targil2();
	//Targil3();
	//Targil4();
	//Targil5();
	//Targil6(5);
	//freeMemoryAllocHead();
	//3-Functions for exercise 7
	writeNewFile();
	save();
	Load();
	freeMemoryAllocRoot();

	return 0;
}

void writeNewFile()
{
	FILE* fp = fopen("c:\\C-Class-Exercises\\ques7Write.bin", "w");
	if (!fp)
	{
		printf("Error");
		return;
	}
	else
	{
		struct place pencil;
		pencil.val = ' ';
		while (pencil.val != 0)
		{
			printf("Enter Number To Val.\nTo Stop Press 0\nNumber: ");
			scanf("%d", &pencil.val);
			if (pencil.val == 0)
			{
				fclose(fp);
				return;
			}
			fwrite(&pencil.val, sizeof(struct place), 1, fp);
		}

		fclose(fp);
	}
	
}

void save()
{
	FILE* fr = fopen("c:\\C-Class-Exercises\\ques7Write.bin", "r");
	if (!fr)
	{
		printf("Error");
		return;
	}
	else
	{
		
		struct place* curr;
		struct place* prev = NULL;
		curr = (struct place*)malloc(sizeof(struct place));
		int num;

		while (num = fread(curr, sizeof(struct place), 1, fr))
		{
			if (num == 0)
			{
				fclose(fr);
				return;
			}

			if (root == NULL)
			{
				root = curr;
				prev = curr;
			}
			else
			{
				prev = curr;
				
			}

			curr = (struct place*)malloc(sizeof(struct place));
			prev->next = curr;
			curr->next = NULL;
		}
		fclose(fr);
	}
	
}

void Load()
{
	FILE* fw = fopen("c:\\C-Class-Exercises\\Load.bin", "w");
	if (!fw)
	{
		printf("Error");
		return;
	}
	else
	{
		struct place* print = root;
		while (print != NULL)
		{
			if (print->next == NULL)
			{
				return;
			}
			
			fwrite(&print->val, sizeof(struct place), 1, fw);
			print = print->next;
			
		}
	}
	

};


void freeMemoryAllocRoot() {
	struct place* current = root;
	struct place* release = root;
	while (current != NULL)
	{
		release = current;
		current = current->next;
		free(release);
	}
}
*/