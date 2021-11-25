#include <bits/stdc++.h>

using namespace std;

const int N = (int)504;
const int ALPHA = 2;

bitset<N> b[ALPHA][N];
char patt[N][N];
bitset<N> result[N];

bitset<N> getShifted(const bitset<N>& b, int len, int shift) {
    assert(0 <= shift && shift < len);
    return (b >> shift) | (b << (len - shift));
}

int main() {
    int n, m, r, c;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        static char str[N];
        scanf("%s", str);
        for (int j = 0; j < m; j++) {
            b[(int)(str[j] - 'a')][i][j] = true;
        }
    }
    
    cin >> r >> c;

    for (int i = 0; i < n; i++) {
        result[i] = ~result[i];
    }

    for (int i = 0; i < r; i++) {
        scanf("%s", patt[i]);
        for (int j = 0; j < c; j++) {
            if (patt[i][j] == '?') continue;
            int c = patt[i][j] - 'a';
            int shiftByX = (((-i) % n) + n) % n;
            int shiftByY = (((j) % m) + m) % m;
            for (int x = 0; x < n; x++) {
                int nx = (x + shiftByX);
                if (nx >= n) nx -= n;
                result[nx] &= getShifted(b[c][x], m, shiftByY);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (result[i][j]) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
}