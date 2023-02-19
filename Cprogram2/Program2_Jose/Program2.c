/*
 * Program2.c
 *
 *  Created on: Feb 9, 2023
 *      Author: Jose Leyba
 * Enter a score and get possible combinations of points to get it
 */
#include <stdio.h>


int main()
{
	int Score; // initializes score
	printf("Please enter a score to calculate all possible ways to get that score: "); //Ask for user input
	scanf("%d", &Score);
	printf("\n\n");
	if (Score < 2)
	{
		printf("You can't get less than two points");
	}
	for(int TD1 = 0; TD1 <= Score; TD1++)
	{
		for(int TD2 = 0; TD2 <= Score; TD2++)
		{
			if ((TD1*8) + (TD2*7) > Score)
			{
				break;
			}
			for(int TD3 = 0; TD3 <= Score; TD3++)
			{
				if ((TD1*8) + (TD2*7) + (TD3*6) > Score)
				{
					break;
				}
				for(int FG = 0; FG <= Score; FG++)
				{
					if ((TD1*8) + (TD2*7) + (TD3*6) + (FG*3) > Score)
					{
						break;
					}
					for(int Saf = 0; Saf <= Score; Saf++)
					{
						if ((TD1*8) + (TD2*7) + (TD3*6) + (FG*3) + (Saf*2) > Score)
						{
							break;
						}
						else if ((TD1*8) + (TD2*7) + (TD3*6) + (FG*3) + (Saf*2) == Score)
						{
							printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",TD1,TD2,TD3,FG,Saf);
						}
					}
				}
			}
		}
	}
	return 0;
}
