#include <iostream>
#include <vector>

using namespace std;
//Bubble Sort optimized
//Time Complexity -O(n^2) in Average and Worst Case and O(n) in best case(sorted order)
//Space Complexity -O(1)
//Better than Selection sort in Best case
//Adjacennt compare and swap is the clue

int main(){
    vector<int> A{2,7,4,5,3,1,-23,34,56,-132,-1322,131,-131,-124,342,-65,-54,-35,43};
    int n = A.size();
    for(int i=0;i<n;i++){
        bool no_swap=false;
        for(int j=0;j<n-1;j++){
            if(A[j] >A[j+1]){
                swap(A[j],A[j+1]);
                no_swap = true;
            }
        }
        if(!no_swap) break;
    }

    for(auto a:A) cout<<" "<<a;
}

