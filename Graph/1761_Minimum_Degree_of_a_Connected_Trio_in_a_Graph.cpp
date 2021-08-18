// 1761. Minimum Degree of a Connected Trio in a Graph

// You are given an undirected graph. You are given an integer n which is the number of nodes in the graph and an array edges, where each edges[i] = [ui, vi] indicates that there is an undirected edge between ui and vi.

// A connected trio is a set of three nodes where there is an edge between every pair of them.

// The degree of a connected trio is the number of edges where one endpoint is in the trio, and the other is not.

// Return the minimum degree of a connected trio in the graph, or -1 if the graph has no connected trios.

 

// Example 1:


// Input: n = 6, edges = [[1,2],[1,3],[3,2],[4,1],[5,2],[3,6]]
// Output: 3
// Explanation: There is exactly one trio, which is [1,2,3]. The edges that form its degree are bolded in the figure above.
// Example 2:


// Input: n = 7, edges = [[1,3],[4,1],[4,3],[2,5],[5,6],[6,7],[7,5],[2,6]]
// Output: 0
// Explanation: There are exactly three trios:
// 1) [1,4,3] with degree 0.
// 2) [2,5,6] with degree 2.
// 3) [5,6,7] with degree 2.
 

// Constraints:

// 2 <= n <= 400
// edges[i].length == 2
// 1 <= edges.length <= n * (n-1) / 2
// 1 <= ui, vi <= n
// ui != vi
// There are no repeated edges.

O(N^3) time complexity

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n+1,vector<int>(n+1,0));
    int maxi=INT_MAX;
    vector<int>deg(n+1);
    for(auto e:edges){
        g[e[0]][e[1]]=1;
         g[e[1]][e[0]]=1;
         deg[e[0]]++;
         deg[e[1]]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(g[i][j] ==1 && g[i][k] ==1 && g[j][k] ==1){
                    maxi = min(maxi,deg[i]+deg[j]+deg[k] -6);
                }
            }
        }
    }
    return maxi == INT_MAX ? -1: maxi;
    }
};
