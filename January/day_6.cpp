#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;
/*
20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 
Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

bool isValid(string s) {
    // Stack to keep track of opening brackets
    stack<char> stack;
    // Mapping of closing brackets to their corresponding opening brackets
    unordered_map<char, char> mapping = {{')', '('}, {'}', '{'}, {']', '['}};

    // Loop through each character in the string
    for (char c : s) {
        // If it's a closing bracket
        if (mapping.count(c)) {
            // Get the top element from the stack or a dummy character if the stack is empty
            char topElement = stack.empty() ? '#' : stack.top();
            stack.pop(); // Remove the top element
            // If it doesn't match the mapping, the string is invalid
            if (topElement != mapping[c]) {
                return false;
            }
        } else {
            // If it's an opening bracket, push it onto the stack
            stack.push(c);
        }
    }
    // If the stack is empty, all brackets were matched correctly
    return stack.empty();
}

// Examples
int main() {
    cout << boolalpha; // To print true/false instead of 1/0
    cout << isValid("()") << endl;       // Output: true
    cout << isValid("()[]{}") << endl;   // Output: true
    cout << isValid("(]") << endl;       // Output: false
    cout << isValid("([])") << endl;     // Output: true
    return 0;
}