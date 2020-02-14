#include <bints/stdc++.h>

using namespace std;

long long euler(long long a){
	long long res = a;
	for(long long i = 2; i*i <= a; i++){
		if(a%i == 0){
			res -= res/i;
			while(a%i == 0){
				a /= i;
			}
		}
	}
	if(a > 1){
		res -= res/a;
	}
	return res;
}

long long prime_factor_count(long long a){

}

long long factor_count(){

}

long long mobius(){

}
