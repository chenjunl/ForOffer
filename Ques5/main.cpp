#include<iostream>
#include<stack>

using namespace std;

void stackPush(int node, stack<int> S1, stack<int> S2) {
	for (int i = 0; S2.empty() != 0; i++) {
		int temp = S2.top();
		S2.pop();
		S1.push(temp);
	}
	S1.push(node);
	return;
}

int stackPop(stack<int> S1, stack<int> S2) {
	for (int i = 0; S1.empty() != 0; i++) {
		int temp = S1.top();
		S1.pop();
		S2.push(temp);
	}
	int temp = S2.top();
	S2.pop();
	return temp;
}

void printStack(stack<int> S) {
	int temp;
	for (int i = 0; i < S.size(); i++) {
		temp = S.top();
		S.pop();
		cout << temp << "\t";
	}
}

int main() {
	stack<int> S1, S2;
	stackPush(1, S1, S2);
	stackPush(2, S1, S2);
	stackPush(3, S1, S2);
	cout << stackPop(S1, S2);
	cout << stackPop(S1, S2);
	stackPush(4, S1, S2);
	cout << stackPop(S1, S2);
	stackPush(5, S1, S2);
	cout << stackPop(S1, S2);
	cout << stackPop(S1, S2);
	system("pause");
	return 0;
}