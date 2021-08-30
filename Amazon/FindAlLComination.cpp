#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

void findAllCombinationOfSum(int target,int current ,int start, vector<vector<int>> &res,vector<int> &out){

    if(target == current) {
        res.push_back(out);
        cout<<res.size();
    }
    for(int i=start;i<target;i++){
        int x =current+i;
        if(x<=target){
            out.push_back(i);
            findAllCombinationOfSum(target,x,i,res,out);
            out.pop_back();
        }
        else break;
    }
}
int main() {
    vector<vector<int>> res1;
    vector<int> out;
    findAllCombinationOfSum(5,0,1,res1,out);
    for(int i=0;i<res1.size();i++){
        cout<<"\n";
        for(auto a:res1[i]){
            cout<<a<<" ";
        }
    }
    return 0;
}
