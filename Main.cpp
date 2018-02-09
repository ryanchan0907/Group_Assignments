#include <iostream>

using namespace std;

void fillArr(int* arrToFill, int arrSize);
void printArr(int* arrToPrint, int arrSize);
int dotProduct(int* arrOne, int* arrTwo, int arrSize);
void alternateArr(int* firstArr, int* secondArr, int arrSize);
void negatives(int* arrToChange, int arrSize);

int main() {
	int arrSize;
	do {
		cout << "Enter the size of your arrays: ";
		cin >> arrSize;
		cout << endl;
	} while (arrSize < 1);
	int *arrOne = new int[arrSize];
	int *arrTwo = new int[arrSize];

	cout << "Now filling up array one.\n";
	fillArr(arrOne, arrSize);
	cout << "----------------------------" << endl;;
	cout << "Now filling up array two.\n";
	fillArr(arrTwo, arrSize);

	cout << "----------------------------\n";
	cout << "The dot product is: "<< dotProduct(arrOne, arrTwo, arrSize)<<"\n";

	cout << "Alternating Array: ";
	alternateArr(arrOne, arrTwo, arrSize);

	cout << "Negative Array 1: ";
	negatives(arrOne, arrSize);

	cout << "Negative Array 2: ";
	negatives(arrTwo, arrSize);

	delete[] arrOne;
	delete[] arrTwo;
	return 0;
}

void fillArr(int* arrToFill, int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		cout << "Enter a number for the array: ";
		cin >> arrToFill[i];
		cout << "\n";
	}
}

void printArr(int* arrToPrint, int arrSize) {
	cout << "[";
	for (int i = 0; i < arrSize; i++) {
		if (i < arrSize - 1)
			cout << arrToPrint[i] << ", ";
		else
			cout << arrToPrint[i];
	}
	cout << "]\n";
}

int dotProduct(int* arrOne, int* arrTwo, int arrSize) {
	int product=0;
	for (int i = 0; i < arrSize; i++) {
		product += arrOne[i] * arrTwo[i];
	}
	return product;
}

void alternateArr(int* firstArr, int* secondArr, int arrSize) {
	int* altArr = new int[arrSize*2];
	for (int altArrIndex = 0, originalIndex = 0; altArrIndex < arrSize*2; i+=2) {
	altArr[altArrIndex] = firstArr[originalIndex];
	altArr[altArrIndex+1] = secondArr[originalIndex];
	originalIndex++;
	}
	
	printArr(altArr, arrSize * 2);
	delete[] altArr;
	return;
}

void negatives(int* arrToChange, int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		arrToChange[i] = -1 * arrToChange[i];
	}
	printArr(arrToChange, arrSize);
	return;
}