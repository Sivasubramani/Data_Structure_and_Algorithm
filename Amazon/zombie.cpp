// #Zombie in Matrix

// Given a 2D grid, each cell is either a zombie 1 or a human 0. Zombies can turn adjacent (up/down/left/right) human beings into zombies every hour. Find out how many hours does it take to infect all humans?

// Example:

// Input:
// [[0, 1, 1, 0, 1],
// [0, 1, 0, 1, 0],
// [0, 0, 0, 0, 1],
// [0, 1, 0, 0, 0]]

// Output: 2
// Explanation:

// At the end of the 1st hour, the status of the grid:
// [[1, 1, 1, 1, 1],
// [1, 1, 1, 1, 1],
// [0, 1, 0, 1, 1],
// [1, 1, 1, 0, 1]]

// At the end of the 2nd hour, the status of the grid:
// [[1, 1, 1, 1, 1],
// [1, 1, 1, 1, 1],
// [1, 1, 1, 1, 1],
// [1, 1, 1, 1, 1]]
// Related problems:

// https://leetcode.com/problems/rotting-oranges/
// https://leetcode.com/problems/walls-and-gates/ (premium)


#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int safePoint(int i,int j,int m,int n,int checker,vector<vector<int>> &A){
    if(i>=0 && j>=0 && i<m && j<n && A[i][j]==checker){
        return 1;
    }
    return 0;
}
int checkNeighbour(int i,int j,vector<vector<int>> &A,int m,int n,int checker){
    if(safePoint(i+1,j,m,n,checker,A) || safePoint(i-1,j,m,n,checker,A) ||
    safePoint(i,j+1,m,n,checker,A) || safePoint(i,j-1,m,n,checker,A)){
        A[i][j]=checker+1;
        return 1;
    }
    return 0;
}

int zombieInMatrix(vector<vector<int>> &A){
    int m=A.size();
    if(m==0) return 0;
    int n=A[0].size();
    int noChange=-1;
    int cycle=0;
    int elements=0;
    while(noChange !=0){
        noChange =0;
        int change=0;
        cycle++;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(A[i][j] == 0){
                    elements++;
                    int val =checkNeighbour(i,j,A,m,n,cycle);
                    if(val ==0) noChange++;
                    else change++;
                }
            }
        }
        if(cycle ==1 && elements==0) cycle--;
    }
    return cycle;
}

int zombieInMatrixBFS( vector<vector<int>> A){
    int m=A.size();
    if(m==0) return 0;
    int n=A[0].size();
    queue<pair<int,int>> q;
    int humans=0;
    int total =m*n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(A[i][j] ==1){
                q.push({i,j});
                humans++;
            }

        }
    }
    int count=0;
    vector<int> dir{0,1,0,-1,0};
    while(!q.empty()){
        if(humans == total) break;
        int size=q.size();
        count++;
        for(int i=0;i<size;i++){
            pair<int,int> p=q.front();
            int x =p.first;
            int y=p.second;
            q.pop();
            for(int i=0;i<4;i++){
                int dx =x+dir[i];
                int dy = y+dir[i+1];
                if(dx>=0 && dy>=0 && dx<m && dy<n && A[dx][dy]==0){
                    q.push({dx,dy});
                    A[dx][dy]=1;
                    humans++;
                }
            }
        }
    }
    return count;
}
int main() {

    vector<vector<int>> v {{0, 1, 1, 0, 1},
                           {0, 1, 0, 1, 0},
                           {0, 0, 0, 0, 1},
                           {0, 1, 0, 0, 0}};
    vector<vector<int>> v1 {{0,0,0,0,0},
                            {0,0,0,0,0},
                            {0,0,0,0,1}};
    vector<vector<int>> v2   {{1, 1, 1, 1, 1},
                              {1, 1, 1, 1, 1},
                              {1, 1, 1, 1, 1},
                              {0, 1, 1, 1, 1}};

    vector<vector<int>> v3   {{1, 1, 1, 1, 1},
                              {1, 1, 1, 1, 1},
                              {1, 1, 1, 1, 1},
                              {1, 1, 1, 1, 1}};
//    cout<<zombieInMatrix(v)<<endl;
//    cout<<zombieInMatrix(v1)<<endl;
//    cout<<zombieInMatrix(v2)<<endl;
//    cout<<zombieInMatrix(v3)<<endl;

    cout<<zombieInMatrixBFS(v)<<endl;
    cout<<zombieInMatrixBFS(v1)<<endl;
    cout<<zombieInMatrixBFS(v2)<<endl;
    cout<<zombieInMatrixBFS(v3)<<endl;
    return 0;
}


