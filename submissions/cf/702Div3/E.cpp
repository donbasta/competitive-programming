#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;

int n;
pair<int, int> a[N + 5];
ll pre[N + 5];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = make_pair(x, i);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i].first;
    }
    vector<int> ans = {a[n].second};
    for (int i = n - 1; i >= 1; i--) {
        if (pre[i] < a[i + 1].first) {
            break;
        }
        ans.push_back(a[i].second);
    }
    sort(ans.begin(), ans.end());
    cout << (int)ans.size() << '\n';
    for (auto& e : ans) {
        cout << e << ' ';
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