// Find whether path exist 
// Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
// The description of cells is as follows:

// A value of cell 1 means Source.
// A value of cell 2 means Destination.
// A value of cell 3 means Blank cell.
// A value of cell 0 means Wall.
// Note: There are only a single source and a single destination.
 

// Example 1:

// Input: grid = {{3,0,3,0,0},{3,0,0,0,3}
// ,{3,3,3,3,3},{0,2,3,0,0},{3,0,0,1,3}}
// Output: 0
// Explanation: The grid is-
// 3 0 3 0 0 
// 3 0 0 0 3 
// 3 3 3 3 3 
// 0 2 3 0 0 
// 3 0 0 1 3 
// There is no path to reach at (3,1) i,e at 
// destination from (4,3) i,e source.
// Example 2:

// Input: grid = {{1,3},{3,2}}
// Output: 1
// Explanation: The grid is-
// 1 3
// 3 2
// There is a path from (0,0) i,e source to (1,1) 
// i,e destination.
 

// Your Task:
// You don't need to read or print anything. Your task is to complete the function is_Possible() which takes the grid as input parameter and returns boolean value true if there is a path otherwise returns false.
 

// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(n2)

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    
 bool isSafe(int i,int j,int n){
     if(i>=0 && i<n && j>=0 && j<n) return true;
     return false;
 }   
 bool isPath(int i,int j, vector<vector<bool>> &v,vector<vector<int>>& g){
        
        if(isSafe(i,j,g.size()) && !v[i][j] &&  g[i][j] !=0) {
                  
        v[i][j] =true;
        if(g[i][j] == 2) return true;
        
        int route = isPath(i+1,j,v,g) || isPath(i-1,j,v,g) || isPath(i,j-1,v,g) || isPath(i,j+1,v,g);
        if(route) return route;
        }return false;

 
    }
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n= grid.size();
        bool flag= false;
        vector<vector<bool>> v(n,vector<bool>(n,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && !v[i][j]){
                    if(isPath(i,j,v,grid)){
                        flag= true;
                        break;
                    }
                    // else flag =false;
                    
                }
            }
        }
        
        return flag;
    }
};
