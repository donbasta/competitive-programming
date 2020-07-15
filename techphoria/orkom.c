#include<stdio.h>

// int mitsuha(int x){
// 	int sgn = (x>>31);
// 	int b = sgn^(sgn+x);
// 	int y = (b>>2);
// 	int z = b&3;
// 	y=y+y+y;
// 	z=z+z+z;
// 	z = z>>2;
// 	return ((y+z)^sgn) + (sgn&1);
// }

// // int sayaka(int x){
// // 	int y = x+x+x;
// // 	int sgn = (y>>31);
// // 	int b = sgn^(sgn+y);
// // 	b = b>>2;
// // 	return (b^sgn)+(sgn&1);
// // }

// // int sayaka(int x){
// // 	int y = x+x+x;

// // 	int sgn = (y>>31);
// // 	int b = sgn^(sgn+y);
// // 	b = b>>2;
// // 	return (b^sgn)+(sgn&1);
// // }

// // int sayaka(int x){
// // 	int y=x+x+x;
// // 	int sgn = y>>31;
// // 	return ( ( (y+((y&3)^3)) >> 2 ) ) ;
// // }

// int sayaka(int x){
// 	int y=x+x+x;
// 	int sgn=(y>>31);
// 	int p = (y^sgn)+(1&(y>>31));
// 	p = p>>2;
// 	return (p^sgn)+(1&(y>>31));
// }

// int fungsi(int x){
// 	return 3*x/4;
// }

// int main(){

// 	int x;
// 	scanf("%d",&x);
// 	// int sgn = (1<<31 & x);
// 	// printf("%d\n", sgn);

// 	// int y = (x^sgn)>>2;
// 	// printf("%d\n", y);

// 	// int z = (x^sgn) & 3;
// 	// printf("%d\n", z);

// 	// y = (y+y+y);
// 	// printf("%d\n", y);

// 	// z = (z+z+z);
// 	// printf("%d\n", z);

// 	// z = z>>2;
// 	// printf("%d\n", z);

// 	// printf("%d\n", ((y+z) | sgn));

// 	// int sgn = x>>31; printf("%d\n"  , sgn&1);
// 	// int b = sgn^(sgn+x); printf("%d\n", b);
// 	// int y = b>>2; printf("%d\n", y);
// 	// int z = b&3; printf("%d\n", z);
// 	// y = y+y+y; printf("%d\n", y);
// 	// z = z+z+z; printf("%d\n", z);
// 	// z = z>>2; printf("%d\n", z);
// 	// printf("%d\n", ((y+z)^sgn) + (sgn&1) ) ;
// 	// int maks = ~(1<<31);
// 	int mini = 1<<31;
// 	int mini1 = mini+1;
// 	// for(int a = mini; a<= mini+100; a++){
// 	// 	printf( "%d\n", sayaka(a)-fungsi(a) );
// 	// }
// 	// printf("%d\n", sayaka(mini));
// 	// printf("%d\n", fungsi(mini));

// 	// int y = mini+mini+mini; printf("%d\n", y);
// 	// int sgn = (x>>31);
// 	// int b = sgn^(sgn+y); printf("%d\n", b);
// 	// b = b>>2;
// 	// int a = (b^sgn)+(sgn&1);
// 	// printf("%d\n", a);
// 	// printf("%d\n", 3*mini/4);

// 	// printf("%d\n", mitsuha(mini));
// 	// for(int i=mini; i<=mini+100; i++){
// 	// 	printf("%d\n", mitsuha(i));
// 	// 	// printf("%d\n", (i>>31));
// 	// }

// 	// printf("%d", (-1)&1);

// 	// int sgn = (mini>>31); int sgn1 = (mini1>>31); printf("%d %d\n", sgn, sgn1);
// 	// int b = sgn^(sgn+mini);int b1 = sgn1^(sgn1+mini1); printf("%d %d\n", b, b1);
// 	// int y = (b>>2);int y1 = (b1>>2); printf("%d %d\n", y, y1);
// 	// int z = b&3;int z1 = b1&3; printf("%d %d\n", z, z1);
// 	// y=y+y+y;y1=y1+y1+y1; printf("%d %d\n", y, y1);
// 	// z=z+z+z;z1=z1+z1+z1; printf("%d %d\n", z, z1);
// 	// z = z>>2;z1 = z1>>2; printf("%d %d\n", z, z1);
// 	// printf("%d %d\n", ((y+z)^sgn) + (sgn&1), ((y1+z1)^sgn1) + (sgn1&1));

// 	printf("%d\n", sayaka(mini));
// 	printf("%d\n", fungsi(mini));
// 	printf("%d\n", fungsi(mini1));
// 	int y=mini+mini+mini; int y1=mini1+mini1+mini1;
// 	int sgn=(y>>31); int sgn1=(y1>>31); printf("%d %d\n", sgn, sgn1);
// 	int p = (y^sgn)+(1&(y>>31)); int p1 = (y1^sgn1)+(1&(y1>>31)); printf("%d %d\n", p, p1);
// 	p = p>>2; p1 = p1>>2; 
// 	printf("%d\n", (p^sgn)+(1&(y>>31))); printf("%d\n", (p1^sgn)+(1&(y1>>31)));
// 	int a = mini+mini;
// 	printf("%d\n", a);

	
int main(){

	int x;
	scanf("%d", &x);
	int sgn = (x>>31);
	int a = (x+(1&sgn)+(1&sgn)+(1&sgn))>>2;
	int b = x + (~(a<<2)) + 1;
	int b = b+b+b;
	int sg = (b>>31);
	int d = (b+(1&sg)+(1&sg)+(1&sg))>>2;
	printf("%d", a+a+a+d);
	return 0;
}