#include <iostream>
using namespace std;
struct person
{
	int no;
	person* next;
};
void testcircle(person* p);
int main()
{
	int n = 0, mod = 0;
	cin >> n >> mod;
	person *end=NULL;
	person start;
	start.next = NULL;
	person* p;
	for (int i = 8; i>=1; i--)
	{
		p = new person;
		p->no = i;
		if (start.next == NULL)//这个p为尾结点
		{
			end = p;
			start.next = p;
			p->next = NULL;
		}
		else
		{
			p->next = start.next;
			start.next = p;
		}
	}
	end->next = p;//尾结点指向首元结点
	//testcircle(p);
	int count = 1;
	int* store = new int[n];
	person* frontp = end;
	int k = 0,j=n;
	while (j != 1)
	{
		if (count == mod)
		{
			frontp->next = p->next;
			store[k++] = p->no;
			j--;
			count = 1;
		}
		else
		{
			frontp = frontp->next;
			count++;
		}
		p = p->next;
	}
	for (int i = 0; i < n-1; i++)
		cout << store[i] << " ";
	return 0;
}
void testcircle(person*p)
{
	while (p)
	{
		cout << p->no << endl;
		p = p->next;
	}
}