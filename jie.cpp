#include <iostream>
#include <string>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::isdigit;

bool isNumber(const std::string& s) {
  string::const_iterator it = s.begin();
  while(it != s.end() && isdigit(*it)) {
    ++it;
  }
  return !s.empty() && it == s.end();
}


int getSize() {
  int size = 0;
  string input;
  while (size <= 0) {
    cout<<"Enter array size: ";
    getline(cin, input);
    cout << input << endl;
    if(!isNumber(input)) {
      cout << "Incorrect array size. Please try again." << endl;
      continue;
    }
    size = atoi(input.c_str());
    if(size <= 0) {
      cout << "Incorrect array size. Please try again." << endl;
    }
  }
  return size;
}

int* createArray(int size) {
  int element;
  string input;
  int* a = new int[size];
  for(int i = 0; i < size;) {
    cout << "Enter element: ";
    getline(cin, input);
    if(!isNumber(input)) {
      cout << "Incorrect element type. Please try again." <<endl;
      continue;
    } else {
      a[i++] = atoi(input.c_str());
    }
  }
  return a;
}

int dotProduct(int* a1, int* a2, int size) {
  int result = 0;
  int* p1 = a1;
  int* p2 = a2;
  for(int i = 0; i < size; ++i) {
    result += (*p1++) * (*p2++);
  }
  return result;
}

void printArray(int* a, int size) {
  cout << "[";
  for (int i = 0; i < size; ++i) {
    cout << a[i];
    if(i != size - 1) {
      cout << ", ";
    }
  }
  cout << "]";
}

void negatives(int* a1, int* a2, int size) {
  for(int i = 0; i < size; ++i) {
    a1[i] = (-1) * a1[i];
    a2[i] = (-1) * a2[i];
  }
}

void alternate(int *a1, int *a2, int size) {
  cout << "[";
  for (int i = 0; i < size; ++i) {
    cout << a1[i] << ", " << a2[i];
    if (i != size - 1) {
      cout << ", ";
    }
  }
  cout << "]";
}


int main() {
  int size = getSize();
  cout << "-----Begin Entering Array Elements-----" << endl;
  cout << "Array 1: " << endl;
  int* a1 = createArray(size);
  cout << "---------------------------------------" << endl;
  cout << "Array 2: " << endl;
  int* a2 = createArray(size);
  cout << "---------------------------------------" << endl;
  cout << "The dot product is: " << dotProduct(a1, a2, size) << endl;
  cout << "Alternating Arrays: ";
  alternate(a1, a2, size);
  cout << endl;
  negatives(a1, a2, size);
  cout << "Negative Array 1: ";
  printArray(a1, size);
  cout << endl;
  cout << "Negative Array 2: ";
  printArray(a2, size);
  cout << endl;

  delete[] a1;
  delete[] a2;

  return 0;
}
