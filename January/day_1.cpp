#include  <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Two Sum Problem
Given an array nums and an integer target, return indices of two numbers that add up to target.

Examples:
Input: nums = [2, 7, 11, 15], target = 9 → Output: [0, 1]
Input: nums = [3, 2, 4], target = 6 → Output: [1, 2]
Input: nums = [3, 3], target = 6 → Output: [0, 1]

Constraints:

Array length: 2 to 10⁴
Numbers: -10⁹ to 10⁹
One valid answer exists.
Follow-up: Solve in less than O(n²) time complexity.
*/

//Solution 1: (Brute Force) Time complexity o(n*2)
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
         for (int j = i + 1; j < n; j++) {
             if (nums[i] + nums[j] == target) {
                return {i, j};
             }
         }
    }
    return {}; // No solution found
}

//Solution 2: (Two-pass Hash Table) Time complexity o(n) 
vector<int> twoSum2(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    int n = nums.size();

    // Build the hash table
    for (int i = 0; i < n; i++) {
        numMap[nums[i]] = i;
    }

    // Find the complement
    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        if (numMap.count(complement) && numMap[complement] != i) {
            return {i, numMap[complement]};
         }
     }

    return {}; // No solution found
}

//Solution 3: (One-pass Hash Table) Time complexity o(n)
vector<int> twoSum3(vector<int>& nums, int target) {
      unordered_map<int, int> numMap;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
         int complement = target - nums[i];
         if (numMap.count(complement)) {
              return {numMap[complement], i};
         }
         numMap[nums[i]] = i;
     }

      return {}; // No solution found
}


vector<int> twoSum(vector<int>& nums, int target);
vector<int> twoSum2(vector<int>& nums, int target);
vector<int> twoSum3(vector<int>& nums, int target);


void printResult(const vector<int>& result) {
    if (!result.empty()) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }
}

int main() {
    
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    cout << "Testing Solution 1 (Brute Force):" << endl;
    vector<int> result1 = twoSum(nums, target);
    printResult(result1);

    cout << "\nTesting Solution 2 (Two-pass Hash Table):" << endl;
    vector<int> result2 = twoSum2(nums, target);
    printResult(result2);

    cout << "\nTesting Solution 3 (One-pass Hash Table):" << endl;
    vector<int> result3 = twoSum3(nums, target);
    printResult(result3);

    return 0;
}
