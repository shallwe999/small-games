/************  ɨ����Ϸ  �����ˣ�shallwe  ����ʱ�䣺2017-5-6  ************/
#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

#define XNUM 30  // �ɵ��ڳ���
#define YNUM 16  // �ɵ��ڿ��
int lei[YNUM][XNUM] = { 0 };  // -1��ʾ�÷������ף��Ǹ�������ʾ�����Ա��׵�����
bool open[YNUM][XNUM] = { 0 };  // �򿪸÷���
int cursorx = XNUM / 2, cursory = YNUM / 2;  // ���
long time1;  // ��Ϸ��ʼʱ��

int init1();
void init2(int mine, int& count);
void print_area(long used_time);
void set_cursor(bool first);
void find_zero();
int game_over();

int main()
{
	int mine, count = 0;
	char ch1;
	mine = init1();
	init2(mine, count);
	print_area(0);

	// ��һ�β������ܲ���
	set_cursor(1);
	system("cls");
	cout << endl << endl << endl << endl;
	print_area(0);
	while (game_over() == 2)
	{
		init2(mine, count);
		system("cls");
		cout << endl << endl << endl << endl;
		print_area(0);
	}
	time1 = time(0);

	while(!game_over())
	{
		set_cursor(0);
		system("cls");
		cout << endl << endl << endl << endl;
		print_area(time(0) - time1);
	};

	if (game_over() == 1)
	{
		system("cls");
		cout << endl << endl << endl << endl;
		print_area(-1);
		cout << endl << "    You win!! ( mine: " << mine << " )" << endl;
		cout << "    TIME: " << time(0) - time1 << endl << endl;
		cout << "    Press space to continue." << endl << endl;
		do
		{
			ch1 = _getch();
		} while (ch1 != ' ');
	}
	else
	{
		system("cls");
		cout << endl << endl << endl << endl;
		print_area(-1);
		cout << endl << "    You lose. ( mine: " << mine << " )" << endl;
		cout << "    TIME: " << time(0) - time1 << endl << endl;
		cout << "    Press space to continue." << endl << endl;
		do
		{
			ch1 = _getch();
		} while (ch1 != ' ');
	}

	return 0;
}

int init1()  // ��ʼ��������
{
	int mine;
	cout << endl << endl << "    Welcome to Minesweeper!~~~ (Written by shallwe) " << endl;
	cout << "    Please input the number of mines in " << XNUM << " * " << YNUM << " area. (99 is Expert Mode) : ";
	cin >> mine;
	return mine;
}

void init2(int mine, int& count)  // ������ף��趨�÷�����Ϣ
{
	int i, j, index;
	count++;
	srand((unsigned)time(0) + count);
	for (i = 0; i < YNUM; i++)  // ����
		for (j = 0; j < XNUM; j++)
			lei[i][j] = { 0 };

	for (i = 0; i < mine; i++)  // ����
	{
		index = rand() % (XNUM * YNUM);
		if (lei[index / XNUM][index % XNUM] == -1) i--;
		lei[index / XNUM][index % XNUM] = -1;
	}

	for (i = 1; i < YNUM - 1; i++)  // �ж��в�������Ϣ
	{
		for (j = 1; j < XNUM - 1; j++)
		{
			if (lei[i][j] != -1)
			{
				if (lei[i - 1][j - 1] == -1) lei[i][j]++;
				if (lei[i - 1][j] == -1) lei[i][j]++;
				if (lei[i - 1][j + 1] == -1) lei[i][j]++;
				if (lei[i][j - 1] == -1) lei[i][j]++;
				if (lei[i][j + 1] == -1) lei[i][j]++;
				if (lei[i + 1][j - 1] == -1) lei[i][j]++;
				if (lei[i + 1][j] == -1) lei[i][j]++;
				if (lei[i + 1][j + 1] == -1) lei[i][j]++;
			}
		}
	}

	for (j = 1; j < XNUM - 1; j++)  // �ж��ϲ�������Ϣ
	{
		if (lei[0][j] != -1)
		{
			if (lei[0][j - 1] == -1) lei[0][j]++;
			if (lei[0][j + 1] == -1) lei[0][j]++;
			if (lei[1][j - 1] == -1) lei[0][j]++;
			if (lei[1][j] == -1) lei[0][j]++;
			if (lei[1][j + 1] == -1) lei[0][j]++;
		}
	}

	for (j = 1; j < XNUM - 1; j++)  // �ж��²�������Ϣ
	{
		if (lei[YNUM - 1][j] != -1)
		{
			if (lei[YNUM - 1][j - 1] == -1) lei[YNUM - 1][j]++;
			if (lei[YNUM - 1][j + 1] == -1) lei[YNUM - 1][j]++;
			if (lei[YNUM - 2][j - 1] == -1) lei[YNUM - 1][j]++;
			if (lei[YNUM - 2][j] == -1) lei[YNUM - 1][j]++;
			if (lei[YNUM - 2][j + 1] == -1) lei[YNUM - 1][j]++;
		}
	}

	for (i = 1; i < YNUM - 1; i++)  // �ж��󲿷�����Ϣ
	{
		if (lei[i][0] != -1)
		{
			if (lei[i - 1][0] == -1) lei[i][0]++;
			if (lei[i - 1][1] == -1) lei[i][0]++;
			if (lei[i][1] == -1) lei[i][0]++;
			if (lei[i + 1][0] == -1) lei[i][0]++;
			if (lei[i + 1][1] == -1) lei[i][0]++;
		}
	}

	for (i = 1; i < YNUM - 1; i++)  // �ж��Ҳ�������Ϣ
	{
		if (lei[i][XNUM - 1] != -1)
		{
			if (lei[i - 1][XNUM - 1] == -1) lei[i][XNUM - 1]++;
			if (lei[i - 1][XNUM - 2] == -1) lei[i][XNUM - 1]++;
			if (lei[i][XNUM - 2] == -1) lei[i][XNUM - 1]++;
			if (lei[i + 1][XNUM - 1] == -1) lei[i][XNUM - 1]++;
			if (lei[i + 1][XNUM - 2] == -1) lei[i][XNUM - 1]++;
		}
	}

	// �жϽ��䷽����Ϣ
	if (lei[0][0] != -1)
	{
		if (lei[1][0] == -1) lei[0][0]++;
		if (lei[0][1] == -1) lei[0][0]++;
		if (lei[1][1] == -1) lei[0][0]++;
	}
	if (lei[0][XNUM - 1] != -1)
	{
		if (lei[1][XNUM - 1] == -1) lei[0][XNUM - 1]++;
		if (lei[0][XNUM - 2] == -1) lei[0][XNUM - 1]++;
		if (lei[1][XNUM - 2] == -1) lei[0][XNUM - 1]++;
	}
	if (lei[YNUM - 1][0] != -1)
	{
		if (lei[YNUM - 2][0] == -1) lei[YNUM - 1][0]++;
		if (lei[YNUM - 1][1] == -1) lei[YNUM - 1][0]++;
		if (lei[YNUM - 2][1] == -1) lei[YNUM - 1][0]++;
	}
	if (lei[YNUM - 1][XNUM - 1] != -1)
	{
		if (lei[YNUM - 2][XNUM - 1] == -1) lei[YNUM - 1][XNUM - 1]++;
		if (lei[YNUM - 1][XNUM - 2] == -1) lei[YNUM - 1][XNUM - 1]++;
		if (lei[YNUM - 2][XNUM - 2] == -1) lei[YNUM - 1][XNUM - 1]++;
	}
}

void print_area(long used_time)
{
	int i, j;
	char lei0 = 2, templei[YNUM][XNUM], temp = lei[cursory][cursorx];
	for (i = 0; i < YNUM; i++)
	{
		for (j = 0; j < XNUM; j++)  // ���ӻ�����
		{
			if (lei[i][j] == -1)
				templei[i][j] = 15;
			else
				templei[i][j] = lei[i][j] + '0';
		}
	}
	templei[cursory][cursorx] = 4;
	cout << "     -------------------------------------------------------------" << endl;
	for (i = 0; i < YNUM; i++)
	{
		cout << "    | ";
		for (j = 0; j < XNUM; j++)
		{
			if (open[i][j] || templei[i][j] == 4) cout << templei[i][j] << " ";
			else cout << "  ";
		}
		cout << "|" << endl;
	}
	cout << "     -------------------------------------------------------------" << endl;
	lei[cursory][cursorx] = temp;

	if (used_time >= 0)
		cout << endl << "    TIME: " << used_time << endl;
}

void set_cursor(bool first)
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
		cout << endl << endl << endl << endl;
		if(first)  print_area(0);
		else       print_area(time(0) - time1);
	}
	open[cursory][cursorx] = 1;
	find_zero();

}

void find_zero()
{
	int i, j;
	bool flag = 0;  // ���ظ�һ������
	for (i = 1; i < YNUM - 1; i++)  // �ж��в�������Ϣ
	{
		for (j = 1; j < XNUM - 1; j++)
		{
			if (lei[i][j] == 0 && open[i][j])
			{
				if (!(open[i][j + 1] && open[i][j - 1] && open[i - 1][j - 1] && open[i - 1][j] && open[i - 1][j + 1] && open[i + 1][j - 1] && open[i + 1][j] && open[i + 1][j + 1]))
				{
					open[i][j + 1] = 1;
					open[i][j - 1] = 1; 
					open[i - 1][j - 1] = 1; 
					open[i - 1][j] = 1; 
					open[i - 1][j + 1] = 1; 
					open[i + 1][j - 1] = 1; 
					open[i + 1][j] = 1; 
					open[i + 1][j + 1] = 1;
					flag = 1;
				}
			}
		}
	}

	for (i = 1; i < YNUM - 1; i++)  // �ж��󲿷�����Ϣ
	{
		if (lei[i][0] == 0 && open[i][0])
		{
			if (!(open[i][1] && open[i - 1][0] && open[i - 1][1] && open[i + 1][0] && open[i + 1][1]))
			{
				open[i][1] = 1;
				open[i - 1][0] = 1;
				open[i - 1][1] = 1;
				open[i + 1][0] = 1;
				open[i + 1][1] = 1;
				flag = 1;
			}
		}
	}

	for (i = 1; i < YNUM - 1; i++)  // �ж��Ҳ�������Ϣ
	{
		if (lei[i][XNUM - 1] == 0 && open[i][XNUM - 1])
		{
			if (!(open[i][XNUM - 2] && open[i - 1][XNUM - 1] && open[i - 1][XNUM - 2] && open[i + 1][XNUM - 1] && open[i + 1][XNUM - 2]))
			{
				open[i][XNUM - 2] = 1;
				open[i - 1][XNUM - 1] = 1;
				open[i - 1][XNUM - 2] = 1;
				open[i + 1][XNUM - 1] = 1;
				open[i + 1][XNUM - 2] = 1;
				flag = 1;
			}
		}
	}

	for (j = 1; j < XNUM - 1; j++)  // �ж��ϲ�������Ϣ
	{
		if (lei[0][j] == 0 && open[0][j])
		{
			if (!(open[0][j + 1] && open[0][j - 1] && open[1][j - 1] && open[1][j] && open[1][j + 1]))
			{
				open[0][j + 1] = 1;
				open[0][j - 1] = 1;
				open[1][j - 1] = 1;
				open[1][j] = 1;
				open[1][j + 1] = 1;
				flag = 1;
			}
		}
	}

	for (j = 1; j < XNUM - 1; j++)  // �ж��²�������Ϣ
	{
		if (lei[YNUM - 1][j] == 0 && open[YNUM - 1][j])
		{
			if (!(open[YNUM - 1][j + 1] && open[YNUM - 1][j - 1] && open[YNUM - 2][j - 1] && open[YNUM - 2][j] && open[YNUM - 2][j + 1]))
			{
				open[YNUM - 1][j + 1] = 1;
				open[YNUM - 1][j - 1] = 1;
				open[YNUM - 2][j - 1] = 1;
				open[YNUM - 2][j] = 1;
				open[YNUM - 2][j + 1] = 1;
				flag = 1;
			}
		}
	}

	if (lei[0][0] == 0 && open[0][0])  // �жϽ��䷽����Ϣ
	{
		if (!(open[0][1] && open[1][0] && open[1][1]))
		{
			open[0][1] = 1;
			open[1][0] = 1;
			open[1][1] = 1;
			flag = 1;
		}
	}
	if (lei[YNUM - 1][0] == 0 && open[YNUM - 1][0])
	{
		if (!(open[YNUM - 1][1] && open[YNUM - 2][0] && open[YNUM - 1][1]))
		{
			open[YNUM - 1][1] = 1;
			open[YNUM - 2][0] = 1;
			open[YNUM - 2][1] = 1;
			flag = 1;
		}
	}
	if (lei[0][XNUM - 1] == 0 && open[0][XNUM - 1])
	{
		if (!(open[0][XNUM - 2] && open[1][XNUM - 1] && open[1][XNUM - 2]))
		{
			open[0][XNUM - 2] = 1;
			open[1][XNUM - 1] = 1;
			open[1][XNUM - 2] = 1;
			flag = 1;
		}
	}
	if (lei[0][XNUM - 1] == 0 && open[0][XNUM - 1])
	{
		if (!(open[0][XNUM - 2] && open[1][XNUM - 1] && open[1][XNUM - 2]))
		{
			open[0][XNUM - 2] = 1;
			open[1][XNUM - 1] = 1;
			open[1][XNUM - 2] = 1;
			flag = 1;
		}
	}
	if (lei[YNUM - 1][XNUM - 1] == 0 && open[YNUM - 1][XNUM - 1])
	{
		if (!(open[YNUM - 1][XNUM - 2] && open[YNUM - 2][XNUM - 1] && open[YNUM - 2][XNUM - 2]))
		{
			open[YNUM - 1][XNUM - 2] = 1;
			open[YNUM - 2][XNUM - 1] = 1;
			open[YNUM - 2][XNUM - 2] = 1;
			flag = 1;
		}
	}

	if (flag) find_zero();
}

int game_over()  // ʧ�ܷ���2���ɹ�����1����������0
{
	int i, j;
	bool flag = 0;
	for (i = 0; i < YNUM; i++)
		for (j = 0; j < XNUM; j++)
			if (open[i][j] && (lei[i][j] == -1))
				return 2;
	for (i = 0; i < YNUM; i++)
	{
		for (j = 0; j < XNUM; j++)
		{
			if ((!open[i][j]) && (lei[i][j] != -1))
			{
				flag = 1;
				goto finish;
			}
		}
	}
finish:
	if(flag) return 0;
	else     return 1;
}