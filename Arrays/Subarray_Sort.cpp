/*Subarray_Sort*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
bool out_of_order(vector<int> A, int i){
    if(i==0) return A[i] > A[i+1];
    else if(i== A.size()-1) return A[i] < A[i-1];
    return A[i] > A[i+1] || A[i] < A[i-1];
}

vector<int> subArraySort(vector<int> A){
    int n= A.size();
    int smallest= INT_MAX;
    int largest =INT_MIN;
    for(int i=0;i<n;i++){
        if(out_of_order(A,i)) {
            smallest = min(smallest, A[i]);
            largest = max(largest, A[i]);
        }
    }
    if(smallest == INT_MAX) return {-1,-1};
    int i=0,j=n-1;
//    cout<<smallest<<" "<<largest<<endl;
    while(i<n && smallest >A[i]) i++;
    while(j>=0 && largest < A[j]) j--;
    return {i,j};
}

int main() {
    vector<int> arr{1,2,3,4,5,8,6,7,9,10,11};
    vector<int> res = subArraySort(arr);
    cout<<"Range is ";
    for(auto p: res ){
        cout<<p<<" ";
    }

    return 0;
}
