#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define INF 1000000000
#define NN 10010
struct pair {
	int first;
	int second;
};

/*
* checks there exists m such that if m*m=n
*/
int is_perfect_square(int n) {
	int m = sqrt(n);
	return m*m==n?1:0;
}

/*
* a*x*x + b*x + c = 0
*/
struct pair quadratic_equation(int a, int b, int c) {
	struct pair ret; ret.first = ret.second = INF;
	int d = b*b-4*a*c;
	if (d < 0) return ret;
	d = sqrt(d);
	int f = -1*b+d; if (f%2 == 0) ret.first = f/2;
	    f = -1*b-d; if (f%2 == 0) ret.second = f/2;
	return ret;
}
	
int used[NN];
int main(int argc, char *argv[]) {
	int t; scanf("%d", &t); while (t--) {
		memset(used, 0, sizeof(used));
		int n, s; scanf("%d%d", &n, &s);
		int answer = 0;
		for (int N = 0; N <= n; N++) {
			int a = 1;
			int b = -1*(1+2*N);
			int c = N*(N-1)-2*s;
			struct pair ret = quadratic_equation(a, b, c);
			if (ret.first>=0 && n-N>=ret.first && !used[N+ret.first]) {
				printf("%d %d\n", N, ret.first);
				used[N+ret.first] = 1;
				answer++;
			}
			if (ret.second>=0 && n-N>=ret.first && !used[N+ret.second]) {
				printf("%d %d\n", N, ret.second);
				used[N+ret.second] = 1;
				answer++;
			}
		}
		printf("%d\n", answer);
	}
	return 0;
}
