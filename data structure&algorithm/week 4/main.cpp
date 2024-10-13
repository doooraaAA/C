#include <iostream>

using namespace std;

#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"ctype.h"

#define OK 1
typedef struct node          //������
{
	char data[10];             //����������Ϊ�ַ���
	struct node *next;      //����ָ����
}ListNode;
typedef ListNode * LinkList;         // �Զ���LinkList����������

LinkList CreatList(void);            //��������ͷ���뷨������ͷ���ĵ�����
LinkList LocateNode(LinkList L, char *ch);      //��������ֵ���ҽ��
void DeleteList(LinkList L, char *ch);           //������ɾ��ָ��ֵ�Ľ��
void Printlist(LinkList L);                    //��������ӡ�����е�����ֵ
void DeleteAll(LinkList L);                   //������ɾ�����н�㣬�ͷ��ڴ�
LinkList AddNode(LinkList L);				 //�޸ĳ������ӽڵ㡣��ͷ�巨������ͷָ��

//==========������==============

int main()
{
	char ch[10], num[5];
	LinkList head;
	head=CreatList();          //��ͷ���뷨��������������ͷָ��
	Printlist(head);             //�������������ֵ
	printf(" Delete node (y/n):");  //����"y"��"n"ȥѡ���Ƿ�ɾ�����
	scanf("%s",num);
	if(strcmp(num,"y")==0 || strcmp(num,"Y")==0){
		printf("Please input Delete_data:");
		scanf("%s",ch);	        //����Ҫɾ�����ַ���
		DeleteList(head,ch);
		Printlist(head);
	}
	printf(" Add node ? (y/n):");  //����"y"��"n"ȥѡ���Ƿ����ӽ��
	scanf("%s",num);
	if(strcmp(num,"y")==0 || strcmp(num,"Y")==0)
	{
		head=AddNode(head);
	}

	Printlist(head);
	DeleteAll(head);            //ɾ�����н�㣬�ͷ��ڴ�
	return OK;
}


//==========��ͷ���뷨������ͷ���ĵ�����===========
LinkList CreatList(void)
{
	char ch[100];
	LinkList head, p;
	head= new ListNode;
	head->next=NULL;

	while(1)
	{
		printf("Input # to end  ");
		printf("Please input Node_data:");
		scanf("%s",ch);

    if (strcmp(p->data, "#")==0) {
    break;
    }
    if (LocateNode(head, ch) == NULL) {
            p=new ListNode;
    strcpy(p->data, ch);
     p->next=head->next;
     head->next=p;
    }

		//���������ַ��������뵥�����С��ԡ�#��Ϊ������־��ͷ�巨��

	}
	return head;
}

//==========��ֵ���ҽ�㣬�ҵ��򷵻ظý���λ�ã����򷵻�NULL==========
LinkList LocateNode(LinkList head, char *key)
{
LinkList p = head->next; //����Ԫ���Ƚ�
//ɨ�赥������ֵ���ҽ�㡣��p=NULL�����ʧ�ܣ�����pָ���ҵ���ֵΪkey�Ľ��

    while (p != NULL && strcmp(p->data, key) != 0) {
    p = p->next;
    }
    return p;    //��p=NULL�����ʧ�ܣ�����pָ���ҵ���ֵΪkey�Ľ��
}

//==========��������ֵ���ӽڵ�=======
LinkList AddNode(LinkList head)
{
    char ch[10];
	LinkList s, pp;

    printf("\nPlease input a New Node_data:");
    scanf("%s",ch);           //����������ַ���

    //�������ַ����뵱ǰ������Ԫ�ؾ���ͬ������뵽��ͷλ��
	if (LocateNode(head, ch) == NULL) {
	s = new ListNode;
	strcpy(s->data, ch);
	s->next = head->next;
	head->next = s;
}
	return head;

}

//==========ɾ����ͷ���ĵ������е�ָ�����=======
void DeleteList(LinkList head, char *key)
{
    LinkList p, r, q=head;
    p=LocateNode(head, key);    //��keyֵ���ҽ���
    if(p==NULL ) {            //��û���ҵ���㣬�˳�
		printf("position error");
		exit(0);
    }
//���ҵ���㣬����ɾ��
    while (q->next != p) {
    q = q->next;
    }
    r = q->next;
    q->next = r->next;
    delete r;
    }

//===========��ӡ����=======
void Printlist(LinkList head)
{
    LinkList p=head->next;       //�ӿ�ʼ����ӡ
    while(p){
		printf("%s,   ",p->data);
		p=p->next;
    }
    printf("\n");
}
//==========ɾ�����н�㣬�ͷſռ�===========
void DeleteAll(LinkList head)
{
    LinkList p=head, r;
    while(p->next){
		r=p->next;
		delete p;
		p=r;
	}
	delete p;
}
