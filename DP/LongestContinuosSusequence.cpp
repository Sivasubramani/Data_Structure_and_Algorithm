
1.Longest Continuos Subsequence
Qn: S1: "AGGTAB" S2: "GXTXAYB"

Mat	S1(i)	A	G	G	T	A	B
S2 (j)	0	0	0	0	0	0	0
G	0	0	1	1	1	1	1
X	0	0	1	1	1	1	1
T	0	0	1	1	2	2	2
X	0	0	1	1	2	2	2
A	0	1	1	1	2	3	3
Y	0	1	1	1	2	3	3
B	0	1	1	1	2	3	4
Mat[s1.size+1][s2.size+1]
if (S1[i-1] ==S2[j-1])  Mat[i][j] =Mat[i-1][j-1]+1
else max(Mat[i][j-1],Mat[i-1][j-1],Mat[i-1][j])
Ans: 4 GTAB at Mat[s1.size][s2.size]





#include <iostream>
#include <vector>

using namespace std;

int longestSubsequences(string s1,string s2){
    vector<vector<int>> m(s1.size()+1,vector<int>(s2.size()+1,0));
    for(int i=1;i<s1.size()+1;i++){
        for(int j=1;j<s2.size()+1;j++){
            if(s1[i-1] == s2[j-1]){
                m[i][j] = m[i-1][j-1]+1;
            }
            else m[i][j] = max(m[i-1][j-1],max(m[i][j-1],m[i-1][j]));
        }
    }
    return m[s1.size()][s2.size()];
}

 int main() {
     string src = "AGGTAB";
     string dest = "GXTXAYB";
     cout<<"Longest Subsequence is: "<<longestSubsequences(src,dest)<<endl;
     cout<<"Longest Subsequence is: "<<longestSubsequences("src","dest")<<endl;
     cout<<"Longest Subsequence is: "<<longestSubsequences("ABABA","BABABA")<<endl;
     return 0;
}
