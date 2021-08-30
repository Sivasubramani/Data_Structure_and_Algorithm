// Given an int array nums and an int target, find how many unique pairs in the array such that their sum is equal to target. Return the number of pairs.

// Example 1:

// Input: nums = [1, 1, 2, 45, 46, 46], target = 47
// Output: 2
// Explanation:
// 1 + 46 = 47
// 2 + 45 = 47
// Example 2:

// Input: nums = [1, 1], target = 2
// Output: 1
// Explanation:
// 1 + 1 = 2
// Example 3:

// Input: nums = [1, 5, 1, 5], target = 6
// Output: 1
// Explanation:
// [1, 5] and [5, 1] are considered the same.



#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;
vector<vector<int>> twoSumUniquePair(vector<int> A,int sum){
    unordered_set<int> elements;
    unordered_set<int> seen;
    vector<vector<int>> res;
    for(int i=0;i<A.size();i++){
        int x = sum -A[i];
        if(elements.find(x) != elements.end() &&  seen.find(x) == seen.end()){
            vector<int> out;
            out.push_back(x);
            out.push_back(A[i]);
            res.push_back(out);
            seen.insert(x);
            seen.insert(A[i]);
        }
        elements.insert(A[i]);
    }
    return res;
}

int main() {

    vector<int> A {1,1,2,45,46,46};
    vector<vector<int>> result=twoSumUniquePair(A,47);

    for(auto a: result) cout<<a[0]<<" "<<a[1]<<endl;

    return 0;
}
