/******************************************************************************/
/*                                  Specter                                   */
/*                      <<Abstract Arithmetics Library>>                      */
/*                              George Delaportas                             */
/*                            Copyright © 2010-2023                           */
/******************************************************************************/



/* Headers */
#include "aal.h"

/* AAL - Length */
uintptr_t aal_len(char *X)
{
	char *P;
	
	if (X == NULL)
		return -1;
	
	P = X;
	
	while (*P != '\0')
		*P++;
	
	return (P - X);
}

/* AAL - Copy */
char *aal_copy(char *S, unsigned long P)
{
	char *N;
	char *CRes = aal_mem_alloc_1(S);
	uintptr_t LenS;
	
	N = S;
	
	LenS = aal_len(S);
	
	while (((P + (N - S)) < LenS) && (isdigit(S[P + (N - S)]) || S[P + (N - S)] == '-' || S[P + (N - S)] == '.'))
	{
		CRes[N - S] = S[P + (N - S)];
		
		*N++;
	}
	
	CRes[N - S] = '\0';
	
	return CRes;
}

/* AAL - Compare */
char aal_cmp(char *A, char *B)
{
	char Bigger;
	char *P;
	uintptr_t LenA; 
	uintptr_t LenB;
	
	Bigger = '0';
	
	LenA = aal_len(A);
	LenB = aal_len(B);
	
	if (LenA > LenB)
		Bigger = '1';
	else if (LenA < LenB)
		Bigger = '2';
	else
	{
		P = A;
		
		while (*P != '\0')
		{
			if (A[P - A] > B[P - A])
			{
				Bigger = '1';
				break;
			}
			else if (A[P - A] < B[P - A])
            {
				Bigger = '2';
				break;
			}
			
			*P++;
		}
	}
	
	return Bigger;
}

/* AAL - Reverse */
char *aal_rvrs(char *X)
{
	char *P;
	char *RevStr = aal_mem_alloc_1(X);
	uintptr_t LenX;
	
	P = X;
	
	LenX = aal_len(X);
	
	if (LenX > 1)
	{
		while (*P != '\0')
		{
			RevStr[(P - X)] = X[LenX - (P - X) - 1];
			
			*P++;
		}
	}
	else
		RevStr = X;
	
	RevStr[LenX] = '\0';
	
	return RevStr;
}

/* AAL - Padding */
char *aal_pad(char *X, char *S)
{
	char *P;
	char *PadStr = aal_mem_alloc_num(aal_len(X) + aal_len(S));
	uintptr_t LenX;
	uintptr_t LenS;

	P = S;
	
	LenX = aal_len(X);
	LenS = aal_len(S);
	
	while (*P != '\0')
	{
		PadStr[P - S] = S[P - S];
		
		*P++;
	}

	P = X;
	
	while (*P != '\0')
	{
		PadStr[LenS + P - X] = X[P - X];
		
		*P++;
	}
	
	PadStr[LenX + LenS] = '\0';
	
	return PadStr;
}

/* AAL - Zero Check */
char aal_zrchk(char *X)
{
	char Zero;
	char *P;
	char *Tracer;
	uintptr_t LenX;
	
	Zero = '0';
	P = X;
	Tracer = X;
	
	LenX = aal_len(X);
	
	while (*P != '\0')
	{
		if (X[(P - X)] == '0')
			*Tracer++;
		
		*P++;
	}
	
	if ((Tracer - X) == LenX)
		Zero = '1';
	
	return Zero;
}

/* AAL - Clear Initial Zeroes */
char *aal_clrzr(char *X)
{
	char Flag;
	char *P;
	char *ClrStr = aal_mem_alloc_1(X);
	
	Flag = '0';
	P = X;
	
	while (*P != '\0')
    {
		if (X[(P - X)] != '0' && (isdigit(X[(P - X)]) || X[(P - X)] == '-' || X[(P - X)] == '.'))
		{
			ClrStr = aal_copy(X, (P - X));
			
			Flag = '1';
			
			break;
		}
		
		*P++;
	}
	
	if (Flag == '0')
	{
		aal_mem_dealloc(ClrStr);
		
		ClrStr = aal_mem_alloc_num(2);
		
		ClrStr[0] = '0';
		ClrStr[1] = '\0';
	}
	
	return ClrStr;
}

/* AAL - Minus Check (Minus Sign) */
char aal_minchk(char *X)
{
	char Minus;
	
	Minus = '0';
	
	if (X[0] == '-')
		Minus = '1';
	
	return Minus;
}

/* AAL - Set Minus Sign */
char *aal_setmin(char *X)
{
	char *P;
	char *FinNum = aal_mem_alloc_1(X);
	
	P = X;
	
	FinNum[0] = '-';
	
	while (*P != '\0')
	{
		FinNum[P - X + 1] = X[P - X];
		
		*P++;
	}
	
	FinNum[P - X + 1] = '\0';
	
	return FinNum;
}

/* AAL - Clear Minus Sign */
char *aal_clrmin(char *X)
{
	char *P;
	char *AbsNum = aal_mem_alloc_1(X);
	
	P = X;
	
	while (*P != '\0')
	{
		AbsNum[P - X] = X[P - X + 1];
		
		*P++;
	}
	
	AbsNum[P - X - 1] = '\0';
	
	return AbsNum;
}

/* AAL - Dot Check (Comma Sign) */
uintptr_t aal_dotchk(char *X)
{
	char *P;
	
	P = X;
	
	while (*P != '\0')
	{
		if (X[(P - X)] == '.')
			break;
		
		*P++;
	}
	
	return (P - X);
}

/* AAL - Set Dot (Comma Sign) */
char *aal_setdot(char *X, char *P)
{
	char *N;
	char *RealNum = aal_mem_alloc_1(X);
	
	N = X;
	
	while ((N - X) != *P)
	{
		RealNum[N - X] = X[N - X];
		
		*N++;
	}
	
	RealNum[N - X] = '.';
	
	*N++;
	
	while (*N != '\0')
	{
		RealNum[N - X] = X[N - X];
		
		*N++;
	}
	
	RealNum[N - X + 1] = '\0';
	
	return RealNum;
}

/* AAL - Clear Dot (Comma Sign) */
char *aal_clrdot(char *X)
{
	char *P;
	char *IntNum = aal_mem_alloc_1(X);
	
	P = X;
	
	while (*P != '.')
	{
		IntNum[P - X] = X[P - X];
		
		*P++;
	}
	
	while (*P != '\0')
	{
		IntNum[P - X] = X[P - X + 1];
		
		*P++;
	}
	
	IntNum[P - X - 2] = '\0';
	
	return IntNum;
}

/* AAL - Fixate Numbers Length */
fixlen aal_fixlen(char *A, char *B)
{
	char *P;
	char *Tmp;
	uintptr_t DifLen;
	uintptr_t LenA;
	uintptr_t LenB;
	fixlen locfxlnrs;
	
	LenA = aal_len(A);
	LenB = aal_len(B);
	
	if (LenA > LenB)
	{
		P = A;
		DifLen = LenA - LenB;

		Tmp = aal_mem_alloc_num(DifLen);
		
		while (DifLen != 0)
		{
			Tmp[P - A] = '0';
			
			*P++;
			
			DifLen--;
		}
		
		Tmp[P - A] = '\0';
		
		locfxlnrs.Bigger = '1';
		locfxlnrs.Num1 = A;
		locfxlnrs.Num2 = aal_pad(B, Tmp);
		locfxlnrs.FinLen = LenA;
		
		aal_mem_dealloc(Tmp);
	}
	else if (LenA < LenB)
	{
		P = B;
		DifLen = LenB - LenA;

		Tmp = aal_mem_alloc_num(DifLen);
		
		while (DifLen != 0)
		{
			Tmp[P - B] = '0';
			
			*P++;
			
			DifLen--;
		}
		
		Tmp[P - B] = '\0';
		
		locfxlnrs.Bigger = '2';
		locfxlnrs.Num1 = aal_pad(A, Tmp);
		locfxlnrs.Num2 = B;
		locfxlnrs.FinLen = LenB;
		
		aal_mem_dealloc(Tmp);
	}
	else
	{
		locfxlnrs.Bigger = '0';
		locfxlnrs.Num1 = A;
		locfxlnrs.Num2 = B;
		locfxlnrs.FinLen = LenA;
	}
	
	return locfxlnrs;
}

/* AAL - Read File */
rdflout aal_rdfl(const char *Z)
{
	unsigned long i;
	unsigned long flsz;
	char *FlStrm;
	size_t file_res;
	rdflout locrdflout;
	FILE *FP;
	
	i = 0;
	flsz = 0;

	FP = fopen(Z, "r");
	
	if (FP == NULL)
	{
		locrdflout.Num1 = "ERROR\0";
		locrdflout.Num2 = "ERROR\0";
	}
	else
	{
		fseek(FP, 0, SEEK_END);
		flsz = ftell(FP);
		rewind(FP);
		
		if (flsz < 3)
		{
			printf("File does not include any numbers!\n");
			
			locrdflout.Num1 = "ERROR\0";
			locrdflout.Num2 = "ERROR\0";
		}
		else
		{
			FlStrm = aal_mem_alloc_num(flsz);
			
			file_res = fread(FlStrm, 1, flsz, FP);
			
			while (FlStrm[i] != ':')
				i++;
			
			locrdflout.Num1 = aal_copy(FlStrm, 0);
			locrdflout.Num2 = aal_copy(FlStrm, i + 1);
		}
		
		fclose(FP);
	}
	
	return locrdflout;
}

/* AAL - Error Check (1 Argument) */
char aal_errchk_1(char *X)
{
	short int Check;
	char Dot;
	char Err;
	char *P;
	uintptr_t LenX;
	
	Check = 1;
	LenX = aal_len(X);
	Dot = '0';
	Err = '0';
	P = X;
	
	while (*P != '\0')
	{
		Check = isdigit(X[P - X]);
		
		if (Check == 0)
		{
			if (((P - X) == 0 && X[(P - X)] != '-') || 
			    ((P - X) > 0 && X[(P - X)] != '.') || 
			    ((P - X) == LenX - 1 && X[(P - X)] == '.') || 
			    (X[(P - X)] == '.' && Dot == '1'))
			{
				Err = '1';
				
				break;
			}
			
			if (X[(P - X)] == '.')
				Dot = '1';
		}
		
		*P++;
	}
	
	return Err;
}

/* AAL - Error Check (2 Arguments) */
char aal_errchk_2(char *A, char *B)
{
	short int Check;
	char Dot;
	char Err;
	char *P;
	uintptr_t LenA;
	uintptr_t LenB;
	
	Check = 1;
	Dot = '0';
	Err = '0';
	P = A;
	
	LenA = aal_len(A);
	
	while (*P != '\0')
	{
		Check = isdigit(A[P - A]);
		
		if (Check == 0)
		{
			if (((P - A) == 0 && A[(P - A)] != '-') || 
			    ((P - A) > 0 && A[(P - A)] != '.') || 
			    ((P - A) == LenA - 1 && A[(P - A)] == '.') || 
			    (A[(P - A)] == '.' && Dot == '1'))
			{
				Err = '1';
				
				break;
			}
			
			if (A[(P - A)] == '.')
				Dot = '1';
		}
		
		*P++;
	}
	
	if (Err == '0')
	{
		Dot = '0';
		P = B;
		
		LenB = aal_len(B);
		
		while (*P != '\0')
		{
			Check = isdigit(B[P - B]);
			
			if (Check == 0)
			{
				if (((P - B) == 0 && B[(P - B)] != '-') || 
				    ((P - B) > 0 && B[(P - B)] != '.') || 
				    ((P - B) == LenB - 1 && B[(P - B)] == '.') || 
				    (B[(P - B)] == '.' && Dot == '1'))
				{
					Err = '1';
					
					break;
				}
				
				if (B[(P - B)] == '.')
					Dot = '1';
			}
			
			*P++;
		}
	}
	
	return Err;
}

/* AAL - Memory Allocator (1 Argument) */
char *aal_mem_alloc_num(unsigned long V)
{
	char *alloc_mem;
	
	alloc_mem = calloc(V, sizeof(alloc_mem));
	
	return alloc_mem;
}

/* AAL - Memory Allocator (1 Argument) */
char *aal_mem_alloc_1(char *A)
{
	char *alloc_mem;
	
	alloc_mem = calloc(aal_len(A), sizeof(alloc_mem));
	
	return alloc_mem;
}

/* AAL - Memory Allocator (2 Arguments) */
char *aal_mem_alloc_2(char *A, char *B)
{
	char *alloc_mem;
	
	if (aal_len(A) >= aal_len(B))
	    alloc_mem = calloc(aal_len(A) + 2, sizeof(*alloc_mem));
	else
	    alloc_mem = calloc(aal_len(B), sizeof(*alloc_mem));
	
	return alloc_mem;
}

/* AAL - Memory Deallocator */
int aal_mem_dealloc(char *S)
{
	free(S);
	
	return 1;
}

/* AAL - Addition */
char *aal_add(char *A, char *B)
{
	short int k;
	char TmpA;
	char TmpB;
	char Flag;
	char *P;
	char *S = aal_mem_alloc_num(3);
	char *T = aal_mem_alloc_num(3);
	char *SS = aal_mem_alloc_2(A, B);
	char *CS = aal_mem_alloc_2(A, B);
	char *Result = aal_mem_alloc_2(A, B);
	fixlen newfxlnrs;
	
	k = 0;
	
	TmpA = '0';
	TmpB = '0';
	Flag = '0';
	
	newfxlnrs = aal_fixlen(A, B);
	
	P = newfxlnrs.Num1;
	
	while ((P - newfxlnrs.Num1) < newfxlnrs.FinLen)
	{
		TmpA = newfxlnrs.Num1[newfxlnrs.FinLen - (P - newfxlnrs.Num1) - 1];
		TmpB = newfxlnrs.Num2[newfxlnrs.FinLen - (P - newfxlnrs.Num1) - 1];
		
		if ((P - newfxlnrs.Num1) > 0)
		{
			k = ((TmpA - 48) + (TmpB - 48) + (CS[P - newfxlnrs.Num1 - 1] - 48));
			
			if (k > 9)
			{
				S[0] = '1';
				S[1] = (k - 10) + 48;
				S[2] = '\0';
			}
			else
			{
				S[0] = k + 48;
				S[1] = '\0';
			}
		}
		else
		{
			k = (TmpA  - 48) + (TmpB - 48);
			
			if (k > 9)
			{
				S[0] = '1';
				S[1] = (k - 10) + 48;
				S[2] = '\0';
			}
			else
			{
				S[0] = k + 48;
				S[1] = '\0';
			}
		}
		
		SS[P - newfxlnrs.Num1] = S[1];
		
		if (SS[P - newfxlnrs.Num1] == '\0')
			SS[P - newfxlnrs.Num1] = S[0];
		
		if (k > 9)
			CS[P - newfxlnrs.Num1] = '1';
		
		else
			CS[P - newfxlnrs.Num1] = '0';
		
		if ((P - newfxlnrs.Num1) == newfxlnrs.FinLen - 1)
		{
			if (Flag == '1')
			{
				T = aal_rvrs(S);
				
				Result[P - newfxlnrs.Num1] = T[0];
				Result[P - newfxlnrs.Num1 + 1] = T[1];
				Result[P - newfxlnrs.Num1 + 2] = T[2];
			}
			else
			{
				Result[P - newfxlnrs.Num1] = S[0];
				Result[P - newfxlnrs.Num1 + 1] = S[1];
				Result[P - newfxlnrs.Num1 + 2] = S[2];
			}
		}
		else
		{
			Flag = '1';
			
			Result[P - newfxlnrs.Num1] = SS[P - newfxlnrs.Num1];
		}
		
		*P++;
	}
	
	if (Flag == '1')
		Result = aal_rvrs(Result);
	
	return Result;
}

/* AAL - Subtraction */
char *aal_sub(char *A, char *B)
{
	short int k;
	char TmpA;
	char TmpB;
	char Flag;
	char Bigger;
	char *P;
	char *S = aal_mem_alloc_num(3);
	char *T = aal_mem_alloc_num(3);
	char *Tmp = aal_mem_alloc_2(A, B);
	char *SS = aal_mem_alloc_2(A, B);
	char *CS = aal_mem_alloc_2(A, B);
	char *Result = aal_mem_alloc_2(A, B);
	fixlen newfxlnrs;
	
	k = 0;
	
	TmpA = '0';
	TmpB = '0';
	Flag = '0';
	Bigger = '0';
	
	Bigger = aal_cmp(A, B);
	
	if (Bigger == '2')
	{
		Tmp = aal_copy(B, 0);
		B = aal_copy(A, 0);
		A = Tmp;
	}
	
	newfxlnrs = aal_fixlen(A, B);
	
	P = newfxlnrs.Num1;
	
	while ((P - newfxlnrs.Num1) < newfxlnrs.FinLen)
	{
		TmpA = newfxlnrs.Num1[newfxlnrs.FinLen - (P - newfxlnrs.Num1) - 1];
		TmpB = newfxlnrs.Num2[newfxlnrs.FinLen - (P - newfxlnrs.Num1) - 1];
		
		if ((P - newfxlnrs.Num1) > 0)
		{
			if ((TmpA  - 48) >= ((TmpB  - 48) + (CS[P - newfxlnrs.Num1 - 1] - 48)))
			{
				k = (TmpA - 48) - ((TmpB - 48) + (CS[P - newfxlnrs.Num1 - 1] - 48));
				
				S[0] = k + 48;
				S[1] = '\0';
			}
			else
			{
				k = (10 + (TmpA - 48)) - ((TmpB - 48) + (CS[P - newfxlnrs.Num1 - 1] - 48));
				
				S[0] = '1';
				S[1] = k + 48;
				S[2] = '\0';
			}
		}
		else
		{
			if ((TmpA  - 48) >= (TmpB  - 48))
			{
				k = (TmpA  - 48) - (TmpB - 48);
				
				S[0] = k + 48;
				S[1] = '\0';
			}
			else
			{
				k = (10 + (TmpA - 48)) - (TmpB - 48);
				
				S[0] = '1';
				S[1] = k + 48;
				S[2] = '\0';
			}
		}
		
		SS[P - newfxlnrs.Num1] = S[1];
		
		if (SS[P - newfxlnrs.Num1] == '\0')
		{
			SS[P - newfxlnrs.Num1] = S[0];
			CS[P - newfxlnrs.Num1] = '0';
		}
		else
			CS[P - newfxlnrs.Num1] = '1';
		
		if ((P - newfxlnrs.Num1) == newfxlnrs.FinLen - 1)
		{
			if (Flag == '1')
			{
				T = aal_rvrs(S);
				
				Result[P - newfxlnrs.Num1] = T[0];
				Result[P - newfxlnrs.Num1 + 1] = T[1];
				Result[P - newfxlnrs.Num1 + 2] = T[2];
			}
			else
			{
				Result[P - newfxlnrs.Num1] = S[0];
				Result[P - newfxlnrs.Num1 + 1] = S[1];
				Result[P - newfxlnrs.Num1 + 2] = S[2];
			}
		}
		else
		{
			Flag = '1';
			
			Result[P - newfxlnrs.Num1] = SS[P - newfxlnrs.Num1];
		}
		
		*P++;
	}
	
	if (Flag == '1')
		Result = aal_rvrs(Result);
	
	return Result;
}

/******************************************************************************/
