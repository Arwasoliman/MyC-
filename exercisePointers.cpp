// >> MyC/Pointers
// by Soliman - UniversityofFlorida

//This is a self implemented excercise covering the topic of pointers in C/C++
//In this example, I practice some aritmitic operations using pointers on a table of scores 

#include <iostream>
#include <iomanip>

// Function to safely print array element
void printElement(int *ptr, int index, int maxIndex) {
    if (!ptr) {
        std::cout << "Error: Pointer is nullptr!" << std::endl;
        return;
    }
    
    if (index >= 0 && index < maxIndex) {
        std::cout << "Element at index " << index << ": " << *(ptr + index) << std::endl;
    } else {
        std::cout << "Error: Index " << index << " out of bounds!" << std::endl;
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
    std::cout << "=== Exercise some pointers concepts on a table of scores ===" << std::endl<< std::endl;
    
    int scores[] = {85, 92, 78, 95, 88, 76, 91, 89};
    int size = 8;
    
    std::cout << "The data of the scores table :";
    for (int i = 0; i < size; i++) {
        std::cout << scores[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n--- Some operations using pointers ---" << std::endl;

    // ===== Find the minimum score  =====
    std::cout << "The minimum Score is : ";
    int *minPtr = findMin(scores, size);
    if (minPtr) {
        int minIndex = minPtr - scores;
        std::cout << *minPtr << " - "<< "at the index : " << minIndex << std::endl;
    }
    
    // ===== Access the score table elements using Pointer =====
    int *ptr = scores;
    
    // ===== Safe pointer arithmetic =====
    int *end = scores + size;
    ptr = scores;
    
    int sum = 0;
    while (ptr < end) {  // Safe bounds check
        sum += *ptr;
        ptr++;
    }
    std::cout << "Sum of all scores: " << sum << std::endl;
    std::cout << "Average score: " << std::fixed << std::setprecision(2) << (double)sum / size << std::endl;
    
    // ===== Swapping using pointers =====
    std::cout << "\n--- Swap using pointers ---" << std::endl;
    int *ptrA = &scores[0];
    int *ptrB = &scores[7];
    
    std::cout << "Before swap: scores[0] = " << *ptrA << ", scores[7] = " << *ptrB << std::endl;
    
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
    
    std::cout << "After swap:  scores[0] = " << *ptrA << ", scores[7] = " << *ptrB << std::endl;
    
    return 0;
}
