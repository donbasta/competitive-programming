#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ld EPS = 1e-9;
const int MX = 30;
const vector<int> magic = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14};

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(MX + 5);
    for (int i = 2; i <= MX; i++) {
        ld lol = pow(ld(n), 1 / ld(i));
        cnt[i] = floor(lol) - 1;
    }
    int pp = 0;
    for (int i = MX; i >= 2; i--) {
        for (int j = i + i; j <= MX; j += i) {
            cnt[i] -= cnt[j];
        }
        pp += cnt[i];
    }
    int xr = 1;
    int ii = 1;
    for (int i = 2; i * i <= n; i++) {
        bool isPP = false;
        for (int j = 2; j <= MX / 2; j++) {
            ld haha = pow(ld(i), ld(1) / ld(j));
            ld hihi = floor(haha);
            if ((haha - hihi) < EPS) {
                isPP = true;
                break;
            }
        }
        if (isPP) {
            pp--;
            continue;
        }
        int ada = 1;
        for (int j = 2; j <= MX; j++) {
            ada += (cnt[j] >= ii);
        }
        ii++;
        xr ^= magic[ada];
    }
    int sisa = n - (floor(sqrt(n))) - pp;
    if (sisa & 1) {
        xr ^= 1;
    }
    cout << ((xr) ? "Vasya" : "Petya") << '\n';
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