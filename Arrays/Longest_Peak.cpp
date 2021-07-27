/*Longest Peak*/

#include <iostream>
#include <vector>
#include<string>
using namespace std;

int longestPeak(vector<int> A){
    int n= A.size();
    int sum=0;
    for(int i=1;i<n-1;){
        if(A[i] > A[i-1] && A[i] > A[i+1]){
            int j=i;
            int cnt=1;

            while(j>=1 && A[j] > A[j-1] ){
                j--;
                cnt++;
            }
            while(i<n-1 && A[i] > A[i+1]){
                i++;
                cnt++;
            }
            sum = max(cnt,sum);
        }

        else i++;
    }
    return sum;
}

int main() {
    vector<int> arr{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    cout<<longestPeak(arr)<<endl;

    return 0;
}
