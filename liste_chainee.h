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
typedef struct element_t element_t;

struct element_t
{
	int value;
	int position;
	element_t * pNext;
};

/* list_t: list data type */
typedef struct list_t list_t;

struct list_t
{
	element_t * head;        /* Head of list */
	unsigned int length;     /* List's length */
};

/********** FUNCTIONS PROTOTYPES ***********/

/* Description: Create simple element                  */
/* Inputs:                                             */
/*  - val (int): value of element                      */
/*                                                     */
/* Outputs:                                            */
/*  -  pointer on new created element (element_t *) */
element_t * CreateElement( int val );

/* Description: Create a simple element and add to the list, at specified position  */
/* Inputs:                                             */
/*  - list (list_t *): list's pointer                  */
/*  - val (int): value of element                      */
/*  - pos ( unsigned int): position of element         */
/*                                                     */
/* Outputs:                                            */
/*  - number of displayed element (int)                */
unsigned int AddElement( list_t * list, int val, unsigned int pos );

/* Description: Delete element in list at specified position  */
/* Inputs:                                             */
/*  - list (list_t *): list's pointer                  */
/*  - pos (int): position of element                   */
/*                                                     */
/* Outputs:                                            */
/*  - number of list's elements (int)                  */
int DeleteElement( list_t * list, unsigned int pos );

/* Description: Delete list's elements                 */
/* Inputs:                                             */
/*  - list (list_t *): list's pointer                  */
/*                                                     */
/* Outputs:                                            */
/*  -  ERROR if error occured, OK otherwise (int)      */
int DeleteList( list_t * list );

/* Description: Display list's element's value at specified position */
/* Inputs:                                             */
/*  - list (list_t *): list's pointer                  */
/*  - pos (int): position of element                   */
/*                                                     */
/* Outputs:                                            */
/*  -                                                  */
void DisplayElement( list_t * list, unsigned int pos );

/* Description: Display list's Elements positions and values */
/* Inputs:                                             */
/*  - list (list_t *): list's pointer                  */
/*                                                     */
/* Outputs:                                            */
/*  - number of displayed element (int)                */
int DisplayList( list_t * list );


#endif /* LISTE_CHAINEE_H */
