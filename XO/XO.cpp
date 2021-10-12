#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
int number[9];
int cache,turn=-1;
int end = 0;
int p = 0, y = 2,k=0;
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void posxo (int& numer){
	for (int i = 1; i <= 9; i++)
	{
		k++;
		p = 1+(5*(k-1));
		if (p >11)
		{
			y += 2;
			k = 1;
			p = 1 + (4 * (k - 1));
		}
		gotoxy(p+ 1, y);
		
		if (number[i-1]==1)
		{
			printf("X");
		}
		else if (number[i - 1] == 0)
		{
			printf("%d",i);
		}
		else printf("O");
		

	}
	gotoxy(0,9);
	p = 0, y = 2, k = 0;
}
void board(int x,int y){
	for (int i = 0; i < y; i++)
	{
		if (i>=1)
		{
			printf("|");
			printf("    ");
			printf("|");
			printf("    ");
			printf("|");
			printf("    ");
			printf("|");
			printf("\n");
		}
		for (int i = 0; i <3; i++)
		{
			printf("-----");
		}
		printf("\n");
	}


}
void reset(){
	for (int i = 0; i < 9; i++)
	{
		number[i] = 0;
		end = 1;
	}
}
void check() {
	for (int i = 0; i < 9; i++)
	{
		if (i==0||i==3||i==6)
		{
			if (number[i] == number[i + 1] && number[i + 1] == number[i + 2]&&turn==-1&& number[i]==1) {
				printf("  PLAYER2 WIN\n");
				reset();
			}
			else if (number[i] == number[i + 1] && number[i + 1] == number[i + 2] && turn == 1 && number[i] == -1) {
				printf("  PLAYER1 WIN\n");
				reset();
			}
		}
		if (i == 0 || i == 1|| i == 2)
		{
			if (number[i] == number[i + 3] && number[i + 3] == number[i + 6] && turn == -1 && number[i] == 1) {
				printf("  PLAYER2 WIN\n");
				reset();

			}
			else if (number[i] == number[i + 3] && number[i + 3] == number[i + 6] && turn == 1 && number[i] == -1) {
				printf("  PLAYER1 WIN\n");
				reset();
			}
		}
		if (i == 0 )
		{
			if (number[i] == number[i + 4] && number[i + 4] == number[i + 8] && turn == -1 && number[i] == 1) {
				printf("  PLAYER2 WIN\n");
				reset();

			}
			else if (number[i] == number[i + 4] && number[i + 4] == number[i + 8] && turn == 1 && number[i] == -1) {
				printf("  PLAYER1 WIN\n");
				reset();
			}
		}
		if (i == 2)
		{
			if (number[i] == number[i + 2] && number[i + 2] == number[i + 4] && turn == -1 && number[i] == 1) {
				printf("  PLAYER2 WIN\n");
				reset();

			}
			else if (number[i] == number[i + 2] && number[i + 2] == number[i + 4] && turn == 1 && number[i] == -1) {
				printf("  PLAYER1 WIN\n");
				reset();
			}
		}
	}

}
int main()
{
	for (int i = 0; i < 9; i++)
	{
		number[i] = 0;
		end = 1;
	}
	srand(time(NULL));
	if (rand()%2)
	{
		printf(" PLAYER1 TURN\n");
		turn = 1;
	}
	else printf("  PLAYER2 TURN\n");
	
	while (cache != 'x')
	{
		system("cls");
			if (turn==1)
			{
				printf(" PLAYER1 TURN\n");
				turn = -1;
			}
			else {
				printf(" PLAYER2 TURN\n");
				turn = 1;
			}
		board(5, 4);
		posxo(number[9]);
		printf("ENTER BLOCK NUMBER\n");
		check();
		if (end==1)
		{

			system("pause");
			end = 0;
			system("cls");
			if (turn == 1)
			{
				printf(" PLAYER1 TURN\n");
				turn = -1;
			}
			else {
				printf(" PLAYER2 TURN\n");
				turn = 1;
			}
			board(5, 4);
			posxo(number[9]);
			printf("ENTER BLOCK NUMBER\n");
		}
		
		scanf_s("%d", &cache);
		if ((number[cache - 1] == 0))
		{
			number[cache - 1] = turn;
		}
		else {
			while (number[cache - 1] != 0) {
				printf("ENTER BLOCK NUMBER Again!!\n");
				scanf_s("%d", &cache);
				if ((number[cache - 1] == 0))
				{
					number[cache - 1] = turn;
					break;
				}

			}
		}
		
	}
	
	return 0;
}

