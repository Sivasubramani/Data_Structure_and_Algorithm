// https://leetcode.com/discuss/interview-question/428240/Audible-Onlie-Assessment-for-New-Graduate-Number-of-characters-escaped

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int getEscape(int start,int end,string s){
    int cnt=0;
    while(start <=end){
        if(s[start] == '!' && islower(s[start+1]))
        {
            cnt++;
        }
        start++;
    }
    return cnt;
}
int escapeCount(string s){
    int begin =0,escapeSeq=0,numSeq=0;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='#') {
            numSeq++;
            if(numSeq ==1) begin=i;
        }

        if(numSeq ==2){
            cnt += getEscape(begin,i,s);

            begin=i;
            numSeq =0;
        }
    }

    return cnt;
}
int main() {
vector<int> A {1,2,4};
cout<<escapeCount("#uv!#!lcr#f!#d!!v!##nwy!t!#i!vpz!kaxc!oj#!#!!d!!k!e#!!qs!rivzj#sqjlf#pe#v!cd!!!nst#je!##qthb#t!!ty#v")<<endl;
cout<<escapeCount("#!r#")<<endl;
cout<<escapeCount("##!r#po#")<<endl;
return 0;
}
