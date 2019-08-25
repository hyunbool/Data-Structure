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

void print(List *plist) //한칸씩 이동하면서 전체 노드의 data값을 print한다. 
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
	int tmp = node1->data; //ListNode *p1의 data field의 값을 tmp에 넣고
	node1->data = node2->data; //ListNode *p1의 data field ListNode *p2의 data field 값을 넣고
	node2->data = tmp; //ListNode *p2의 data field 에 tmp에 넣어둔, ListNode *p1의 data field값을 넣는다. 
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

	printf("IT공학전공 1612169 배현진\n\n");
	printf("project #2\n\n");
	NodeInit(&list); // 초기화

	//노드 삽입
	for(i= 0; i < sizeof(array)/sizeof(int); i++)
		NodeInsert(&list, array[i]);

	// 정렬 전 리스트 출력
	printf("Initial Array: \n");
	print(&list);

	sort(&list);


	system("pause");
}
