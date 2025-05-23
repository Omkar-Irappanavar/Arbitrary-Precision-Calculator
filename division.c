// /*******************************************************************************************************************************************************************
// *Title			: Division
// *Description		: This function performs division of two given large numbers and store the result in the resultant list.
// *Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
// *Input Parameters	: head1: Pointer to the first node of the first double linked list.
// 			: tail1: Pointer to the last node of the first double linked list.
// 			: head2: Pointer to the first node of the second double linked list.
// 			: tail2: Pointer to the last node of the second double linked list.
// 			: headR: Pointer to the first node of the resultant double linked list.
// *Output			: Status (SUCCESS / FAILURE)
// *******************************************************************************************************************************************************************/
#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	Dlist *head3 = NULL, *tail3 = NULL;
	Dlist *duprh = NULL, *duprt = NULL;
	Dlist *vh = NULL, *vt = NULL;

	remove_zeroes(head2);
	
	if( ((*head2)->next == NULL) && ((*head2)->data == 0) )
		return FAILURE;
	
	dl_insert_first(&vh, &vt, 1);
	dl_insert_first(headR, tailR, 0);

	int ret;
	while((ret = compare_value(*head1, *head2)) != -1)
	{
		// substraction
		substraction(head1, tail1, head2, tail2, &head3, &tail3);
		// removing first zeroes
		 remove_zeroes(&head3);
		// adding count
		addition(headR, tailR, &vh, &vt, &duprh, &duprt);

		dl_delete_list(head1, tail1);

		*head1 = head3, *tail1 = tail3;
		head3 = NULL, tail3 = NULL;

		dl_delete_list(headR, tailR);

		*headR = duprh;
		*tailR = duprt;
		duprh = NULL;
		duprt = NULL;
	}
	return SUCCESS;
}