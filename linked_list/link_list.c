//Given a singly linked list split it into two lists of equal or almost equal 
//size. First half will be the front list and second half will be the back list.

#include<stdio.h>
#include<stdlib.h>

typedef int list_entry;
typedef struct node
{
	list_entry entry;
	struct node * next;
}Node;

typedef struct double_node
{
	list_entry entry;
	struct double_node * prev, * next;
}double_node;

Node * create_node(list_entry entry);
void print_link_list(Node * header);
Node * insert_begin(Node * header, list_entry entry);
Node * insert_end(Node * header, list_entry entry);
Node * input_to_link(Node *header);

Node * split_in_half(Node * header);
void remove_duplicates(Node * header);
void del_mth_last(Node * header, int m);
Node * insertion_sort(Node *header);
int length_of_link(Node * header);
Node * split_alterate(Node * header1);
Node * shuffle_merge(Node * header1, Node  *header2);
void sorted_merge(Node * header1, Node  *header2);
Node * set_and(Node * header1, Node  *header2);
Node * set_or(Node * header1, Node  *header2);
Node * set_or_not(Node * header1, Node  *header2);
Node * set_and_not(Node * header1, Node  *header2);
Node * reverse_recursive(Node *prev, Node *curr, Node * next);
int check_palindrome(Node * header, Node * front);
void merge_sort(Node * front);
int check_cyclic(Node * header);

void print_doubly_link_list(double_node *header3);
double_node * create_node_doubly_linked(list_entry entry);
double_node * insert_begin_doubly_linked(double_node * header, list_entry entry);
double_node * insert_end_doubly_linked(double_node * header, list_entry entry);
double_node * create_node_doubly_linked(list_entry entry);
double_node * insert_begin_doubly_linked(double_node * header, list_entry entry);
double_node * insert_end_doubly_linked(double_node * header, list_entry entry);
double_node * reverse_doubly_linked(double_node * header );
void quick_sort_doubly_linked(double_node * front, double_node * back);
void split_half_list(Node * entry);


int main()
{
	Node * header, * header2;
	double_node *header3;
	int ch = -1, y_n;
	list_entry data;
	header = NULL;
    printf("\n 0: Print Linked List");
	printf("\n 1: Insert at beginning");
	printf("\n 2: Insert at end");
	printf("\n 3: split half the list");
	printf("\n 4: Remove duplicates");
	printf("\n 5: Remove mth last element");
	printf("\n 6: Insertion sort");
	printf("\n 7: Split alternate node");
	printf("\n 8: Merge alternate node");//code end case
	printf("\n 9: Merge sorted list in order");//code logical error
	printf("\n 10: Intersection of sorted lists");
	printf("\n 11: Set operations on lists");
	printf("\n 12: Reverse a doubly linked list");
	printf("\n 13: Reverse a singly linked list");
	printf("\n 14: Quick sort on doubly linked list");
	printf("\n 15: Check if list is palindrome");
	printf("\n 16: Merge sort on singly linked list");
	printf("\n 17: List is cyclic or not");
	printf("\n 99: Exit\n");
    while(ch != 99)
	{
		printf("\nEnter your choice\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 0: 
				print_link_list(header);
				break;
			case 1:
				printf("Enter the element to be inserted in the linked list\n");
				fflush(stdin);
				scanf("%d", &data);
				header = insert_begin(header, data);
				print_link_list(header);
				break;
			case 2:
				printf("Enter the element to be inserted in the linked list");
				fflush(stdin);
				scanf("%d", &data);
				header = insert_end(header, data);
				print_link_list(header);
				break;
			case 3:
				header2 = split_in_half(header);
				print_link_list(header);
				print_link_list(header2);
				break;
			case 4:
				remove_duplicates(header);
				print_link_list(header);
				break;
			case 5: 
				printf("Enter the index from last to be deleted from the linked list");
				fflush(stdin);
				scanf("%d", &data);
				del_mth_last(header, data);
				print_link_list(header);
				break;
				
			case 6:
				//insertion_sort();
				header = insertion_sort(header);
				print_link_list(header);
				break;
				
			case 7:
				header2 = split_alterate(header);
				print_link_list(header);
				print_link_list(header2);
				break;
				
			case 8:
				header2 = input_to_link(header2);
				header = shuffle_merge(header, header2);
				print_link_list(header);
				print_link_list(header2);
				break;
				
			case 9:
				header2 = input_to_link(header2);
				sorted_merge(header, header2);
				print_link_list(header);
				break;
				
			case 10:
				header2 = input_to_link(header2);
				print_link_list(set_and(header, header2));
				break;
				
			case 11:
				header2 = input_to_link(header2);
				print_link_list(set_and(header, header2));
				print_link_list(set_or(header, header2));
				print_link_list(set_or_not(header, header2));
				print_link_list(set_and_not(header, header2));
				break;
				
			case 12:
				//required
				header3 = reverse_doubly_linked(header3);
				print_doubly_link_list(header3);
				break;
			
			case 13:
				header = reverse_recursive(NULL, header, NULL);
				print_link_list(header);
				break;
				
			case 14:
				//required
				quick_sort_doubly_linked(header3, NULL);
				print_doubly_link_list(header3);
				break;
				
			case 15:
				y_n = check_palindrome(header, header);
				if (y_n == 0){printf("its not a palindrome");}
				else{printf("its a palindrome");}
				break;
				
			case 16:
				merge_sort(header);
				print_link_list(header);
				break;
				
			case 17:
				y_n = check_cyclic(header);
				if (y_n == 0){printf("its not cyclic");}
				else{printf("its cyclic");}
				break;

			default: 
				printf("Wrong choice");
		}
	}

    return 0;
}

Node * create_node(list_entry entry)
{
	Node * p;
	p = (Node *)malloc(sizeof(Node));
	p->entry = entry; 
	p->next = NULL;
	return(p);
}

Node * insert_begin(Node * header, list_entry entry)
{
	Node * p;
	p = create_node(entry);//changed
    p->next = header;
    header = p;
	return(header);
}

Node * insert_end(Node * header, list_entry entry)
{
	Node *p, * curr;
	p = create_node(entry);
	if(header == NULL)
	{
		header = p;
	}
	else
	{
		curr = header;
		while(curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = p;
	}
	return(header);	
}

void print_doubly_link_list(double_node * header)
{
	double_node * curr;
	if(header == NULL)
	{
		printf("Linked list is empty");
	}
	else
	{
		curr = header;
		while(curr != NULL)
		{
			printf("%d ->", curr->entry);
			curr = curr->next;
		}
		printf("NULL");
	}
}	

void print_link_list(Node * header)
{
	Node * curr;
	if(header == NULL)
	{
		printf("Linked list is empty");
	}
	else
	{
		curr = header;
		while(curr != NULL)
		{
			printf("%d ->", curr->entry);
			curr = curr->next;
		}
		printf("NULL");
	}
}		


Node * input_to_link(Node *header2)
{
	int n;
	list_entry entry;
	printf("enter the second link list length\n");
	scanf("%d", &n);
	fflush(stdin);
	printf("enter the elements\n");
	for (int i ; i<n ; i++)
	{
		scanf("%d", &entry);
		fflush(stdin);
		header2 = insert_end(header2, entry);
	}
	return header2;
}

//started here////
Node * split_in_half(Node * header)
{
	Node * curr1, *curr2, *header2 = NULL;
	int length , i;
	if(header == NULL)
	{
		return header2;
	}
	else
	{
		curr1 = header;
		while(curr1 != NULL)
		{
			length++;
			curr1 = curr1 -> next;
		}
		curr1 = header;
		i = 0;
		while(i< (length/2)-1)
		{
			curr1 = curr1 -> next;
		}
		curr2 = curr1 -> next;
		curr1 -> next =NULL;
	}
    return header2;
}

void remove_duplicates(Node * header)
{
	Node * curr1, *curr2;
	curr1 = header;
	curr2 = header->next;
	while(curr1->next != NULL)
	{
		while(curr2 -> next != NULL)
		{
			if (curr1->entry == curr2->entry)
			{
				curr2 = curr2->next;
			}
		}
		if (curr1 -> next == NULL)
		{
			curr1 -> next = NULL;
		}
		curr1->next = curr2;
		curr1 = curr1 -> next;
		curr2 = curr2 ->next;
	}
}


void del_mth_last(Node * header, int m)
{
	Node  *curr_front;
	curr_front = header;
	for(int i = 0; i<m+1 ; i++)
	{
		curr_front = curr_front->next;
	}
	while(curr_front->next != NULL)
	{
		curr_front = curr_front->next;
		header = header->next;
	}
	header->next = header->next->next;
}

int length_of_link(Node * header)
{
	Node * curr = header;
	int count = 0;
	while( curr->next != NULL)
	{
		curr = curr-> next;
		count++;
	}
	return count;
}

Node * insertion_sort(Node *header)
{
	Node * p, *curr_main, *curr_back;
	for (int i = 0 ; curr_main->next != NULL; i++)
	{
		while(curr_back->next != NULL)
		{
			for(int j = 0; j<i ; j++)
			{
				curr_back = curr_back->next;
			}
		}
	}
	return(header);
}
Node * split_alterate(Node * header)
{
	Node * curr1, *curr2, *header2 = NULL;
	if(header == NULL)
	{
		return header2;
	}
	else
	{
		curr1 = header;
        header2 = header->next;
		while(curr1->next != NULL && curr1->next->next != NULL)
		{
            curr2->next = curr1->next;
            curr2 = curr2->next;
            curr1->next = curr2->next;
			curr1 = curr1->next;
		}
        curr2->next = curr1->next;
		curr1->next = NULL;
	}
    return header2;
}

Node * shuffle_merge(Node * header1, Node  *header2)
{
	Node * temp;
	while(header1->next != NULL && header2 != NULL )
	{
		temp = header1 -> next;
		header1 ->next = header2 ;
		header1 = header1 -> next;
		header1 -> next = temp;
		header2 = header2 -> next;
	}
	return header1;
}

void sorted_merge(Node * header1, Node  *header2)
{
	Node * temp;
	if(header1 -> entry > header2 -> entry)
	{
		temp -> entry = header2 -> entry;
		header2 -> entry = header1 -> entry;
		header1 -> entry = temp -> entry;
	}
	while(header1 -> next != NULL && header2 -> next != NULL )
	{
		if(header1 -> next -> entry <= header2 -> next -> entry)
		{
			header1 = header1 -> next;
		}
		else
		{
			temp = header1 -> next;
			header1 ->next = header2 -> next;
			header2 -> next = temp;
		}
	}
}

Node * set_and(Node * header1, Node  *header2)
{
	Node * new = NULL;
	while(header1 != NULL && header2 != NULL )
	{
		if(header1 -> entry < header2 -> entry)
		{
			header1 = header1 -> next;
		}
		else if (header1 -> entry > header2 -> entry)
		{
			header2 = header2 -> next;
		}
		else if (header1 -> entry == header2 -> entry)
		{
			new = insert_end(new, header1 -> entry);
			header2 = header2 -> next;
			header1 = header1 -> next;
		}
	}
	return new;
}

Node * set_or(Node * header1, Node  *header2)
{
	Node * new = NULL;
	while(header1 != NULL && header2 != NULL )
	{
		if(header1 -> entry < header2 -> entry)
		{
			header1 = header1 -> next;
			new = insert_end(new, header1 -> entry);
		}
		else if (header1 -> entry > header2 -> entry)
		{
			header2 = header2 -> next;
			new = insert_end(new, header2 -> entry);
		}
		else if (header1 -> entry == header2 -> entry)
		{
			new = insert_end(new, header1 -> entry);
			header2 = header2 -> next;
			header1 = header1 -> next;
		}
	}
	if (header1 == NULL){header1 = header2;}
	return new;
}

Node * set_or_not(Node * header1, Node  *header2)
{
	return header1;
}

Node * set_and_not(Node * header1, Node  *header2)
{
	Node * new = NULL;
	while(header1 != NULL && header2 != NULL )
	{
		if(header1 -> entry < header2 -> entry)
		{
			header1 = header1 -> next;
			new = insert_end(new, header1 -> entry);
		}
		else if (header1 -> entry > header2 -> entry)
		{
			header2 = header2 -> next;
		}
		else if (header1 -> entry == header2 -> entry)
		{
			header2 = header2 -> next;
			header1 = header1 -> next;
		}
	}
	return new;
}


double_node * create_node_doubly_linked(list_entry entry)
{
	double_node * p;
	p = (double_node *)malloc(sizeof(double_node));
	p->entry = entry;
	p -> prev = NULL;
	p->next = NULL;
	return(p);
}

double_node * insert_begin_doubly_linked(double_node * header, list_entry entry)
{
	double_node * p;
	p = create_node_doubly_linked(entry);//changed
    p->next = header;
    header -> prev = p;
	header = p;
	return(header);
}

double_node * insert_end_doubly_linked(double_node * header, list_entry entry)
{
	double_node *p, * curr;
	p = create_node_doubly_linked(entry);
	if(header == NULL)
	{
		header = p;
	}
	else
	{
		curr = header;
		while(curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = p;
		p -> prev = curr;
	}
	return(header);	
}

double_node * reverse_doubly_linked(double_node * header )
{
	double_node *prev, *curr, *next;
	curr = header;
	prev = NULL;
	while(curr != NULL)
	{
		next = curr -> next;
		curr -> next = prev;
		curr -> prev = next;
		prev = curr;
		curr = next;
	}
	return prev;
}

//reverse_singly_linked
//initalize reverse_recursive( header, header, NULL)
Node * reverse_recursive(Node *prev, Node *curr, Node * next)
{
	if(curr != NULL)
	{
		next = curr -> next;
		curr -> next = prev;
		prev= curr;
		curr = next;
		return reverse_recursive(prev, curr, next);
	}
	else{return prev;}
}

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


int check_palindrome(Node * header, Node * front)
{
	Node *temp, *back;
	back = header;
	temp = front;
	while (temp -> next != NULL)
	{
		back = back->next;
		temp = temp->next;
	}
	if (back -> entry == front -> entry && back != front && back->next != front){return check_palindrome(header, front->next);}
	else if(back -> entry == front -> entry && (back == front || back->next == front)){return 1;}
	else {return 0;}
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

//Check whether a given singly linked list is cyclic or not
int check_cyclic(Node * header)
{
	Node * temp = header;
	while (header != NULL)
	{
		header = header-> next;
		if(header == temp){return 1;}
	}
	return 0;
}