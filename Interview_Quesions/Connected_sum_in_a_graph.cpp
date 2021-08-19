// A distributed caching service wants to build an algorithm to measure the efficiency of its network. The network is 
// represented as 	a number of nodes and a list of connected pairs. The efficiency of this network can be estimated 
// by first summing the cost of each isolated set of nodes where each individual node has a cost of 1. 
// To account for the increase in efficiency as mode nodes  are connected, update the cost of each isolated set to be the 
// ceiling of the square root of the original cost and return the final sum of all costs.


// Example
// n = 10 nodes
// Edges = [[1,2], [1,3], [2,4], [3,5], [7,8]]

// There are two isolated sets with more than one node, {1,2,3,4,5} and {7,8}. The ceilings of their square roots 
// are 5 ^ 1/2 = 2.236 and ceil(2.236) = 3, 2 ^ 1/2 = 1.414 and ceil (1.414) = 2. The other three isolated nodes 
// are separate and the square root of their weights is 1 ^ 1/2 = 1 respectively. The sum is 3 + 2 + (3 * 1) = 8.

// Input has two parameters:
// n - no of nodes
// edges - list of edges, each edge is represented a string "1 2"

// output:
// int: an integer that denotes the sum of the values calculated.
  

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include "GraphDataStructure/Graph.h"

using namespace std;

void dfs(vector<vector<int>> g,vector<bool> &v,int i,int &sum){
    if(i==0) return;
    sum=sum+1;
    v[i] =true;
//    cout<<"i---"<<i<<endl;
    for(auto p: g[i])
        if(!v[p]) dfs(g,v,p,sum);

}
int connectedSumsDFS(vector<vector<int>> edges,int n){
    vector<vector<int>> g(n+1,vector<int>(n+1,0));
    vector<bool> v(n+1,false);
    for(auto e: edges){
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }

    int res=0;
    for(int i=1;i<=n;i++){
        if(v[i]) continue;
        int sum=0;
        dfs(g,v,i,sum);
        res = res+ ceil(sqrt(sum));
        cout<<sum<<endl;
    }

    return res;

}
int connectedSumsBFS(vector<vector<int>> edges,int n){
    vector<vector<int>> g(n+1,vector<int>(n+1,0));
    vector<bool> v(n+1,false);
    for(auto e: edges){
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }
    queue<int> q;
    int res=0;
    for(int i=1;i<=n;i++){
        if(v[i]) continue;
        q.push(i);
        int cnt=1;

        while(!q.empty()){
            int top = q.front();
            q.pop();
            v[top]=true;
            for(int p:g[top]){
               if(!v[p]) {
                   v[p] =true;
                   q.push(p);
                   cnt++;
               }
            }
        }
        res = res+ ceil(sqrt(cnt));
        cout<<i<<"----"<<ceil(sqrt(cnt))<<endl;
    }

    return res;
}
int main() {
vector<vector<int>> edges {{1,2}, {1,3}, {2,4}, {3,5}, {7,8}};
cout<<connectedSumsBFS(edges,10)<<endl;
cout<<connectedSumsDFS(edges,10)<<endl;
return 0;
}
