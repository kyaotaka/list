#include <iostream>
using namespace std;
struct person
{
	int no;
	char name[10];
	person* next;
};
void printlist(person* head);
int lengthlist(person*head);//���س���
void locatelist(person* head, int locateno);//����Ҫ���ҵ�ѧ��
void deletelist(person* head, int deleteno);
void insertlist(person* head, person* insertper);
int main()
{
	person l;//ͷ���
	l.next = NULL;
	person* head = &l;//ͷָ��
	person* p;
	for (int i = 30; i>=1; i--)
	{
		p = new person;
		p->no = i;
		if (l.next == NULL)
			p->next = NULL;
		else
			p->next = l.next;//��һ��p
		l.next = p;//�������p
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
	person* p = head;//p��ʼΪͷ���
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
		frontp = p;//qΪp��ǰһ�����
		p = p->next;
		if (p->no == deleteno)
		{
			frontp->next = p->next;//��Ԫ���ͱ����β��㴦����һ��
			break;
		}
	}
}
void insertlist(person* head, person* insertper)
{
	person* p = head;
	person* behindp = p->next;
	if (p->next == NULL)//�ձ�
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
	 if (insertper->no <= behindp->no)//��һ������������
	{
		p->next = insertper;
		insertper->next = behindp;
	}
	else if (behindp->next == NULL)//�ڶ�������������
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
	// while (insertper->no > p->no );//Ѱ�Ҳ���λ��
	//if(p==NULL)//��Ϊ��һ������������
	//{
	//	p->next = insertper;
	//	insertper = NULL;
	//}
	//else//˵������Ϊ�ڶ�������������
	//{
	//	frontp->next = insertper;//ͷ��ͱ�����һ��
	//		insertper->next = p;
	//}
}