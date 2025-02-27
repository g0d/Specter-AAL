/******************************************************************************/
/*                                   Specter                                  */
/*                                 <<Console>>                                */
/*                              George Delaportas                             */
/*                            Copyright © 2010-2025                           */
/******************************************************************************/



/* Headers */
#include "headers/console.h"

/* Main Function */
int main(int argc, char *argv[])
{
	/* Set Variables */
	int i = 0;
	int j = 0;
	short int status = 0;
	long init_time = 0;
	long final_time = 0;
	long delay = 0;
	char *Input1 = aal_mem_alloc_num(9999999);
	char *Input2 = aal_mem_alloc_num(9999999);
	char *Output;
	rdflout newrdflout;
	
	/* Main Menu */
	printf("=====================\n");
	printf("*** Specter (AAL) ***\n");
	printf("---------------------\n");
	printf("    |Version 1.4|    \n");
	printf("=====================\n");
	printf("\n");
	printf("1. Addition\n");
	printf("2. Subtraction\n");
	printf("3. Multiplication\n");
	printf("4. Division\n");
	printf("5. Modulo\n");
	printf("6. Power\n");
	printf("7. Sqrt\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select: ");
	status = scanf("%i", &i);
	
	/* First Level Choices */
	if (i == 0)
		printf("Goodbye!\n");
	else if (i < 1 || i > 7)
		printf("\nWrong selection!\n");
	else
	{
		printf("\n\n\n");
		printf("1.Keyboard input\n");
		printf("2.File input\n");
		printf("\n");
		printf("Select: ");
		status = scanf("%i", &j);
		
		/* Second Level Choices */
		if (j == 1)
		{
			if (i == 1)
			{
				printf("\n\n\n");
				printf("* --- Addition --- *\n");
				
				printf("Please enter number 1: ");
				status = scanf("%s", Input1);
				
				printf("Please enter number 2: ");
				status = scanf("%s", Input2);
				
				init_time = benchmark();

				Output = specter_add(Input1, Input2);

				final_time = benchmark();
				
				printf("Result: %s\n", Output);
				
				delay = final_time - init_time;
				
				printf("\nBenchmark :: Delay: %lims\n", delay);
			}
			
			if (i == 2)
			{
				printf("\n\n\n");
				printf("* --- Subtraction --- *\n");
				
				printf("Please enter number 1: ");
				status = scanf("%s", Input1);
				
				printf("Please enter number 2: ");
				status = scanf("%s", Input2);
				
				init_time = benchmark();
				
				Output = specter_sub(Input1, Input2);
				
				final_time = benchmark();
				
				printf("Result: %s\n", Output);
				
				delay = final_time - init_time;
				
				printf("\nBenchmark :: Delay: %lims\n", delay);
			}
		}
		else if (j == 2)
		{
			newrdflout = aal_rdfl("MyNum");
			
			init_time = benchmark();
			
			if (i == 1)
				Output = specter_add(newrdflout.Num1, newrdflout.Num2);
			else if (i == 2)
				Output = specter_sub(newrdflout.Num1, newrdflout.Num2);
			else
			{
				printf("\nWrong selection!\n");
				
				return 0;
			}
			
			final_time = benchmark();
			
			printf("Number 1: %s\n", newrdflout.Num1);
			printf("Number 2: %s\n", newrdflout.Num2);
			printf("Result: %s\n", Output);
			
			delay = final_time - init_time;
			
			printf("\nBenchmark :: Delay: %lims\n", delay);
		}
		else
			printf("\nWrong selection!\n");
	}
	
	/* Clean Up */
	aal_mem_dealloc(Input1);
	aal_mem_dealloc(Input2);
	
	return 0;
}

/******************************************************************************/
