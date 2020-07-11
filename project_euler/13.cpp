#include<bits/stdc++.h>
using namespace std;

int dp[]

int countFactor(){
    int ans = 2;
    for(int j=2; j*j<=x; j++){
        if(x%j==0){
            if(j*j==x) ans++;
            else ans += 2;
        }
    }
    return ans;
}

int countFactorTriangular(int n){
    if(n%2==0){
        return countFactor(n/2) + countFactor(n+1);
    } else {
        return countFactor((n+1)/2) + countFactor(n);
    }
}

int main(){
    int n=1, k;
    cout << "Masukkan nilai: ";
    cin >> k;
    while(countFactorTriangular(n) <= k){
        n++;
    }
    cout << n;
}