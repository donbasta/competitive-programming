#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

string s;
string anto = "ANTO";
map<char, int> mp;

string find_order(const vector<vector<ll>>& cnt) {
    string c_anto = anto;
    sort(c_anto.begin(), c_anto.end());
    string ans;
    ll mx = -1;
    do {
        ll tot = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                tot += cnt[mp[c_anto[j]]][mp[c_anto[i]]];
            }
        }
        if (tot > mx) {
            mx = tot;
            ans = c_anto;
        }
    } while (next_permutation(c_anto.begin(), c_anto.end()));
    return ans;
}

void solve() {
    for (int i = 0; i < 4; i++) { mp[anto[i]] = i; }
    vector<vector<ll>> cnt(4, vector<ll>(4));
    vector<ll> pre(4);

    cin >> s;
    int n = (int) s.length();
    for (int i = 0; i < n; i++) {
        char cur = s[i];
        for (int j = 0; j < 4; j++) {
            if (j == mp[cur]) continue;
            cnt[j][mp[cur]] += pre[j];
        }
        pre[mp[cur]]++;
    }
    string ss = find_order(cnt);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < pre[mp[ss[i]]]; j++) {
            cout << ss[i];
        }
    }   
    cout << '\n';
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