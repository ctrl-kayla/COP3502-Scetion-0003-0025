/* Kayla Butler
COP 3502 Section 3
Lab Assignment #4
8 February 2024 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int numNodes = 0; // Initialize number of nodes in linked list to 0

	node *temp = head; // Initalize temporary pointer to head

	while (temp != NULL)
	{
		numNodes++; // Increment number of nodes
		temp = temp -> next; // Traverse to next node
	}

	return numNodes; // Return numbe rof nodes in linked list
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int len = length(head); // Call length function to get length of list/string

	/* Allocate memory for length of string. 
	Get length of string from number of nodes in linked list*/
	char * str = (char*)malloc((len + 1)* sizeof(char));

	node * temp = head; // Initalize temporary pointer to head
 
	int index = 0; // Initialize first index of string to 0.
	while (temp != NULL)
	{
		str[index] = temp -> letter; // Copy char in each node to correspinding index in string
		temp = temp -> next; // Traverse through list
		index ++;
	}


	return str; // Return string

}

// inserts character to the linkedlist
// if the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as follows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{

	node * newNode = (node*)malloc(sizeof(char)); // Allocate memory for new node
	newNode -> next = NULL;

	node ** temp = pHead; // Initalize temporary pointer to pHead

	while (*temp != NULL)
		{
			temp = &((*temp) -> next); // Traverse to end of list
		}
	// temp -> next is currently NULL.
	*temp = newNode; // Inserts newNode at end of linked list
	// No need to initalize newNode -> next to NULL because of '\0'
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	// All nodes in the linked list are deallocated one by one.
	node * current = pHead; // Initalize current node to pHead
	node * next;

	while (current != NULL)
	{
		node* next = current -> next; // Store next node
		free(current); // Dealloate memory for current node
		current = next; // Traverse to next node
	}

	*pHead = NULL; // Update head to show list is empty
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}