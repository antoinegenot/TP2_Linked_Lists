/**
*\file list.c
*\brief Modelisation of a chained list
*\version 1.0
*\author Antoine GENOT
*\date 01 march 2015
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

nodeList * newNodeList(int v, nodeList * n){
	nodeList * nouv = (nodeList*) malloc(sizeof(nodeList));
	if(nouv == NULL) return NULL;
	nouv->value = v;
	nouv->next = n;
	return nouv;
}

void printList(list * l){
	nodeList * tamp = l->current;
	printf("***** List : ");
	l->current = l->first;
	while(l->current != NULL){
		printf("%d ",l->current->value);
		l->current = l->current->next;
	}
	//REMETTRE CURRENT COMME AU DEPART
	l->current = tamp;
	printf("\n");
}

void initList(list * l){ l->first = l->last = l->current = NULL; }

int empty(list * l){ return l->first == NULL; }

int first(list * l){ return l->first == l->current; }

int last(list * l){ return l->last == l->current; }

int outOfList(list * l){ return l->current == NULL; }

void setOnFirst(list * l){ l->current = l->first; }

void setOnLast(list * l){ l->current = l->last; }

void next (list * l){ l->current = l->current->next; }

int getCurrent (list * l){ return l->current->value; }

int insertFirst(list * l, int v){
	nodeList * nouv;
	nouv = newNodeList(v, l->first);
	if(nouv == NULL)
		return 0;
	if(empty(l))
		l->last = l->current = nouv;	
	l->first = nouv;
	return 1;
}

int insertLast(list * l, int v){
	nodeList * nouv;
	nouv = newNodeList(v, NULL);
	if(nouv == NULL)
		return 0;
	if(empty(l))
		l->first = l->current = nouv;	
	l->last->next = nouv;
	l->last = nouv;
	return 1;
}
int insertAfterCurrent(list * l, int v){
	nodeList * nouv;
	nouv = newNodeList(v, l->current->next);
	if(nouv == NULL)
		return 0;
	if(empty(l)) {
		l->first = l->current = l->last = nouv;
		return 1;
	}
	if(l->first == l->last) l->last = nouv;
	l->current->next = nouv;
	return 1;
}

int deleteFirst(list * l){
	if(empty(l)) return -1;
	if(l->first == l->last){
		initList(l);
		return 0;
	}
	if(first(l)) next(l);
	l->first = l->first->next;
	return 1;
}

int deleteLast(list * l){
	if(empty(l)) return -1;
	if(l->first == l->last){
		initList(l);
		return 0;
	}
	if(last(l)) setOnFirst(l);
	while(l->current->next != l->last) next(l);
	l->current->next = NULL;
	l->last = l->current;
	return 1;
}

int deleteCurrent(list * l){
	nodeList * tamp;
	if(empty(l)) return -1;
	if(first(l)){ deleteFirst(l); return 1; }
	if(last(l)){ deleteLast(l); return 1; }
	tamp = l->current;
	setOnFirst(l);
	while(l->current->next != tamp) next(l);
	l->current->next = tamp->next;
	next(l);
	return 1;
}

int find(list * l, int v){
	if(empty(l)) return 0;
	setOnFirst(l);
	while(l->current->value != v && !outOfList(l)) next(l);
	if(outOfList(l)) return 0;
	return 1;
}

int deleteValue(list * l, int v){
	if(!find(l,v)) return 0;
	return deleteCurrent(l);
}

void sort(list * l){
	nodeList * first;
	if(!empty(l)){
		first = l->first;
		setOnFirst(l);
		next(l);
		while(l->first != l->last){
			while(!outOfList(l)){
				if(l->first->value > l->current->value){
					l->current->value += l->first->value;
					l->first->value = l->current->value - l->first->value;
					l->current->value -= l->first->value;
				}
				next(l);
			}
			l->first = l->first->next;
			l->current = l->first->next;
		}
		l->first = first;
		setOnFirst(l);
	}
}
