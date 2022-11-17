//有n人围成一圈，顺序排号。
//从第1个人开始报数（从1到3报数），凡报到3的人退出圈子，
//问最后留下的是原来的第几号的那位。
#include <iostream>
using namespace std;
//数组实现
int main()
{
	int n = 0;
	cin >> n;
	int mod = 0;
	cin >> mod;
	bool arr[50] = { false };//不设置的值默认为0 所以判断用取反!
	int store[50] = { 0 };
	int count = 1;
	int j = n;
	int k = 0;
	while (j != 1)
	{
		for (int i = 0; i < n; i++)
		{
			if (!arr[i])
			{
				if (count == mod)
				{
					arr[i] = true;
					store[k++] = i + 1;
					j--;
					count = 1;
				}
				else
					count++;
			}
		}
	}
	for (int i = 0; i < n - 1; i++)//出列顺序
	{
		cout << store[i] << " ";
	}
	return 0;
}

