#include <iostream>
/*Longest_Band*/

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int longestBand(vector<int> A){
    int n= A.size();
    unordered_set<int> s;

    for(auto p:A){
        s.insert(p);
    }
    int sum=0;
    for(int i=0;i<A.size();i++){
        int search = A[i];
        if(s.find(search-1) == s.end()){
            int cnt=0;
            while(s.find(search) != s.end()){
                cnt++;
                search++;
            }
//            cout<<cnt<<endl;
            sum =max(cnt,sum);

        }
    }
    return sum;
}

int main() {
    vector<int> arr{1,9,3,0,18,5,2,4,10,7,12,6};
    cout<<longestBand(arr)<<endl;

    return 0;
}
