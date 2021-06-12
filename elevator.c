#include "elevator.h"
#include "person.h"

#include <stdio.h>
#include <stdlib.h>

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons)
{
	// creates an elevator
	Elevator *res = malloc(sizeof(Elevator));
	res->capacity = capacity;
	res->currentFloor = currentFloor;
	res->persons = persons;
	
	return res;
	
}

Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists)
{
	// creates a building
	Building *res = malloc(sizeof(Building));
	res->nbFloor = nbFloor;
	res->elevator= elevator;
	res->waitingLists = waitingLists;
	
	return res;
}

int nbPersons(Elevator *e)
{
        //local function that counts the nb of persons in the elevator
        int res = 0;
        PersonList *temp = e->persons;//copy of the list of persons in the elevator
        while(temp != NULL)
        {
                res++;
                temp = temp->next;
        }
        return res;
}

PersonList* exitElevator(Elevator *e)
{	
	/* this function returns a list of persons exiting the elevator and updates the list 
	of persons in the elevator with the remaing persons */
	
	PersonList* res = NULL;
	PersonList* remainingPersons = NULL;
	PersonList* temp = e->persons;
	int nbPersonsInE = nbPersons(e); // number of persons in the elevator
	
	if(temp != NULL) // people can exit only if the elevator is not empty
	{
		for(int i = 0; i < nbPersonsInE; i++) //only people in the elevator can exit
		{
			if(temp->person->dest == e -> currentFloor)
			{
				// keep in mind  leaving persons
				res = insert(temp->person, res);
			}
			else
			{
				/*keep also in mind remaining people to update the persons 
				in the elevator*/
			
				remainingPersons = insert(temp->person, remainingPersons);
			}
	
			temp = temp->next;		
		}
	
		if(res != NULL)
		{
			/*update the list of persons in the elevator with the list of remaining persons
			but only if some persons have exit the elevator	*/
	
			e->persons = remainingPersons;
		}
	
	}
	
	return res;// will directly return NULL if the elevator is empty
}


PersonList* enterElevator(Elevator *e, PersonList *waitingList)
{
	// this function lets people enter in the elevator and returns an updated waitinList
	
	for(int cpt = nbPersons(e); cpt < e->capacity; cpt++)
	{	/* fills the elevator starting from the head of the waitingList if it is not
			empty and if the elevator is not full */
		
		if(waitingList != NULL)	
		{
			e->persons = insert(waitingList->person, e->persons);		
		
			waitingList = waitingList->next;
		}
	}
	
	return waitingList;

}


void stepElevator(Building *b)
{
	// simulate the movement of the elevator
	
	if(b->elevator->targetFloor > b->elevator->currentFloor)
	{
		// move upwards
		b->elevator->currentFloor++;
	}
	else 	if(b->elevator->targetFloor ==  b->elevator->currentFloor)
		{
			// let people enter and exit the elevator
			if(b->elevator->persons != NULL)
			{
				exitElevator(b->elevator);
			}
			if (b->waitingLists[b->elevator->currentFloor] != NULL)
			{
				// let people enter and update the new waitingList
				b->waitingLists[b->elevator->currentFloor] = enterElevator(
					b->elevator, b->waitingLists[b->elevator->currentFloor]
					);
			}
		}
	else
	{
		b->elevator->currentFloor--;
	}
}

