#include <fstream>
#include <iostream>
#include "Windows.h"
#include <string.h>
using namespace std;

int** FillGpaph(int &n, char* input = "E:\\�����\\2 ����\\��\\4C++\\lab4\\lab4\\Debug\\test1.txt")
{
	//������� �������� ����� � ��������� ��� � ������
	ifstream in(input);
	int **x = new int*;
	if (in.is_open())
	{
		//������� ����� � �����
		int count = 0;
		int temp;

		while (!in.eof())
		{
			in >> temp;
			count++;
		}

		in.seekg(0, ios::beg); //������� � ������ ������
		in.clear();

		n = sqrt(count); //����� �����

		x = new int*[n];
		for (int i = 0; i < n; i++)
			x[i] = new int[n];

		//������� ������� �� �����
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				in >> x[i][j];

		in.close();
	}
	else
	{
		cout << "���� �� ������.";
	}
	return x;
}

void ShowGraph(int **&x, int n)
{
	cout << "����: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << x[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
}

void DeleteGraph(int **x, int n)
{
	for (int i = 0; i < n; i++)
		delete[] x[i];
	delete[] x;
}

void DepthSearch(int n, int **Graph, bool *Visited, int Node)
{
	Visited[Node] = true;
	for (int i = 0; i < n; i++)
		if (Graph[Node][i] && !Visited[i])
			DepthSearch(n, Graph, Visited, i);
}

bool ifConnected(int n, int **Graph, bool *Visited)
{
	bool q = true;
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < n; i++)
			Visited[i] = false;
		DepthSearch(n, Graph, Visited, i);
		for (int i = 0; i < n; i++)
		{
			cout << Visited[i] << "  ";
			if (q)
				q = Visited[i];
		}
		cout << endl;
	}
	cout << endl;
	return q;
}

int main()
{
	SetConsoleOutputCP(1251);
	int n = 0;
	int** x = FillGpaph(n);
	ShowGraph(x, n);
	bool *Visited;
	Visited = new bool[n];
	if (ifConnected(n, x, Visited))
		cout << "���� �������" << endl;
	else
		cout << "���� ���������" << endl;
	DeleteGraph(x, n);
	system("pause");
}
