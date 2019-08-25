#include <stdio.h>

int binsearch(int list[], int searchnum, int left, int right) {
	int middle;
	while (left <= right) {
		middle = (right + left) / 2;
		printf("\ncurrent middle: %d", middle);
		if (list[middle] > searchnum)
			right = middle - 1;
		else if (list[middle] < searchnum)
			left = middle + 1;
		else
			return middle;
	}
	return -1;
}


void main(void) {
	int result, size = 0;
	int list[] = {4, 7, 8, 11, 13, 15, 21, 26, 42, 43, 48, 49, 75, 96, 97, 103};

	printf("IT공학전공 1612169 배현진\n\n");
	printf("project #3\n\n");
	
	size = sizeof(list) / sizeof(int);

	result = binsearch(list, 13, 0, size);
	printf("\n(1) 13 _ index: %d\n", result);

	result = binsearch(list, 97, 0, size);
	printf("\n(2) 97 _ index: %d\n", result);

	result = binsearch(list, 103, 0, size);
	printf("\n(3) 103 _ index: %d\n", result);

	result = binsearch(list, 7, 0, size);
	printf("\n(4) 7 _ index: %d\n", result);

	result = binsearch(list, 26, 0, size);
	printf("\n(5) 26 _ index: %d\n", result);


	system("pause");
}
