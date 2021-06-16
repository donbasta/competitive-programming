#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<int> ve;
    vector<bool> isi(n + 1, false);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            ve.emplace_back(i);
            isi[x] = true;
        }
    }
    int sz = (int) ve.size();
    cerr << sz << '\n';
    int ans = 2e9;
    for (int start = 0; start < sz; start++) {
        vector<bool> cisi = isi;
        int tmp = 0;
        int idx = start;
        int last = ve[idx];
        int cur = (ve[idx] % n) + 1;
        int cnt = 0;
        while (cnt < sz) {
            last = ve[idx];
            cur = 
            while (cisi[cur]) cur = ((cur + n - 2) % n) + 1;
            cisi[cur] = true;
            int dist = cur - last;
            if (dist < 0) dist += n;
            tmp += dist;
            idx = (idx + 1) % sz;
            cnt++;
        }
        cerr << "test\n";
        ans = min(ans, tmp);
    }
    cerr << "hehe";
    cout << ans << '\n';
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