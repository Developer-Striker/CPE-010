#include <iostream>
#include "PalindromeLL.h"

// ==========================================
// Palindrome Implementation Using Your Stack
// ==========================================
bool isNumberPalindrome(int number) {
    // Negative numbers are not palindromes
    if (number < 0) return false;
    // Single digits are always palindromes
    if (number >= 0 && number < 10) return true;

    int originalNumber = number;

    // Step 1: Push all digits onto the stack
    while (number > 0) {
        int digit = number % 10;
        push<int>(digit); 
        number /= 10;
    }

    // Step 2: Pop digits to rebuild the number in reverse
    int reversedNumber = 0;
    int placeValue = 1;

    while (!isEmpty<int>()) {
        int digit = pop<int>();
        reversedNumber += digit * placeValue;
        placeValue *= 10;
    }

    // Step 3: Compare original with reversed
    return originalNumber == reversedNumber;
}

int main() {
    int num = 1003003001;

    std::cout << "Checking number: " << num << "\n";
    
    if (isNumberPalindrome(num)) {
        std::cout << num << " IS a palindrome.\n";
    } else {
        std::cout << num << " is NOT a palindrome.\n";
    }

    return 0;
}