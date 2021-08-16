#include <stdio.h>
#define length 5

typedef char entry;
typedef struct stack
{
	entry items[length];
	int pointer_loc;
} stack;

void initialize_stack(stack *s)
{
	s->pointer_loc = -1;
}

void push(entry value, stack *s)
{
	s->items[(s->pointer_loc) + 1] = value;
	s->pointer_loc += 1;
}

entry pop(stack *s)
{
	entry popped;
	popped = s->items[(s->pointer_loc)];
	s->pointer_loc -= 1;
	return popped;
}

int stack_full(stack s)
{
	int full = 0;
	if (s.pointer_loc == length - 1)
	{
		full = 1;
	}
	return full;
}

int stack_empty(stack s)
{
	int empty = 0;
	if (s.pointer_loc == -1)
	{
		empty = 1;
	}
	return empty;
}

int main()
{
	int choice = -1;
	stack s;
	entry x;
	initialize_stack(&s);
	for (; choice;)
	{
		printf("\nEnter the option \n1.Push \n2.Pop \n3.Check if empty \n4.Check if full \n0.Exit \n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\nEnter the data item you want to push\n");
			fflush(stdin);
			scanf("%c", &x);
			if (!stack_full(s))
			{
				push(x, &s);
			}
			else
			{
				printf("\nStack is full, cannot push");
			}
			break;
		case 2:
			x = stack_empty(s);
			if (!x)
			{
				x = pop(&s);
				printf("\nThe popped item is %c", x);
			}
			else
			{
				printf("\nCannnot pop. Stack is empty");
			}
			break;
		case 3:
			if (stack_empty(s))
			{
				printf("\nStack is empty");
			}
			else
			{
				printf("\nStack is not empty");
			}
			break;
		case 4:
			if (stack_full(s))
			{
				printf("\nStack is full");
			}
			else
			{
				printf("\nStack is not full");
			}
			break;

		default:
			printf("Program over");
		}
	}
	return (0);
};