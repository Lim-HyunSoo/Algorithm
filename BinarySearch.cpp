#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int binarySearch(vector<int> _arr, int _search) {
	if (_arr.size() == 1 && (_search == _arr[0])) {
		return 0;
	}
	if (_arr.size() == 0 || ((_arr.size() == 1) && (_search != _arr[0]))) {
		return -1;
	}

	int medium = _arr.size() / 2;
	int size = _arr.size();

	if (_search == _arr[medium]) {
		return medium;
	}
	else {
		vector <int> arr;
		if (_search < _arr[medium]) {
			for (int i = 0; i < medium; i++) {
				arr.push_back(_arr[i]);
			}
		}
		else {
			for (int i = medium + 1; i < size; i++) {
				arr.push_back(_arr[i]);
			}
		}
		return binarySearch(arr, _search);
	}
}

void bsort(vector<int> _arr, int size) {
	for (int index = 0; index < size; index++) {
		for (int index2 = 0; index2 < size - index - 1; index2++) {
			if (_arr[index2] > _arr[index2 + 1]) {
				int temp = _arr[index2];
				_arr[index2] = _arr[index2 + 1];
				_arr[index2 + 1] = temp;
			}
		}
	}

	int i = binarySearch(_arr, 24);
	cout << i << endl;
}

int main() {
	vector <int> testData;

	for (int i = 0; i < 10; i++) {
		testData.push_back(int(rand() % 100));
	}

	int size = testData.size();

	for (int data : testData) {
		cout << data << " ";
	}
	cout << endl;

	bsort(testData, size);

	return 0;
}
