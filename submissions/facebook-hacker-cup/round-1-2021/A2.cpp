#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9;

string s;
int k;

void solve() {
    vector<vector<int>> dis(26, vector<int>(26, INF));
    cin >> s;
    cin >> k;
    for (int i = 0; i < k; i++) {
        string ss;
        cin >> ss;
        int a = ss[0] - 'A', b = ss[1] - 'A';
        dis[a][b] = 1;
    }
    for (int i = 0; i < 26; i++) {
        dis[i][i] = 0;
    }
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < 26; i++) {
        int tmp = 0;
        bool cant = false;
        for (auto c : s) {
            int cc = c - 'A';
            if (dis[cc][i] >= INF) {
                cant = true;
                break;
            } else {
                tmp += dis[cc][i];
            }
        }
        if (cant) continue;
        else {
            ans = min(ans, tmp);
        }
    }
    if (ans == INF) ans = -1;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
  
    return 0;
}