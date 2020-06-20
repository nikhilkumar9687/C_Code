/* This file contains operations on Linked List
 * it includes operation like :
 * 1. creating a node
 *
 */


#include <stdio.h>
#include <stdlib.h>


struct Node
{
	int data;
	struct Node *next;
};

void Display( struct Node *node)
{
	while(node != NULL)
	{
		printf("%d->", node->data);
		node = node->next;
	}
	printf("\n");

}


void append(struct Node **head_ref)
{
	/*
	 ******************************************************
	 *   Append is to add a node at last of the list      *
	 *   THIS CAN ALSO BE USED TO CREATE A NEW LINKED LIST*
	 ******************************************************   
	 *   it has 7 steps,
	 *  step 1. take a new node "temp"
	 *  step 2. take a struct Node pointer last 
	 *          to hold the head node ref(*head_ref) (*last = *head_ref)
	 *  step 3. put the data to the newly created node (temp->data = data)
	 *  step 4. put the next of temp to NULL (temp->next = NULL)
	 *  step 5. check if List is Empty if TRUE temp is the 1st node,
	 *          hence, head reference should point to temp
	 *          i.e.(*head_ref = temp)
	 *  step 6. else traverse the node by using 
	 *          the last pointer till the end of the list
	 *  step 7. change the next of last to newly created node   
	 */ 

	/* Step 1.*/
	int data;
	struct Node *new_node = NULL;
	new_node = (struct Node *) malloc (sizeof(struct Node));

	/* Step 2.*/
	struct Node *last = *head_ref;

	/* Step 3.*/
	printf("Enter the data for new node\n");
	scanf("%d",&data);

	new_node->data = data;

	/* Step 4.*/
	new_node->next = NULL;

	/* Step 5 : if list is Empty make head_ref point to new_node*/
	if (*head_ref == NULL)
		(*head_ref) = new_node;
	else/*Step 6:*/
	{
		/* traverse till the last of list to add new_node*/
		while(last->next != NULL)
			last = last->next;
		/*Step 7:*/	
		last->next = new_node;
	}


}


void insertany(struct Node **head_ref, int pos)
{
	int data;
	struct Node *new_node = NULL;
	struct Node *temp = (*head_ref);

	new_node = (struct Node *)malloc(sizeof(struct Node));

	printf("Enter the data for new node\n");
	scanf("%d",&data);
	
	if (*head_ref == NULL)
		append(&(*head_ref));
	else
	{
		do
		{
			if(pos == 0)
			{

				new_node->data = data;
				new_node->next = (*head_ref);
				(*head_ref) = new_node;

			}
			else
				head_ref = &(*head_ref)->next;
		}
		while (pos--);
	}

}


void main()
{
	int num_node, i, pos = 0;
	struct Node *head = NULL;

	
	printf("Enter number of nodes to create for the linked list\n");
	scanf("%d",&num_node);
        
	/* Creating a new linked list */
	for (i = 0; i < num_node; i++)
		append(&head);
	
	printf("Enter the position to insert a node in linked list\n");
	scanf("%d",&pos);
        

	insertany(&head,(pos - 1));
	Display(head);


}

