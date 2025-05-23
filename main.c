/**************************************************************************************************************************************************************
 * Name: Omkar Irappanavar
 * Date: 12/02/2024
 *Title		: main function(Driver function)
 *Description	: This function is used as the driver function for the all the functions
 ***************************************************************************************************************************************************************/

#include "apc.h"

int main(int argc, char *argv[])
{
	if (read_and_validate_args(argc, argv) == FAILURE)		// function to validate the arguments
	{
		return FAILURE;
	}

	/* Declare the pointers */
	Dlist *head1, *tail1, *head2, *tail2, *headR, *tailR;
	char option, operator, ret;
	int sign_flag = 0;

	/* function to convert string input operands to nodes */
	if (convert_ip_to_nodes(&head1, &tail1, argv[1]) == FAILURE)	
		return FAILURE;

	if (convert_ip_to_nodes(&head2, &tail2, argv[3]) == FAILURE)
		return FAILURE;

	/* Based on input operands sign the operation performed */
	sign_conversion(argc, argv, head1, head2, &sign_flag);

	while(option != 'n' && option != 'N')
	{
		/* Extracting the operator */
		operator= argv[2][0];

		switch (operator)
		{
		case '+':
			/* call the function to perform the addition operation */
			if (addition(&head1, &tail1, &head2, &tail2, &headR, &tailR) != SUCCESS)
			{
				printf("Addition failed\n");
				return FAILURE;
			}
			if (sign_flag == -1)
				printf("-");
			print_list(headR);
			break;
		case '-':		/* call the function to perform the subtraction operation */
			ret = compare_value(head1, head2);
			switch (ret)
			{
			case 1:
				substraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				remove_zeroes(&headR);
				if (sign_flag == -1)
					printf("-");
				print_list(headR);
				break;
			case 0:
				printf("Result => 0\n");
				break;
			case -1:
				substraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
				remove_zeroes(&headR);
				if (sign_flag == -1)
					printf("-");
				print_list(headR);
				break;
			default:
				printf("Invalid return value\n");
			}

			break;
		case '*':
			/* call the function to perform the multiplication operation */
			if (multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR) != SUCCESS)
			{
				printf("MULTIPLICATION failed\n");
				return FAILURE;
			}
			remove_zeroes(&headR);
			if(sign_flag == -1)
				printf("-");
			print_list(headR);
			break;
		case '/':
			/* call the function to perform the division operation */
			if (division(&head1, &tail1, &head2, &tail2, &headR, &tailR) != SUCCESS)
			{
				printf("DIVISION failed\n");
				return FAILURE;
			}
			remove_zeroes(&headR);
			if(sign_flag == -1)
				printf("-");
			print_list(headR);
			break;
		default:
			printf("Invalid Input:- Try again...\n");
		}
		option = 'N';
	}

	return 0;
}

/* Fucntion to validate the input arguments */
int read_and_validate_args(int argc, char *argv[])
{
	if (argc < 4)
	{
		printf("USAGE: <./a.out> <operand1> <operator> <operand2>\n");
		return FAILURE;
	}

	int len = strlen(argv[2]);
	if(len > 1)
	{
		int i=1;
		while(argv[2][i] != '\0')
		{
			if(argv[2][i] != ' ')
			{
				printf("ERROR: Opearator Error\n");
				return FAILURE;
			}
		}
	}
	if (argv[1][0] == '+' || argv[1][0] == '-' || (argv[1][0] >= '0' && argv[1][0] <= '9'))
	{
	}
	else
	{
		printf("Invalid Input of <operand1> or <operand2>\n");
		return FAILURE;
	}

	for (int i = 1; argv[1][i] != '\0'; i++)
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
		{
		}
		else
		{
			printf("Invalid Input of <operand1>\n");
			return FAILURE;
		}
	}

	for (int i = 1; argv[3][i] != '\0'; i++)
	{
		if (argv[3][i] >= '0' && argv[3][i] <= '9')
		{
		}
		else
		{
			printf("Invalid Input of <operand2>\n");
			return FAILURE;
		}
	}

	return SUCCESS;
}

/* Function to convert string input operands to nodes(Double link list) */
int convert_ip_to_nodes(Dlist **head, Dlist **tail, char str[])
{
	int i = 0;
	if (str[0] == '+' || str[0] == '-')
		i = 1;

	while (str[i] != '\0')
	{
		if (dl_insert_last(head, tail, str[i] - '0') == FAILURE)
		{
			printf("Insert_first failed\n");
			return FAILURE;
		}
		i++;
	}

	return SUCCESS;
}

/* Funciton to decide the operator based on operands sign */
int sign_conversion(int argc, char *argv[], Dlist *head1, Dlist *head2, int *sign_flag)
{

	// Addition
	if (argv[2][0] == '+')
	{
		if (argv[1][0] == '-' && argv[3][0] == '-')
		{
			*sign_flag = -1;
		}
		else if (compare_value(head1, head2) == -1)
		{
			if (argv[3][0] == '-')
			{
				*sign_flag = -1;	// result is negative
				argv[2][0] = '-';	// operation convert to substraction
			}
			if (argv[1][0] == '-')
				argv[2][0] = '-';
		}
		else if (compare_value(head1, head2) == 1)
		{
			if (argv[1][0] == '-')
			{
				*sign_flag = -1;
				argv[2][0] = '-';
			}
			if (argv[3][0] == '-')
				argv[2][0] = '-';
		}
	}
	// Subtraction
	else if (argv[2][0] == '-')
	{
		if (argv[1][0] == '-' && argv[3][0] == '-')
		{
			if(compare_value(head1, head2) != -1)
				*sign_flag = -1;		// Result is negative
		}
		else if (compare_value(head1, head2) == -1) // If head2 > head1
		{
			if (argv[3][0] == '-')
			{
				argv[2][0] = '+'; // Convert operation to addition
			}
			else if(argv[1][0] == '-')
			{
				*sign_flag = -1;  // The result is negative
				argv[2][0] = '+'; // Convert to addition
			}
			else
				*sign_flag = -1;
		}
		else if (compare_value(head1, head2) == 1)
		{
			if (argv[3][0] == '-')
			{
				argv[2][0] = '+';	// Convert to addition
			}
			else if(argv[1][0] == '-')
			{
				*sign_flag = -1;	// The result is negative
				argv[2][0] = '+';	// Convert to addition
			}
		}
	}
	// Multiplication
	else if (argv[2][0] == '*')
	{
		if ((argv[1][0] == '-' && argv[3][0] != '-') || (argv[1][0] != '-' && argv[3][0] == '-'))
		{
			*sign_flag = -1;
		}
	}
	// Division
	else if (argv[2][0] == '/')
	{
		if ((argv[1][0] == '-' && argv[3][0] != '-') || (argv[1][0] != '-' && argv[3][0] == '-'))
		{
			*sign_flag = -1;
		}
	}

	return SUCCESS;
}