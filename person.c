#include "person.h"

#include <stdio.h>
#include <stdlib.h>

Person* createPerson(int src, int dest)
{
	Person* res = malloc(sizeof(Person));
	res->src = src;
	res->dest = dest;
	
	return res;
}

/*PersonList* createList()
{
	return NULL;
}*/

PersonList* insert(Person *p, PersonList *list)
{

	PersonList* res = malloc(sizeof(PersonList));		
	res->person = p;
	res->next = list;
	
	return res;

}
