/*Binary_Search*/
//For both ascending and descending order
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int binarySearch(vector<int> A,int k){
    //Array should be sorted for binary search
    int n=A.size();
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(A[mid] == k) return mid;
        else if(A[mid] < k) start =mid+1;
        else end=mid-1;
    }
    return -1;

}

int binarySearchDecreasing(vector<int> A,int k){
    //Array should be sorted for binary search
    int n=A.size();
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(A[mid] == k) return mid;
        else if(A[mid] > k) start =mid+1;
        else end=mid-1;
    }
    return -1;

}
int main() {
    vector<int> arr{1,2,10,11,19,21,28};
    cout<<binarySearch(arr,19)<<endl;
    cout<<binarySearchDecreasing({90,30,20,15,12,5,4,2},4)<<endl;

}
