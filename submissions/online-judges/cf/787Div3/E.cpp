#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> chars;
    vector<bool> fnd(26);
    for (int i = 0; i < n; i++) {
        int tmp = s[i] - 'a';
        if (!fnd[tmp]) {
            chars.push_back(tmp);
            fnd[tmp] = true;
        }
    }

    vector<int> ct(26);
    for (int i = 0; i < chars.length(); i++) {
        if (k == 0) break;
        int move = -1, mx = -1;
        for (int j = i; j < chars.length(); j++) {
            mx = max(mx, chars[j]);
            int 
            if (mx < k) {

            }
            int best = 
        }

        k -= move;
    }

    string ans;
    for (int i = 0; i < n; i++) {
        ans.push_back((char)(ct[s[i] - 'a'] + 'a'));
    }
    cout << ans << '\n';
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