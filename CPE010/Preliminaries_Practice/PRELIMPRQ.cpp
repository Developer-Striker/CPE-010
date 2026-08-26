#include <iostream>
#include "PalindromeARR.h"

// ==========================================
// Palindrome Implementation Using Your Queue
// ==========================================
bool isNumberPalindrome(int number) {
    if (number < 0) return false;
    if (number >= 0 && number < 10) return true;

    int originalNumber = number;
    
    // Allocate space for up to 20 digits (plenty for a standard integer)
    queueArr<int> myQueue(20); 

    // Step 1: Extract digits from right to left and enqueue them
    while (number > 0) {
        int digit = number % 10;
        myQueue.Enqueue(digit);
        number /= 10;
    }

    // Step 2: Rebuild the number from the queue
    // Because it is a FIFO queue, the first digit we enqueued (the last digit of original)
    // is the first one out. This effectively preserves the original digit direction!
    int extractedOriginal = 0;
    int placeValue = 1;

    while (!myQueue.Empty()) {
        int digit = myQueue.Front();
        myQueue.Dequeue();
        
        extractedOriginal += digit * placeValue;
        placeValue *= 10;
    }

    // Step 3: Compare reconstructed sequence to original value
    return originalNumber == extractedOriginal;
}

int main() {
    int testNumbers[] = {12321, 10201, 88, 0, 12345};

    std::cout << "====================================\n";
    std::cout << "   Queue-Based Palindrome Check     \n";
    std::cout << "====================================\n";

    for (int num : testNumbers) {
        std::cout << "Testing: " << num << "\t -> ";
        if (isNumberPalindrome(num)) {
            std::cout << "IS a palindrome.\n";
        } else {
            std::cout << "is NOT a palindrome.\n";
        }
    }

    return 0;
}

