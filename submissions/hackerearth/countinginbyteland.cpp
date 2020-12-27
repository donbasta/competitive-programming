#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int MAXN = 105;

int N,Q;
LL bit[MAXN][MAXN][MAXN];

void upd(int x, int y, int z, LL val){
    for(int i = x ; i <= N; i += i&-i){
        for(int j = y ; j <= N; j += j&-j){
            for(int k = z ; k <= N; k += k&-k){
                bit[i][j][k] += val;
            }
        }
    }
}

LL pre(int x, int y, int z){
    LL res = 0;
    for(int i=x ; i > 0; i -= i&-i){
        for(int j=y ; j > 0; j -= j&-j){
            for(int k=z ; k > 0; k -= k&-k){
                res += bit[i][j][k];
            }
        }
    }
    return res;
}

LL que(int x, int y, int z, int X, int Y, int Z){
    return (pre(X,Y,Z)-pre(X,Y,z-1)-pre(X,y-1,Z)-pre(x-1,Y,Z)+pre(X,y-1,z-1)+pre(x-1,Y,z-1)+pre(x-1,y-1,Z)-pre(x-1,y-1,z-1));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    N++;
    cin >> Q;
    LL cur = 0;
    int x, y, z, X, Y, Z, t;
    LL val;
    while(Q--){
        cin >> t;
        if(t==1){
            cin >> x >> y >> z >> val;
            upd(x+1,y+1,z+1,val);
            cur+=1ll*val;
        } else if (t==2){
            cin >> x >> y >> z >> X >> Y >> Z;
            cout << cur - que(x+1,y+1,z+1,X+1,Y+1,Z+1) << "\n";
        }
    }
}