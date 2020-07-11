#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;
vector<ll> ve, pre;


int main(){

    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();

    cin >> n;
    ve.resize(n+1);
    pre.resize(n+1,0);
    for(int i=0; i<n; i++){
        cin >> ve[i];
        pre[i] = pre[i-1] + v[i];
    }

    int hi = n-1, lo = 0, ans = -1;
    while(hi-lo >= 3){
        int diff = (hi-lo)/3;
        int l = lo + dif/3;
        int h = hi - dif/3;
        if()
    }



}