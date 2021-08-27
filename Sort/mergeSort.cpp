#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> splitVector(vector <int> arr, int size) {
	int medium = size / 2;

	vector <int> leftVec;
	vector <int> rightVec;

	for (int i = 0; i < size; i++) {
		if (i < medium) {
			leftVec.push_back(arr[i]);
		}
		else {
			rightVec.push_back(arr[i]);
		}
	}

	return mergeFunc(leftVec, rightVec);
}

vector <int> mergeFunc(vector <int> left, vector <int> right) {
	vector <int> mergeVec;
	int leftIndex = 0;
	int rightIndex = 0;

	while (left.size() > leftIndex || right.size() > rightIndex) {
		if (left[leftIndex] > right[rightIndex]) {
			mergeVec.push_back(right[rightIndex]);
			rightIndex++;
		}
		else {
			mergeVec.push_back(left[leftIndex]);
			leftIndex++;
		}
	}

	while (left.size() > leftIndex) {
		mergeVec.push_back(left[leftIndex]);
		leftIndex++;
	}

	while (right.size() > rightIndex) {
		mergeVec.push_back(right[rightIndex]);
		rightIndex++;
	}
	
	return mergeVec;
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


	vector <int> resultData = splitVector(testData, size);

	for (int data : resultData) {
		cout << data << " ";
	}

	return 0;
}
