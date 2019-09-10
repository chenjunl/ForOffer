#include<iostream>
#include<vector>

using namespace std;

struct treeNode {
	int val;
	treeNode *left;
	treeNode *right;
	treeNode(int x) :val(x), left(nullptr), right(nullptr){}
};

treeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	treeNode *root = nullptr;
	if (pre.size() == 0)
		return root;
	root = new treeNode(pre[0]);
	vector<int> preLeft, preRight, vinLeft, vinRight;
	int i;
	for (int flag = 0, i = 0; i < pre.size(); i++) {
		if (vin[i] != pre[0] && flag == 0) 
			vinLeft.push_back(vin[i]);
		else if (vin[i] == pre[0])
			flag = 1;
		else
			vinRight.push_back(vin[i]);
	}
	for (i = 1; i < pre.size(); i++) {
		if (i < vinLeft.size() + 1)
			preLeft.push_back(pre[i]);
		else
			preRight.push_back(pre[i]);
	}
	root->left = reConstructBinaryTree(preLeft, vinLeft);
	root->right = reConstructBinaryTree(preRight, vinRight);
	return root;
}

void printTree(treeNode *root) {
	if (root == nullptr)
		return;
	cout << root->val << "\t";
	printTree(root->left);
	printTree(root->right);
}

int main(){
	vector<int> pre = { 1,2,4,7,3,5,6,8 };
	vector<int> vin = { 4,7,2,1,5,3,8,6 };
	treeNode *root;
	root = reConstructBinaryTree(pre, vin);
	printTree(root);
	system("pause");
	return 0;
}