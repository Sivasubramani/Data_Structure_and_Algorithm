/*Reverse Array using Binary search method*/

//O(logn) time complexity
//O(1) space 

#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b);
void reverseArray(vector<int> &A);

void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}
void reverseArray(vector<int> &A){
    int n= A.size();
    int left=0;
    int right=n-1;
    while(left<=right){
        swap(A[left],A[right]);
        left++;
        right--;
    }
}
int main() {
    vector<int> arr{1,2,10,11,19,21,28};
    reverseArray(arr);
    for(int x: arr){
        cout<<x<<endl;
    }
    return 0;
}
