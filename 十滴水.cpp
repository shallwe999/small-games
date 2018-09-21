/************  十滴水游戏 制作人：shallwe  制作时间：2017-5-8  ************/
#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>

using namespace std;

#define XNUM 6
#define YNUM 6
int stage = 0;  // 关卡
int water[6][6];  // 网格水滴数
int remain = 9;  // 剩余水滴数（保证第一关是10滴）
int cursorx = 0, cursory = 0;  // 光标

void init();
void stage_init();
void print_area(bool cursor);
void set_cursor();
void running();
int game_result();

int main()
{
	init();
	do
	{
		if (stage != 0)
		{
			cout << endl << "    Stage clear!~~~" << endl;
			Sleep(1500);  // 延时1.5s
			if (stage == 30)
			{
				cout << "    Congratulations! You pass 30 stages! Incredible!" << endl;
				break;
			}
			cout << "    Stage " << stage + 1 << " is coming!~~~" << endl;
			Sleep(1500);  // 延时1.5s
			system("cls");
		}
		stage++;
		stage_init();
		print_area(1);
		do
		{
			set_cursor();
			if(water[cursory][cursorx] == 5)  running();
			system("cls");
			cout << endl << endl << endl;
			print_area(1);
		} while (game_result() == 0);
	} while (game_result() == 2);
	if (game_result() == 2)
		cout << "    Game over!~~~" << endl;

	return 0;
}

void init()  // 开始界面初始化
{
	char ch1;
	cout << endl << endl << "    Welcome to Ten Drops!~~~ (Written by shallwe) " << endl;
	cout << "    Press space to start!" << endl;
	do
	{
		ch1 = _getch();
	}
	while (ch1 != ' ');
	system("cls");
}

void stage_init()  // 关卡水滴初始化
{
	int i, j, index, count;
	remain++;
	if (stage <= 5)  count = 75;  // 设置难度
	else if (stage <= 10)  count = 65;
	else if (stage <= 15)  count = 55;
	else if (stage <= 20)  count = 50;
	else if (stage <= 25)  count = 45;
	else  count = 40;
	srand((unsigned)time(0) + stage);
	cout << endl << endl << endl;
	for (i = 0; i < YNUM; i++)  // 水滴清零
		for (j = 0; j < XNUM; j++)
			water[i][j] = 0;
	for (i = 0; i < count; i++)  // 布水滴
	{
		do
		{
			index = rand() % (XNUM * YNUM);
		}
		while (water[index / XNUM][index % XNUM] >= 4);
			water[index / XNUM][index % XNUM]++;
	}
}

void print_area(bool cursor)  // cursor为1则显示光标
{
	int i, j;
	char tempwater[YNUM][XNUM];

	for (i = 0; i < YNUM; i++)  // 可视化处理
		for (j = 0; j < XNUM; j++)
		{
			if (water[i][j] == 0)
				tempwater[i][j] = ' ';
			else if (water[i][j] >= 11 && water[i][j] <= 14)
				tempwater[i][j] = water[i][j] + 13;
			else  tempwater[i][j] = water[i][j] + '0';
		}
	if(cursor)  tempwater[cursory][cursorx] = 4;

	cout << endl << "    Stage " << stage << endl;
	cout << endl << "    Drops: " << remain << endl;
	cout << endl << "     -------------" << endl;
	for (i = 0; i < YNUM; i++)
	{
		cout << "    |";
		for (j = 0; j < XNUM; j++)
		{
			cout << " " << tempwater[i][j];
		}
		cout << " |" << endl;
	}
	cout << "     -------------" << endl;
}

void set_cursor()
{
	char ch1;
	while (1)
	{
		ch1 = _getch();
		if (ch1 == ' ') break;
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
		cout << endl << endl << endl;
		print_area(1);
	}
	remain--;
	water[cursory][cursorx]++;
	system("cls");
	cout << endl << endl << endl;
	print_area(1);
}

void running()  // 水滴戳破之后执行
{
	int i, j, k, count_running = 0, countx[36], county[36], bonus = 1;
	bool continue_running = 1;
	water[cursory][cursorx] = 0;
	if (cursory != 0)
	{
		if (water[cursory - 1][cursorx] == 0)
			water[cursory - 1][cursorx] = 11;  // 向上运动水滴
		else
			water[cursory - 1][cursorx]++;
	}
	if (cursory != YNUM - 1)
	{
		if (water[cursory + 1][cursorx] == 0)
			water[cursory + 1][cursorx] = 12;  // 向下运动水滴
		else
			water[cursory + 1][cursorx]++;
	}
	if (cursorx != XNUM - 1)
	{
		if (water[cursory][cursorx + 1] == 0)
			water[cursory][cursorx + 1] = 13;  // 向右运动水滴
		else
			water[cursory][cursorx + 1]++;
	}
	if (cursorx != 0)
	{
		if (water[cursory][cursorx - 1] == 0)
			water[cursory][cursorx - 1] = 14;  // 向左运动水滴
		else
			water[cursory][cursorx - 1]++;
	}
	while (continue_running)  // 判断有无还在运动的水滴
	{
		continue_running = 0;
		count_running = 0;
		Sleep(500);  // 延时0.5s
		system("cls");
		cout << endl << endl << endl;
		print_area(0);
		for (i = 0; i < YNUM; i++)
		{
			for (j = 0; j < XNUM; j++)
			{
				if ((water[i][j] >= 5 && water[i][j] <= 8) || (water[i][j] >= 11 && water[i][j] <= 14))
				{
					countx[count_running] = j;
					county[count_running] = i;
					count_running++;
				}
				if (water[i][j] >= 15)  // 暂时清除运动水滴碰撞的bug
					water[i][j] = 0;
			}
		}

		for (k = 0; k < count_running; k++)
		{
			j = countx[k];
			i = county[k];
			if (water[i][j] >= 5 && water[i][j] <= 8)  // 判断新的被戳破水滴
			{
				bonus++;
				if (bonus == 3)  // 水滴奖励
				{
					remain++;
					bonus = 0;
				}
				water[i][j] = 0;
				if (i != 0)
				{
					if (water[i - 1][j] == 0)
						water[i - 1][j] = 11;  // 向上运动水滴
					else
						water[i - 1][j]++;
				}
				if (i != YNUM - 1)
				{
					if (water[i + 1][j] == 0)
						water[i + 1][j] = 12;  // 向下运动水滴
					else
						water[i + 1][j]++;
				}
				if (j != XNUM - 1)
				{
					if (water[i][j + 1] == 0)
						water[i][j + 1] = 13;  // 向右运动水滴
					else
						water[i][j + 1]++;
				}
				if (j != 0)
				{
					if (water[i][j - 1] == 0)
						water[i][j - 1] = 14;  // 向左运动水滴
					else
						water[i][j - 1]++;
				}
				continue_running = 1;
			}

			else if (water[i][j] == 11)  // 移动向上运动的水滴
			{
				water[i][j] = 0;
				if (i != 0 && water[i - 1][j] != 0)
				{
					water[i - 1][j]++;
					if (water[i - 1][j] >= 5 && water[i - 1][j] <= 8)
						continue_running = 1;
				}
				else if (i != 0)
				{
					water[i - 1][j] = 11;
					continue_running = 1;
				}
			}

			else if (water[i][j] == 12)  // 移动向下运动的水滴
			{
				water[i][j] = 0;
				if (i != YNUM - 1 && water[i + 1][j] != 0)
				{
					water[i + 1][j]++;
					if (water[i + 1][j] >= 5 && water[i + 1][j] <= 8)
						continue_running = 1;
				}
				else if (i != YNUM - 1)
				{
					water[i + 1][j] = 12;
					continue_running = 1;
				}
			}

			else if (water[i][j] == 13)  // 移动向右运动的水滴
			{
				water[i][j] = 0;
				if (j != XNUM - 1 && water[i][j + 1] != 0)
				{
					water[i][j + 1]++;
					if (water[i][j + 1] >= 5 && water[i][j + 1] <= 8)
						continue_running = 1;
				}
				else if (j != XNUM - 1)
				{
					water[i][j + 1] = 13;
					continue_running = 1;
				}
			}

			else if (water[i][j] == 14)  // 移动向左运动的水滴
			{
				water[i][j] = 0;
				if (j != 0 && water[i][j - 1] != 0)
				{
					water[i][j - 1]++;
					if (water[i][j - 1] >= 5 && water[i][j - 1] <= 8)
						continue_running = 1;
				}
				else if (j != 0)
				{
					water[i][j - 1] = 14;
					continue_running = 1;
				}
			}
		}
	}
	Sleep(500);  // 延时0.5s
	system("cls");
	cout << endl << endl << endl;
	print_area(1);

}

int game_result()  // 返回0游戏继续，返回1游戏结束，返回2进入下一关
{
	int i, j;
	bool flag_win = 1;
	for (i = 0; i < YNUM; i++)
		for (j = 0; j < XNUM; j++)
			if (water[i][j] != 0)  flag_win = 0;
	if (flag_win)  return 2;
	if (remain)    return 0;
	else           return 1;
}