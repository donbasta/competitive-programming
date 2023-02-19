#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void makeCombiUtil(vector<vector<int>>& ans,
                   vector<int>& tmp, int n, int left, int k) {
    if (k == 0) {
        ans.push_back(tmp);
        return;
    }

    for (int i = left; i <= n; ++i) {
        tmp.push_back(i);
        makeCombiUtil(ans, tmp, n, i + 1, k - 1);
        tmp.pop_back();
    }
}

vector<vector<int>> makeCombi(int n, int k) {
    vector<vector<int>> ans;
    vector<int> tmp;
    makeCombiUtil(ans, tmp, n, 1, k);
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    set<char> se;
    for (auto c : a) {
        se.insert(c);
    }
    unordered_map<char, int> lol;
    int idx = 0;
    for (auto c : se) {
        lol[c] = idx++;
    }

    ll mx = 0;
    int nn = se.size();
    vector<vector<int>> ans = makeCombi(nn, min(k, nn));
    for (int i = 0; i < ans.size(); i++) {
        vector<bool> ada(nn);
        for (int j = 0; j < ans[i].size(); j++) {
            ada[ans[i][j] - 1] = true;
        }
        int cur = 0;
        ll tmp = 0;
        for (int i = 0; i < n; i++) {
            if (ada[lol[a[i]]] || (a[i] == b[i])) {
                cur++;
            } else {
                tmp += 1LL * (cur + 1) * cur / 2;
                cur = 0;
            }
        }
        tmp += 1LL * (cur + 1) * cur / 2;
        mx = max(mx, tmp);
    }
    cout << mx << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}