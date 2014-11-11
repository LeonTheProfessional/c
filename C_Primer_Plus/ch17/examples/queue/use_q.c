/*************************************************************************
	> File Name: use_q.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Mon 10 Nov 2014 11:52:10 PM CST
 ************************************************************************/

#include <stdio.h>
#include "queue.h"

int main(void)
{
    Queue line;
    Item temp;
    char ch;

    InitializeQueue(&line);
    puts("Testing the Queue interface. Type a to add a value, ");
    puts("type d to delete a value, and type q to quit.");
    while ((ch = getchar()) != 'q')
    {
        if (ch != 'a' && ch != 'd')
        {
            continue;
        }
        if (ch == 'a')
        {
            printf("Integer to add: ");
            scanf("%d", &temp);
            if (!QueueIsFull(&line))
            {
                printf("Putting %d into queue\n", temp);
                EnQueue(temp, &line);
            }
            else
            {
                puts("Queue is full!");
            }
        }
        else
        {
            if (QueueIsEmpty(&line))
            {
                puts("Nothing to delete!");
            }
            else
            {
                DeQueue(&temp, &line);
                printf("Removing %d from queue\n", temp);
            }
        }
        printf("%d items in queue\n", QueueItemCount(&line));
        puts("Type a to add, d to delete, q to quit: ");
    }
    EmptyTheQueue(&line);
    puts("Bye!");

    return 0;
}
