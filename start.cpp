#include <iostream>
using namespace std;
struct student
{
	int no;
	char name[10];
	student* next;
};//l为头结点
void printlist(student* l);//打印链表所有成员
bool emptylist(student* l);//判断是否为空链表 0为空
int lengthlist(student* l);//返回长度
void clearlist(student* l);//清空链表 动态链表使用
void locatelist(student* l,int seekno);//传入要查找的学号
void deletelist(student* l, int deleteno);//传入要删除的学号
void insertlist(student* l, student* insertst);//传入要插入学生地址
int main()
{
	
	student s5 = { 7,"孙七",NULL };
	student s4 = { 6,"赵六",&s5 };
	student s3 = { 3,"王五",&s4 };
	student s2 = { 2,"李四",&s3 };
	student s1 = { 1,"张三",&s2 };
	student l;//头结点 指的始终是首元结点 用指针p来遍历
	l.next = &s1;
	//printlist(&l);//打印测试成功
	//int n = emptylist(&l);
	//cout << n << endl;//测试成功
	//int n = lengthlist(&l);
	//cout << n << endl;//测试成功
	//locatelist(&l, 8); //首元结点 中间结点 尾结点都测试成功
	deletelist(&l, 7);//首元结点 中间结点 尾结点都测试成功
	//student s6 = { 8,"周八",NULL };
	//insertlist(&l, &s6);
	printlist(&l);
	return 0;
}
void printlist(student* l)
{
	student* p = l->next;
	//int len= lengthlist(l);
	//for (int i = 0; i < len; i++)
	while(p)//两种遍历方式
	{
		cout << p->no << " " << p->name << endl;
		p = p->next;
	}
}
bool emptylist(student* l)
{
	if (l->next == NULL)
		return 0;
	else
		return 1;
}
int lengthlist(student* l)
{
	student* p = l->next;
	int count = 0;
	while (p)
	{
		count++;
		p = p->next;//遍历到最后一个结点p才变为空
	}
	return count;
}
void clearlist(student* l) 
{
	student* p = l->next;
	student* q = NULL;
	while (p) 
	{
		q = p->next;//q为p后一个结点
		delete(p);
		p = q;
	}
	l->next = NULL;//头结点设置为空
}
void locatelist(student* l, int seekno)
{
	student* p = l->next;
	int flag = 0;
	while (p)
	{
		if (p->no == seekno)
		{
			cout << p->no << " " << p->name << endl;
			flag++;
			break;
		}
		else
			p = p->next;
	}
	if (flag == 0)
		cout << "查无此人" << endl;
}
void deletelist(student* l, int deleteno)
{
	student* p = l->next;
	student* q = l;
	while (p)
	{
		if (p->no== deleteno)
		{
			if (p->next == NULL)//当删除数据是末数据时	
				q->next = NULL;//把倒第二个数据指针域设置为空指针
			else
				q->next = p->next;//跳过要删除的学号地址
			break;
		}
		else
		{
			p = p->next;
			q = q->next;//在删除中q为p的前一个结点 始终保持用p来遍历指针
		}
	}
}
void insertlist(student* l, student* insertst)//注意访问权限不能越界
{
	student*& st = insertst;
	student* p = l->next;
	student* q = p->next;
	int len = lengthlist(l);
	for (int i = 0; i < len; i++)
	{
		if (p->next == NULL)
		{
			p->next = st;
			break;
		}
		if (st->no > p->no && st->no < q->no)
		{
			p->next = st;
			st->next = q;
			break;
		}
		else if (st->no < p->no)
		{
			l->next = st;
			st->next = p;
			break;
		}
		p = p->next;
		q = p->next;//插入中q总是p后一个结点
	}
}
