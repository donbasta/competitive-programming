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
	long long res = 0;
	for(long long i = 2; i*i <= a; i++){
		if(a%i == 0){
			res += 1;
			while(a%i == 0){
				a /= i;
			}
		}
	}
	if(a > 1){
		res += 1;
	}
	return res;
}

long long factor_count1(long long a){
	long long res = 1;
	for(long long i = 2; i*i <= a; i++){
		if(a%i == 0){
			long long cur = 0;
			while(a%i == 0){
				a /= i;
				cur++;
			}
			res *= (cur+1);
		}
	}
	if(a > 1){
		res *= 2;
	}
	return res;
}

long long factor_count2(long long a){
	long long res = 0;
	for(long long i = 1; i*i <= a; i++){
		if(a%i == 0){
			res++;
			if(i != n/i) {res++;}
		}
	}
	return res;
}

long long mobius(){

}
