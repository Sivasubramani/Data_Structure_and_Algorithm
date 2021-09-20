#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

//Selection Sort
//Time Complexity - O(n^2) in All cases
//Space Complexity - O(1)
//Clue -> Find min and traverse
int main(){
    vector<int> A {2,7,4,5,3,1,-23,34,56,-132,-1322,131,-131,-124,342,-65,-54,-35,43};
    int n= A.size();
    for(int i=0;i<n-1;i++){
        int minValue =A[i];
        for(int j=i+1;j<n;j++){

            if(minValue > A[j]){
                swap(A[i],A[j]);
                minValue =A[i];
            }
        }
    }
    for(auto a:A) cout<<" "<<a;
}

