#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void bsort(vector<int> arr, int size) {
	for (int index = 0; index < size; index++) {
		for (int index2 = 0; index2 < size - index - 1; index2++) {
			if (arr[index2] > arr[index2 + 1]) {
				int temp = arr[index2];
				arr[index2] = arr[index2 + 1];
				arr[index2 + 1] = temp;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	
}

int main() {
	vector<int> testData(10);

	for (int i = 0; i < 10; i++) {
		testData[i] = int(rand() % 100);
	}
	
	
	for (int i = 0; i < 10; i++) {
		cout << testData[i] << " ";
	}
	cout << endl;

	bsort(testData, testData.size());

	return 0;
}
