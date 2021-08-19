// A farmer has built a long barn with N stalls. The stalls are placed in a straight manner at positions from x1, x2, ...xN. But his cows (C) are aggressive and don’t want to be near other cows. To prevent cows from hurting each other, he wants to place them in such a way so that the minimum distance between them is as large as possible. What is the largest minimum distance?

// Constraints:

//     N: 2<=N<=100,000
//     C: 2<=C<=N
//     Xi: 0<=Xi<=1,000,000,000
// Input:

//     Line1: Two integers N and C
//     Next N lines: An integer for Xi stall's position
// Example:

//     Input: 
//     5 3
//     1 2 4 8 9

//     Output:
//     3
      
//Time Complexity: O(NlogN), Space Complexity: O(N)
bool possible (vector<int> &A,int mid,int k){
    int cows=1;
    int lastCow =A[0]; //Greedy Approach
    for(int i=1;i<A.size();i++){
        if(A[i] -lastCow  >= mid){
            cows++;
            lastCow =A[i];
        }
        if(cows >=k) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &A,int k){
    int n=A.size();
    sort(A.begin(),A.end());
    int l=1,r=A[n-1]-A[0];
    int res=0;
    while(l<=r){
        int mid = (l+r)/2;
        if(possible(A,mid,k)){
            res = mid;
            l =mid+1;
        }
        else r=mid-1;
    }

    return res;
}
int main() {
    vector<int> A{1,2,4,8,9};
    cout<<aggressiveCows(A,3)<<endl;
return 0;
}
