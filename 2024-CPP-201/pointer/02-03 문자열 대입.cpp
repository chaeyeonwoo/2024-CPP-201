#include <stdio.h>
#include <string.h>
void main(void) {
	char str[100] = "Juyoung";
	char str2[100];

	//// str에 있는 내용을 str2에 복사하기
	//str2[0] = str[0];
	//str2[1] = str[1];
	//str2[2] = str[2];
	//str2[3] = str[3];
	//str2[4] = str[4];
	//str2[5] = str[5];
	//str2[6] = str[6];
	//str2[7] = str[7];
	
	//printf("%s", str2);

	/*int i = 0;
	for (; str[i] != '\0'; i++) {
		str2[i] = str[i];
	}
	str2[i] = str[i];*/
	
	strcpy(str2, str);
	printf("%s", str2);
}