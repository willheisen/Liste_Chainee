/*****************************************************************************/
/*                                                                           */
/* File name: liste_chainee.h                                                */
/* Author: W.Bastat                                                          */
/* Date of creation: 07.05.2018                                              */
/* Date of Last Modification: 07.05.2018                                     */
/*                                                                           */
/*****************************************************************************/

#ifndef LISTE_CHAINEE_H
#define LISTE_CHAINEE_H

/********** INCLUDES **********/
#include "stdlib.h"
#include "stdio.h"

/*********** CONSTANTS ***********/
#define OK     0            /* No errors occured */
#define ERROR -1            /* Error occured */

/*********** DATA TYPES ***********/
/* element_t: basic element data type */
struct element_t
{
	int value;
	int position;
	struct element_t * pNext;
};

/* list_t: list data type */
struct list_t
{
	struct element_t * head; /* Head of list */
	unsigned int length;     /* List's length */
};

/********** FUNCTIONS PROTOTYPES ***********/

/* Description: Create simple element                  */
/* Inputs:                                             */
/*  - val (int): value of element                      */
/*                                                     */
/* Outputs:                                            */
/*  -  pointer on new created element (struct element_t *) */
struct element_t * CreateElement( int val );

/* Description: Create a simple element and add to the list, at specified position  */
/* Inputs:                                             */
/*  - list (struct list_t *): list's pointer           */
/*  - val (int): value of element                      */
/*  - pos ( unsigned int): position of element         */
/*                                                     */
/* Outputs:                                            */
/*  - number of displayed element (int)                */
unsigned int AddElement( struct list_t * list, int val, unsigned int pos );

/* Description: Delete element in list at specified position  */
/* Inputs:                                             */
/*  - list (struct list_t *): list's pointer           */
/*  - pos (int): position of element                   */
/*                                                     */
/* Outputs:                                            */
/*  - number of list's elements (int)                  */
int DeleteElement( struct list_t * list, unsigned int pos );

/* Description: Delete list's elements                 */
/* Inputs:                                             */
/*  - list (struct list_t *): list's pointer           */
/*                                                     */
/* Outputs:                                            */
/*  -  ERROR if error occured, OK otherwise (int)      */
int DeleteList( struct list_t * list );

/* Description: Display list's Elements positions and values */
/* Inputs:                                             */
/*  - list (struct list_t *): list's pointer           */
/*                                                     */
/* Outputs:                                            */
/*  - number of displayed element (int)                */
int DisplayList( struct list_t * list );


#endif /* LISTE_CHAINEE_H */
