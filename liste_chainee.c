/*****************************************************************************/
/*                                                                           */
/* File name: liste_chainee.c                                                */
/* Author: W.Bastat                                                          */
/* Date of creation: 07.05.2018                                              */
/* Date of Last Modification: 07.05.2018                                     */
/*                                                                           */
/*****************************************************************************/

/*********** INCLUDES ***********/
#include "liste_chainee.h"

 /* FUNCTIONS IMPLEMENTATIONS */
struct element_t * CreateElement( int val )
{
	struct element_t * newElement;
	newElement = malloc(sizeof(newElement));	
	newElement->value = val;
	newElement->pNext = NULL;
	return newElement;
}

unsigned int AddElement( struct list_t * list, int val, unsigned int pos )
{
	/* Check if the element can be placed at the desired position in the list */
	struct element_t * element, * newElement;
	/* Initialise element with first element of list */
	element = list->head;
	/* If the position is superior than list's length, can't place the element */
	if ( pos > list->length )
	{
		printf("New element can't be placed at position n°: %d, because there is(are) %d element(s) in the list.\n", pos, list->length);
		return ERROR;
	}
	else
	{
		/* If the list is empty */
		if ( list->length == 0 )
		{
			/* Create element  and add element at the beginning */
			list->head = CreateElement( val );
			/* Set Element's position */
			list->head->position = pos;
			list->head->pNext = NULL;
			/* Display result */
			printf("New element created and placed at position n°: %d, value: %d\n", pos, val);
		}

		else
		{
			/* Create element */
			newElement = CreateElement( val );
			/* Set Element's position */
			newElement->position = pos;
			/* Look for the list's element with the position "pos - 1" */
			/* This one will be shift right after the new one */
			/* Initialise element with first element of list */
			element = list->head;
			/* While there's no element with NULL value, display position and value */
			while(element->position != (pos -1))
			{ 
				/* Point to the next element of the list */
				element = element->pNext;
			}
			/* The new element ( at position pos) has be to be linked with the actual one at the position "pos" */
			newElement->pNext = element->pNext;

			/* The element pos - 1 has to be linked with the new one */
			element->pNext = newElement;


			/* Each element after the new pos has thier position to be incremented */
			element = newElement->pNext;
			while(element)
			{ 
				/* Increment position */
				element->position++;
				/* Point to the next element of the list */
				element = element->pNext;
			}

			printf("New element created and placed at position n°: %d, value: %d\n", pos, val);
		}
	}
	/* Increment list's length */
	list->length++;
	/* return list's length */
	return list->length;
}

int DeleteElement( struct list_t * list, unsigned int pos )
{
	struct element_t * element = NULL;
	struct  element_t * elementToDel = NULL;
	/* If there's a element in the list with the specified position */
	if( pos < list->length )
	{
		/* If delete first list's element */
		if( pos == 0 )
		{
			/* Attach to the element to delete before reconnection */
			elementToDel = list->head;
			/* Link head to the 2nd element */
			list->head = list->head->pNext;
			element = list->head;
		}
		else
		{
			/* Search for the element just before the one at position "pos" */
			element = list->head;
			while( element->position != (pos - 1) )
			{
				element = element->pNext;
			}
			/* Attach to the element to delete before reconnection */
			elementToDel = element->pNext;
			/* Link the previous element to the next one */
			element->pNext = element->pNext->pNext;
			/* Go to "the next" one (at position "pos") */
			element = element->pNext;
		}
		/* Decrement position values of each element after the delete one */
		while( element )
		{

			element->position--;
			element = element->pNext;
		}
		/* Delete the element */
		free(elementToDel);

	/* Decrement list's length */
	list->length--;
	printf("Deleting element at position n°: %d\n", pos);
	}
	else
	{
		printf("Can't delete element at position n°: %d, because there is(are) %d element(s) in the list.\n", pos, list->length);
		return ERROR;		
	}
	/* Return list's length */
	return list->length;
}

int DeleteList( struct list_t * list )
{
	struct element_t * element = NULL;
	element = list->head;
	while(element)
	{
		printf("Deleting element at position n°: %d\n", element->position);
		free(element);
		element = element->pNext;
	}
	return OK;
}

int DisplayList( struct list_t * list )
{
	struct element_t * element = NULL;
	/* Initialise element with first element of list */
	element = list->head;
	/* While there's no element with NULL value, display position and value */
	while(element)
	{
		/* Display position (ie. nbElements value) and value */
		printf("Position: %d, value: %d\n", element->position, element->value);
		/* Point to the next element of the list */
		element = element->pNext;
	}
	/* When every element of the list has been displayed, return the number of elements */
	return list->length;
}