#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

const int MAXN = 3e5;
LL parsel[MAXN];
LL M,N;

LL cari_ekstremum(bool maks){

    LL lo = 1, hi = 1e13;
    LL ans = -1;
    LL mid;
    
    while(lo<=hi){
        mid = (lo+hi)>>1;
        LL tot = 0;
        for(int i=1; i<=N; i++){
            tot += (mid/parsel[i]);
        }
        if(tot>M){
            hi = mid-1;
        } else if(tot<M) {
            lo = mid+1;
        } else if(maks){
            ans = mid;
            lo = mid+1;
        } else {
            ans = mid;
            hi = mid-1;
        }
    }

    return ans;
}

int main(){

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> parsel[i];
    }

    LL a = cari_ekstremum(1);
    LL b = cari_ekstremum(0);

    if(a==-1 || b==-1) cout << 0 << '\n';
    else cout << a-b+1 << '\n';

}