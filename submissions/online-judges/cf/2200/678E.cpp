#include<bits/stdc++.h>
using namespace std;

const int N = 20, EXPN = (1 << 18) + 3;
 
int n;
double p[N][N];
 
bool read() {
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)  assert(cin >> p[i][j]);
    return true;
}
 
double z[EXPN][N];
 
double solve(int mask, int i) {
    double& ans = z[mask][i];
    if (ans > -0.5) return ans;
    if (mask == (1 << n) - 1) return ans = !i;
    ans = 0;
    for(int j = 0; j < n; j++)
        if (!(mask & (1 << j))) {
            double cur = 0;
            cur += solve(mask | (1 << j), i) * p[i][j];
            cur += solve(mask | (1 << j), j) * p[j][i];
            ans = max(ans, cur);
        }
    return ans;
}
 
void solve() {
    cin >> n;
    read();
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
 
    for(int i = 0; i < (1 << n); i++) for(int j = 0; j < n; j++) z[i][j] = -1;
 
    double ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++) {
            int mask = (1 << i) | (1 << j);
            double cur = 0;
            cur += solve(mask, i) * p[i][j];
            cur += solve(mask, j) * p[j][i];
            ans = max(ans, cur);
        }
    cout << ans << endl;
}