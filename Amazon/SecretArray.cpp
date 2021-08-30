//Secret Array
//
//
//An array is said to be analogous to the secret array if all of the following conditions are true:
//• The length of the array is equal to the length of the secret array.
//• Each integer in the array lies in the interval [lowerBound, upperBound].
//• The difference between each pair of consecutive integers of the array must be equal to the difference between the respective pair of consecutive integers in the secret array. In other words, let the secret array be [s[0], s[1],..., s[n-1]] and let the analogous array be [a[0], a[1],..., a[n-1]], then (a[i-1] - a[i]) must be equal to (s[i-1] - s[i]) for each i from 1 to n -1.
//
//Given the value of integers lowerBound and upperBound, inclusive, and the array of differences between each pair of consecutive integers of the secret array, find the number of arrays that are analogous to the secret array. If there is no array analogous to the secret array, return 0.
//
//consecutiveDifference = [-2, -1, -2, 5]
//lowerBound = 3
//upperBound = 10
//
//Note that none of the values is out of the bound. All possible analogous arrays are:
//[3, 5, 6, 8, 3]
//[4, 6, 7, 9, 4]
//[5, 7, 8, 10, 5]
//
//Tha answer is 3.

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int findSecretArrayCount(vector<int> A,int lowerBound,int upperBound){
    if(A.size()==0) return 0;
    int cur =0;
    int prev =lowerBound;
    int mini=lowerBound;
    int maxi=lowerBound;
    for(int i=0;i<A.size();i++){
        cur = prev - A[i];
        mini =min(mini,cur);
        maxi =max(maxi,cur);
        prev=cur;
//        cout<<mini<<" "<<maxi<<endl;
    }
    int count=0;
    while(maxi <= upperBound){
        if ( mini >= lowerBound ) count++;
        mini++;
        maxi++;
    }

    return count;
}

int main() {
    vector<int> A {-2, -1, -2, 5};
    int lowerBound =3;
    int upperBound =10;
    cout<<findSecretArrayCount(A,lowerBound,upperBound);

    return 0;
}
