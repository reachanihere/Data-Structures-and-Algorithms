#include <iostream>
using namespace std;

void removeX(char s[]) {
	if (s[0] == '\0') {
		return;
	}

	if (s[0] != 'x') {
		removeX(s + 1);
	} else {
		int i = 1;
		for (; s[i] != '\0'; i++) {
			s[i - 1] = s[i];
		}
		s[i - 1] = s[i];
		removeX(s);
	}
}

int length(char s[]) {
	if (s[0] == '\0') {
		return 0;
	}
	int smallStringLength = length(s + 1);
	return 1 + smallStringLength;
}

int main() {
	char str[100];
	cin >> str;

	int l = length(str);
	cout << l << endl;
	removeX(str);
	cout << str << endl;
	l = length(str);
	cout << l << endl;
}

