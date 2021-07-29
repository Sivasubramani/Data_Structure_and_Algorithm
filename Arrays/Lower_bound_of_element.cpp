/*Lower_bound_of_element*/
#include <iostream>
#include <vector>

using namespace std;
//O(n) time complexity
//O(1) space complexity
int lowerBound(vector<int> A,int x){
    int n=A.size();
    int left= 0;
    int right =n-1;
    int minimum=INT_MAX;
    int element =-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(A[mid] ==x) return A[mid];

        else if(A[mid] <x) {
            int value= x-A[mid];
            if(minimum > value){
                minimum=value;
                element =A[mid];
            }
            left = mid+1;
        }
        else right =mid-1;
    }
    return element;
}

int main() {
    vector<int> arr{-1,1,3,5,232};
    int num=0;
    cout<<"Enter the number to find the lowerbound"<<endl;
    cin>>num;
    cout<<"Lowerbound of "<<num<<" is: "<<lowerBound(arr,num)<<endl;

    return 0;
}
