#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 210000
char s[N];
int numbers[N/2], how_many;

int main(int argc, char *argv[]) {
	scanf("%s", s);
	int sz = strlen(s), sum = 0;
	for (int i = 0; i < sz; i++) {
		if (s[i] == '=') {
			int j = i+1;
			int current = 0;
			while (j<sz) {
				if (s[j] == '+' || j==sz-1) {
					if (j == sz-1) current = current*10 + (s[j]-'0');
					numbers[how_many++] = current;
					sum += current;
					current = 0;
				} else {
					current = current*10 + (s[j]-'0');
				}
				j++;
			}
		}
	}
	if (how_many == 1) {
		printf("No solution\n");
	} else {
		bool found = 0;
		int current_sum = 0;
		for (int i = 0; i < how_many-1; i++) 
			if (numbers[i+1]-numbers[i] >= 2) {
				current_sum += ++numbers[i];
				int cnt = (sum-current_sum)/numbers[i];
				for (int j = 1; j < cnt; j++)
					numbers[i+j] = numbers[i];
				numbers[i+cnt] = numbers[i]+(sum-current_sum)%numbers[i];
				found = 1;
				how_many = i+cnt+1;
				break;
			} else {
				current_sum += numbers[i];
			}
		printf("%d=", sum);
		if (found) {
			for (int i = 0; i < how_many-1; i++)
				printf("%d+", numbers[i]);
			printf("%d\n", numbers[how_many-1]);
		} else {
			for (int i = 0; i < how_many-2; i++)
				printf("%d+", numbers[i]);
			printf("%d\n", numbers[how_many-2]+numbers[how_many-1]);
		}
	}
	return 0;
}
