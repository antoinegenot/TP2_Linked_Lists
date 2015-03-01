/**
*\file main.c
*\brief Modelisation of a chained list
*\version 1.0
*\author Antoine GENOT
*\date 01 march 2015
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	/******** GROUPE 1 **********/
	/* Tests sur une liste vide */
	list l;		// liste vide
	list l1;	// liste remplie
	list l2;    // liste à trier

	initList(&l);
	printf("Affichage d'une liste vide \n");
	printList(&l);
	printf("Element courant hors de la liste ? (Oui=1/Non=0) %d \n", outOfList(&l));

	printf("Test si une liste est vide \n");
	printf("Si liste vide 1, sinon 0. \nResultat = %d \n\n",empty(&l));

	/* Tests sur une liste remplie manuellement */
	initList(&l1);
	l1.last = newNodeList(5, NULL);
	l1.current = newNodeList(3, l1.last);
	l1.first = newNodeList(1, l1.current);
	
	printf("Affichage d'une liste remplie \n");
	printList(&l1);
	printf("Element courant hors de la liste ? (Oui=1/Non=0) %d \n", outOfList(&l1));
	printf("Courant : %d \n",getCurrent(&l1));
	setOnFirst(&l1);
	printf("Courant (apres un setOnFirst) %d \n",getCurrent(&l1));
	next(&l1);
	printf("Courant (apres un next) : %d \n",getCurrent(&l1));
	setOnLast(&l1);
	printf("Courant (apres un setOnLast %d \n\n",getCurrent(&l1));

	/******** GROUPE 2 **********/
	insertFirst(&l1, 0);
	printList(&l1);
	insertLast(&l1, 7);
	printList(&l1);
	insertAfterCurrent(&l1, 6);
	printList(&l1);

	printf("test sur liste vide de delete : %d \n", deleteFirst(&l));
	insertFirst(&l, 19);
	printList(&l);
	printf("test sur liste vide de delete : %d \n", deleteFirst(&l));
	printList(&l);
	printf("test sur liste vide de delete : %d \n", deleteFirst(&l1));
	printList(&l1);
	printf("Courant : %d \n",getCurrent(&l1));
	deleteCurrent(&l1);
	printList(&l1);

	/******** GROUPE 3 **********/
	printf("\n");
	initList(&l2);
	insertFirst(&l2, 4);
	insertAfterCurrent(&l2, 1);
	insertLast(&l2, 3);
	//printf("%d %d %d \n", l2.first->value, l2.current->value, l2.last->value);
	insertLast(&l2, 0);
	insertLast(&l2, 2);
	printList(&l2);
	sort(&l2);
	//printf("%d %d %d \n", l2.first->value, l2.current->value, l2.last->value);
	printList(&l2);
	system("PAUSE");
	return EXIT_SUCCESS;
}
