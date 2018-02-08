#include <iostream>

using namespace std;

void fillArr(int* arrToFill, int arrSize);
void alternateArr(int* firstArr, int* secondArr, int arrSize);
void negatives(int* arrToChange, int arrSize);

int main() {
	int arrSize;
	do {
		cout <<"Enter the size of your arrays: ";
		cin >> arrSize;
		cout << endl;
	} while (arrSize < 1);
	int *arrOne = new int[arrSize];
	int *arrTwo = new int[arrSize];

	cout << "Now filling up array one.\n";
	fillArr(arrOne, arrSize);
	cout << "----------------------------\n";
	cout << "Now filling up array two.\n";
	fillArr(arrTwo, arrSize);
	
	negatives(arrOne, arrSize);
	alternateArr(arrOne, arrTwo, arrSize);
	system("PAUSE");
	return 0;
}

void fillArr(int* arrToFill, int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		cout << "Enter a number for the array: ";
		cin >> arrToFill[i];
		cout << "\n";
	}
}

void alternateArr(int* firstArr, int* secondArr, int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		if (i < arrSize - 1)
			cout << firstArr[i] << ", " << secondArr[i] << ", ";
		else
			cout << firstArr[i] << ", " << secondArr[i];
	}
	/*cout << "[";
	for (int i = 0; i < arrSize; i++) {
		if (i < arrSize - 1)
			cout << firstArr[i] << ", " << secondArr[i] << ", ";
		else
			cout << firstArr[i] << ", " << secondArr[i];
	}
	cout << "]"<<endl;*/
}

void negatives(int* arrToChange, int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		arrToChange[i] = -1 * arrToChange[i];
	}
}