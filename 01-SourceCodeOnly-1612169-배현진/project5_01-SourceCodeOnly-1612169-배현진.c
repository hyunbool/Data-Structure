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
/* 공통으로 사용한 함수*/ 
// 리스트 초기화
void NodeInit(List *plist) {
	plist->head = NULL;
	plist->tail = NULL;
}

// 리스트 프린트  
void print(List *plist){
	node *temp = plist->head;
	int i;
	printf("전체 리스트: ");
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
// 단일 링크드 리스트에 노드를 삽입하는 코드
void SingleNodeInsert(List *plist, char *data) {
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = NULL;

	printf("삽입중: %s\n", newnode->data);

	if (plist->head == NULL)
		plist->head = newnode;
	else
		plist->tail->next = newnode;

	plist->tail = newnode;
}


// 단일 연결 리스트를 circular로 만들기
void makeSingleCircular(List *plist) {
	plist->tail->next = plist->head;
}

/*5-2*/

// Single Linked List에서 Skip Number만큼 뛰어넘어 노드를 삭제하는 코드
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

		printf("%d단계 deleted node: %s \n", i, temp2->data);
		temp->next = temp2->next;
	}

	printf("Survivers: ");

	for (i = 1; i < 4; i++) {
		printf("%s ", temp->data);
		temp = temp->next;
	}
}

/*5-3*/
// 이중 링크드 리스트에 노드를 삽입하는 코드
void DoubleNodeInsert(List *plist, char *data) {
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;

	printf("삽입중: %s\n", newnode->data);

	if (plist->head == NULL)
		plist->head = newnode;
	else {
		plist->tail->next = newnode;
		newnode->prev = plist->tail;
	}

	plist->tail = newnode;
}


// 이중 연결 리스트를 circular로 만들기
void makeDoubleCircular(List *plist) {
	plist->tail->next = plist->head;
	plist->head->prev = plist->tail;
}

/*5-4*/
// Double Linked List에서 Skip Number만큼 뛰어넘어 노드를 삭제하는 코드
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

		//오른쪽으로 돌면서 삭제
		for (j = 1; j < RranNum; j++) {
			temp = temp->next;
		}

		temp2 = temp->next;

		printf("%d단계 deleted node: %s \n", 2*i - 1, temp2->data);
		temp->next = temp2->next;
		temp2->next->prev = temp;


		// 왼쪽으로 돌면서 삭제
		for (z = 1; z < LranNum; z++) {
			temp = temp->prev;
		}
		
		temp3 = temp->prev;
		
		printf("%d단계 deleted node: %s \n", 2*i, temp3->data);
		
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

	printf("IT공학전공 1612169 배현진\n\n");
	printf("project #5\n\n");
	
	char *array[37] = { "1-레일리", "2-윤성빈", "3-듀브론트", "4-노경은", "5-송승준", "6-김원중", "7-손승락", "8-오현택", "9-진명호", "10-박세웅", "11-조정훈", "12-박진형",
		"13-나종덕", "14-이대호", "15-채태인", "16-신본기", "17-손아섭", "18-민병헌", "19-전준우", "20-이병규", "21-김문호", "22-한동희", "23-김사훈", "24-문규현", 
		"25-정훈", "26-번즈", "27-오윤택", "28-나경민", "29-배장호", "30-이명우", "31-장시환", "32-나원탁", "33-김동한", "34-조원우", "35-윤길현", "36-황진수", "37-최동원"};

	//5-1: singly circular linked list를 설정하는 입력 프로그램
	printf("-------Singly Linked List-------\n");
	printf("#5-1\n");
	
	NodeInit(&singlelist); // 초기화
	

	printf("1단계: 노드 삽입\n");
	for (i = 0; i < 37; i++)
		SingleNodeInsert(&singlelist, array[i]);

	makeSingleCircular(&singlelist);

	print(&singlelist);
	
	//5-2: Singly Circular List에서 3명의 생존자 뽑는 프로그램  
	printf("#5-2\n");
	skipnum = rand()%37 + 1; // 1~37까지의 정수 중 하나를 랜덤으로 뽑는다.
	SingleNodeDelete(&singlelist, skipnum);

	printf("\n--------------------------------\n");

	//5-3: Doubly Circular Linked List를 설정하는 프로그램
	printf("\n-------Doubly Linked List-------\n");
	printf("#5-3\n");
	
	NodeInit(&doublelist); // 초기화


	printf("1단계: 노드 삽입\n");
	for (i = 0; i < 37; i++)
		DoubleNodeInsert(&doublelist, array[i]);

	makeDoubleCircular(&doublelist);
	
	print(&doublelist); 
	//5-4: Doubly Circular List에서 3명의 생존자 뽑는 프로그램 
	printf("#5-4\n"); 
	skipnum = rand() % 37 + 1; // 1~37까지의 정수 중 하나를 랜덤으로 뽑는다.
	DoubleNodeDelete(&doublelist, skipnum);
	
	printf("\n--------------------------------\n");
	system("pause");
}
