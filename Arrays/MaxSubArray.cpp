//
// Created by Sivasubramani on 30/07/21.
//

#include "MaxSubArray.h"
vector<int>MaxSubArray::calcFunc(vector<int> A){
    int n=A.size();
    int currentSum=0;
    int maxSum=INT_MIN;
    int start =0;
    int end=0;
    int s=0;
    vector<int> v;

    for(int i=0;i<n;i++){
        currentSum+=A[i];
        if(currentSum > maxSum){
            maxSum =currentSum;
            start =s;
            end =i;
        }
        if(currentSum <0){
            currentSum =0;
            s=i+1;
        }
    }
    for(int i=start;i<=end;i++){
        v.push_back(A[i]);
    }

    return v;
}
void MaxSubArray::print_vector(vector<int> A){
    cout<<"Vector is ";
    cout<<"[";
    for(int i=0;i<A.size();i++){
        if(i==A.size()-1) cout<<A[i];
        else cout<<A[i]<<" ";
    }
    cout<<"]";
}