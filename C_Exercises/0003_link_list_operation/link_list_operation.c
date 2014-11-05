/*************************************************************************
	> File Name: link_list_operation.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Fri 24 Oct 2014 11:29:57 PM CST
 ************************************************************************/

#include "link_list_operation.h"

Status InitList(LinkList *L)
{
    if (!L)
    {
        return ERROR;
    }
    L->head = (LNode*)malloc(sizeof(LNode));
    L->head->data = 0;
    L->len = 0;

    return OK;
}

void FreeNode(LNode *p)
{
    if (p)
    {
	    free(p);
	    p = NULL;
    }
}

Status ClearList(LinkList *L)
{
    if (!L || !L->head)
    {
        return ERROR;
    }
	LNode *p = L->head->next;
    L->head->next = NULL;
	LNode *q;
	while (p)
	{
		q = p;
		p = p->next;
		FreeNode(q);
		L->len--;
	}
    return  OK;
}

Status DestroyList(LinkList *L)
{
	if (!ClearList(L))
	{
		return ERROR;
	}
	else
	{
		FreeNode(L->head);
        L->len = 0;
		return OK;
	}
}

void Display(LinkList *L)
{
    if (L && L->head)
    {
        LNode *p = L->head->next;
        while (p)
        {
            printf("%d", p->data);
            p = p->next;
            if (p)
            {
                printf(" --> ");
            }
        }
        printf("\nLinkList Length: %d\n", L->len);
    }
}

Status InsFirst(LinkList *L, ElemType e)
{
	if (L && L->head)
	{
        LNode *node = (LNode*)malloc(sizeof(LNode));
        node->data = e;
        node->next = L->head->next;
		L->head->next = node;
		L->len++;
		return OK;
	}
	else
	{
		return ERROR;
	}
}

Status DelFirst(LinkList *L)
{
	if(L && L->head && L->head->next)
	{
		LNode *q = L->head->next;
		L->head->next = q->next;
		L->len--;
		return OK;
	}
	else
	{
		return ERROR;
	}
}

Status Append(LinkList *L, ElemType e)
{
    if (!L || !L->head)
    {
        return ERROR;
    }
    LNode *p = L->head;
	while (p->next)
	{
        p = p->next;
	}
    LNode *node = (LNode*) malloc(sizeof(LNode));
    node->data = e;
    node->next = NULL;
    p->next = node;
    L->len++;

	return 	OK;
}

Status Remove(LinkList *L, ElemType e)
{
    if (!L || !L->head)
	{
		return ERROR;
	}
	LNode *p = L->head;
	while (p->next)
	{
        if (p->next->data == e)
        {
            LNode *q = p->next;
            p->next = q->next;
            FreeNode(q);
            L->len--;
            break;
        }
        else
        {
            p = p->next;
        }
	}
    return OK;
}
