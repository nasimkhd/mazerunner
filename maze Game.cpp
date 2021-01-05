// maze Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Nasim.Khodapanah
#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;

class position
{
public:
	int x;
	int y;
	position()
	{
		x = 0;
		y = 0;
	}
	position(int X, int Y)
	{
		x = X;
		y = Y;
	}
};


void show(int **A, int row, int col)
{
	char ch = 176;
	for (int i = 0; i < col + 1; i++)
	{
		cout << ch << ch;
	}
	cout << ch;
	cout << endl;
	for (int i = 0; i < row; i++)
	{
		cout << ch << " ";
		for (int j = 0; j < col; j++)
		{
			if (A[i][j] == -1)
			{
				cout << ch << ch;
				continue;
			}
			if (A[i][j] == -3)
			{
				cout << "." << " ";
				continue;
			}
			if (A[i][j] == -2)
			{
				cout << "*" << " ";
				continue;
			}
			cout << "  ";
		}
		cout << ch << " ";
		cout << endl;
	}
	for (int i = 0; i < col + 1; i++)
	{
		cout << ch << ch;
	}
	cout << ch;
	cout << endl;
}

void solve(int **A, int row, int col, position start)
{
	//char ch;
	queue<position> que;
	position temppos;

	bool ExistWay = false;
	A[start.x][start.y] = 1;
	que.push(start);

	while (que.size() != 0)
	{
		temppos = que.front();
		//cout<<"*********"<<endl;
		que.pop();

		if (temppos.x > 0)
		{
			if (A[temppos.x - 1][temppos.y] == 0 || A[temppos.x - 1][temppos.y] == -2)
			{
				if (A[temppos.x - 1][temppos.y] == -2)
				{
					ExistWay = true;
					break;
				}
				A[temppos.x - 1][temppos.y] = A[temppos.x][temppos.y] + 1;
				que.push(position(temppos.x - 1, temppos.y));
			}
			//show(A,row,col);
			//cin>>ch;
		}
		if (temppos.x < row - 1)
		{
			if (A[temppos.x + 1][temppos.y] == 0 || A[temppos.x + 1][temppos.y] == -2)
			{
				if (A[temppos.x + 1][temppos.y] == -2)
				{
					ExistWay = true;
					break;
				}
				A[temppos.x + 1][temppos.y] = A[temppos.x][temppos.y] + 1;
				que.push(position(temppos.x + 1, temppos.y));
			}
			//show(A,row,col);
			//cin>>ch;
		}
		if (temppos.y > 0)
		{
			if (A[temppos.x][temppos.y - 1] == 0 || A[temppos.x][temppos.y - 1] == -2)
			{
				if (A[temppos.x][temppos.y - 1] == -2)
				{
					ExistWay = true;
					break;
				}
				A[temppos.x][temppos.y - 1] = A[temppos.x][temppos.y] + 1;
				que.push(position(temppos.x, temppos.y - 1));
			}
			//show(A,row,col);
			//cin>>ch;
		}
		if (temppos.y < col - 1)
		{
			if (A[temppos.x][temppos.y + 1] == 0 || A[temppos.x][temppos.y + 1] == -2)
			{
				if (A[temppos.x][temppos.y + 1] == -2)
				{
					ExistWay = true;
					break;
				}
				A[temppos.x][temppos.y + 1] = A[temppos.x][temppos.y] + 1;
				que.push(position(temppos.x, temppos.y + 1));
			}
			//show(A,row,col);
			//cin>>ch;
		}
	}

	if (ExistWay == false)
	{
		cout << "No way to target!" << endl;
	}
	else
	{
		int p;
		int q = A[temppos.x][temppos.y];

		for (int i = 0; i < q; i++)
		{
			p = A[temppos.x][temppos.y] - 1;
			A[temppos.x][temppos.y] = -3;

			if (temppos.x > 0)
			{
				if (A[temppos.x - 1][temppos.y] == p)
				{
					temppos = position(temppos.x - 1, temppos.y - 1);
				}
			}
			if (temppos.x < row - 1)
			{
				if (A[temppos.x + 1][temppos.y] == p)
				{
					temppos = position(temppos.x + 1, temppos.y);
				}
			}
			if (temppos.y > 0)
			{
				if (A[temppos.x][temppos.y - 1] == p)
				{
					temppos = position(temppos.x, temppos.y - 1);
				}
			}
			if (temppos.y < col - 1)
			{
				if (A[temppos.x][temppos.y + 1] == p)
				{
					temppos = position(temppos.x, temppos.y + 1);
				}
			}
		}
	}
	show(A, row, col);
}
//-----------------------------------------------------------

int main()
{

	int row = 20;
	int col = 20;
	int **A;
	position start(0, 0);
	A = new int *[row];
	for (int i = 0; i < col; i++)
	{
		A[i] = new int[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			A[i][j] = 0;
		}
	}
	A[1][1] = A[1][2] = A[1][3] = A[1][4] = A[0][4] = A[2][1] = A[4][1] = A[5][1] = A[5][0] = -1;//For Wall
	A[2][3] = A[2][4] = A[2][5] = A[2][5] = -1;//For Wall
	A[3][3] = A[4][3] = A[5][3] = A[6][3] = A[8][3] = -1;//For Wall
	A[8][3] = A[9][3] = -1;//For Wall
	A[8][5] = A[7][5] = -1; //For Wall
	A[6][5] = A[3][5] = -1;

	A[7][8] = -2;//For Goal point

	solve(A, row, col, start);
	getchar();
	getchar();
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
