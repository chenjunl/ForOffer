#include<iostream>
#include<cstdlib>

using namespace std;

void repalaceSpace(char *str, int length) {
	if (str == nullptr)
		return;
	
	int spaceNumber = 0;
	int len = 0;
	while (*(str + len) != '\0') {
		if (*(str + len) == ' ')
			spaceNumber++;
		len++;
	}
	cout << "len: " << len << endl;

	if ((len + spaceNumber * 2) > length)
		str = (char *)realloc(str, (len + spaceNumber * 2) * sizeof(char));

	char *pStr, *pEnd;
	pStr = str + len;
	pEnd = str + len + spaceNumber * 2;
	for (int i = len; i >= 0; i--) {
		if (*(pStr) == ' ') {
			*(pEnd) = '0';
			pEnd--;
			*(pEnd) = '2';
			pEnd--;
			*(pEnd) = '%';
			pStr--;
			pEnd--;
		}
		else {
			*(pEnd) = *(pStr);
			pStr--;
			pEnd--;
		}
	}
}

void repalceSpace_inBook(char* str, int length) {
	if (str == nullptr || length < 0)
		return;

	int originalLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	while (str[i] != '\0') {
		++originalLength;
		if (str[i] == ' ')
			++numberOfBlank;
		i++;
	}

	int newLength = originalLength + numberOfBlank * 2;
	if (newLength > length)
		return;
	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
		if (str[indexOfOriginal] == ' ') {
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';
		}
		else
			str[indexOfNew--] = str[indexOfOriginal];
		--indexOfOriginal;
	}
}
int main() {
	char str[100] = "Hello  World!";
	int length = 100;
	cout << "Before replace: " << str << endl;
	repalaceSpace(str, length);
	cout << "After replace: " << str << endl;
	system("pause");
	return 0;
}