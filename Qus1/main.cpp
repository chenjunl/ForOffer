#include<iostream>
#include<vector>
using namespace std;

bool Find(int target, vector<vector<int>> array) {
	int column = array.size();
	if (column == 0)
		return false;
	int raw = array[0].size();
	cout << "raw: " << raw << endl << "column: " << column << endl;
	int i = 0;
	int j = column - 1;
	int k = 0;
	for (; i <= raw - 1; i++) {
		for (; j >= 0; j--) {
			k++;
			cout << "No." << k << ": " << array[i][j] << endl;
			if (array[i][j] > target)
				continue;
			else if (array[i][j] == target)
				return true;
			else
				break;
		}
		if (j < 0)
			j++;
		if (array[i][j] < target)
			continue;
		else if (array[i][j] == target)
			return true;
		else
			break;
	}
	return false;
}

bool Find_inBook(int *matrix, int rows, int columns, int number) {
	bool found = false;

	if (matrix != nullptr && rows > 0 && columns > 0) {
		int row = 0;
		int column = columns - 1;
		while (row < rows && column >= 0) {
			if (matrix[row*columns + column] == number) {
				found = true;
				break;
			}
			else if (matrix[row*columns + column] > number)
				--column;
			else
				++row;
		}
	}
	return found;
}

int main() {
	int t = 0;
	vector<vector<int>> a = { {1, 2, 8, 9},{2, 4, 9, 12},{4, 7, 10, 13},{6, 8, 11, 15} };
	cout << "result: " << Find(t, a) << endl;
	system("pause");
	return 0;
}