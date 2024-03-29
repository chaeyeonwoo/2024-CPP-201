#include <stdio.h>

int main(void) {
	int arr[4] = { 10, 20, 30, 40 };
	char str[4];

	int* pi = arr;
	char* pc = str;


	// 4바이트 차이(x86으로 설정하면 더 좋아요)
	//printf("%d %d\n", &arr[0], &arr[1]);

	// 1바이트 차이(x86으로 설정하면 더 좋아요)
	//printf("%d %d\n", &str[0], &str[1]);

	// 위의 코드와 결과가 같다 arr+1 = &arr[1]
	//printf("%d %d\n", arr, arr+1);

	// 두 코드의 결과는 같다
	printf("%d %d\n", (&arr[0]), (&arr[1]));	// 4차이
	printf("%d %d\n", (arr), (arr + 1));		

	printf("%d %d\n", (pi[0]), (pi + 1));	// 4차이
	printf("%d %d\n", (pc), (pc + 1));		// 1차이
}