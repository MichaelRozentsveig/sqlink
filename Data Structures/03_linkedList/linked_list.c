#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct Node* next;
}Node;

Node* flipList(Node* head) 	/*	Ex  1	*/
{
	Node* prevNode;
	Node* currentNode;

	if(head != NULL)
	{
		prevNode = head;
		currentNode = head->next;
		head = head->next;

		prevNode->next = NULL; 

		while(head != NULL)
		{
			head = head->next;
			currentNode->next = prevNode;

			prevNode = currentNode;
			currentNode = head;
		}
        head = prevNode; 
	}
	return head;
}


int middleList(Node* head)  /*	Ex 2	*/
{
	Node* doublejump ;
	Node* singlejump ; 
	
	doublejump = head;
	singlejump = head;
	if (checkCircles(head)==1)
	{
		return 0;
	}	

	while (doublejump!= NULL)
	{
		singlejump = singlejump->next;
		doublejump = doublejump->next->next;
	}
	return singlejump->value;
}

int checkCircles(Node* head) 	/*	 Ex 3   */
{
	Node* doublejump = malloc(sizeof(Node));
	doublejump = head;
	while ( doublejump->next->next != NULL)
	{
		doublejump = doublejump->next->next;
		head = head->next;
		if (doublejump->value == head->value)
		{
			return 1;
		}
	}
	return 0;
}

int getIntesectionNode(struct Node* head1, struct Node* head2) 
{ 
    int c1 = getCount(head1); 
    int c2 = getCount(head2); 
    int d; 
  
    if (c1 > c2) { 
        d = c1 - c2; 
        return _getIntesectionNode(d, head1, head2); 
    } 
    else { 
        d = c2 - c1; 
        return _getIntesectionNode(d, head2, head1); 
    } 
} 
  
/* function to get the intersection point of two linked 
   lists head1 and head2 where head1 has d more nodes than 
   head2 */
int _getIntesectionNode(int d, Node* head1, Node* head2) 
{ 
    int i; 
    Node* current1 = head1; 
    Node* current2 = head2; 
  
    for (i = 0; i < d; i++) { 
        if (current1 == NULL) { 
            return -1; 
        } 
        current1 = current1->next; 
    } 
  
    while (current1 != NULL && current2 != NULL) { 
        if (current1 == current2) 
            return current1->value; 
        current1 = current1->next; 
        current2 = current2->next; 
    } 
  
    return -1; 
} 
  
/* Takes head pointer of the linked list and 
   returns the count of nodes in the list */
int getCount( Node* head) 
{ 
    struct Node* current = head; 
    int count = 0; 
  
    while (current != NULL) { 
        count++; 
        current = current->next; 
    } 
  
    return count; 
} 



Node* makeList(int length)
{
	Node* head;
	Node* currentNode;
	int i=0;
	head = malloc (sizeof(Node));
	head->value = 4;
	head->next = NULL;
	currentNode = head;
	

	for (i = 1 ; i<length; i++)
	{
		currentNode->next = malloc (sizeof(Node));
		currentNode = currentNode->next;
		currentNode->value = i*6;
	}
	currentNode->next = NULL;
	
	return head;
}

void printList(Node* head)
{
	while (head!=NULL)
	{
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}

Node* makeLooplist(int length)
{
	Node* head;
	Node* currentNode;
	Node* loopNode;
	int i=0;
	head = malloc (sizeof(Node));
	head->value = 4;
	currentNode = head;
	

	for (i = 1 ; i<length; i++)
	{
		currentNode->next = malloc (sizeof(Node));
		currentNode = currentNode->next;
		currentNode->value = i*6;
	}

	currentNode->next = head;
	
	return head;
}

int main()
{
	int ans = 0;
	int size = 10;	
	Node* head;
	Node* head1;
	Node* head2;
	Node* current;
	Node* loopHead;
	Node* checkNode1;
	Node* checkNode2;

        head= makeList(size);
	loopHead = makeLooplist(size);
        current=head;

	printf("Regular list circle ans : %d\n", checkCircles(head));
	printf("Looped list circle ans : %d\n", checkCircles(loopHead));
	printf("Middle list: %d\n", middleList(head));

	printList(head);

	head = flipList(head);
	printList(head);

    	head1 = (Node*)malloc(sizeof( Node)); 
    	head1->value = 10; 
  
	head2 = (Node*)malloc(sizeof( Node)); 
	head2->value = 3; 

	checkNode1 = (Node*)malloc(sizeof( Node)); 
	checkNode1->value = 6; 
	head2->next = checkNode1; 

	checkNode1 = (Node*)malloc(sizeof( Node)); 
	checkNode1->value = 9; 
	head2->next->next = checkNode1; 

	checkNode1 = (Node*)malloc(sizeof( Node)); 
	checkNode1->value = 15; 
	head1->next = checkNode1; 
	head2->next->next->next = checkNode1; 

	checkNode1 = (Node*)malloc(sizeof( Node)); 
	checkNode1->value = 30; 
	head1->next->next = checkNode1; 

	head1->next->next->next = NULL; 
	
	printList(head1);
	printList(head2);

	printf("%d\n",getIntesectionNode(head1, head2));

}







