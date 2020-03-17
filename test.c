#include <stdio.h>

int f(int a);
int x;
int main(){
	int k[2][4] = {
		{1, 2, 3, 4},
		{2, 3, 4, 5}
		};
	float a = 1.525f;
	int b = 2;
	int c = 3;
	int i = 1, j = 10;
	
	struct test{
	int q, *w;} *test1,test2;
	int z = f(c);
	test1->q = f(b);
	test1->w = &z;
	test2.q = f(b);
        test2.w = &z;
	printf("q, w and q w\n%d %d %d %d", test1->q, *test1->w, test2.q, *test2.w);
	return 0;
}


int f(int a){
	int sum;
	if (a == 2){
		sum = a;}

	return sum;
}
