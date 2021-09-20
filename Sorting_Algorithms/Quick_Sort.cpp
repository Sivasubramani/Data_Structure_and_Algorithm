#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

//Time Complexity - O(nlogn)
// Space Complexity - O(n)


int getPivotValue(vector<int> &A,int start,int end){

    int j=start;
    int pivot = end;
    int pivPoint = A[end];
    for(int i=start;i<=end;i++){
        if(A[i] <= A[pivot]){
            swap(A[i],A[j]);
            j++;
        }
    }
    swap(A[pivot],A[j]);
    return pivot;

}
void quickSort(vector<int> &A,int start,int end){
    if(start<end){
        int pivot = getPivotValue(A,start,end);
        quickSort(A,start,pivot-1);
        quickSort(A,pivot+1,end);
    }

}

int main(){
    vector<int> A{2,7,4,5,3,1,-23,34,56,-132,-1322,131,-131,-124,342,-65,-54,-35,43};
    int n= A.size();
    quickSort(A,0,n-1);
    for(auto a:A) cout<<" "<<a;

}
