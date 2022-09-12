#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }

    int a = 2, b = (n / 2);
    int step = 2;

    //precompute power of 2
    vector<int> pw2(30);
    for (int i = 0; i < 30; i++) {
        pw2[i] = (1 << i);
    }

    //simulate
    while (b > 1) {
        int a1, b1; //new values of a, b, c
        if (step % 2 == 1) { //walking to the right
            a1 = a;
        } else { //walking to the left 
            if (b % 2 == 0) {
                a1 = a + pw2[step - 1];
            } else {
                a1 = a;
            }
        }
        b1 = (n / pw2[step]) + ((n % pw2[step]) >= a1);
        a = a1, b = b1;
        step++;
    }
    cout << a << '\n';
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