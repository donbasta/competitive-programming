#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int INF = 2e9;
 
void solve() {
    string s;
    cin >> s;
    int len = s.length();
    if (len & 1) {
        cout << "NO" << '\n';
        return;
    }

    int le = 0, ri = 0;
    vector<int> pos;
    int idx = 0;
    for (auto c : s) {
        le += (c == '(');
        ri += (c == ')');
    }
    for (auto c : s) {
        if (c == '?') pos.push_back(idx);
        idx++;
    }
    le = (len / 2) - le;
    ri = (len / 2) - ri;
    for (int i = 0; i < pos.size(); i++) {
        if (i < le) s[pos[i]] = '(';
        else s[pos[i]] = ')';
    }

    int s1 = 0;
    for (auto c : s) {
        if (c == '(') s1++;
        else if (c == ')') s1--;
        if (s1 < 0) {
            cout << "NO" << '\n';
            return;
        }
    }

    if (le == 0 || ri == 0) {
        cout << "YES" << '\n';
        return;
    }

    swap(s[pos[le - 1]], s[pos[le]]);

    int s2 = 0;
    for (auto c : s) {
        if (c == '(') s2++;
        else if (c == ')') s2--;
        if (s2 < 0) {
            cout << "YES" << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
    return;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}
