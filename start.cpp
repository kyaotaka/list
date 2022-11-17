#include <iostream>
using namespace std;
struct student
{
	int no;
	char name[10];
	student* next;
};//lΪͷ���
void printlist(student* l);//��ӡ�������г�Ա
bool emptylist(student* l);//�ж��Ƿ�Ϊ������ 0Ϊ��
int lengthlist(student* l);//���س���
void clearlist(student* l);//������� ��̬����ʹ��
void locatelist(student* l,int seekno);//����Ҫ���ҵ�ѧ��
void deletelist(student* l, int deleteno);//����Ҫɾ����ѧ��
void insertlist(student* l, student* insertst);//����Ҫ����ѧ����ַ
int main()
{
	
	student s5 = { 7,"����",NULL };
	student s4 = { 6,"����",&s5 };
	student s3 = { 3,"����",&s4 };
	student s2 = { 2,"����",&s3 };
	student s1 = { 1,"����",&s2 };
	student l;//ͷ��� ָ��ʼ������Ԫ��� ��ָ��p������
	l.next = &s1;
	//printlist(&l);//��ӡ���Գɹ�
	//int n = emptylist(&l);
	//cout << n << endl;//���Գɹ�
	//int n = lengthlist(&l);
	//cout << n << endl;//���Գɹ�
	//locatelist(&l, 8); //��Ԫ��� �м��� β��㶼���Գɹ�
	deletelist(&l, 7);//��Ԫ��� �м��� β��㶼���Գɹ�
	//student s6 = { 8,"�ܰ�",NULL };
	//insertlist(&l, &s6);
	printlist(&l);
	return 0;
}
void printlist(student* l)
{
	student* p = l->next;
	//int len= lengthlist(l);
	//for (int i = 0; i < len; i++)
	while(p)//���ֱ�����ʽ
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
		p = p->next;//���������һ�����p�ű�Ϊ��
	}
	return count;
}
void clearlist(student* l) 
{
	student* p = l->next;
	student* q = NULL;
	while (p) 
	{
		q = p->next;//qΪp��һ�����
		delete(p);
		p = q;
	}
	l->next = NULL;//ͷ�������Ϊ��
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
		cout << "���޴���" << endl;
}
void deletelist(student* l, int deleteno)
{
	student* p = l->next;
	student* q = l;
	while (p)
	{
		if (p->no== deleteno)
		{
			if (p->next == NULL)//��ɾ��������ĩ����ʱ	
				q->next = NULL;//�ѵ��ڶ�������ָ��������Ϊ��ָ��
			else
				q->next = p->next;//����Ҫɾ����ѧ�ŵ�ַ
			break;
		}
		else
		{
			p = p->next;
			q = q->next;//��ɾ����qΪp��ǰһ����� ʼ�ձ�����p������ָ��
		}
	}
}
void insertlist(student* l, student* insertst)//ע�����Ȩ�޲���Խ��
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
		q = p->next;//������q����p��һ�����
	}
}
