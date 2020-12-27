#include<stdio.h>

int itomori(int x, int y){
	return ~( ~(~y & x) & ~(~x & y));
}

int tokyo(void){
	return 1<<31;
}

int musubi(int x, int n, int m){
	int a = (x >> (n<<3) & (0xff));
	int b = (x >> (m<<3) & (0xff));
	return ( x^(a<<(n<<3))^(b<<(n<<3)) | (a<<(m<<3)) | (b<<(n<<3)) );
}

int kuchikamizake(int x){
	int a = x << 16;
	int b = x & a;
	a = b << 8;
	b = a & b;
	a = b << 4;
	b = a & b;
	a = b << 2;
	b = a & b;
	b = b & (1 << 31);
	return !(!b);
}

unsigned katawaredoki(unsigned uf){
	int f = (~(1<<8))<<23;
	int e = f&uf;
	if(!(e^f)) return uf;
	return uf & ~(1<<31);
}

int tessie(int x){
	return ( ((x&0xff)<<24) | ((x&(0xff<<8))<<8) | (((x&(0xff<<16))>>8)&(0xff<<8)) |  (((x&(0xff<<24))<<24)&(0xff))  );
}

// int sayaka(int x){
// 	return
// }

// int koi(int x){

// }

// int mitsuha(int x){

// }

// unsigned taki (unsigned uf){
// 	unsigned f = (~(1<<8) );
// }

int main(){
	int x;
	scanf("%d", &x);
	printf("%d\n", tessie(x));

}