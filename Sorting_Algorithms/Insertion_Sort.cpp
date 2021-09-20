#include <iostream>
#include <vector>

using namespace std;
//Insertion Sort
//Time Complexity ->O(n^2) in Worst and Average case and O(n) in Best case
//Space Complexity -> O(1)
//Better than Bubble sort, no extra case need to handle

int main(){
    vector<int> A{2,7,4,5,3,1,-23,34,56,-132,-1322,131,-131,-124,342,-65,-54,-35,43};
    int n = A.size();
    for(int i=1;i<n;i++){
        int value = A[i];
        int hole =i;
        while(hole >0 && A[hole] < A[hole-1]){
            swap(A[hole],A[--hole]);
        }
    }
    for(auto a:A) cout<<" "<<a;
}

