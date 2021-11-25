#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

bool valid(double a, double b){
    if(abs(a+b-36.0)<0.0001||abs(a-b-36.0)<0.0001||abs(a*b-36.0)<0.0001||b&&abs(a/b-36.0)<0.0001)
        return true;
    return false;
}

bool valid(double a,double b,double c){
    if(valid(a + b, c) || valid(a - b, c) || valid(a * b, c) ||b && valid(a / b, c)) return true;
    if(valid(a, b + c) || valid(a, b - c) || valid(a, b * c) ||c && valid(a, b / c)) return true;
    return false;
}

bool valid(vector<int>& ve){
    double a = ve[0], b= ve[1], c = ve[2], d = ve[3];
    if(valid(a + b, c, d) || valid(a - b, c, d) || valid(a * b, c, d) || valid(a / b, c, d)) return true;
    if(valid(a, b + c, d) || valid(a, b - c, d) || valid(a, b * c, d) || valid(a, b / c, d)) return true;
    if(valid(a, b, c + d) || valid(a, b, c - d) || valid(a, b, c * d) || valid(a, b, c / d)) return true;
    return false;
}

void solve() {
    vector<int> ve(4);
    for (int i = 0; i < 4; i++) {
        cin >> ve[i];
    }
    sort(ve.begin(), ve.end());
    do {
        if (valid(ve)) {
            cout << "Bisa" << '\n';
            return;
        }
    } while (next_permutation(ve.begin(), ve.end()));
    cout << "Tidak Bisa" << '\n';
    return;
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