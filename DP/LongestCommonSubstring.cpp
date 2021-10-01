// Input : X = “GeeksforGeeks”, y = “GeeksQuiz” 
// Output : 5 
// Explanation:
// The longest common substring is “Geeks” and is of length 5.

// Input : X = “abcdxyz”, y = “xyzabcd” 
// Output : 4 
// Explanation:
// The longest common substring is “abcd” and is of length 4.

// Input : X = “zxabcdezy”, y = “yzabcdezx” 
// Output : 6 
// Explanation:
// The longest common substring is “abcdez” and is of length 6.

#include <iostream>
#include <vector>

using namespace std;

int longestSubstring(string s1,string s2){
    int maxi =INT_MIN;
    vector<vector<int>> m(s1.size()+1,vector<int>(s2.size()+1,0));
    for(int i=1;i<s1.size()+1;i++){
        for(int j=1;j<s2.size()+1;j++){
            if(s1[i-1] == s2[j-1]){
                m[i][j] = m[i-1][j-1]+1;
                maxi = max(m[i][j],maxi);
            }
        }
    }
    return maxi;
}

 int main() {
     string src = "AGGTAB";
     string dest = "GXTXAYB";
     cout<<"Longest Substring is: "<<longestSubstring(src,dest)<<endl;
     cout<<"Longest Substring is: "<<longestSubstring("GeeksforGeeks","GeeksQuiz")<<endl;
     cout<<"Longest Substring is: "<<longestSubstring("ABAB","BABABA")<<endl;
     return 0;
}
