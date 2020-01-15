#include<stdio.h>
#include<stdlib.h> //system("pause")

/*


*/

//指针如何变成变量
//1. 用变量地址初始化
int a=1;
int *p=&a;
*p=4;
//2.用堆内存初始化
int *pp=(int *)malloc(sizeof(int));
int *p =new int(4);

struct Node
{
	int data;
	struct Node* next;
};

//1. 创建表头
struct Node* createList()
{
	struct Node* headNode = (struct *)malloc(sizeof(struct Node));
    headNode->next=NULL;
    return headNode;
};

//2. 创建结点
struct Node* createnode(int data)
{
	struct Node* newNode= (struct *)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}

//3. 插入链表
void insertlistByHead(struct Node* headNode,int data)
{

	struct Node* newNode = createnode(data);
	newNode->next=headNode->next;
	headNode->next=newNode;
}

void insertlistByPos(struct Node* headNode, int data,int posData)
{
	struct Node* p1;
	struct Node* p2;
	p1=headNode->next;
	p2=headNode;
	while(p1!=NULL&&p1->data!=posData)
	{
		p2=p1;
		p1=p1->next;
	}
	if(p1==NULL)
	{
		printf("Can not insert...\n");
	}
	if(p1->data==posData)
	{
		struct Node* newNode=createnode(data);
		newNode->next=p1;
		p2->next=newNode;
	}
}

void insertlistByTail(struct Node* headNode,int data)
{
	struct Node* pmove;
	pmove=headNode;

	while(pmove->next!=NULL)
	{
		pmove=pmove->next;
	}
	struct Node* newNode=createnode(data);
	pmove->next=newNode;
}

//4. 删除结点
void deleteByHead(struct *Node headNode)
{
	struct Node* nextNode = (struct *)malloc(sizeof(struct Node));
	headNode->next=nextNode->next;
	free(nextNode);
}

//打印链表
void printlist(struct Node* headNode)
{
	//从第二个节点开始
	struct Node* pmove;
	pmove=headNode->next;
	while(pmove!=NULL)
	{
		printf("%d\n",pmove->data );
		pmove=pmove->next;
	}
}

//----------------------------
//---------无头链表------------
//----------------------------


