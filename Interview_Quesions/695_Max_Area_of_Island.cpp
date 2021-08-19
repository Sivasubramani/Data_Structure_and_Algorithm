// 695. Max Area of Island

// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0.

 

// Example 1:


// Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.
// Example 2:

// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// grid[i][j] is either 0 or 1.
  
  
  class Solution {
public:
    
vector<int> dir{0,-1,0,1,0};    
int bfs(int i,int j,vector<vector<int>>& g,int m,int n){
    int cnt=1;
    queue<pair<int,int>> q;
    q.push({i,j});
    g[i][j] =2;
    while(!q.empty()){
        pair<int,int> p =q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        for(int i=0;i<4;i++){
            int dx = x+dir[i];
            int dy = y+dir[i+1];
            if(dx>=0 && dx<m && dy<n && dy>=0 && g[dx][dy]==1){
                g[dx][dy]=2;
                q.push({dx,dy});
                cnt++;
            }
        }
    }
    
    return cnt;
}
int maxAreaOfIsland(vector<vector<int>>& g) {
        if(g.size() ==0) return 0;
        int ans=0;
        int m= g.size();
        int n=g[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j] ==1) {
                    ans = max(ans,bfs(i,j,g,m,n));
                }
            }
        }
        
        return ans;
        
    }
};
