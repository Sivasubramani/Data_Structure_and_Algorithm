// 1041. Robot Bounded In Circle

// On an infinite plane, a robot initially stands at (0, 0) and faces north. The robot can receive one of three instructions:

// "G": go straight 1 unit;
// "L": turn 90 degrees to the left;
// "R": turn 90 degrees to the right.
// The robot performs the instructions given in order, and repeats them forever.

// Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

 

// Example 1:

// Input: instructions = "GGLLGG"
// Output: true
// Explanation: The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
// When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.
// Example 2:

// Input: instructions = "GG"
// Output: false
// Explanation: The robot moves north indefinitely.
// Example 3:

// Input: instructions = "GL"
// Output: true
// Explanation: The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...
 

// Constraints:

// 1 <= instructions.length <= 100
// instructions[i] is 'G', 'L' or, 'R'.

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
bool findRobotDirection(string s){
    if(s.size() ==0) return true;
    char curDir ='N';
    int vertical=0;
    int horizontal =0;
    for(auto a :s){
        if(a=='G'){
            if(curDir == 'N') vertical++;
            else if(curDir == 'S') vertical--;
            else if(curDir == 'E') horizontal++;
            else if(curDir == 'E') horizontal--;
        }
        else{
            if(curDir == 'N')  curDir = (a== 'R') ? 'E' : 'W';
            else if(curDir == 'S') curDir = (a== 'R') ? 'W' : 'E';
            else if(curDir == 'E') curDir = (a== 'R') ? 'S' : 'N';
            else if(curDir == 'W') curDir = (a== 'R') ? 'N' : 'S';
        }
    }

    bool res = (vertical==0 && horizontal==0) || curDir !='N';
    return res;
}

int main() {
    string s="GL";
    bool res = findRobotDirection(s);
    if(res) cout<<"Yes";
    else cout<<"No";

    return 0;
}
