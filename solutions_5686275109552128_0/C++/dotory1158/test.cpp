#include <stdio.h>
const int MX = 1234567891;
int d[1050];
int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, i, j, tmp, min, N;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		min = MX;
		scanf("%d", &N);
		for(i = 1; i <= N; i++) scanf("%d", &d[i]);
		for(i = 1; i <= 1000; i++) {
			tmp = i;
			for(j = 1; j <= N; j++) tmp += (d[j]-1)/i;
			if(tmp < min) min = tmp;
		}
		printf("Case #%d: %d\n", t, min);
	}
	return 0;
}