
// >> MyC/Pointers
// by Soliman - UniversityofFlorida

//This is a self implemented excercise covering the topic of pointers in C/C++
//In this example, I practice some aritmitic operations using pointers on a table of scores 

#include <iostream>
using namespace std;

// Function to safely print array element
void printElement(int *ptr, int index, int maxIndex) {
    if (!ptr) {
        cout << "Error: Pointer is nullptr!" << endl;
        return;
    }
    
    if (index >= 0 && index < maxIndex) {
        cout << "Element at index " << index << ": " << *(ptr + index) << endl;
    } else {
        cout << "Error: Index " << index << " out of bounds!" << endl;
    }
}

// Function to find min in the array
int* findMin(int *ptr, int size) {
    if (!ptr || size <= 0) {
        return nullptr;
    }
    
    int *minPtr = ptr;
    for (int i = 1; i < size; i++) {
        if (*(ptr + i) < *minPtr) {
            minPtr = ptr + i;
        }
    }
    return minPtr;
}

int main() {
    cout << "=== Exercise some pointers concepts on a table of scores ===" << endl<< endl;
    
    int scores[] = {85, 92, 78, 95, 88, 76, 91, 89};
    int size = 8;
    
    cout << "The data of the scores table :";
    for (int i = 0; i < size; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;
    
    cout << "\n--- Some operations using pointers ---" << endl;

    // ===== Find the minimum score and its index using pointer  =====
    cout << "The minimum Score is : ";
    int *minPtr = findMin(scores, size);
    if (minPtr) {
        int minIndex = minPtr - scores;
        cout << *minPtr << " - "<< "at the index : " << minIndex << endl;
    }
    
    // ===== Access the score table elements using Pointer =====
    int *ptr = scores;
    int *end = scores + size;
    ptr = scores;
    
    int sum = 0;
    while (ptr < end) { 
        sum += *ptr;
        ptr++;
    }
    cout << "Sum of all scores: " << sum << endl;
    cout << "Average score: " << (double)sum / size << endl;
    
    // ===== Swapping using pointers =====
    cout << "\n--- Swap using pointers ---" << endl;
    int *ptrA = scores;
    int *ptrB = scores + size-1;
    
    cout << "Before swap" << endl;
    printElement(scores, 0, size);
    printElement(scores, size-1, size);
    cout << endl;

    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
    
    cout << "After swap" << endl;
    printElement(scores, 0, size);
    printElement(scores, size-1, size);
    cout << endl;
    return 0;
}
