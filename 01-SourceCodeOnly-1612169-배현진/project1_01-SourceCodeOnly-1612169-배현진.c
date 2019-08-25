#include <stdio.h>

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void sort(int list[], int size) {
	int i, j, a, min;

	printf("Initial Array: \n");
	for (a = 0; a < size; a++) {
		printf("%d ", list[a]);
	}

	for (i = 0; i < size-1; i++) {
		min = i;
		for (j = i + 1; j < size; j++) {
			if (list[j] < list[min]) {
				min = j;
			}
		}
		swap(&list[i], &list[min]);
		printf("\nSorting... : \n");
		for (a = 0; a < size; a++) {
			printf("%d ", list[a]);
		}
	}

	printf("\n");
	printf("Sorted Array: \n");
	for (a = 0; a < size; a++) {
		printf("%d ", list[a]);
	}

	printf("\n");
}


void main(void) {
	int size;
	int list[] = { 96, 4, 26, 49, 75, 103, 43, 42, 21, 7, 15, 97, 13, 11, 8, 48};

	printf("IT공학전공 1612169 배현진\n\n");
	printf("project #1\n\n");

	size = sizeof(list) / sizeof(int);

	sort(list, size);

	
	system("pause");
}



