// >> MyC/Problems
// by Soliman - UniversityofFlorida

//This is a self solved problem on 
//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//You can return the answer in any order.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map <int, int> hash;
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if(hash.find(complement) != hash.end())
                return {hash[complement],i};

        hash[nums[i]] = i;           
    }
    return {};
}

int main(){

    // Test Case 1:
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = twoSum(nums1, target1);
    cout << "Test Case 1: ";
    for (int i=0; i < result1.size(); i++) 
        cout << result1[i] << " "; // Expected output: [0, 1]
    cout << endl;

    // Test Case 2:
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = twoSum(nums2, target2);
    cout << "Test Case 2: ";
    for (int i=0; i < result2.size(); i++) 
        cout << result2[i] << " "; // Expected output: [1, 2]
    cout << endl;

    // Test Case 3:
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = twoSum(nums3, target3);
    cout << "Test Case 3: ";
    for (int i=0; i < result3.size(); i++) 
        cout << result3[i] << " "; // Expected output: [0, 1]
    cout << endl;

    return 0;
}