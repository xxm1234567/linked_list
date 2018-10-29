#include "linked_list.h"
// create a new list item and add that to end of list int 
add_to_list(linked_list *ll, char * s) {
	linked_list * node, *p;
	// allocate a memory
	node = (linked_list *)malloc(sizeof(struct linked_list));
	if (node == NULL)
	{
		return -1;
	}
	// add node into list
	node->data = s;
	node->next = NULL;
	int index = 1;
	for (p = ll; p->next != NULL; p = p->next, index++);
	p->next = node;
	node->index = index;
	return index;
}
// displays the required element int display_item(linked_list *ll) {
	if(!ll) return -1;
	else{
		printf("\nIndex %d: %s\n", ll->index, ll->data);
		return 0;
	}
}
// list all element in a list int display_list(linked_list *ll) {
	int index = 0;
	linked_list *p;
	for (p = ll; p->next != NULL; p = p->next, index++)
	{
		// print each element
		printf("%s\n", p->next->data);
	}
	printf("\n");
	return index;
}
// search for data from a list linked_list * 
search_from_list(linked_list *ll, char *s) {
	
	linked_list *p;
	for (p = ll; p->next != NULL; p = p->next)
	{
		// find the s
		if (strcmp(s, p->next->data) == 0)
		{
			return p->next;
		}
	}
	return NULL;
}
// delete item from a list and free space int 
delete_from_list(linked_list *ll, int index) {
	linked_list *p, *q;
	int i;
	// find the index-th element
	i = 0;
	for (p = ll; p->next != NULL; p = p->next)
	{
		if (i == index)
		{
			break;
		}
		i++;
	}
	if (p->next == NULL)
	{
		return -1;
	}
	q = p->next->next;
	free(p->next);
	p->next = q;
	return linkedlist_status(ll);
}
