#include <iostream>

using namespace std;

#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"ctype.h"

#define OK 1
typedef struct node          //定义结点
{
	char data[10];             //结点的数据域为字符串
	struct node *next;      //结点的指针域
}ListNode;
typedef ListNode * LinkList;         // 自定义LinkList单链表类型

LinkList CreatList(void);            //函数，用头插入法建立带头结点的单链表
LinkList LocateNode(LinkList L, char *ch);      //函数，按值查找结点
void DeleteList(LinkList L, char *ch);           //函数，删除指定值的结点
void Printlist(LinkList L);                    //函数，打印链表中的所有值
void DeleteAll(LinkList L);                   //函数，删除所有结点，释放内存
LinkList AddNode(LinkList L);				 //修改程序：增加节点。用头插法，返回头指针

//==========主函数==============

int main()
{
	char ch[10], num[5];
	LinkList head;
	head=CreatList();          //用头插入法建立单链表，返回头指针
	Printlist(head);             //遍历链表输出其值
	printf(" Delete node (y/n):");  //输入"y"或"n"去选择是否删除结点
	scanf("%s",num);
	if(strcmp(num,"y")==0 || strcmp(num,"Y")==0){
		printf("Please input Delete_data:");
		scanf("%s",ch);	        //输入要删除的字符串
		DeleteList(head,ch);
		Printlist(head);
	}
	printf(" Add node ? (y/n):");  //输入"y"或"n"去选择是否增加结点
	scanf("%s",num);
	if(strcmp(num,"y")==0 || strcmp(num,"Y")==0)
	{
		head=AddNode(head);
	}

	Printlist(head);
	DeleteAll(head);            //删除所有结点，释放内存
	return OK;
}


//==========用头插入法建立带头结点的单链表===========
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

		//根据输入字符串，插入单链表中。以“#”为结束标志（头插法）

	}
	return head;
}

//==========按值查找结点，找到则返回该结点的位置，否则返回NULL==========
LinkList LocateNode(LinkList head, char *key)
{
LinkList p = head->next; //从首元结点比较
//扫描单链表，按值查找结点。若p=NULL则查找失败，否则p指向找到的值为key的结点

    while (p != NULL && strcmp(p->data, key) != 0) {
    p = p->next;
    }
    return p;    //若p=NULL则查找失败，否则p指向找到的值为key的结点
}

//==========按照输入值增加节点=======
LinkList AddNode(LinkList head)
{
    char ch[10];
	LinkList s, pp;

    printf("\nPlease input a New Node_data:");
    scanf("%s",ch);           //输入各结点的字符串

    //若输入字符串与当前链表结点元素均不同，则插入到表头位置
	if (LocateNode(head, ch) == NULL) {
	s = new ListNode;
	strcpy(s->data, ch);
	s->next = head->next;
	head->next = s;
}
	return head;

}

//==========删除带头结点的单链表中的指定结点=======
void DeleteList(LinkList head, char *key)
{
    LinkList p, r, q=head;
    p=LocateNode(head, key);    //按key值查找结点的
    if(p==NULL ) {            //若没有找到结点，退出
		printf("position error");
		exit(0);
    }
//若找到结点，则将其删除
    while (q->next != p) {
    q = q->next;
    }
    r = q->next;
    q->next = r->next;
    delete r;
    }

//===========打印链表=======
void Printlist(LinkList head)
{
    LinkList p=head->next;       //从开始结点打印
    while(p){
		printf("%s,   ",p->data);
		p=p->next;
    }
    printf("\n");
}
//==========删除所有结点，释放空间===========
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
