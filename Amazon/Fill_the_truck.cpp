//Fill the truck

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

bool comparator(vector<int> &a, vector<int> &b) {
    return a[1]>b[1];
}
int fillTruck(vector<vector<int>> &A,int maxSize){
    sort(A.begin(),A.end(),comparator);
    int sum=0;
    for(auto a:A){
        cout<<a[0]<<" "<<a[1]<<endl;
        if(a[0] <= maxSize){
            maxSize -=a[0];
            sum+=a[0]*a[1];
        }
        else{
            sum+=maxSize*a[1];
            break;
        }
    }

    return sum;
}
int main() {
    vector<vector<int>> A{{3,1},{1,3},{2,2}};
    vector<vector<int>> B{{5,10},{2,5},{4,7},{3,9}};
    cout<<fillTruck(A,4)<<endl;
    cout<<fillTruck(B,10)<<endl;
    return 0;
}
