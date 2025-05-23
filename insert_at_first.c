#include "apc.h"

int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
        return FAILURE;
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }

    (*head)->prev = new;
    new->next = *head;
    *head = new;
    return SUCCESS;

}