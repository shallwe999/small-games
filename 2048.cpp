/************  2048游戏  制作人：shallwe  制作时间：2017-5-4  ************/
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <ctime>

using namespace std;

int MATRIX[4][4] = { 0 };
int SCORE = 0;

void init();
int get_direction();
bool available(int direction);
void print_matrix();
void move(int direction);
void put_new_number();
bool game_over();

int main()
{
	int direction;
	srand( (unsigned)time(0) );
	init();
	cout << "Welcome to 2048. (Written by shallwe) Game start!~~~";
	print_matrix();

	while (!game_over() || available(1) || available(2) || available(3) || available(4))
	{
		do
		{
			direction = get_direction();
		} while (direction == 0 || !available(direction));
		system("cls");
		move(direction);
		print_matrix();
	}
	cout << "Game over! Your score: " << SCORE << endl << endl;
	return 0;
}

void init()
{
	int t1, t2, n1, n2;
	do
	{
		t1 = rand() % 16;
		t2 = rand() % 16;
	} while (t1 == t2);
	n1 = rand() % 2;
	n2 = rand() % 2;
	MATRIX[t1 / 4][t1 % 4] = n1 * 2 + 2;
	MATRIX[t2 / 4][t2 % 4] = n2 * 2 + 2;
}

int get_direction()
{
	char ch1;
	ch1 = _getch();
	if (ch1 == 'w')
		return 1;
	else if (ch1 == 's')
		return 2;
	else if (ch1 == 'a')
		return 3;
	else if (ch1 == 'd')
		return 4;
	return 0;
}

void print_matrix()
{
	int i, j;
	cout << endl << endl << endl << endl << endl;
	cout << "  SCORE: " << setw(10) << SCORE << endl;
	cout << "   ------------------------------- " << endl;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (MATRIX[i][j])
				cout << "  |" << setw(5) << MATRIX[i][j];
			else
				cout << "  |" << setw(5) << ' ';
		}
		cout << "  |" << endl << "  |                               |" << endl;
	}
	cout << "   ------------------------------- " << endl << endl;
}

bool available(int direction)
{
	int i;
	if (direction == 1)
	{
		for (i = 0; i < 4; i++)
		{
			if (MATRIX[3][i] != 0 && (MATRIX[2][i] == 0 || MATRIX[1][i] == 0 || MATRIX[0][i] == 0))
				return true;
			if (MATRIX[2][i] != 0 && (MATRIX[1][i] == 0 || MATRIX[0][i] == 0))
				return true;
			if (MATRIX[1][i] != 0 && MATRIX[0][i] == 0)
				return true;
			if (MATRIX[0][i] == MATRIX[1][i] && MATRIX[1][i] != 0)
				return true;
			if (MATRIX[1][i] == MATRIX[2][i] && MATRIX[2][i] != 0)
				return true;
			if (MATRIX[2][i] == MATRIX[3][i] && MATRIX[3][i] != 0)
				return true;
		}
		return false;
	}

	if (direction == 2)
	{
		for (i = 0; i < 4; i++)
		{
			if (MATRIX[0][i] != 0 && (MATRIX[1][i] == 0 || MATRIX[2][i] == 0 || MATRIX[3][i] == 0))
				return true;
			if (MATRIX[1][i] != 0 && (MATRIX[2][i] == 0 || MATRIX[3][i] == 0))
				return true;
			if (MATRIX[2][i] != 0 && MATRIX[3][i] == 0)
				return true;
			if (MATRIX[0][i] == MATRIX[1][i] && MATRIX[1][i] != 0)
				return true;
			if (MATRIX[1][i] == MATRIX[2][i] && MATRIX[2][i] != 0)
				return true;
			if (MATRIX[2][i] == MATRIX[3][i] && MATRIX[3][i] != 0)
				return true;
		}
		return false;
	}

	if (direction == 3)
	{
		for (i = 0; i < 4; i++)
		{
			if (MATRIX[i][3] != 0 && (MATRIX[i][2] == 0 || MATRIX[i][1] == 0 || MATRIX[i][0] == 0))
				return true;
			if (MATRIX[i][2] != 0 && (MATRIX[i][1] == 0 || MATRIX[i][0] == 0))
				return true;
			if (MATRIX[i][1] != 0 && MATRIX[i][0] == 0)
				return true;
			if (MATRIX[i][0] == MATRIX[i][1] && MATRIX[i][1] != 0)
				return true;
			if (MATRIX[i][1] == MATRIX[i][2] && MATRIX[i][2] != 0)
				return true;
			if (MATRIX[i][2] == MATRIX[i][3] && MATRIX[i][3] != 0)
				return true;
		}
		return false;
	}

	if (direction == 4)
	{
		for (i = 0; i < 4; i++)
		{
			if (MATRIX[i][0] != 0 && (MATRIX[i][1] == 0 || MATRIX[i][2] == 0 || MATRIX[i][3] == 0))
				return true;
			if (MATRIX[i][1] != 0 && (MATRIX[i][2] == 0 || MATRIX[i][3] == 0))
				return true;
			if (MATRIX[i][2] != 0 && MATRIX[i][3] == 0)
				return true;
			if (MATRIX[i][0] == MATRIX[i][1] && MATRIX[i][1] != 0)
				return true;
			if (MATRIX[i][1] == MATRIX[i][2] && MATRIX[i][2] != 0)
				return true;
			if (MATRIX[i][2] == MATRIX[i][3] && MATRIX[i][3] != 0)
				return true;
		}
		return false;
	}

}

void move(int direction)
{
	int i, j;
	if (direction == 1)
	{
		for (i = 0; i < 4; i++)
		{
			if (MATRIX[2][i] == 0)
			{
				MATRIX[2][i] = MATRIX[3][i];
				MATRIX[3][i] = 0;
			}
			if (MATRIX[1][i] == 0)
			{
				MATRIX[1][i] = MATRIX[2][i];
				MATRIX[2][i] = MATRIX[3][i];
				MATRIX[3][i] = 0;
			}
			if (MATRIX[0][i] == 0)
			{
				MATRIX[0][i] = MATRIX[1][i];
				MATRIX[1][i] = MATRIX[2][i];
				MATRIX[2][i] = MATRIX[3][i];
				MATRIX[3][i] = 0;
			}

			if ( (MATRIX[0][i] == MATRIX[1][i]) && (MATRIX[2][i] == MATRIX[3][i]) )
			{
				SCORE += MATRIX[0][i];
				SCORE += MATRIX[2][i];
				MATRIX[0][i] *= 2;
				MATRIX[1][i] = MATRIX[2][i] * 2;
				MATRIX[2][i] = 0;
				MATRIX[3][i] = 0;
				continue;
			}

			for (j = 0; j <= 2; j++)
			{
				if (MATRIX[j][i] == MATRIX[j + 1][i])
				{
					SCORE += MATRIX[j][i];
					MATRIX[j][i] *= 2;
					MATRIX[j + 1][i] = 0;
				}
			}

			if (MATRIX[2][i] == 0)
			{
				MATRIX[2][i] = MATRIX[3][i];
				MATRIX[3][i] = 0;
			}
			if (MATRIX[1][i] == 0)
			{
				MATRIX[1][i] = MATRIX[2][i];
				MATRIX[2][i] = MATRIX[3][i];
				MATRIX[3][i] = 0;
			}
			if (MATRIX[0][i] == 0)
			{
				MATRIX[0][i] = MATRIX[1][i];
				MATRIX[1][i] = MATRIX[2][i];
				MATRIX[2][i] = MATRIX[3][i];
				MATRIX[3][i] = 0;
			}
		}
		put_new_number();
	}
	
	if (direction == 2)
	{
		for (i = 0; i < 4; i++)
		{
			if (MATRIX[1][i] == 0)
			{
				MATRIX[1][i] = MATRIX[0][i];
				MATRIX[0][i] = 0;
			}
			if (MATRIX[2][i] == 0)
			{
				MATRIX[2][i] = MATRIX[1][i];
				MATRIX[1][i] = MATRIX[0][i];
				MATRIX[0][i] = 0;
			}
			if (MATRIX[3][i] == 0)
			{
				MATRIX[3][i] = MATRIX[2][i];
				MATRIX[2][i] = MATRIX[1][i];
				MATRIX[1][i] = MATRIX[0][i];
				MATRIX[0][i] = 0;
			}

			if ((MATRIX[0][i] == MATRIX[1][i]) && (MATRIX[2][i] == MATRIX[3][i]))
			{
				SCORE += MATRIX[3][i];
				SCORE += MATRIX[1][i];
				MATRIX[3][i] *= 2;
				MATRIX[2][i] = MATRIX[1][i] * 2;
				MATRIX[1][i] = 0;
				MATRIX[0][i] = 0;
				continue;
			}

			for (j = 2; j >= 0; j--)
			{
				if (MATRIX[j][i] == MATRIX[j + 1][i])
				{
					SCORE += MATRIX[j][i];
					MATRIX[j][i] = 0;
					MATRIX[j + 1][i] *= 2;
				}
			}

			if (MATRIX[1][i] == 0)
			{
				MATRIX[1][i] = MATRIX[0][i];
				MATRIX[0][i] = 0;
			}
			if (MATRIX[2][i] == 0)
			{
				MATRIX[2][i] = MATRIX[1][i];
				MATRIX[1][i] = MATRIX[0][i];
				MATRIX[0][i] = 0;
			}
			if (MATRIX[3][i] == 0)
			{
				MATRIX[3][i] = MATRIX[2][i];
				MATRIX[2][i] = MATRIX[1][i];
				MATRIX[1][i] = MATRIX[0][i];
				MATRIX[0][i] = 0;
			}
		}
		put_new_number();
	}

	if (direction == 3)
	{
		for (i = 0; i < 4; i++)
		{
			if (MATRIX[i][2] == 0)
			{
				MATRIX[i][2] = MATRIX[i][3];
				MATRIX[i][3] = 0;
			}
			if (MATRIX[i][1] == 0)
			{
				MATRIX[i][1] = MATRIX[i][2];
				MATRIX[i][2] = MATRIX[i][3];
				MATRIX[i][3] = 0;
			}
			if (MATRIX[i][0] == 0)
			{
				MATRIX[i][0] = MATRIX[i][1];
				MATRIX[i][1] = MATRIX[i][2];
				MATRIX[i][2] = MATRIX[i][3];
				MATRIX[i][3] = 0;
			}

			if ((MATRIX[i][0] == MATRIX[i][1]) && (MATRIX[i][2] == MATRIX[i][3]))
			{
				SCORE += MATRIX[i][0];
				SCORE += MATRIX[i][2];
				MATRIX[i][0] *= 2;
				MATRIX[i][1] = MATRIX[i][2] * 2;
				MATRIX[i][2] = 0;
				MATRIX[i][3] = 0;
				continue;
			}

			for (j = 0; j <= 2; j++)
			{
				if (MATRIX[i][j] == MATRIX[i][j + 1])
				{
					SCORE += MATRIX[i][j];
					MATRIX[i][j] *= 2;
					MATRIX[i][j + 1] = 0;
				}
			}

			if (MATRIX[i][2] == 0)
			{
				MATRIX[i][2] = MATRIX[i][3];
				MATRIX[i][3] = 0;
			}
			if (MATRIX[i][1] == 0)
			{
				MATRIX[i][1] = MATRIX[i][2];
				MATRIX[i][2] = MATRIX[i][3];
				MATRIX[i][3] = 0;
			}
			if (MATRIX[i][0] == 0)
			{
				MATRIX[i][0] = MATRIX[i][1];
				MATRIX[i][1] = MATRIX[i][2];
				MATRIX[i][2] = MATRIX[i][3];
				MATRIX[i][3] = 0;
			}
		}
		put_new_number();
	}

	if (direction == 4)
	{
		for (i = 0; i < 4; i++)
		{
			if (MATRIX[i][1] == 0)
			{
				MATRIX[i][1] = MATRIX[i][0];
				MATRIX[i][0] = 0;
			}
			if (MATRIX[i][2] == 0)
			{
				MATRIX[i][2] = MATRIX[i][1];
				MATRIX[i][1] = MATRIX[i][0];
				MATRIX[i][0] = 0;
			}
			if (MATRIX[i][3] == 0)
			{
				MATRIX[i][3] = MATRIX[i][2];
				MATRIX[i][2] = MATRIX[i][1];
				MATRIX[i][1] = MATRIX[i][0];
				MATRIX[i][0] = 0;
			}

			if ((MATRIX[i][0] == MATRIX[i][1]) && (MATRIX[i][2] == MATRIX[i][3]))
			{
				SCORE += MATRIX[i][3];
				SCORE += MATRIX[i][1];
				MATRIX[i][3] *= 2;
				MATRIX[i][2] = MATRIX[i][1] * 2;
				MATRIX[i][1] = 0;
				MATRIX[i][0] = 0;
				continue;
			}

			for (j = 2; j >= 0; j--)
			{
				if (MATRIX[i][j] == MATRIX[i][j + 1])
				{
					SCORE += MATRIX[i][j];
					MATRIX[i][j] = 0;
					MATRIX[i][j + 1] *= 2;
				}
			}

			if (MATRIX[i][1] == 0)
			{
				MATRIX[i][1] = MATRIX[i][0];
				MATRIX[i][0] = 0;
			}
			if (MATRIX[i][2] == 0)
			{
				MATRIX[i][2] = MATRIX[i][1];
				MATRIX[i][1] = MATRIX[i][0];
				MATRIX[i][0] = 0;
			}
			if (MATRIX[i][3] == 0)
			{
				MATRIX[i][3] = MATRIX[i][2];
				MATRIX[i][2] = MATRIX[i][1];
				MATRIX[i][1] = MATRIX[i][0];
				MATRIX[i][0] = 0;
			}
		}
		put_new_number();
	}

}

void put_new_number()
{
	int i, j, index[15] = {0}, count = 0, num, temp;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (MATRIX[i][j] == 0)
			{
				index[count] = i * 4 + j;
				count++;
			}
		}
	}
	temp = rand() % count;
	num = rand() % 2;
	MATRIX[index[temp] / 4][index[temp] % 4] = num * 2 + 2;
}

bool game_over()
{
	int i, j;
	bool count = true;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (MATRIX[i][j] == 0)
			{
				count = false;
				break;
			}
		}
	}
	if (count) return true;
	else       return false;
}