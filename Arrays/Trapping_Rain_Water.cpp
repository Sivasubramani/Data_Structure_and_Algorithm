/*Trapping_Rain_Water*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int trappedrainWater(vector<int> A){
    int n= A.size();
    vector<int> left(n,0);
    vector<int> right(n,0);
    left[0]=A[0];
    right[n-1] = A[n-1];
    for(int i=0;i<n;i++){
        left[i+1]= max(left[i],A[i+1]);
        right[n-i-2] = max(right[n-i-1],A[n-i-2]);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+= (min(left[i],right[i])) - A[i];
    }
    return sum;
}

int main() {
    vector<int> arr{0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trappedrainWater(arr)<<endl;

    return 0;
}
