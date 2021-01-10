/*
 * Q.1157 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1  // 참을 의미하는 상수
#define FALSE 0 // 거짓을 의미하는 상수

#define MAXSIZE 1000000 // 문자열의 최대 길이를 의미하는 상수
#define ISTRERROR -1 // 입력 문자열에 오류가 있음을 의미하는 상수

// 함수 선언부
int validator(char* str); // 입력된 문자열이 제약조건을 만족하는 지 확인
void counter(int*, char*); // 입력된 문자열에 사용된 알파벳 사용정보를 업데이트
int findBest(int*); // 가장 많은 빈도로 사용된 알파벳을 판별하는 함수

int main()
{
	char inputStr[MAXSIZE]; // 사용자 입력 문자열
	int alCount[26] = {0};  // 각 알파벳 별로 등장한 횟수값을 저장하는 정수형 배열
	int maxAlUse;          // 가장 많이 사용된 알파벳에 대한 인덱스 값
	char result;           // 가장 많이 사용된 알파벳

	// 1. 문자열 입력 + 예외처리(문자종류, 길이)
	scanf("%s", inputStr);
	// 1-1. 입력 문자열이 유효성 검사를 통과하지 못한 경우
	if (validator(inputStr) == FALSE) {
		printf("Error! - invalid string input error.\n");
		return ISTRERROR;
	}
	
	// 2. 각 알파벳 별로 사용된 횟수정보 업데이트
	counter(alCount, inputStr);

	// 3. 최다 사용 알파벳 판별
	maxAlUse = findBest(alCount);
	// 최다 사용 알파벳이 고유하지 않은 경우
	if (maxAlUse == -1)
		result = 63; // 63 - '?'에 해당하는 ASCII 코드 값
	// 최다 사용 알파벳이 고유하게 존재하는 경우
	else
		result = maxAlUse + 65; // 알파벳 대문자에 해당하는 ASCII 코드를 할당하는 부분

	// 4. 판별결과 출력
	printf("%c\n", result);

	// 5. 프로그램 종료
	return 0;
}

// 함수 정의부
int validator(char* str)
{
	int len = (int)strlen(str); // 입력 문자열의 길이
	char temp; // 문자열을 구성하는 각 문자를 일시저장
	// 1. 입력된 문자열이 알파벳 대/소문자 만을 가지는 지 확인
	for (int i = 0; i < len; i++) {
		temp = str[i]; // 문자열을 구성하는 문자를 가져옴
		// 알파벳 대소문자 이외의 문자를 포함하는 경우
		if (!((temp >= 65 && temp <= 90) || (temp >= 97 && temp <= 122)))
			return FALSE;
	}
	// 2. 입력된 문자열의 길이가 지정한 범위 내에 있는 지 확인
	if (!(len >= 1 && len <= MAXSIZE))
		return FALSE;
	return TRUE;
}

void counter(int* alCount, char* str)
{
	int len = (int)strlen(str); // 입력 문자열의 길이
	char temp; // 문자열을 구성하는 각 문자를 임시저장
	
	for (int i = 0; i < len; i++) {
		temp = str[i]; // 해당회차의 문자를 읽어옴
		// 1. 해당문자가 대문자인 경우에 대한 처리
		if (temp >= 65 && temp <= 90) {
			alCount[temp - 65]++; // 해당 알파벳에 해당하는 인덱스의 값을 1증가
		}
		// 2. 해당문자가 소문자인 경우에 대한 처리
		else {
			alCount[temp - 97]++; // 해당 알파벳에 해당하는 인덱스의 값을 1증가
		}
	}
}

/*
* 주어진 배열에서 가장 큰 빈도수를 가지는 인덱스 값을 출력하는 함수
* 가장 큰 빈도수가 여러 인덱스에 걸쳐 중복되어 나타나는 경우 -1을 반환
*/
int findBest(int* alCount)
{
	int max = -1;        // 빈도수의 최댓값 (의미없는 값으로 초기화 하기 위해 -1 사용)
	int maxIdx = -2;     // 최대 빈도를 가지는 인덱스 (의미없는 값으로 초기화 하기 위해 -2 사용)

	for (int i = 0; i < 26; i++) {
		// 최대 빈도수를 발견한 경우
		if (max < alCount[i]) {
			max = alCount[i]; // 최댓값 업데이트
			maxIdx = i; // 최대값을 가지는 인덱스 업데이트
		}
		// 최대 빈도 값이 고유하지 않은 경우
		else if (max == alCount[i])
			maxIdx = -1;  // maxIdx의 값을 -1로 변경
		// 그 이외의 경우
		else continue;
	}
	return maxIdx;
}