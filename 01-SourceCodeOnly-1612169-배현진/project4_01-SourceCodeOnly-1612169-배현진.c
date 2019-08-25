#include <stdio.h>

typedef struct _node {
	int data;
	struct _node *next;
}node;

typedef struct _list {
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


int returnNode(List *list, int middle) {
	int i, searchData;
	node *temp;
	temp = list->head;
	for (i = 1; i < middle; i++) {
		temp = temp->next;
	}
	searchData = temp->data;
	return searchData;
}

int binsearch(List *list, int searchnum, int left, int right) {
	int middle, searchData;

	while (left <= right) {
		middle = (right + left) / 2;
		printf("\ncurrent middle: %d", middle);

		searchData = returnNode(list, middle);  
		if (searchData > searchnum)
			right = middle - 1;
		else if (searchData < searchnum)
			left = middle + 1;
		else
			return middle;
	}
	return -1;
}


void main(void) {
	List list;
	int data;
	int i;
	int result, size = 0;
	int array[] = {4, 7, 8, 11, 13, 15, 21, 26, 42, 43, 48, 49, 75, 96, 97, 103};

	NodeInit(&list); // 초기화

					 //노드 삽입
	for (i = 0; i < sizeof(array) / sizeof(int); i++)
		NodeInsert(&list, array[i]);

	size = sizeof(array) / sizeof(int);

	printf("IT공학전공 1612169 배현진\n\n");
	printf("project #4\n\n");
	
	result = binsearch(&list, 13, 1, size);
	printf("\n(1) 13: %d번째 위치해 있습니다.\n", result);

	result = binsearch(&list, 97, 1, size);
	printf("\n(2) 97: %d번째 위치해 있습니다.\n", result);

	result = binsearch(&list, 103, 1, size);
	printf("\n(3) 103: %d번째 위치해 있습니다.\n", result);

	result = binsearch(&list, 7, 1, size);
	printf("\n(4) 7: %d번째 위치해 있습니다.\n", result);

	result = binsearch(&list, 26, 1, size);
	printf("\n(5) 26: %d번째 위치해 있습니다.\n", result);


	system("pause");
}
