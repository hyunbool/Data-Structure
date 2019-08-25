#include <stdio.h>

typedef struct _node {
	int data;
	struct _node *next;
}node;

typedef struct _list{
	node *head;
	node *tail;
}List;

void NodeInit(List *plist) {
	plist->head = NULL;
	plist->tail = NULL;
}

void NodeInsert(List *plist, int data) {
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = NULL;

	if (plist->head == NULL)
		plist->head = newnode;
	else
		plist->tail->next = newnode;

	plist->tail = newnode;
}

void print(List *plist) //��ĭ�� �̵��ϸ鼭 ��ü ����� data���� print�Ѵ�. 
{
	node *temp = plist->head;

	while (temp)
	{
		printf(" %d", temp->data);
		temp = temp->next; 
	}
	printf(" \n");
}

void swap(node *node1, node *node2)
{
	int tmp = node1->data; //ListNode *p1�� data field�� ���� tmp�� �ְ�
	node1->data = node2->data; //ListNode *p1�� data field ListNode *p2�� data field ���� �ְ�
	node2->data = tmp; //ListNode *p2�� data field �� tmp�� �־��, ListNode *p1�� data field���� �ִ´�. 
}


void sort(List *plist) {
	node *min;
	node *temp = plist->head;
	node *savecur;
	node *curhead = plist->head;
	
	while (curhead->next) {
		min = curhead;
		savecur = curhead->next;

		while (savecur) {
			if (savecur->data < min->data)
				min = savecur;
			savecur = savecur->next;
		}

		swap(curhead, min);

		curhead = curhead->next;

		printf("Sorted Array: \n");
		print(plist);
	}

}

void main() {
	List list;
	node* temp;
	int data;
	int i;
	int array[] = { 96, 4, 26, 49, 75, 103, 43, 42, 21, 7, 15, 97, 13, 11, 8, 48 };

	printf("IT�������� 1612169 ������\n\n");
	printf("project #2\n\n");
	NodeInit(&list); // �ʱ�ȭ

	//��� ����
	for(i= 0; i < sizeof(array)/sizeof(int); i++)
		NodeInsert(&list, array[i]);

	// ���� �� ����Ʈ ���
	printf("Initial Array: \n");
	print(&list);

	sort(&list);


	system("pause");
}
