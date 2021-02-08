#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int isi[7][6];
int last[7];

bool check(int i, int j, int p) {
    bool bawah = false;
    bool ans = false;
    if (j >= 3) {
        ans |= ((isi[i][j - 1] == p) && (isi[i][j - 2] == p) && (isi[i][j - 3] == p));
    }
    int cekSamping = 0, cekDiagonal1 = 0, cekDiagonal2 = 0;
    int l = i - 1, r = i + 1;
    while (l >= 0 && (isi[l][j] == p)) {
        l--, cekSamping++;
    }
    while (r < 7 && (isi[r][j] == p)) {
        r++, cekSamping++;
    }
    int a = i + 1, b = j + 1;
    while (a < 7 && b < 6 && isi[a][b] == p) {
        a++, b++, cekDiagonal1++;
    }
    a = i - 1, b = j - 1;
    while (a >= 0 && b >= 0 && isi[a][b] == p) {
        a--, b--, cekDiagonal1++;
    }
    a = i + 1, b = j - 1;
    while (a < 7 && b >= 0 && isi[a][b] == p) {
        a++, b--, cekDiagonal2++;
    }
    a = i - 1, b = j + 1;
    while (a >= 0 && b < 6 && isi[a][b] == p) {
        a--, b++, cekDiagonal2++;
    }
    ans |= (cekSamping >= 3);
    ans |= (cekDiagonal2 >= 3);
    ans |= (cekDiagonal1 >= 3);
    return ans;
}

void solve() {
    memset(isi, -1, sizeof(isi));
    memset(last, -1, sizeof(last));
    string winner;
    int turn = -1;
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 2; j++) {
            int col;
            cin >> col;
            col--;
            last[col]++;
            if (check(col, last[col], j)) {
                winner = ((j & 1) ? "YELLOW" : "RED");
                turn = 2 * i + j + 1;
                break;
            }
            isi[col][last[col]] = j;
        }
        if (turn > 0) break;
    }
    cout << winner << ' ' << turn << '\n';
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