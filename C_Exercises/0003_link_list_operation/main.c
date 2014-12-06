/*************************************************************************
	> File Name: main.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Fri 24 Oct 2014 11:31:10 PM CST
 ************************************************************************/

#include "link_list_operation.h"

//打印项目信息
static void DisplayItem(const Item item);
//清理缓冲区剩余字符
static void ClearBuffer();

int main(int argc, char * argv[])
{
	List list;
    Item item;
    
    //初始化单链表
    printf("Initialize List\n");
    Initialize(&list);

    if (IsEmpty(&list)) {
        printf("List is empty!\n");
        while (1 == scanf("%d", &item)) {
            AddItemHead(item, &list);
        }
        ClearBuffer();
    }
    
    printf("List items:\n");
    Traverse(&list, (void (*) (Item item)) (&DisplayItem));
    printf("\nList has %d items.\n", ItemCount(&list));

    if (IsFull(&list)) {
        printf("List is full!\n");
    }

    printf("Clear List!\n");
    ClearList(&list);

    if (IsEmpty(&list)) {
        printf("List is empty!\n");
        while (1 == scanf("%d", &item)) {
            AddItemTail(item, &list);
        }
        ClearBuffer();
    }

    DeleteFirstItem(&list);
    DeleteLastItem(&list);
    printf("List items:\n");
    Traverse(&list, (void (*) (Item item)) (&DisplayItem));
    printf("\nList has %d items.\n", ItemCount(&list));

    item = 3;
    RemoveItem(item, &list);
    printf("List items:\n");
    Traverse(&list, (void (*) (Item item)) (&DisplayItem));
    printf("\nList has %d items.\n", ItemCount(&list));

    DestroyList(&list);

	return 0;
}

//打印项目信息
static void DisplayItem(const Item item)
{
    printf("%d\t", item);
}

//清理缓冲区剩余字符
static void ClearBuffer()
{
    int c;
    do {
        c = getchar();
    } while (c != EOF && c != '\n');
}
