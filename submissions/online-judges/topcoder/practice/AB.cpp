#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

class AB {
   public:
    string createString(int n, int k) {
        int mid = (n / 2);
        int mx = mid * (n - mid);
        if (k > mx) return "";
        int r = (k + mid - 1) / mid;
        string ret;
        for (int i = 0; i < n - r - mid; i++) ret += 'B';
        for (int i = 0; i < r; i++) ret += 'A';
        for (int i = 0; i < mid; i++) ret += 'B';
        int j = r * mid - k;
        swap(ret[n - mid - 1], ret[n - mid - 1 + j]);
        return ret;
    }
};

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    AB problem;
    cout << problem.createString(n, k) << '\n';
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