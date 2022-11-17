#include <iostream>
using namespace std;
struct person
{
	int no;
	char name[10];
	person* next;
};
void printlist(person* head);
int lengthlist(person*head);//返回长度
void locatelist(person* head, int locateno);//传入要查找的学号
void deletelist(person* head, int deleteno);
void insertlist(person* head, person* insertper);
int main()
{
	person l;//头结点
	l.next = NULL;
	person* head = &l;//头指针
	person* p;
	for (int i = 30; i>=1; i--)
	{
		p = new person;
		p->no = i;
		if (l.next == NULL)
			p->next = NULL;
		else
			p->next = l.next;//上一个p
		l.next = p;//储存这个p
	}
	//printlist(head);
	int n = lengthlist(head);
	//cout << n << endl;
	int locateno = 0;
	//cin >> locateno;
	//locatelist(head, locateno);
	int deleteno = 0;
	//cin >> deleteno;
	//deletelist(head, deleteno);
	//printlist(head);
	person insertper;
	insertper.no = 4;
	insertlist(head, &insertper);
	printlist(head);
	return 0;
}
void printlist(person* head)
{
	person* p = head;//p初始为头结点
	while (p->next != NULL)
	{
		p = p->next;
		cout << p->no << endl;
	}
}
int lengthlist(person *head)
{
	person* p = head;
	int count = 0;
	while (p->next != NULL)
	{
		p = p->next;
		count++;
	}
	return count;
}
void locatelist(person* head, int locateno)
{
	person* p = head;
	while (p->next != NULL)
	{
		p = p->next;
		if (p->no == locateno)
		{
			cout << p->no << endl;
			break;
		}
	}
}
void deletelist(person* head, int deleteno)
{
	person* p = head;
	person* frontp;
	while (p->next != NULL)
	{
		frontp = p;//q为p的前一个结点
		p = p->next;
		if (p->no == deleteno)
		{
			frontp->next = p->next;//首元结点和表结点和尾结点处理方法一样
			break;
		}
	}
}
void insertlist(person* head, person* insertper)
{
	person* p = head;
	person* behindp = p->next;
	if (p->next == NULL)//空表
	{
		p->next = insertper;
		insertper->next = NULL;
		return;
	}
	while (insertper->no > behindp->no && behindp->next != NULL)
	{
		p = p->next;//p=behindp;
		behindp = behindp->next;
	}
	 if (insertper->no <= behindp->no)//第一个条件结束的
	{
		p->next = insertper;
		insertper->next = behindp;
	}
	else if (behindp->next == NULL)//第二个条件结束的
	{
		behindp->next = insertper;
		insertper->next = NULL;
	}
	//person* frontp;
	//do 
	//{
	//	frontp = p;
	//	p = p->next;
	//	if (p== NULL)
	//		break;
	//}
	// while (insertper->no > p->no );//寻找插入位置
	//if(p==NULL)//因为第一个条件结束的
	//{
	//	p->next = insertper;
	//	insertper = NULL;
	//}
	//else//说明是因为第二个条件结束的
	//{
	//	frontp->next = insertper;//头插和表间插入一样
	//		insertper->next = p;
	//}
}