#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e3;

int n;
int ar[N * 2 + 5];

void solve() {
    cin >> n;
    vector<bool> udah(n + 5);
    map<int, bool> ada;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> ar[i];
        ada[ar[i]] = 1;
    }
    sort (ar + 1, ar + 1 + 2 * n);
    if (accumulate(ar + 1, ar + n + 1, 0LL) > ar[2 * n]) {
        cout << "NO\n";
        return;
    }
    vector<tuple<int, int, int>> lul;
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j < i; j++) {
            lul.emplace_back(ar[i] + ar[j], i, j);
        }
    }
    sort(lul.begin(), lul.end());
    int next = -1;
    int tot = 0;
    vector<pair<int, int>> ans;
    for (auto t : lul) {
        int cek, u, v;
        tie(cek, u, v) = t;
        if (next != -1) {
            if (max(ar[u], ar[v]) != next) 
                continue;
            if (udah[u] || udah[v])
                continue;
        }
        if (ada.find(cek) != ada.end()) {
            ans.emplace_back(ar[u], ar[v]);
            udah[u] = udah[v] = 1;
            next = cek;
            tot++;
            if (tot == n) {
                break;
            }
        }
    }
    if (tot < n) {
        cout << "NO\n";   
        return;
    }
    cout << "YES\n";
    cout << next << '\n';
    reverse(ans.begin(), ans.end());
    for (auto e : ans) {
        cout << e.first << ' ' << e.second << '\n';
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