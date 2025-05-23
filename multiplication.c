// /*******************************************************************************************************************************************************************
// *Title			: Multiplication
// *Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
// *Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
// *Input Parameters	: head1: Pointer to the first node of the first double linked list.
// 			: tail1: Pointer to the last node of the first double linked list.
// 			: head2: Pointer to the first node of the second double linked list.
// 			: tail2: Pointer to the last node of the second double linked list.
// 			: headR: Pointer to the first node of the resultant double linked list.
// *Output			: Status (SUCCESS / FAILURE)
// *******************************************************************************************************************************************************************/


#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *headR2 = NULL, *tailR2 = NULL;   // Temporary list for each partial product
    Dlist *backup_headR = NULL, *backup_tailR = NULL; // Stores the result after addition
    Dlist *temp2 = *tail2, *temp1;
    int num1, num2, carry, result, zeroes = 0;

    // Iterate through each digit of the second number from right to left
    while (temp2 != NULL)
    {
        temp1 = *tail1;
        num2 = temp2->data;
        carry = 0;
        headR2 = tailR2 = NULL;  // Reset the list

        // Add zeroes to shift the multiplication result
        for (int i = 0; i < zeroes; i++)
        {
            dl_insert_first(&headR2, &tailR2, 0);
        }

        // Multiply with each digit of the first number from right to left
        while (temp1 != NULL)
        {
            num1 = temp1->data;
            result = carry + (num1 * num2);
            carry = result / 10;
            dl_insert_first(&headR2, &tailR2, result % 10);
            temp1 = temp1->prev;
        }

        // Insert remaining carry
        if (carry)
        {
            dl_insert_first(&headR2, &tailR2, carry);
        }

        // If first multiplication, assign headR directly
        if (*headR == NULL)
        {
            *headR = headR2;
            *tailR = tailR2;
        }
        else
        {
            // Add headR and headR2, store in backup_headR
            addition(headR, tailR, &headR2, &tailR2, &backup_headR, &backup_tailR);
            dl_delete_list(headR, tailR);
            dl_delete_list(&headR2, &tailR2);

            *headR = backup_headR;
            *tailR = backup_tailR;
            backup_headR = NULL;
            backup_tailR = NULL;
        }

        zeroes++;  // Increase zeroes for shifting
        temp2 = temp2->prev;
    }

    return SUCCESS;
}
