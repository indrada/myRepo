#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{	
	int counter=0;
	node * tmp=head;
	if(head==NULL) return 0;
	while(tmp!=NULL){
		tmp=tmp->next;
		counter++;

	}
	return counter;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	node* tmp=head;
	int L = length(head);
	char* retVal=malloc(sizeof(char)*(L));
	for(int i=0;i<L;i++){
		*(retVal+i)=tmp->letter;
		tmp=tmp->next;

	}
	return retVal;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* tmp=*pHead;
	node* newNode=malloc(sizeof(node));
	newNode->letter=c;
	newNode->next=NULL;
	if(*pHead==NULL){
		*pHead=newNode;
		return;
	}
	while(tmp->next!=NULL){
		tmp=tmp->next;
	}

	tmp->next=newNode;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{

	node*tmp=*pHead;
	while(tmp->next!=NULL){
		node* nextPointer=tmp->next;
		free(tmp);
		tmp=nextPointer;
	}
	*pHead=NULL;
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