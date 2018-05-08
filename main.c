/*****************************************************************************/
/*                                                                           */
/* File name: main.c                                                         */
/* Author: W.Bastat                                                          */
/* Date of creation: 07.05.2018                                              */
/* Date of Last Modification: 07.05.2018                                     */
/*                                                                           */
/*****************************************************************************/

/* INCLUSIONS */
#include "liste_chainee.h"

/********** MAIN PROGRAM FUNCTION **********/

int main(int argc, char ** argv)
{
	struct list_t list;
	list.length = 0;
	int nb = 0;
	AddElement(&list, 68, 0);
	AddElement(&list, 69, 1);
	AddElement(&list, 70, 2);
	AddElement(&list, 71, 3);
	DisplayList(&list);
	DeleteElement(&list, 2);
	DisplayList(&list);
	DeleteList(&list);


	return EXIT_SUCCESS;
}