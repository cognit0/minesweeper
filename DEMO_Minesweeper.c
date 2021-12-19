#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
	int plat[1000];
	int solu[1000];
	int game[1000];
	int i;
	int a;
	int misra = 0;
	int x;
	int one = 1;
	int zero = 0;
	srand(time(NULL));
	int ran;

	i = 1;
	while (i <= 1000)
	{
		ran = rand() % 1000;
		if (ran % 11 != 0 && ran % 17 != 0)
		{
			plat[i] = zero;
		}
		else
		{
			plat[i] = one;
		}
		solu[i] = 0;
		game[i] = 0;
		i++;
	}
	for (int b = 1; b <= 1000; b++)
	{
		printf("%d ", plat[b]);
		if (b % 50 == 0)
			printf("\n");
	}
	for (int b = 1; b <= 50; b++)
	{
		printf("-");
		if (b == 50)
			printf("\n");
	}
	for (i = 1; i <= 1000; i++)
	{			
		if (plat[i - 51] == 1 && i > 1 && plat[i] != 1)
			solu[i] += 1;
		if (plat[i - 50] == 1 && i > 1 && plat[i] != 1)
			solu[i] += 1;
		if (plat[i - 49] == 1 && i > 1 && plat[i] != 1)
			solu[i] += 1;
		if (plat[i - 1] == 1 && i > 1 && plat[i] != 1)
			solu[i] += 1;
		if (plat[i + 1] == 1 && i > 1 && plat[i] != 1)
			solu[i] += 1;
		if (plat[i + 49] == 1 && i > 1 && plat[i] != 1)
			solu[i] += 1;
		if (plat[i + 50] == 1 && i > 1 && plat[i] != 1)
			solu[i] += 1;
		if (plat[i + 51] == 1 && i > 1 && plat[i] != 1)
			solu[i] += 1;
		if (plat[i] == 1)
			solu[i] = plat[i] + 5;
		printf("%d ", solu[i]);
		if (i % 50 == 0)
			printf("\n");
	}
	i = 1;
	while (i <= 1000)
	{
		if (plat[i] == 6)
			misra++;
		i++;
	}
	while (1)
	{
		printf("THE AMOUNT OF BOMBS: %d\n", misra);
		printf("GUESS TIME: ");
		scanf("%d", &x);
		if(solu[x] != 6)
		{		
			for(int z = 0; z <= 51; z++)
			{
				if (z != 51 && z != 50 && z != 49 && z != 1 && z != 0)
					continue ;
				if (solu[x - z] != 6 && x - z >= 0 && x - z <= 1000)
				{
					game[x - z] = solu[x - z];
				}
				if (z != 51 && z != 50 && z != 49 && z != 1 && z != 0)
					continue ;
				if (solu[x + z] != 6 && x + z >= 0 && z + x <= 1000)
				{
					game[z + x] = solu[z + x];
				}
			}
		
//			if (solu[x - 51] != 6)
//				game[x - 51] = solu[x - 51];
//			if (solu[x - 50] != 6)
//				game[x - 50] = solu[x - 50];
//			if (solu[x - 49] != 6)
//				game[x - 49] = solu[x - 49];
//			if (solu[x - 1] != 6)
//				game[x - 1] = solu[x - 1]; 
//			if (solu[x] != 6)
//				game[x] = solu[x];
//			if (solu[x + 1] != 6)
//				game[x + 1] = solu[x + 1];
//			if (solu[x + 49] != 6)
//				game[x + 49] = solu[x + 49];
//			if (solu[x + 50] != 6)
//				game[x + 50] = solu[x + 50];
//			if (solu[x + 51] != 6)
//				game[x + 51] = solu[x + 51];
			printf("TRUE\n");
		}
		else 
		{
			printf("YOU LOST\n");
			return 0;
		}


		i = 1;
		while (i <= 1000)
		{
			printf("%d ", game[i]);
			if (i % 50 == 0)
				printf("\n");
			i++;
		}	
	}
}
