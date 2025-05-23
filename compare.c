#include "apc.h"

/* Function to find which number(node->data) is bigger or equal */
int compare_value(Dlist *head1, Dlist *head2)    
{
    Dlist *temp1 = head1, *temp2 = head2;
    int count1 = 0, count2 = 0;

    while (temp1 != NULL)
    {
        count1++;
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        count2++;
        temp2 = temp2->next;
    }

    if (count1 > count2)
        return 1;
    else if (count1 < count2)
        return -1;

    temp1 = head1, temp2 = head2;
    while (temp1 != NULL)
    {
        if (temp1->data < temp2->data)
            return -1;
        else if (temp1->data > temp2->data)
            return 1;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return 0;
}

/* Function to remove first zeroes */
int remove_zeroes(Dlist **head)   
{
    Dlist *temp;
    while ((*head)->next != NULL)
    {
        if ((*head)->data == 0)
        {
            temp = (*head);
            (*head) = (*head)->next;
            (*head)->prev = NULL;
            free(temp);
        }
        else
            return SUCCESS;
    }
    return SUCCESS;
}