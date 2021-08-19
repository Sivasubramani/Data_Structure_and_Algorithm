// The keyboard have only 3 keys, K,L,A and performs 3 operations ctrl-A(select all), crtl-C(copy), ctrl-V(paste). Return the maximum number of KLA words that can be formed for a given N.
// Ex: N=6
// Words = 2 -> KLA ctrl-A ctrl-C ctrl-V
// N=8
// Words = 4-> KLA ctrl-A ctrl-C ctrl-V ctrl-V ctrl-V


#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;
int maxWord(int n)
{
    if(n <= 6) return n;

    vector<int> s(n+1);
    for(int i=0;i<=6;i++){
        s[i] =i;
    }
    for(int i=7;i<=n;i++){
        s[i] = max(2*s[i-3],
                   max(3*s[i-4],4*s[i-5]));
    }
    return (s[n]/3);

}
int main() {
vector<int> A {1,2,4};
for(int i=1;i<20;i++){
    cout<<i<<"----> "<<maxWord(i)<<endl;
}


return 0;
}
