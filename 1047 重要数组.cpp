//��n��Χ��һȦ��˳���źš�
//�ӵ�1���˿�ʼ��������1��3��������������3�����˳�Ȧ�ӣ�
//��������µ���ԭ���ĵڼ��ŵ���λ��
#include <iostream>
using namespace std;
//����ʵ��
int main()
{
	int n = 0;
	cin >> n;
	int mod = 0;
	cin >> mod;
	bool arr[50] = { false };//�����õ�ֵĬ��Ϊ0 �����ж���ȡ��!
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
	for (int i = 0; i < n - 1; i++)//����˳��
	{
		cout << store[i] << " ";
	}
	return 0;
}

