/**
*\file list.h
*\brief Modelisation of a chained list
*\version 1.0
*\author Antoine GENOT
*\date 01 march 2015
*/

#ifndef LIST_H
#define LIST_H

typedef struct nodeList{
	int value;
	struct nodeList * next; 
}nodeList;

typedef struct{
     nodeList * first;
     nodeList * current;
	 nodeList * last;        
}list;

nodeList * newNodeList(int v, nodeList * n); //ok

/******** GROUPE 1 **********/
void printList(list * l);
void testList();

void initList(list * l);
int empty(list * l);
int first(list * l);
int last(list * l);
int outOfList(list * l);

void setOnFirst(list * l);
void setOnLast(list * l);
void next (list * l);
int getCurrent (list * l);

/******** GROUPE 2 **********/
int insertFirst(list * l, int v);
int insertLast(list * l, int v);
int insertAfterCurrent(list * l, int v);

int deleteFirst(list * l);
int deleteLast(list * l);
int deleteCurrent(list * l);
int find(list * l, int v);

/******** GROUPE 3 **********/
int deleteValue(list * l, int v);
void sort(list * l);

#endif
