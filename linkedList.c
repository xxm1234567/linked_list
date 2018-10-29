#include "linked_list.h"



// create a new list item and add that to end of list
int add_to_list(linked_list *ll, char * s)
{
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

// displays the required element
int display_item(linked_list *ll)
{
	if(!ll) return -1;
	else{
		printf("\nIndex %d:  %s\n", ll->index, ll->data);
		return 0;
	}
}


// list all element in a list
int display_list(linked_list *ll)
{
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

// search for data from a list
linked_list * search_from_list(linked_list *ll, char *s)
{
	
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

// delete item from a list and free space
int delete_from_list(linked_list *ll, int index)
{
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

// remove all items from the list and free memory
int empty_list(linked_list *ll)
{
	linked_list *p, *q;
	int num;

	num = 0;
	p = ll->next;
	// empty list
	if (p == NULL)
	{
		return 0;
	}
	while (1)
	{
		q = p->next;
		// free the space
		free(p);
		num++;
		if (q == NULL)
		{
			break;
		}
		p = q;
	}
	return num;
}

// swap order of two items
int swap_items(linked_list *ll, linked_list *f, linked_list * s)
{
	linked_list *pf, *ps, *tf, *ts;

	// find the piror of the f and s
	for (pf = ll; pf->next != NULL; pf = pf->next)
	{
		if (pf->next == f)
		{
			break;
		}
	}
	for (ps = ll; ps->next != NULL; ps = ps->next)
	{
		if (ps->next == s)
		{
			break;
		}
	}
	if (pf->next != f || ps->next != s)
	{
		return -1;
	}

	// exchange
	tf = f->next;
	ts = s->next;
	pf->next = s;
	ps->next = f;
	s->next = tf;
	f->next = ts;


	return 0;
}

// sort list in rising order based on data
int sort_list(linked_list *ll)
{
	linked_list *q, *t;
	int end;
	if (ll->next == NULL || ll->next->next == NULL)
	{
		return 0;
	}
	// bubble sort
	do
	{
		end = 1;
		for (q = ll; q->next->next != NULL; q = q->next)
		{
			if (strcmp(q->next->data, q->next->next->data) > 0)
			{
				t = q->next->next;
				q->next->next = t->next;
				t->next = q->next;
				q->next = t;
				end = 0;
			}
		}
	} while (end != 1);

	return 0;
}

// count the number of elements in the list
int linkedlist_status(linked_list *ll)
{
	linked_list *p;
	int i;
	i = 0;
	for (p = ll; p->next != NULL; p = p->next)
	{
		// count increase
		i++;
	}
	return i;
}


