#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].*/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int romanToInt(string s) {
    // Map to store Roman numeral values
    unordered_map<char, int> roman = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int result = 0;
    int n = s.size();
    
    // Loop through the string
    for (int i = 0; i < n; i++) {
        // If the current value is less than the next value, subtract it
        if (i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {
            result -= roman[s[i]];
        } else {
            // Otherwise, add it
            result += roman[s[i]];
        }
    }
    
    return result;
}

int main() {
    // Test cases
    string s1 = "III";
    string s2 = "LVIII";
    string s3 = "MCMXCIV";
    
    cout << "Roman numeral: " << s1 << ", Integer: " << romanToInt(s1) << endl; // Output: 3
    cout << "Roman numeral: " << s2 << ", Integer: " << romanToInt(s2) << endl; // Output: 58
    cout << "Roman numeral: " << s3 << ", Integer: " << romanToInt(s3) << endl; // Output: 1994
    
    return 0;
}


