/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	short num1, num2, carry=0, sum=0;
	Dlist *temp1 = *tail1, *temp2 = *tail2;

	while(temp1 != NULL || temp2 != NULL)
	{
		num1 = 0, num2 = 0;
		if(temp1 != NULL)
		{
			num1 = temp1->data;
			temp1 = temp1->prev;
		}
		if(temp2 != NULL)
		{
			num2 = temp2->data;
			temp2 = temp2->prev;
		}

		sum = carry + num1 + num2;
		carry = sum/10;
		dl_insert_first(headR, tailR, sum%10);
	}
	if(carry)
	{
		dl_insert_first(headR, tailR, carry);
	}

	return SUCCESS;
}
