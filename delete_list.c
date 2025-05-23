#include "apc.h"

int dl_delete_list(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
        return FAILURE;

    Dlist *temp = *head;

    while(temp != NULL)
    {
        *head = temp;
        temp = temp->next;
        free(*head);
    }
    *head = NULL;
    *tail = NULL;
    return SUCCESS;
}