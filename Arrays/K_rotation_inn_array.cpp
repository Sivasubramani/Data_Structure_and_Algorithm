/*K rotation*/
#include <iostream>
#include <vector>

using namespace std;

//O(n) time complexity
//O(1) space complexity
int findGCD(int a,int b){
    if(b==0) return a;
    return findGCD(b,a%b);
}
vector<int> kRotations_Optimized(vector<int> &A, int d){
    int n=A.size();
    d=d%n;
    int gcd = findGCD(d,n);
    int k=0,j=0,temp=0;
    for(int i=0;i<gcd;i++){
        j=i;
        temp=A[i];
        while(1){
            k=j+d;
            if(k>=n) k -= n;
            if(k==i) break;
            A[j] =A[k];
            j=k;
        }
        A[j] =temp;
    }
    return A;
}

//O(n) time complexity
//O(n) space complexity
vector<int> kRotations(vector<int> A, int k){
    int n= A.size();
    vector<int> v(n,0);
    k=k%n;
    k=n-k;
    int i=0;
    for(int j=k;j<n;j++){
        v[i++] = A[j];
    }
    for(int j=0;j<k;j++){
        v[i++] =A[j];
    }
    return v;
}

int main() {
    vector<int> arr{10,22,28,29,30,40,43};
    int num=0;
    cout<<"Enter the number to find the k rotation"<<endl;
    cin>>num;
    vector<int> res= kRotations_Optimized(arr,num);
    cout<<"After rotation of "<<num<<" is: ";
    for(auto c: res){
        cout<<c<<endl;
    }

    return 0;
}
