#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/


string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
        return "";
    }
    
    // Sort the strings lexicographically
    sort(strs.begin(), strs.end());
    
    // Compare the first and last strings after sorting
    string first = strs[0];
    string last = strs[strs.size() - 1];
    string commonPrefix = "";
    
    for (int i = 0; i < min(first.size(), last.size()); i++) {
        if (first[i] == last[i]) {
            commonPrefix += first[i];
        } else {
            break;
        }
    }
    
    return commonPrefix;
}

int main() {
    vector<string> strs1 = {"flower", "flow", "flight"};
    vector<string> strs2 = {"dog", "racecar", "car"};
    
    cout << "Longest Common Prefix (Example 1): " << longestCommonPrefix(strs1) << endl; // Output: "fl"
    cout << "Longest Common Prefix (Example 2): " << longestCommonPrefix(strs2) << endl; // Output: ""
    
    return 0;
}
