#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

#define NMAX 1010

int N, OK;
int viz[NMAX]; 
vector <int> V[NMAX];

void dfs (int nod) {

	viz[nod]++;	 
	if (viz[nod] > 1) return ; 
	for (vector <int>::iterator it = V[nod].begin (); it != V[nod].end (); it++) {
		//printf ("!!%d ", *it);
		dfs (*it);
	}
}

int main () {
	
	freopen ("A.in", "r", stdin);
	freopen ("A.out", "w", stdout);
    
	int T, len, x;                                 
	scanf ("%d", &T);
	for (int t = 1; t <= T; t++) {
		
		scanf ("%d", &N);
		for (int i = 1; i <= N; i++) {
			V[i].clear ();
			scanf ("%d", &len);
			for (int j = 1; j <= len; j++) {
				scanf ("%d", &x);
				V[i].push_back (x);
				//printf ("%d %d\n", i, x);
			}
		}

		printf ("Case #%d: ", t);
		for (int i = 1; i <= N; i++) {
			//printf ("--%d\n", i);
			OK = 0;
			memset (viz, 0, sizeof (viz));
			dfs (i);
			for (int j = 1; j <= N; j++) {
				if (viz[j] > 1) {
					printf ("Yes\n" );  
					OK = 1;
					break;
				} 
			}

			if (OK) break;
		}

		if (!OK) printf ("No\n");
	}

	return 0;
}
