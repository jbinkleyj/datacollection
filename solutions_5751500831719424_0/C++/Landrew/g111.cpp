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
ifstream fin ("INP111.in");

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

  for (int tt=0; tt<TT; tt++)
  {
	 int n;
     fin >> n;

     vector <string> st;
     vector <int> pos;

	 for (int i=0; i<n; i++)
	 {
        string temp;
		fin >> temp;
		st.push_back(temp);
		pos.push_back(0);
	 }

	 int num = 0;
     bool done = false;
	 bool poss = true;
	 while (!done)
	 {
        char c = 'X';   
        bool someDiff = false;
        bool someDone = false;
		bool someND   = false;
		for (int i=0; i<n; i++)
		{
           if (pos[i] >= st[i].size())
			   someDone = true;
		   else
		   {
               someND = true;
               if (c == 'X')
				   c=st[i][pos[i]];
			   else if (st[i][pos[i]] != c)
			       someDiff = true;
		   }
		}
        
		if (someDone && !someND)
		{
           done = true;
		   continue;
		}

		if (someDiff || (someDone && someND))
		{
           done = true;
		   poss = false;
		   continue;
		}

		vector <int> len;
		int ma = -1; 
		int mi = 200;
		for (int i=0; i<n; i++)
		{
           int cur = 1;
		   int j = pos[i];
		   while (j < st[i].size() - 1 && st[i][j+1] == c)
		   {
			   j++;
			   cur++;
		   }
		   len.push_back(cur);
		   ma = max(ma, cur);
		   mi = min(mi, cur);
		}

		int bes = -1;
		for (int j=mi; j<=ma; j++)
		{
           int cur = 0;
		   for (int i=0; i<n; i++)
		   {
              cur += abs(len[i] - j);
		   }
		   if (bes == -1)
			   bes = cur;
		   else
			   bes = min(bes, cur);
		}

		num += bes;
        for (int i=0; i<n; i++)
		  pos[i] += len[i];

	 }

	 if (!poss)
         fout << "Case #" << tt+1 << ": " << "Fegla Won"  << endl;
	 else
	     fout << "Case #" << tt+1 << ": " << num  << endl;

	 //fout.precision(14);
	 //fout << "Case #" << tt+1 << ": " << dis << endl;
	
  }

   return 0;
}

