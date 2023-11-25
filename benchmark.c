/******************************************************************************/
/*                                   Specter                                  */
/*                       	      <<Benchmark>>      	                      */
/*                              George Delaportas                             */
/*                            Copyright © 2010-2023                           */
/******************************************************************************/



/* Headers */
#include "benchmark.h"

/* Benchmark Function */
long benchmark()
{
	struct timeval time;
	long microtime = 0;
	
	gettimeofday(&time, NULL);
	
	microtime = time.tv_sec;
	microtime += time.tv_usec / 1000;
	
	return microtime;
}

/******************************************************************************/
