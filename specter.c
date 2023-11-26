/******************************************************************************/
/*                                  Specter                                   */
/*                      	   <<Specter Library>>                            */
/*                              George Delaportas                             */
/*                            Copyright © 2010-2023                           */
/******************************************************************************/



/* Headers */
#include "specter.h"

/* Specter - Addition */
char *specter_add(char *A, char *B)
{
	char Err;
	char AZero;
	char BZero;
	char MinA;
	char MinB;
	char Bigger;
	char *Result = aal_mem_alloc_2(A, B);
	uintptr_t DotA;
	uintptr_t DotB;
	
	AZero = '0';
	BZero = '0';
	MinA = '0';
	MinB = '0';
	Bigger = '0';
	
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
		AZero = aal_zrchk(A);
		BZero = aal_zrchk(B);
		
		if (AZero == '1')
			Result = aal_clrzr(B);
		else if (BZero == '1')
			Result = aal_clrzr(A);
		else
		{
			MinA = aal_minchk(A);
			MinB = aal_minchk(B);
			
			DotA = aal_dotchk(A);
			DotB = aal_dotchk(B);
			
			if (MinA == '0' && MinB == '0')
			{
				A = aal_clrzr(A);
				B = aal_clrzr(B);
				
				Result = aal_add(A, B);
			}
			else if (MinA == '1' && MinB == '1')
			{
				A = aal_clrmin(A);
				B = aal_clrmin(B);
				
				A = aal_clrzr(A);
				B = aal_clrzr(B);
				
				Result = aal_add(A, B);
				
				Result = aal_setmin(Result);
			}
			else
			{
				if (MinA == '1')
				{
					A = aal_clrmin(A);
					
					A = aal_clrzr(A);
					B = aal_clrzr(B);
					
					Result = aal_sub(A, B);
					
					Bigger = aal_cmp(A, B);
					
					if (Bigger == '1')
						Result = aal_setmin(Result);
				}
				
				if (MinB == '1')
				{
					B = aal_clrmin(B);
					
					A = aal_clrzr(A);
					B = aal_clrzr(B);
					
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

/* Specter - Subtraction */
char *specter_sub(char *A, char *B)
{
	char Err;
	char AZero;
	char BZero;
	char MinA;
	char MinB;
	char Bigger;
	char *Result = aal_mem_alloc_2(A, B);
	
	AZero = '0';
	BZero = '0';
	MinA = '0';
	MinB = '0';
	Bigger = '0';
	
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
		AZero = aal_zrchk(A);
		BZero = aal_zrchk(B);
		
		if (AZero == '1')
			Result = aal_clrzr(B);
		else if (BZero == '1')
			Result = aal_clrzr(A);
		else
		{
			MinA = aal_minchk(A);
			MinB = aal_minchk(B);
			
			if (MinA == '0' && MinB == '0')
			{
				A = aal_clrzr(A);
				B = aal_clrzr(B);
				
				Result = aal_sub(A, B);
			}
			else if (MinA == '1' && MinB == '1')
			{
				A = aal_clrmin(A);
				B = aal_clrmin(B);
				
				A = aal_clrzr(A);
				B = aal_clrzr(B);
				
				Result = aal_sub(A, B);
				
				Result = aal_setmin(Result);
			}
			else
			{
				if (MinA == '1')
				{
					A = aal_clrmin(A);
					
					A = aal_clrzr(A);
					B = aal_clrzr(B);
					
					Result = aal_add(A, B);
					
					Bigger = aal_cmp(A, B);
					
					if (Bigger == '1')
						Result = aal_setmin(Result);
				}
				
				if (MinB == '1')
				{
					B = aal_clrmin(B);
					
					A = aal_clrzr(A);
					B = aal_clrzr(B);
					
					Result = aal_add(A, B);
					
					Bigger = aal_cmp(A, B);
					
					if (Bigger == '2')
						Result = aal_setmin(Result);
				}
			}
		}
	}
	
	return Result;
}

/******************************************************************************/
