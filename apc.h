#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Include the prototypes here */
int read_and_validate_args(int argc, char *argv[]);
int compare_value(Dlist *head1, Dlist *head2);
int sign_conversion(int argc, char *argv[], Dlist *head1, Dlist *head2, int *sign_flag);

int convert_ip_to_nodes(Dlist **head, Dlist **tail, char str[]);
int dl_insert_first(Dlist **head, Dlist **tail, int data);
int dl_insert_last(Dlist **head, Dlist **tail, int data);
int dl_delete_list(Dlist **head, Dlist **tail);
int remove_zeroes(Dlist **head);
void print_list(Dlist *head);

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int substraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);


#endif
