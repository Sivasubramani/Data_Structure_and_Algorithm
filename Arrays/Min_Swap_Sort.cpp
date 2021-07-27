/*
Minimum number of swaps required to sort an array
Difficulty Level : Hard
Last Updated : 24 Jun, 2021
Given an array of n distinct elements, find the minimum number of swaps required to sort the array.

Examples: 

Input: {4, 3, 2, 1}
Output: 2
Explanation: Swap index 0 with 3 and 1 with 2 to 
              form the sorted array {1, 2, 3, 4}.

Input: {1, 5, 4, 3, 2}
Output: 2
*/

#include <iostream>
#include <vector>
#include<string>
using namespace std;

int minSwap(vector<int> A){
    int n= A.size();
    vector<pair<int,int>> native;
    for(int i=0;i<n;i++){
        native.push_back({A[i],i});
    }

    sort(native.begin(),native.end());
    vector<bool> visited(n,false);
    int sum=0;

    for(int i=0;i<n;i++){
        int oldPosition = native[i].second;
        if(visited[i] ==true || oldPosition == i) continue;
        int node=i;
        int cnt=0;
        while(!visited[node]){
            visited[node] = true;
            node = native[i].second;
            cnt++;
        }
        sum+=cnt-1;
    }
    return sum;
}

int main() {
    vector<int> arr{5,4,3,2,1};
    cout<<minSwap(arr)<<endl;

    return 0;
}
