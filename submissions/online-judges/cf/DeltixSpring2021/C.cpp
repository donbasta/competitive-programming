#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void ans(const vector<int>& idx) {
    int sz = (int) idx.size();
    for (int i = 0; i < sz; i++) {
        cout << idx[i];
        if (i != sz - 1) cout << '.';
    }
}

void solve() {
    cin >> n;
    vector<int> ve(n);
    for (auto& e : ve) { cin >> e; }
    vector<int> idx;
    idx.push_back(1);
    cout << 1 << '\n';

    int sz = 1;
    for (int i = 1; i < n; i++) {
        if (ve[i] == 1) {
            idx.emplace_back(1), sz++;
        } else {
            while(idx.back() != ve[i] - 1) {
                idx.pop_back(), sz--;
            }
            idx[sz - 1]++;
        }
        ans(idx);
        cout << '\n';
    }
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