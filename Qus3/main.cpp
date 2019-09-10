#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :				//结构体的构造函数，用来取代为新结构体赋值的代码
		val(x), next(NULL) {}
};

void ListCreate(ListNode *p, int count)
{
	ListNode *newP;
	newP = p;
	ListNode *nextP;
	
	for (int i = 1; i <= count; i++) {
		nextP = new	ListNode(i);
		newP->next = nextP;
		newP = nextP;
	}
}

void PrintNode(ListNode *p) {
	if (p->next == nullptr)
		cout << p->val << endl;
	else
		cout << p->val << "->\t";
}

void PrintList(ListNode *p) {
	while (p != NULL) {
		PrintNode(p);
		p = p->next;
	}
}

// 递归实现从头到尾打印链表并存于容器中
vector<int> PrintListFromTailToHead(ListNode *head) {
	vector<int> result;
	ListNode *p = head;
	if(p->next != nullptr)
		result = PrintListFromTailToHead(p->next);
	result.push_back(p->val);
	if (p == head)
		return result;
}

void PrintListFromTailToHead_inBook(ListNode *head) {
	std::stack<ListNode *> nodes;
	ListNode *p = head;
	while (p != nullptr) {
		nodes.push(p);
		p = p->next;
	}
	while (!nodes.empty()){
		p = nodes.top();
		printf("%d\t", p->val);
		nodes.pop();
	}
}

int main() {
	ListNode *head;
	head = new ListNode(0);
	ListCreate(head, 10);
	vector<int> result;
	//result = PrintListFromTailToHead(head);
	PrintListFromTailToHead_inBook(head);
	system("pause");
	return 0;
}