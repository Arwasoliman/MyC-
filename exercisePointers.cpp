
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

// Function to safely search in array
int* safeFindMin(int *ptr, int size) {
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
    std::cout << "=== Advanced Pointer Concepts ===" << std::endl;
    
    int scores[] = {85, 92, 78, 95, 88, 76, 91, 89};
    int size = 8;
    
    std::cout << "\n--- Original Array ---" << std::endl;
    std::cout << "Scores: ";
    for (int i = 0; i < size; i++) {
        std::cout << scores[i] << " ";
    }
    std::cout << std::endl;
    
    // ===== Find minimum score safely =====
    std::cout << "\n--- Find Minimum Score ---" << std::endl;
    int *minPtr = safeFindMin(scores, size);
    if (minPtr) {
        int minIndex = minPtr - scores;
        std::cout << "Minimum score: " << *minPtr << " at index " << minIndex << std::endl;
    }
    
    // ===== Safe element access =====
    std::cout << "\n--- Safe Element Access ---" << std::endl;
    printElement(scores, 0, size);
    printElement(scores, 7, size);
    printElement(scores, 10, size);  // Out of bounds - safely handled
    
    // ===== Pointer manipulation =====
    std::cout << "\n--- Pointer Manipulation ---" << std::endl;
    int *ptr = scores;
    std::cout << "First element: " << *ptr << std::endl;
    std::cout << "Third element using ptr[2]: " << ptr[2] << std::endl;
    std::cout << "Third element using *(ptr+2): " << *(ptr + 2) << std::endl;
    
    // ===== Safe pointer arithmetic =====
    std::cout << "\n--- Safe Pointer Arithmetic ---" << std::endl;
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
    std::cout << "\n--- Swap Using Pointers ---" << std::endl;
    int *ptrA = &scores[0];
    int *ptrB = &scores[7];
    
    std::cout << "Before swap: scores[0] = " << *ptrA << ", scores[7] = " << *ptrB << std::endl;
    
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
    
    std::cout << "After swap:  scores[0] = " << *ptrA << ", scores[7] = " << *ptrB << std::endl;
    
    // ===== Complex pointer scenarios =====
    std::cout << "\n--- Complex Scenarios ---" << std::endl;
    
    // Check if two pointers point to same element
    int *ptr1 = &scores[3];
    int *ptr2 = scores + 3;
    std::cout << "ptr1 == ptr2: " << (ptr1 == ptr2 ? "true (same element)" : "false") << std::endl;
    
    // Check pointer order
    ptr1 = &scores[2];
    ptr2 = &scores[5];
    if (ptr1 < ptr2) {
        std::cout << "ptr1 points to an earlier element than ptr2" << std::endl;
    }
    
    // Count difference
    std::cout << "Distance between ptr1 and ptr2: " << (ptr2 - ptr1) << " elements" << std::endl;
    
    return 0;
}
