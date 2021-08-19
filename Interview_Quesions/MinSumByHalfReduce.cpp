// Given an array and k operations, in each operation replace a number with half of it. After k operations, return the sum of array that is minimum
// Ex: [1,2,4] k=3
// k=1 -> 1 2 2
// k=2 -> 1 2 1
// k=3 -> 1 1 1 -> Sum=3

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include "GraphDataStructure/Graph.h"

using namespace std;


int minSumByHalfReduce(vector<int> A,int k){
    int n= A.size();
    priority_queue<int> pq;
    for(auto a:A) pq.push(a);
    while(!pq.empty() && k>0){
        int top = pq.top();
        pq.pop();
        float x = top/2;
        pq.push((x));
        k--;
    }
    int sum=0;
    while(!pq.empty()) {
        sum+=pq.top();
        pq.pop();
    }
    return sum;
}

int main() {
vector<int> A {1,2,4};
cout<<minSumByHalfReduce(A,3)<<endl;

return 0;
}
