#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#define M 1010
#define INF 100000000
using namespace std;
vector <int> numbers[M];

int lower_bound(int left, int right, int k) {
	int lo = 0, hi = numbers[k].size()-1;
	while (lo < hi) {
		int mid = lo + (hi-lo)/2;
		if (numbers[k][mid]>=left && numbers[k][mid]<=right) {
			hi = mid;
		} else if (numbers[k][mid] < left) {
			lo = mid+1;
		} else {
			hi = mid-1;
		}
	}
	if (numbers[k][lo]>=left && numbers[k][lo]<=right) return lo;
	return INF;
}

int upper_bound(int left, int right, int k) {
	int lo = 0, hi = numbers[k].size()-1;
	while (lo < hi) {
		int mid = lo + (hi-lo+1)/2;
		if (numbers[k][mid]>=left && numbers[k][mid]<=right) {
			lo = mid;
		} else if (numbers[k][mid] < left) {
			lo = mid+1;
		} else {
			hi = mid-1;
		}
	}
	if (numbers[k][lo]>=left && numbers[k][lo]<=right) return lo;
	return -1;
}


int main(int argc, char *argv[]) {
	int n, mn=M, mx=-1; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int k; scanf("%d", &k);
		mn = min(mn, k);
		mx = max(mx, k);
		numbers[k].push_back(i);
	}
	int q; scanf("%d\n", &q); while (q--) {
		char c, d; int lo, hi; scanf("%c%c %d%d%c", &c, &c, &lo, &hi, &d);
		lo--, hi--;
		if (c == 'n') { //min
			int ret_cnt = INF, ret_value;
			for (int i = mn; i <= mx; i++) {
				if (numbers[i].size()) {
					int llo = lower_bound(lo, hi, i);
					int hhi = upper_bound(lo, hi, i);
					if (llo == INF) llo = -1;
					if (hhi == -1) hhi = INF;
					int df = hhi-llo;
					if (df < ret_cnt) {
						ret_cnt = df;
						ret_value = i;
					}
				}
			}
			printf("%d\n", ret_value);
		} else if (c == 'x') { //max
		int ret_cnt = -1, ret_value;
		for (int i = mn; i <= mx; i++) {
			if (numbers[i].size()) {
				int llo = lower_bound(lo, hi, i);
				int hhi = upper_bound(lo, hi, i);
				if (ret_cnt < hhi-llo) {
					ret_cnt = hhi-llo;
					ret_value = i;
				}
			}
		}
		printf("%d\n", ret_value);
		} else { //count distinct
			int ret = 0;
			for (int i = mn; i <= mx; i++)
				if (numbers[i].size()) {
					int llo = lower_bound(lo, hi, i);
					if (llo != INF) ret++;
				}
			printf("%d\n", ret);
		}
	}
	return 0;
}
