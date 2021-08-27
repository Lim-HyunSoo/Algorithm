#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void Selctionsort(vector<int> arr, int size) {
	int lowest, temp; 

	for (int index = 0; index < size - 1; index++) {
		lowest = index;
		for (int index2 = index; index2 < size; index2++) {
			if (arr[lowest] > arr[index2]) {
				lowest = index2;
			}
		}
		temp = arr[index];
		arr[index] = arr[lowest];
		arr[lowest] = temp;
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

	Selectionsort(testData, testData.size());

	return 0;
}
