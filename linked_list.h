#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <stdlib.h>
#include<string.h>
#include <stdio.h>


typedef struct linked_list linked_list;

// defination of struct linked_list
struct linked_list
{
	char * data;
	int index;//not used
	struct linked_list * next;
	struct linked_list * prior;

};

// create a new list item and add that to end of list
int add_to_list(linked_list *ll, char * s);

// displays the required element
int display_item(linked_list *ll);

// list all element in a list
int display_list(linked_list *ll);

// search for data from a list
linked_list * search_from_list(linked_list *ll, char * s);

// delete item from a list and free space
int delete_from_list(linked_list *ll, int index);

// remove all items from the list and free memory
int empty_list(linked_list *ll);

// swap order of two items
int swap_items(linked_list *ll, linked_list *f, linked_list * s);

// sort list in rising order based on data
int sort_list(linked_list *ll);

// count the number of elements in the list
int linkedlist_status(linked_list *ll);

#endif // !_LINKEDLIST_H_

