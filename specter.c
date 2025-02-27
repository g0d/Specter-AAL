/******************************************************************************/
/*                                   Specter                                  */
/*                      	   <<Specter Library>>                            */
/*                              George Delaportas                             */
/*                            Copyright © 2010-2025                           */
/******************************************************************************/



/* Headers */
#include "headers/specter.h"

/* Specter - Addition */
char *specter_add(char *A, char *B)
{
	char Err;
	char ZeroA;
	char ZeroB;
	char MinA;
	char MinB;
	char Bigger;
	char *Result = aal_mem_alloc_2(A, B);
	uintptr_t DotA;
	uintptr_t DotB;
	
	Err = aal_errchk_2(A, B);
	
	if ((aal_len(A) == 1 && isdigit(A[0]) == 0) || (aal_len(B) == 1 && isdigit(B[0]) == 0))
		Err = '1';
	
	if (Err == '1')
	{
		Result[0] = '#';
		Result[1] = '\0';
	}
	else
	{
		A = aal_clrzr(A);
		B = aal_clrzr(B);
		
		MinA = aal_minchk(A);
		MinB = aal_minchk(B);
		
		ZeroA = aal_zrchk(A);
		ZeroB = aal_zrchk(B);
		
		DotA = aal_dotchk(A);
		DotB = aal_dotchk(B);
		
		if (MinA == '1' && ZeroA == '1')
			A = aal_clrmin(A);
		
		if (MinB == '1' && ZeroB == '1')
			B = aal_clrmin(B);
		
		if (ZeroA == '1')
			Result = aal_clrzr(B);
		else if (ZeroB == '1')
			Result = aal_clrzr(A);
		else
		{
			if (MinA == '0' && MinB == '0')
				Result = aal_add(A, B);
			
			else if (MinA == '1' && MinB == '1')
			{
				A = aal_clrmin(A);
				B = aal_clrmin(B);

				Result = aal_add(A, B);
				Result = aal_setmin(Result);
			}
			else
			{
				if (MinA == '1')
				{
					A = aal_clrmin(A);

					Result = aal_sub(A, B);
					
					Bigger = aal_cmp(A, B);
					
					if (Bigger == '1')
						Result = aal_setmin(Result);
				}
				
				if (MinB == '1')
				{
					B = aal_clrmin(B);
					
					Result = aal_sub(A, B);
					
					Bigger = aal_cmp(A, B);
					
					if (Bigger == '2')
						Result = aal_setmin(Result);
				}
			}
		}
	}
	
	return Result;
}

/* Specter - Subtraction :: TODO FIX */
char *specter_sub(char *A, char *B)
{
	char Err;
	char ZeroA;
	char ZeroB;
	char MinA;
	char MinB;
	char Bigger;
	char *Result = aal_mem_alloc_2(A, B);
	uintptr_t DotA;
	uintptr_t DotB;
	
	Err = aal_errchk_2(A, B);
	
	if ((aal_len(A) == 1 && isdigit(A[0]) == 0) || (aal_len(B) == 1 && isdigit(B[0]) == 0))
		Err = '1';
	
	if (Err == '1')
	{
		Result[0] = '#';
		Result[1] = '\0';
	}
	else
	{
		A = aal_clrzr(A);
		B = aal_clrzr(B);
		
		MinA = aal_minchk(A);
		MinB = aal_minchk(B);
		
		ZeroA = aal_zrchk(A);
		ZeroB = aal_zrchk(B);
		
		DotA = aal_dotchk(A);
		DotB = aal_dotchk(B);
		
		if (MinA == '1' && ZeroA == '1')
			A = aal_clrmin(A);
		
		if (MinB == '1' && ZeroB == '1')
			B = aal_clrmin(B);
		
		if (ZeroA == '1')
			Result = aal_clrzr(B);
		else if (ZeroB == '1')
			Result = aal_clrzr(A);
		else
		{
			if (MinA == '0' && MinB == '0')
				Result = aal_sub(A, B);
			
			else if (MinA == '1' && MinB == '1')
			{
				Result = aal_sub(A, B);
			}
			else
			{
				if (MinA == '1')
				{
					Result = aal_add(A, B);
					
					Bigger = aal_cmp(A, B);
					
					/*if (Bigger == '1')
						Result = aal_setmin(Result);*/
				}
				
				if (MinB == '1')
				{
					Result = aal_add(A, B);
					
					Bigger = aal_cmp(A, B);
					
					/*if (Bigger == '2')
						Result = aal_setmin(Result);*/
				}
			}
		}
	}
	
	return Result;
}

/******************************************************************************/
