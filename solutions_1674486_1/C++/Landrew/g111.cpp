#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stdio.h>

#include <math.h>

using namespace std;

ofstream fout("OUT111.txt");
ifstream fin ("INP111.txt");

//FILE* pFile;
//int c;
//pFile = fopen("ou.txt","w");
//pFile=fopen ("beads.txt","r");

int main() {

//FILE* pFile;
//pFile = fopen("ou.txt","w");

// string na;
// if (tt == 0)
//  getline(fin,na);

// getline(fin,na);

// istringstream sin(na); 
// string v; 
// while (sin>>v) 
//   names.push_back(v); 

//fprintf(pFile, "Case #%d: ", t+1);
//fprintf(pFile,"%d\n",res);

  int TT;
  fin >> TT;

  int adj[1002][12];

  for (int tt=0; tt<TT; tt++)
  {
     memset(adj, 0, sizeof(adj));
     int n;
	 fin >> n;
	 for (int i=1; i<=n; i++)
	 {
        int m;
		fin >> m;
		adj[i][0]=m;
		for (int j=1; j<=m; j++)
		{ 
           fin >> adj[i][j];
		}
	 }

     int vis[1002];
	 bool found = false;
	 for (int i=1; i<=n && !found; i++)
	 {
        memset(vis, 0, sizeof(vis));
        stack <int> S;
		vis[i]=1;
		S.push(i);
		while (!S.empty() && !found)
		{
           int a = S.top();
		   S.pop();
		   for (int j=1; j<= adj[a][0]; j++)
		   {
             if (vis[adj[a][j]] == 1)
				 found = true;
			 else
			 {
                vis[adj[a][j]] = 1;
				S.push(adj[a][j]);
			 }
		   }
		}
	 }

     fout << "Case #" << tt+1 << ": ";
	 if (found)
		 fout << "Yes" << endl;
	 else
		 fout << "No" << endl;

     //double res=0;
	 //fout.precision(9);
	 //fout.setf(ios::fixed, ios::floatfield);
	 //fout << "Case #" << tt+1 << ": " << res << endl;
  }

   return 0;
}
