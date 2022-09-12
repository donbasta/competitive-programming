#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<pair<string, string>> ve(n);
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        ve[i] = make_pair(s1, s2);
        mp[s1]++;
        if (s2 != s1) {
            mp[s2]++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (mp[ve[i].first] > 1 && mp[ve[i].second] > 1) {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}