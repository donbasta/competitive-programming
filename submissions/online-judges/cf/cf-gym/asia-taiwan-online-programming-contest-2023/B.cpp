#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

int conv(double s) {
    double ss = s * 100;
    return roundl(ss);
}

void el_psy_congroo() {
    int rt, rj;
    double st, sj;
    cin >> rt >> rj >> st >> sj;
    int sst = conv(st), ssj = conv(sj);

    if ((rt - 1) * ssj < (rj - 1) * sst) {
        cout << "TAOYUAN" << '\n';
    } else if ((rt - 1) * ssj > (rj - 1) * sst) {
        cout << "JAKARTA" << '\n';
    } else {
        cout << "SAME" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}