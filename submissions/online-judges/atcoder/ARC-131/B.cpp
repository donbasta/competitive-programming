#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] != '.') continue;
            vector<bool> ada(6);
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (s[nx][ny] == '.') continue;
                ada[s[nx][ny] - '0'] = true;
            }
            for (int k = 1; k <= 5; k++) {
                if (!ada[k]) {
                    s[i][j] = (char) (k + '0');
                    break;
                }
            }
        }
    }
    for (int i = 0; i < h; i++) {
        cout << s[i] << '\n';
    }
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