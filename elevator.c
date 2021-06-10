#include "elevator.h"
#include "person.h"

#include <stdio.h>
#include <stdlib.h>

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons)
{
	Elevator *res = malloc(sizeof(Elevator));
	res->capacity = capacity;
	res->currentFloor = currentFloor;
	res->persons = persons;
	
	return res;
	
}

Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists)
{
	Building *res = malloc(sizeof(Building));
	res->nbFloor = nbFloor;
	res->elevator= elevator;
	res->waitingLists = waitingLists;
	
	return res;
}


PersonList* exitElevator(Elevator *e)
{	PersonList* curr = e->persons;
	while(curr->next)
	{
		if((curr->person->dest) == e-)
		{
			
		}
	}
	
}
PersonList* enterElevator(Elevator *e, PersonList *list)
{
	

}


void stepElevator(Building *b)
{
	if(b->elevator->targetFloor > b->elevator->currentFloor)
	{
		b->elevator->currentFloor++;
	}
	else 	if(b->elevator->targetFloor ==  b->elevator->currentFloor)
		{
			// appeler les fonctions exit et enter
			exitElevator(b->elevator);
			enterElevator(b->elevator);
		}
	else
	{
		b->elevator->currentFloor--;
	}
	
}

