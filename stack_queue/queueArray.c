//Queue using circular array implementation

#include<stdio.h>

#define SIZE 5
#define TRUE 1
#define FALSE 0

typedef int BOOL;

typedef int queue_entry;

typedef struct queue
{
	queue_entry entry[SIZE];
	int front;
	int rear;
	int count;
}QUEUE;

void initialiseQueue(QUEUE *s);
BOOL enqueue(int d, QUEUE *q);
queue_entry dequeue(QUEUE *q);
BOOL IsQueueEmpty(QUEUE q);
BOOL IsQueueFull(QUEUE q);
int QueueSize(QUEUE q);
void clearQueue(QUEUE *q);
queue_entry QueueFront(QUEUE q);
void traverseQueue(QUEUE q);

int main()
{
	QUEUE q;
	int size;
	queue_entry result;
	int choice = -1;
	queue_entry d;
	
	
	initialiseQueue(&q);
	
	while(choice)
	{
	printf("\nEnter the option");
	printf("\n1. Enqueue");
	printf("\n2. Dequeue");
	printf("\n3. Is Queue Empty");
	printf("\n4. Is Queue Full");
	printf("\n5: Queue Size");
	printf("\n6: ClearQueue");
	printf("\n7: TraverseQueue");
	printf("\n8: QueueFront");
	printf("\n0. Exit\n");
	scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the data item you want to enqueue");
				fflush(stdin);
				scanf("%d", &d);
				result = enqueue(d,&q);
				if(result == 1)
				{
					printf("Successfully enqueued");
				}
				else
				{
					printf("Queue is full, cannot enqueue");
				}
				break;
			case 2:
				if(!IsQueueEmpty(q))
				{
					d = dequeue(&q);
					printf("The dequeued item is %d", d);
				}
				else
				{
					printf("Cannnot dequeue. Queue is empty");
				}
				break;
			case 3:
				d = IsQueueEmpty(q);
				if(d)
				{
					printf("Queue is empty");
				}
				else
				{
					printf("Queue is not empty");
				}
				break;
			case 4:
				d = IsQueueFull(q);
				if(d == 1)
				{
					printf("Queue is full");
				}
				else
				{
					printf("Queue is not full");
					
				}	
				break;
			case 5:
				size = 	QueueSize(q);
				printf("\n %d", size);
				break;
				
			case 6:
				clearQueue(&q);
				break;
			case 7: 
				traverseQueue(q);
				break;
			case 8:
				d = QueueFront(q);
				printf("\n %d", d);
				break;
			default:
				printf("Program over");
		}
	}	
	return(0);
}

void initialiseQueue(QUEUE *q)
{
	q->front = 0;
	q->rear = -1;
	q->count = 0;
}

BOOL enqueue(queue_entry d, QUEUE *q)
{
	if(!(IsQueueFull(*q)))
	{
		q->count ++;
		q->rear = (q->rear + 1)%SIZE;
		q->entry[q->rear] = d;
		
	}
	else
	{
		return(FALSE);
	}
	return(TRUE);
}

int dequeue(QUEUE *q)
{
	queue_entry ans;
	if(!IsQueueEmpty(*q))
	{
		q->count --;	
		ans = q->entry[q->front];
		q->front = (q->front + 1)%SIZE;
	
	}
	else
	{
		return(-1);
	}
	return(ans);
}

BOOL IsQueueEmpty(QUEUE q)
{
	return(q.count == 0);
}

int IsQueueFull(QUEUE q)
{
	return(q.count >= SIZE);
}

int QueueSize(QUEUE q)
{
	return(q.count);
}

void clearQueue(QUEUE *q)
{
	q->count = 0;
	q->front = q->rear + 1;
}

void traverseQueue(QUEUE q)
{
	int i;
	printf("\n");
	if(!IsQueueEmpty(q))
	{
	
		for(i= q.front ;i - q.front < q.count; i= i+1)
		{
			printf("\t%d", q.entry[i%SIZE]);
		}	
	}
	else
	{
		printf("\nQueue is empty");
	}
}

queue_entry QueueFront(QUEUE q)
{
	return(q.front);
}


