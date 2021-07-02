/*

Author: Rahul Mac

Loop Unrolling and Loop Splitting

*/

#include <stdio.h>
#include <ctype.h>
#include <time.h>
#define N 100

int main()
{
	int i;
	char choice;
	clock_t start, stop;
	double time;
	printf("\nDo you want to use optimized code? (y/n): ");
	scanf("%c", &choice);
	choice = tolower(choice);
	start = clock();
	switch(choice)
	{
		case 'y':
				//	UNROLLING
				for(i = 0; i < N; i += 2)
					printf("\n%d", i);

				//	SPLITTING
				for(i = 0; i < N/2; i++)
					printf("\nLESS");
				for(;i < N; i++)
					printf("\nMORE");
				break;
				
		case 'n':
				for(i = 0; i < N; i++)
				{
					if((i % 2) == 0)
						printf("\n%d", i);
				}
				for(i = 0; i < N; i++)
				{
					if(i < N/2)
						printf("\nLESS");
					else
						printf("\nMORE");
				}
				break;	
		default: printf("\nInvalid Choice");
	}
	stop = clock();
	time = (double) (stop - start) / CLOCKS_PER_SEC;
	printf("\nExecution Time = %f seconds.", time); 
	return 0;
}
