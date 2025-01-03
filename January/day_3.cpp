#include <iostream>
using namespace std;

/*
9. Palindrome Number
Given an integer x, return true if x is a palindrome integer.

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-231 <= x <= 231 - 1
*/

// Function to determine if an integer is a palindrome
bool isPalindrome(int x) {
    // Negative numbers are not palindromes
    if (x < 0)
        return false;

    // Variable to store the reversed number
    long reversed = 0;
    // Copy of the original number to manipulate
    int y = x;

    // Reverse the digits of the number
    while (y > 0) {
        // Append the last digit of y to reversed
        reversed = reversed * 10 + y % 10;
        // Remove the last digit from y
        y /= 10;
    }

    // Check if the original number is equal to its reversed version
    return reversed == x;
}

int main() {
    int x;
    // Prompt the user to enter an integer
    cout << "Enter an integer: ";
    // Read the integer from standard input
    cin >> x;
    // Output whether the integer is a palindrome
    cout << "Is Palindrome: " << isPalindrome(x) << endl;
    return 0;
}
