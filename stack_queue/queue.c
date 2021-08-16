#include <stdio.h>
#define length 5

typedef char entry;
typedef struct queue
{
    entry items[length];
    int front_pointer, back_pointer, count;
} queue;

void initialize_queue(queue *q)
{
    q->front_pointer = 0;
    q->back_pointer = -1;
    q->count = 0;
}

void enqueue(entry value, queue *q)
{
    q->items[(q->front_pointer)] = value;
    q->count++;
    q->front_pointer++;
    q->front_pointer = q->front_pointer % length;
}

entry dequeue(queue *q)
{
    entry popped;
    popped = q->items[(q->back_pointer)+1];
    q->back_pointer+=1;
    q->count--;
    return popped;
}

int queue_full(queue q)
{
    int full = 0;
    if (q.count >= length)
    {
        full = 1;
    }
    return full;
}

int queue_empty(queue q)
{
    int empty = 0;
    if (q.count == 0)
    {
        empty = 1;
    }
    return empty;
}
void clear_queue(queue *q)
{
    q->count = 0;
    q->front_pointer = q->back_pointer + 1;
}

void traverse_queue(queue q)
{
    int i;
    printf("\n");
    if (!queue_empty(q))
    {
        for (i = q.front_pointer; i - q.front_pointer < q.count; i = i + 1)
        {
            printf("\t%c", q.items[i]);
        }
    }
    else
    {
        printf("\nQueue is empty");
    }
}
entry queue_front(queue q)
{
    return (q.front_pointer);
}

int main()
{
    int choice = -1;
    queue q;
    entry x;
    initialize_queue(&q);
    for (; choice;)
    {
        printf("\nEnter the option \n1.Enqueue \n2.Dequeue \n3.Check if empty \n4.Check if full \n5.Queue count \n6.Clear queue \n7.Traverse queue \n8.Queue front \n0.Exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data item you want to Enqueue\n");
            fflush(stdin);
            scanf("%c", &x);
            if (!queue_full(q))
            {
                enqueue(x, &q);
            }
            else
            {
                printf("\nQueue is full, cannot Enqueue");
            }
            break;
        case 2:
            if (!queue_empty(q))
            {
                x = dequeue(&q);
                printf("\nThe Dequeued item is %c", x);
            }
            else
            {
                printf("\nCannnot Dequeue. Queue is empty");
            }
            break;
        case 3:
            if (queue_empty(q))
            {
                printf("\nQueue is empty");
            }
            else
            {
                printf("\nQueue is not empty");
            }
            break;
        case 4:
            if (queue_full(q))
            {
                printf("\nQueue is full");
            }
            else
            {
                printf("\nQueue is not full");
            }
            break;
        case 5:
            printf("\n%d", q.count);
            break;
        case 6:
            clear_queue(&q);
            printf("\nQueue is cleared");
            break;
        case 7:
            traverse_queue(q);
            break;
        case 8:
            printf("\n%d", queue_front(q));
            break;

        default:
            printf("Program over");
        }
    }
    return (0);
};