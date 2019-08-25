#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _node {
	char *data;
	struct _node *next;
	struct _node *prev;
}node;

typedef struct _list {
	node *head;
	node *tail;
}List;
/* �������� ����� �Լ�*/ 
// ����Ʈ �ʱ�ȭ
void NodeInit(List *plist) {
	plist->head = NULL;
	plist->tail = NULL;
}

// ����Ʈ ����Ʈ  
void print(List *plist){
	node *temp = plist->head;
	int i;
	printf("��ü ����Ʈ: ");
	for(i=0; i<37; i++){
		if(i == 36)
			printf("%s", temp->data);
		else
			printf("%s -> ", temp->data);
		temp= temp->next;
	}
	printf("\n");
}

/*5-1*/ 
// ���� ��ũ�� ����Ʈ�� ��带 �����ϴ� �ڵ�
void SingleNodeInsert(List *plist, char *data) {
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = NULL;

	printf("������: %s\n", newnode->data);

	if (plist->head == NULL)
		plist->head = newnode;
	else
		plist->tail->next = newnode;

	plist->tail = newnode;
}


// ���� ���� ����Ʈ�� circular�� �����
void makeSingleCircular(List *plist) {
	plist->tail->next = plist->head;
}

/*5-2*/

// Single Linked List���� Skip Number��ŭ �پ�Ѿ� ��带 �����ϴ� �ڵ�
void SingleNodeDelete(List *plist, int ranNum) {
	node *temp, *temp2;
	int i, j;
	
	temp = plist->head;
	temp2 = plist->head;

	printf("skip number: %d\n", ranNum);

	for (i = 1; i < 35; i++) {
		for (j = 1; j < ranNum; j++) {
			temp = temp->next;
		}

		temp2 = temp->next;

		printf("%d�ܰ� deleted node: %s \n", i, temp2->data);
		temp->next = temp2->next;
	}

	printf("Survivers: ");

	for (i = 1; i < 4; i++) {
		printf("%s ", temp->data);
		temp = temp->next;
	}
}

/*5-3*/
// ���� ��ũ�� ����Ʈ�� ��带 �����ϴ� �ڵ�
void DoubleNodeInsert(List *plist, char *data) {
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;

	printf("������: %s\n", newnode->data);

	if (plist->head == NULL)
		plist->head = newnode;
	else {
		plist->tail->next = newnode;
		newnode->prev = plist->tail;
	}

	plist->tail = newnode;
}


// ���� ���� ����Ʈ�� circular�� �����
void makeDoubleCircular(List *plist) {
	plist->tail->next = plist->head;
	plist->head->prev = plist->tail;
}

/*5-4*/
// Double Linked List���� Skip Number��ŭ �پ�Ѿ� ��带 �����ϴ� �ڵ�
void DoubleNodeDelete(List *plist, int ranNum) {
	node *temp, *temp2, *temp3;
	int i, j, z, x;
	int RranNum, LranNum;
	temp = plist->head;
	temp2 = plist->head;
	temp3 = plist->head;

	RranNum = ranNum;
	LranNum = ranNum - 1;
	printf("right skip number: %d\n", RranNum);
	printf("left skip number: %d\n", LranNum);

	for (i = 1; i < 18; i++) {

		//���������� ���鼭 ����
		for (j = 1; j < RranNum; j++) {
			temp = temp->next;
		}

		temp2 = temp->next;

		printf("%d�ܰ� deleted node: %s \n", 2*i - 1, temp2->data);
		temp->next = temp2->next;
		temp2->next->prev = temp;


		// �������� ���鼭 ����
		for (z = 1; z < LranNum; z++) {
			temp = temp->prev;
		}
		
		temp3 = temp->prev;
		
		printf("%d�ܰ� deleted node: %s \n", 2*i, temp3->data);
		
		temp->prev = temp3->prev;
		temp3->prev->next = temp;
		
	}

	printf("Survivers: ");

	for (x = 1; x < 4; x++) {
		printf("%s ", temp->data);
		temp = temp->next;
	}

}

int main(void) {
	List singlelist, doublelist;
	int skipnum, i;
	int size = 0;
	srand(time(NULL));

	printf("IT�������� 1612169 ������\n\n");
	printf("project #5\n\n");
	
	char *array[37] = { "1-���ϸ�", "2-������", "3-����Ʈ", "4-�����", "5-�۽���", "6-�����", "7-�ս¶�", "8-������", "9-����ȣ", "10-�ڼ���", "11-������", "12-������",
		"13-������", "14-�̴�ȣ", "15-ä����", "16-�ź���", "17-�վƼ�", "18-�κ���", "19-���ؿ�", "20-�̺���", "21-�蹮ȣ", "22-�ѵ���", "23-�����", "24-������", 
		"25-����", "26-����", "27-������", "28-�����", "29-����ȣ", "30-�̸��", "31-���ȯ", "32-����Ź", "33-�赿��", "34-������", "35-������", "36-Ȳ����", "37-�ֵ���"};

	//5-1: singly circular linked list�� �����ϴ� �Է� ���α׷�
	printf("-------Singly Linked List-------\n");
	printf("#5-1\n");
	
	NodeInit(&singlelist); // �ʱ�ȭ
	

	printf("1�ܰ�: ��� ����\n");
	for (i = 0; i < 37; i++)
		SingleNodeInsert(&singlelist, array[i]);

	makeSingleCircular(&singlelist);

	print(&singlelist);
	
	//5-2: Singly Circular List���� 3���� ������ �̴� ���α׷�  
	printf("#5-2\n");
	skipnum = rand()%37 + 1; // 1~37������ ���� �� �ϳ��� �������� �̴´�.
	SingleNodeDelete(&singlelist, skipnum);

	printf("\n--------------------------------\n");

	//5-3: Doubly Circular Linked List�� �����ϴ� ���α׷�
	printf("\n-------Doubly Linked List-------\n");
	printf("#5-3\n");
	
	NodeInit(&doublelist); // �ʱ�ȭ


	printf("1�ܰ�: ��� ����\n");
	for (i = 0; i < 37; i++)
		DoubleNodeInsert(&doublelist, array[i]);

	makeDoubleCircular(&doublelist);
	
	print(&doublelist); 
	//5-4: Doubly Circular List���� 3���� ������ �̴� ���α׷� 
	printf("#5-4\n"); 
	skipnum = rand() % 37 + 1; // 1~37������ ���� �� �ϳ��� �������� �̴´�.
	DoubleNodeDelete(&doublelist, skipnum);
	
	printf("\n--------------------------------\n");
	system("pause");
}
