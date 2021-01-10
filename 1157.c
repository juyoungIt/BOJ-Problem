/*
 * Q.1157 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1  // ���� �ǹ��ϴ� ���
#define FALSE 0 // ������ �ǹ��ϴ� ���

#define MAXSIZE 1000000 // ���ڿ��� �ִ� ���̸� �ǹ��ϴ� ���
#define ISTRERROR -1 // �Է� ���ڿ��� ������ ������ �ǹ��ϴ� ���

// �Լ� �����
int validator(char* str); // �Էµ� ���ڿ��� ���������� �����ϴ� �� Ȯ��
void counter(int*, char*); // �Էµ� ���ڿ��� ���� ���ĺ� ��������� ������Ʈ
int findBest(int*); // ���� ���� �󵵷� ���� ���ĺ��� �Ǻ��ϴ� �Լ�

int main()
{
	char inputStr[MAXSIZE]; // ����� �Է� ���ڿ�
	int alCount[26] = {0};  // �� ���ĺ� ���� ������ Ƚ������ �����ϴ� ������ �迭
	int maxAlUse;          // ���� ���� ���� ���ĺ��� ���� �ε��� ��
	char result;           // ���� ���� ���� ���ĺ�

	// 1. ���ڿ� �Է� + ����ó��(��������, ����)
	scanf("%s", inputStr);
	// 1-1. �Է� ���ڿ��� ��ȿ�� �˻縦 ������� ���� ���
	if (validator(inputStr) == FALSE) {
		printf("Error! - invalid string input error.\n");
		return ISTRERROR;
	}
	
	// 2. �� ���ĺ� ���� ���� Ƚ������ ������Ʈ
	counter(alCount, inputStr);

	// 3. �ִ� ��� ���ĺ� �Ǻ�
	maxAlUse = findBest(alCount);
	// �ִ� ��� ���ĺ��� �������� ���� ���
	if (maxAlUse == -1)
		result = 63; // 63 - '?'�� �ش��ϴ� ASCII �ڵ� ��
	// �ִ� ��� ���ĺ��� �����ϰ� �����ϴ� ���
	else
		result = maxAlUse + 65; // ���ĺ� �빮�ڿ� �ش��ϴ� ASCII �ڵ带 �Ҵ��ϴ� �κ�

	// 4. �Ǻ���� ���
	printf("%c\n", result);

	// 5. ���α׷� ����
	return 0;
}

// �Լ� ���Ǻ�
int validator(char* str)
{
	int len = (int)strlen(str); // �Է� ���ڿ��� ����
	char temp; // ���ڿ��� �����ϴ� �� ���ڸ� �Ͻ�����
	// 1. �Էµ� ���ڿ��� ���ĺ� ��/�ҹ��� ���� ������ �� Ȯ��
	for (int i = 0; i < len; i++) {
		temp = str[i]; // ���ڿ��� �����ϴ� ���ڸ� ������
		// ���ĺ� ��ҹ��� �̿��� ���ڸ� �����ϴ� ���
		if (!((temp >= 65 && temp <= 90) || (temp >= 97 && temp <= 122)))
			return FALSE;
	}
	// 2. �Էµ� ���ڿ��� ���̰� ������ ���� ���� �ִ� �� Ȯ��
	if (!(len >= 1 && len <= MAXSIZE))
		return FALSE;
	return TRUE;
}

void counter(int* alCount, char* str)
{
	int len = (int)strlen(str); // �Է� ���ڿ��� ����
	char temp; // ���ڿ��� �����ϴ� �� ���ڸ� �ӽ�����
	
	for (int i = 0; i < len; i++) {
		temp = str[i]; // �ش�ȸ���� ���ڸ� �о��
		// 1. �ش繮�ڰ� �빮���� ��쿡 ���� ó��
		if (temp >= 65 && temp <= 90) {
			alCount[temp - 65]++; // �ش� ���ĺ��� �ش��ϴ� �ε����� ���� 1����
		}
		// 2. �ش繮�ڰ� �ҹ����� ��쿡 ���� ó��
		else {
			alCount[temp - 97]++; // �ش� ���ĺ��� �ش��ϴ� �ε����� ���� 1����
		}
	}
}

/*
* �־��� �迭���� ���� ū �󵵼��� ������ �ε��� ���� ����ϴ� �Լ�
* ���� ū �󵵼��� ���� �ε����� ���� �ߺ��Ǿ� ��Ÿ���� ��� -1�� ��ȯ
*/
int findBest(int* alCount)
{
	int max = -1;        // �󵵼��� �ִ� (�ǹ̾��� ������ �ʱ�ȭ �ϱ� ���� -1 ���)
	int maxIdx = -2;     // �ִ� �󵵸� ������ �ε��� (�ǹ̾��� ������ �ʱ�ȭ �ϱ� ���� -2 ���)

	for (int i = 0; i < 26; i++) {
		// �ִ� �󵵼��� �߰��� ���
		if (max < alCount[i]) {
			max = alCount[i]; // �ִ� ������Ʈ
			maxIdx = i; // �ִ밪�� ������ �ε��� ������Ʈ
		}
		// �ִ� �� ���� �������� ���� ���
		else if (max == alCount[i])
			maxIdx = -1;  // maxIdx�� ���� -1�� ����
		// �� �̿��� ���
		else continue;
	}
	return maxIdx;
}