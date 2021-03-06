#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <list>
using namespace std;

#define LL long long
ifstream fin ("C-small.in");
ofstream fout ("C-small.out");
//ifstream fin ("C-large.in");
//ofstream fout ("C-large.out");

bool found;
int u[32], n;
long long s[32];

void back(int i, LL s1, LL s2) {
   if( found || i>n ) return;
   if( s1==s2 && s1>0 ) {
      found = 1;
      for(int i=0; i<n; i++)
         if(u[i]==1 ) fout << s[i] << " ";

      fout << "\n";
      for(int i=0; i<n; i++)
         if(u[i]==2 ) fout << s[i] << " ";
      fout << "\n";
      return;
   }

   u[i] = 1;
   back(i+1, s1+s[i], s2);
   u[i] = 2;
   back(i+1, s1, s2+s[i]);
   u[i] = 0;
   back(i+1, s1, s2);
}

void solve() {
   memset(s, 0, sizeof(s));
   fin >> n;
   for(int i=0; i<n; i++)
      fin >> s[i];
   
   found = 0;
   back(0, 0, 0);
   
   if( !found )
      fout << "Impossible\n";
}

int main() {
   int N, N2 = 1;
	fin >> N;
	while( N2<=N ) {
      fout << "Case #" << N2++ << ":\n";
      solve();
   }

	return 0;
}