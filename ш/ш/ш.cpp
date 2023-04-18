#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>

#define UP 72
#define DOWN 80
#define ESC 27
#define ENTER 13
#define SPACE 32

int action();

using namespace std;

int x = 35, y = 12;
string choice[] = { "Ваш счет: ", "Ваша Задолженность: ", "Ваш Доход: ", "Погасить кредит", "Сделать инвестицию" };
int active_button = 3;

double crd, dxd, sum, crdn;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void GoToXY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}

void ConsoleCursorVisible(bool show, short size)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show;
	structCursorInfo.dwSize = size;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

void act1()
{
	system("cls");

	x = 35, y = 12;

	GoToXY(x, y);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
	cout << "Введите сумму: ";
	double col;
	cin >> col;
	while (col > sum)
	{
		system("cls");

		x = 35, y = 12;

		GoToXY(x, y);
		SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
		cout << "Недостаточно средств!" << endl;

		GoToXY(x, ++y);

		cout << "Введите еще: ";

		cin >> col;
	}
	crd *= 1.05;
	sum -= col;
	crd -= col;
	sum += dxd;

	if (crd > crdn * 10)
	{
		system("cls");
		x = 35, y = 12;

		GoToXY(x, y);
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
		cout << "Вы проиграли!";
		GoToXY(x, 2 * y);
		exit(0);
	}

	if (crd <= 0)
	{
		system("cls");
		x = 35, y = 12;

		GoToXY(x, y);
		SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
		cout << "Вы выиграли!";
		GoToXY(x, 2 * y);
		exit(0);
	}
}

void act2()
{
	system("cls");

	x = 35, y = 12;

	GoToXY(x, y);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
	cout << "Введите сумму: ";
	double col;
	cin >> col;
	while (col > sum)
	{
		system("cls");

		x = 35, y = 12;

		GoToXY(x, y);
		SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
		cout << "Недостаточно средств!" << endl;

		GoToXY(x, ++y);

		cout << "Введите еще: ";

		cin >> col;
	}
	sum -= col;
	crd *= 1.05;
	col = col * (rand() % 21 + 1);
	dxd += col / 100;
	sum += dxd;
	if (crd > crdn * 10)
	{
		system("cls");
		x = 35, y = 12;

		GoToXY(x, y);
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
		cout << "Вы проиграли!";
		GoToXY(x, 2 * y);
		exit(0);
	}
}

int action()
{
	while (true)
	{
		system("cls");

		x = 35, y = 9;

		GoToXY(x, y);

		for (int i = 0; i < 5; i++)
		{
			if (i == 0)
			{
				GoToXY(x, y++);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
				cout << choice[i] << sum << endl;
			}
			else if (i == 1)
			{
				GoToXY(x, y++);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
				cout << choice[i] << crd << endl;
			}
			else if (i == 2)
			{
				GoToXY(x, y++);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
				cout << choice[i] << dxd << endl;
			}
			else
			{
				if (i == active_button) {
					SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				}
				else SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
				GoToXY(x, y++);
				cout << choice[i] << endl;
			}
		}

		char ch = _getch();
		if (ch == -32) ch = _getch();

		switch (ch)
		{
		case UP:
			if (active_button == 4)
			{
				--active_button;
			}
			else
			{
				active_button = 4;
			}
			break;
		case DOWN:
			if (active_button == 3)
			{
				++active_button;
			}
			else
			{
				active_button = 3;
			}
			break;
		case ENTER:
			switch (active_button)
			{
			case 3:
				return 1;
				break;
			case 4:
				return 2;
				break;
			default:
				break;
			}
		case ESC:
			exit(0);
		default:
			break;
		}
	}
	return action();
}

int main()
{
	{
		SetConsoleTitle(L"KazakhStyle");
		setlocale(0, "RU");
		ConsoleCursorVisible(false, 100);
	}

	GoToXY(x, y);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
	cout << "Введите сумму кредитa: ";

	cin >> crd;

	crdn = crd;

	system("cls");

	sum = crd - 1000;
	GoToXY(x, y);

	dxd = 50;

	while (crd > 0)
	{
		if (action() == 1)
		{
			act1();
		}
		else
		{
			act2();
		}
	}

	system("pause");
}


