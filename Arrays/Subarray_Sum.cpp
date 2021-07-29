/*Subarray Sum*/

#include <iostream>
#include <vector>

using namespace std;
void subArrayCombination(vector<int> A){
    int n=A.size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<"[";
            count++;
            for(int k=i;k<=j;k++){
                if(k==j) cout<<A[k];
                else cout<<A[k]<<",";

            }
            cout<<"]\n";
        }
    }
    cout<<"Total combinations:"<<count<<endl;
}
//O(n^3) time O(1) space
int subArraySum_Brute(vector<int> A){
    int n=A.size();
    int sum=0,largestSum=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum=0;
            for(int k=i;k<=j;k++){
                sum+=A[k];
            }
            largestSum =max(largestSum,sum);
        }
    }
    return largestSum;
}
//O(n^2)time O(n) space
int subArraySum_PrefixSum(vector<int> A){
    int n=A.size();
    vector<int> p(n,0);
    p[0]=A[0];
    int sum=0,largestSum=0;
    for(int i=1;i<n;i++){
        p[i] = p[i-1]+A[i];
    }
    for(int i=0;i<n;i++){
        int sum =0;
        for(int j=i;j<n;j++){
            sum = i>0 ? p[j] -p[i-1] : p[j];
            largestSum = max(sum,largestSum);
        }

    }
    return largestSum;
}
int main() {
    vector<int> arr{10,9,7,8,6,5,4,3,2,1,-5,4,5,-67,200};
    subArrayCombination(arr);
    cout<<"Largest subarray Sum by Brute: "<<subArraySum_Brute(arr)<<endl;
    cout<<"Largest subarray Sum by PrefixSum: "<<subArraySum_PrefixSum(arr)<<endl;

    return 0;
}
