#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const ll INF = 1e18;
 
void solve() {
    int m;
    cin >> m;
    vector<vector<ll>> ar(3, vector<ll>(m + 1));
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> ar[i][j];
        }
    }

    ll ans = INF;
    ll offset;
    ll j;

    //1st type
    offset = 0;
    j = 0;
    for (int i = 2; i <= m; i++) {
        offset = max(offset, ar[1][i] - j);
        j++;
    }
    for (int i = m; i >= 1; i--) {
        offset = max(offset, ar[2][i] - j);
        j++;
    }
    ans = min(ans, m * 2 - 1 + offset);
    
    vector<vector<ll>> off(3, vector<ll>(m + 1));
    vector<vector<ll>> sufA(3, vector<ll>(m + 1));
    vector<vector<ll>> sufB(3, vector<ll>(m + 1));

    off[1][1] = 0;
    off[2][1] = max(off[1][1], ar[2][1]);
    j = 1;
    for (int i = 2; i <= m; i++) {
        if (i & 1) {
            off[1][i] = max(off[1][i - 1], ar[1][i] - j);
            j++;
            off[2][i] = max(off[1][i], ar[2][i] - j);
            j++;
        } else {
            off[2][i] = max(off[2][i - 1], ar[2][i] - j);
            j++;
            off[1][i] = max(off[2][i], ar[1][i] - j);
            j++;
        }
    }

    sufA[1][m] = sufB[1][m] = off[1][m];
    sufA[2][m] = sufB[2][m] = off[2][m];
    for (int i = m - 1; i >= 1; i--) {
        sufA[1][i] = max(sufA[1][i + 1], off[1][i] - i);
        sufA[2][i] = max(sufA[2][i + 1], off[2][i] - i);
        sufB[1][i] = max(sufB[1][i + 1], off[1][i] + i);
        sufB[2][i] = max(sufB[2][i + 1], off[2][i] + i);
    }

    for (int i = 1; i <= m; i++) {
        ll tmp;
        if (i & 1) {
            offset = max(off[2][i], sufA[2][i + 1] - i, sufB[1][i + 1] )
            tmp = 
        } else {

        }
        ans = min(ans, tmp);
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
