/*Largest Subarray Sum by Kadane's Algorithm*/
#include <iostream>
#include <vector>

using namespace std;
//O(n) time complexity
//O(1) space complexity
int kadanesAlgorithm(vector<int> A){
    int n= A.size();
    int currentSum =0;
    int largestSum=0;
    for(int i=0;i<n;i++){
        currentSum +=A[i];
        if(currentSum <=0 ) currentSum=0;
        largestSum = max(largestSum,currentSum);
    }
    return largestSum;
}
int kadanesAlgorithm_Pattern(vector<int> A){
    int n= A.size();
    int currentSum =0;
    int largestSum=0;
    int consistent =0;
    vector<int> v;
    for(int i=0;i<n;i++){
        currentSum +=A[i];
        if(currentSum <=0 ) {
            consistent=0;
            currentSum=0;
        }
        else consistent++;

        if(currentSum > largestSum){
            if(consistent) v.push_back(A[i]);
        }
        else consistent=0;
        largestSum = max(largestSum,currentSum);
    }
    return largestSum;
}

int main() {
    vector<int> arr{10,9,7,8,6,5,4,3,2,1,-5,4,5,-57,200};
    cout<<"Largest subarray Sum by Kadane's Algorithm: "<<kadanesAlgorithm(arr)<<endl;

    return 0;
}
