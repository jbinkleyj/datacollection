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

  double aa[100002];

  for (int tt=0 ;tt<TT; tt++)
  {
    int a, b;
	fin >> a >> b;
	memset(aa, 0, sizeof(aa));

	for (int i=0; i<a; i++)
		fin >> aa[i];
 
	double best = 300000;

	best = a+b+1;

	double prob = 1;
	for (int i=1; i<=a; i++)
	{
       prob = prob*aa[i-1];
	   double numera = a-i;
	   double numnew = b-i;
	   double num = numera + numnew + 1;
	   double expa = prob*num + (1-prob)*(num+b+1);
	   best = min(best, expa);
	}

	double bb = b+2;
    best = min(best, bb);

	fout.precision(13);
	fout.setf(ios::fixed, ios::floatfield);
    fout << "Case #" << tt+1 << ": " << best << endl;
  }

   return 0;
}
