/************  五子棋游戏  制作人：shallwe  制作时间：2017-5-4  ************/
#include <iostream>
#include <conio.h>

using namespace std;

#define XNUM 20
#define YNUM 20
char qipan[YNUM][XNUM] = { 0 };
int cursorx = XNUM / 2, cursory = YNUM / 2;

void init();
void print_qipan();
void set_qizi(int qizi);
int game_over();

int main()
{
	init();
	print_qipan();
	cout << "  白子操作：wsad移动，q下子" << endl;
	cout << "  黑子操作：8546移动，\\下子" << endl;
	while (1)
	{	
		cout << "  轮到白子了~" << endl;
		set_qizi(2);
		system("cls");
		cout << endl;
		print_qipan();
		if ( game_over() ) break;
		cout << "  轮到黑子了~" << endl;
		set_qizi(1);
		system("cls");
		cout << endl;
		print_qipan();
		if ( game_over() ) break;
	}

	if (game_over() == 2)
		cout << "  游戏结束！黑子胜~" << endl << endl;
	else if (game_over() == 1)
		cout << "  游戏结束！白子胜~" << endl << endl;
	else if (game_over() == 3)
		cout << "  游戏结束！平局~~~" << endl << endl;
	return 0;
}

void init()
{
	int i, j;
	for (i = 0; i < YNUM; i++)
	{
		for (j = 0; j < XNUM; j++)
		{
			qipan[i][j] = 32;
		}
	}
	cout << "  欢迎来到五子棋游戏！（shallwe创作）请黑子先下棋~~" << endl;
}

void print_qipan()
{
	int i, j;
	char temp = qipan[cursory][cursorx];
	qipan[cursory][cursorx] = 63;
	cout << endl << endl;
	cout << "    ----------------------------------------" << endl;
	for (i = 0; i < YNUM; i++)
	{
		cout << "   |";
		for (j = 0; j < XNUM; j++)
		{
			cout << qipan[i][j] << ' ';
		}
		cout << "|" << endl;
	}
	cout << "    ----------------------------------------" << endl << endl;
	qipan[cursory][cursorx] = temp;
}

void set_qizi(int qizi)
{
	char ch1;
	set:
	if (qizi == 1)  // 黑子下棋
	{
		while (1)
		{
			ch1 = _getch();
			if (ch1 == 'q') break;
			else if (ch1 == 'w')
			{
				if (cursory == 0) cursory = YNUM - 1;
				else cursory--;
			}
			else if (ch1 == 's')
			{
				if (cursory == YNUM - 1) cursory = 0;
				else cursory++;
			}
			else if (ch1 == 'a')
			{
				if (cursorx == 0) cursorx = XNUM - 1;
				else cursorx--;
			}
			else if (ch1 == 'd')
			{
				if (cursorx == XNUM - 1) cursorx = 0;
				else cursorx++;
			}
			system("cls");
			cout << endl;
			print_qipan();
		}
	}
	else  // 白子下棋
	{
		while (1)
		{
			ch1 = _getch();
			if (ch1 == '\\') break;
			else if (ch1 == '8')
			{
				if (cursory == 0) cursory = YNUM - 1;
				else cursory--;
			}
			else if (ch1 == '5')
			{
				if (cursory == YNUM - 1) cursory = 0;
				else cursory++;
			}
			else if (ch1 == '4')
			{
				if (cursorx == 0) cursorx = XNUM - 1;
				else cursorx--;
			}
			else if (ch1 == '6')
			{
				if (cursorx == XNUM - 1) cursorx = 0;
				else cursorx++;
			}
			system("cls");
			cout << endl;
			print_qipan();
		}
	}
	if (qipan[cursory][cursorx] != 32)
	{
		if (cursorx == XNUM - 1) cursorx = 0;
		else cursorx++;
		system("cls");
		cout << endl;
		print_qipan();
		cout << "  此处已有棋子！~~" << endl;
		goto set;
	}
	qipan[cursory][cursorx] = qizi;
	if (cursorx == XNUM - 1) cursorx = 0;
	else cursorx++;
}

int game_over()  // 输出1黑子胜，输出2白子胜，输出0游戏继续，输出3为平局
{
	int i, j;
	bool pingju = 1;
	for (i = 0; i < YNUM; i++)
	{
		for (j = 0; j < XNUM; j++)
		{
			if (qipan[i][j] == 32)
			{
				pingju = 0;
				break;
			}
		}
	}
	if (pingju) return 3;

	for (i = 0; i < YNUM; i++)
	{
		for (j = 0; j < XNUM - 4; j++)
		{
			if (qipan[i][j] == 1 && qipan[i][j + 1] == 1 && qipan[i][j + 2] == 1 && qipan[i][j + 3] == 1 && qipan[i][j + 4] == 1)
				return 1;
			if (qipan[i][j] == 2 && qipan[i][j + 1] == 2 && qipan[i][j + 2] == 2 && qipan[i][j + 3] == 2 && qipan[i][j + 4] == 2)
				return 2;
		}
	}

	for (i = 0; i < YNUM - 4; i++)
	{
		for (j = 0; j < XNUM; j++)
		{
			if (qipan[i][j] == 1 && qipan[i + 1][j] == 1 && qipan[i + 2][j] == 1 && qipan[i + 3][j] == 1 && qipan[i + 4][j] == 1)
				return 1;
			if (qipan[i][j] == 2 && qipan[i + 1][j] == 2 && qipan[i + 2][j] == 2 && qipan[i + 3][j] == 2 && qipan[i + 4][j] == 2)
				return 2;
		}
	}

	for (i = 0; i < YNUM - 4; i++)
	{
		for (j = 0; j < XNUM - 4; j++)
		{
			if (qipan[i][j] == 1 && qipan[i + 1][j + 1] == 1 && qipan[i + 2][j + 2] == 1 && qipan[i + 3][j + 3] == 1 && qipan[i + 4][j + 4] == 1)
				return 1;
			if (qipan[i][j] == 2 && qipan[i + 1][j + 1] == 2 && qipan[i + 2][j + 2] == 2 && qipan[i + 3][j + 3] == 2 && qipan[i + 4][j + 4] == 2)
				return 2;
		}
	}

	for (i = 0; i < YNUM - 4; i++)
	{
		for (j = 4; j < XNUM; j++)
		{
			if (qipan[i][j] == 1 && qipan[i + 1][j - 1] == 1 && qipan[i + 2][j - 2] == 1 && qipan[i + 3][j - 3] == 1 && qipan[i + 4][j - 4] == 1)
				return 1;
			if (qipan[i][j] == 2 && qipan[i + 1][j - 1] == 2 && qipan[i + 2][j - 2] == 2 && qipan[i + 3][j - 3] == 2 && qipan[i + 4][j - 4] == 2)
				return 2;
		}
	}

	return 0;
}