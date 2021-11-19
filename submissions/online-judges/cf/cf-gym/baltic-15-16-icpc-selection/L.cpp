#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve () {
    int n;
    string s;
    cin >> n >> s;
    int happy = 0, sad = 0;
    for (int i = 0; i < n - 1; i++) {
        string emot = s.substr(i, 2);
        if (emot == ":)" || emot == "(:" ) {
            happy++;
        } else if (emot == ":(" || emot == "):" ) {
            sad++;
        }
    }
    if (happy > sad) {
        cout << "HAPPY";
    } else if (happy < sad) {
        cout << "SAD";
    } else {
        cout << "BORED";
    }
    cout << '\n';
    return;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve ();
    }

    return 0;
}