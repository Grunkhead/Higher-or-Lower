#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char player1[15];
	char player2[15];
	int modus = 0;
	int score1 = 3;
	int score2 = 3;
	int turn1 = 1;
	int turn2 = 1;
	char higher[2] = "h";
	char lower[2] = "l";
	char guess[7];

	printf("\nWelcome to the game higher or lower!\n");
	printf("You start with a score of 10 if you guess right your total score will increase by 1 else it will decrease by 1.\n");
	playerMenu: printf("Do you want to start the game for 1 or 2 players?\n");
	scanf("%d", &modus);

	if (modus == 1)
	{
		printf("Singleplayer activated.\n");
		printf("Please fill in your name.\n");
		scanf("%s", player1);
		printf("Alright %s lets play the game.\n", player1);
		while (score1 > 0)
		{
			printf("Do you think that the number is 'h' or 'l' than 50? -turn %d\n", turn1);
			scanf("%s", guess);
			srand(time(NULL));
			int number = rand() % 101;
			if (strcmp(guess, higher) == 0)
			{
				if (number >= 50)
				{
					printf("The number is %d.\n", number);
					score1++;
					printf("You win the number was %d, your current score is %d\n", number, score1);
					turn1++;
				}
				else
				{
					score1--;
					printf("You lose the number was %d, your current score is %d\n", number, score1);
					turn1++;
				}
			}
			else if (strcmp(guess, lower) == 0)
			{
				if (number < 50)
				{
					score1++;
					printf("You win the number was %d, your current score is %d\n", number, score1);
					turn1++;
				}
				else
				{
					score1--;
					printf("You lose the number was %d, your current score is %d\n", number, score1);
					turn1++;
				}
			}
			else
			{
				printf("Please fill in 'h' or 'l'..\n");
			}
		}
	}
	else if (modus == 2)
	{
		int changePlayer = 1;
		printf("Multiplayer activated.\n");
		printf("Player 1 fill in your name.\n");
		scanf("%s", player1);
		printf("Player 2 fill in your name.\n");
		scanf("%s", player2);
		printf("%s VS %s, let's see who wins!\n", player1, player2);
		while (score1 && score2 > 0)
		{
			int number = rand() % 101;
			switch(changePlayer)
			{

			    case 1 :
			    	printf("%s do you think that the number is 'h' or 'l' than 50? -turn %d\n", player1, turn1);
					scanf("%s", guess);
					srand(time(NULL));
					if (strcmp(guess, higher) == 0)
					{
						if (number >= 50)
						{
							printf("You win the number was %d, your current score is %d\n", number, score1);
							turn1++;
							changePlayer = 0;
						}
						else
						{
							score1--;
							printf("You lose the number was %d, your current score is %d\n", number, score1);
							turn1++;
							changePlayer = 0;
						}
					}
					else if (strcmp(guess, lower) == 0)
					{
						if (number < 50)
						{
							printf("You win the number was %d, your current score is %d\n", number, score1);
							turn1++;
							changePlayer = 0;
						}
						else
						{
							score1--;
							printf("You lose the number was %d, your current score is %d\n", number, score1);
							turn1++;
							changePlayer = 0;
						}
					}
					else
					{
						printf("Please fill in 'h' or 'l'..\n");
					}
			    	break;

			    case 0 :
			    	printf("%s do you think that the number is 'h' or 'l' than 50? -turn %d\n", player2, turn2);
					scanf("%s", guess);
					srand(time(NULL));
					if (strcmp(guess, higher) == 0)
					{
						if (number >= 50)
						{
							printf("You win the number was %d, your current score is %d\n", number, score2);
							turn2++;
							changePlayer = 1;
						}
						else
						{
							score2--;
							printf("You lose the number was %d, your current score is %d\n", number, score2);
							turn2++;
							changePlayer = 1;
						}
					}
					else if (strcmp(guess, lower) == 0)
					{
						if (number < 50)
						{
							printf("You win the number was %d, your current score is %d\n", number, score2);
							turn2++;
							changePlayer = 1;
						}
						else
						{
							score2--;
							printf("You lose the number was %d, your current score is %d\n", number, score2);
							turn2++;
							changePlayer = 1;
						}
					}
					else
					{
						printf("Please fill in 'h' or 'l'..\n");
					}
			    	break;
			} // Switch ends here!
		}
	}
	else
	{
		printf("Please fill in '1' or '2'\n");
		goto playerMenu;
	}
}