/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int substraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	Dlist *temp1= *tail1, *temp2 = *tail2;
	short num1=0, num2=0, borrow=0, result=0;

	while(temp1 != NULL)
	{
		num1 = temp1->data;
		temp1 = temp1->prev;

		if(temp2 != NULL)
		{
			num2 = temp2->data;
			temp2 = temp2->prev;
		}
		else
			num2 = 0;

		if(borrow == 1)
		{
			num1 = num1-1;
			borrow = 0;
		}
		if(num1 < num2)
		{
			num1 = num1 + 10;
			borrow =1;
		}
		result = num1 - num2;
		dl_insert_first(headR, tailR, result);
	}
	return SUCCESS;
}
