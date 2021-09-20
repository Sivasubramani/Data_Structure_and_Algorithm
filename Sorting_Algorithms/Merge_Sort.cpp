#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

//Time Complexity - O(nlogn)
// Space Complexity - O(2n) ~ O(n) if we delete auxilary array
void mergeIntervals(vector<int> &A, int start, int mid, int end){
    int i=start;
    int j=mid+1;
    vector<int> temp;
    while(i<=mid && j<= end){
        if(A[i] <A[j]){
            temp.push_back(A[i]);
            i++;
        }
        else{
            temp.push_back(A[j]);
            j++;
        }
    }

    while(i<=mid ){
        temp.push_back(A[i]);
        i++;
    }
    while(j<=end ){
        temp.push_back(A[j]);
        j++;
    }

    for(int i=start;i<=end;i++){
        A[i] =temp[i-start];
    }
}

void mergeFunction(vector<int> &A, int start, int end){
    if(start < end){
        int mid = (start + end)/2;
        mergeFunction(A,start,mid);
        mergeFunction(A,mid+1,end);
        mergeIntervals(A,start,mid,end);
    }
}

int main(){
    vector<int> A{2,7,4,5,3,1,-23,34,56,-132,-1322,131,-131,-124,342,-65,-54,-35,43};
    int n = A.size();
    mergeFunction(A,0,n-1);
    for(auto a: A) cout<<a<<" ";
}
