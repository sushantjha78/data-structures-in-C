
void quick_sort_doubly_linked(double_node * front, double_node * back)
{
	double_node *i, *j, *prev, *next, *temp;
	int count_i = 0, count_j = 0;
	i = front;
	j = front;
	while (i -> next != back && j -> next != back)//check edge cases
	{
		while(i != back && i->entry > front -> entry)
		{
			i = i -> next;
			count_i++;
		}
		while(j != back && j->entry < front -> entry)
		{
			j = j -> next;
			count_j++;
		}
		if (count_i > count_j)
		{
			temp -> entry = i -> entry;
			i -> entry = j -> entry;
			j -> entry = temp -> entry;
		}
	}
	temp -> entry = j -> entry;
	j -> entry = front -> entry;
	front -> entry = j -> entry;
	quick_sort_doubly_linked(front, j);
	quick_sort_doubly_linked(j -> next, back);
}



void merge_sort(Node * front)
{
	Node *f_p, *b_p, *temp;
	int count_i = 0, count_j = 0;
	f_p = front;
	b_p = front;
	while (f_p -> next != NULL)
	{
		f_p = f_p -> next;
		if (f_p -> next != NULL)
		{
			f_p = f_p -> next;
			b_p = b_p -> next;
		}
	}
	temp = b_p;
	b_p = b_p -> next;
	temp -> next = NULL;
	merge_sort(front);
	merge_sort(b_p);
	sorted_merge(front, b_p);
}
