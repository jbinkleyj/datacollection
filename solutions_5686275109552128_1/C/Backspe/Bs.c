#include <stdio.h>

int main() {
	int T, t;
	int D;
	int a, pm, s;
	int i, j, flag;
	int c[10001];
	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		scanf ("%d", &D);
		for(i = 1; i <= 1000; i++) c[i] = 0;
		pm = 0;
		for(i = 0; i < D; i++) {
			scanf ("%d", &s);
			c[s]++;
			if(s > pm) pm = s;
		}
		a = pm;
		for(i = 1; i <= pm; i++) {
			s = 0;
			for(j = i + 1; j <= pm; j++) {
				s += c[j] * ((j - 1) / i);
			}
			if (a > s + i) a = s + i;
		}
		printf("Case #%d: %d\n", t, a);
	}
	return 0;
}
