#include <iostream>
#include <fstream>
using namespace std;
int main(void)
{
	setlocale(LC_ALL, "rus");
	int n, m, max;
	ifstream in("in.txt");
	if (!in.is_open())
	{
		cout << "Не удалось создать файл in.txt" << endl;
		return -4;
	}
	in >> n >> m;
	int** A = new int*[m];
	for (int i = 0; i<n; i++)
	{
		A[i] = new int[m];
		for (int j = 0; j<m; j++)
		{
			in >> A[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			max = A[i][j];
			for (int k = i; k < n; k++)
			{
				for (int g = j; g < m; g++)
				{
					if (A[k][g] > max)
					{
						max = A[k][g];
					}
				}
			}
			A[i][j] = max;
		}
	}
	ofstream out("out.txt");
	if (!out.is_open())
	{
		cout << "Не удалось создать файл out.txt" << endl;
		return -4;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			out << A[i][j] << ' ';
		}
		out << endl;
	}
	system("pause");
	return 0;
}