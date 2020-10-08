#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;

set<int> se[26];
string s,t;

int main(){
    cin >> s >> t;
    for(int i = 0; i<(int)s.length(); i++){
        se[t[i]-'A'].insert(s[i]-'a');
    }
    long long ans = 1;
    for(int i = 0; i<(int)s.length(); i++){
        ans *= (se[t[i]-'A'].size() + 1);
        ans %= mod;
    }
    cout << ans << "\n";
}