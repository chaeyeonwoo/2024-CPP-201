#include <stdio.h>

// 배열의 모든 원소를 0으로 한다.
void erase(int *_arr, int _length) {
	for (int i = 0; i < _length; i++)
		_arr[i] = 0;
}

int main(void) {
	int arr[4] = { 10, 20, 30, 40 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int length = sizeof(arr) / sizeof(*arr);
	erase(arr, length);

	printf("%d ", length);
	printf("%d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);
	for (int i = 0; i < 4; i++) {
		arr[i] = 0;
		printf("%d ", arr[i]);
	}
	return 0;
}