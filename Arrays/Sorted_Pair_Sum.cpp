/*Sorted pair sum*/

#include <iostream>
#include <vector>

using namespace std;

//O(logn) time complexity binary search
//O(2) space complexity
void max_change(int l,int r,int &max_diff,int diff,vector<int> &v){
    if(max_diff > diff){
        max_diff = diff;
        v[0]=l;
        v[1]=r;
    }
}

pair<int,int> pairs(vector<int> A,int x){
    vector<int> v(2,0);
    int n =A.size();
    int l=0;
    int r=n-1;
    int max_diff=INT_MAX;

    while(l<r){
        int value =A[l]+A[r];
        if(value == x) return {A[l],A[r]};

        else if(value < x){
            int diff = abs(value -x);
            max_change(A[l],A[r],max_diff,diff,v);
            l++;
        }

        else {
            int diff = abs(value -x);
            max_change(A[l],A[r],max_diff,diff,v);
            r--;
        }
    }
    return {v[0],v[1]};
}

int main() {
    vector<int> arr{10,22,28,29,30,40};
    int num=0;
    cout<<"Enter the number to find the pair"<<endl;
    cin>>num;
    pair<int,int> res= pairs(arr,num);
    cout<<"Pair of "<<num<<" are: "<<res.first<<" "<<res.second<<endl;

    return 0;
}
