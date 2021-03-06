// ProblemA.cpp: определяет точку входа для консольного приложения.
//

#include <stdio.h>
#include <tchar.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <algorithm>
#include <sstream>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

string processTestCase(fstream& inputFile)
{
	int N;
	inputFile >> N;
	vector<string> strings(N);
	for (int i = 0; i < N; ++i)
	{
		inputFile >> strings[i];
	}
	vector<deque<pair<char,int>>> groups(N);
	for (int i = 0; i < N; ++i)
	{
		string& s = strings[i];
		deque<pair<char,int>>& cg = groups[i];
		cg.push_back(MP(s[0], 1));
		for (int k = 1; k < s.size(); ++k)
		{
			pair<char,int>& last = cg.back();
			if (last.first != s[k])
			{
				cg.push_back(MP(s[k], 1));
			}
			else
			{
				last.second++;
			}
		}
	}

	deque<pair<char,int>>& et = groups[0];
	for (int i = 1; i < N; ++i)
	{
		deque<pair<char,int>>& c = groups[i];
		if (c.size() != et.size())
		{
			return string("Fegla Won");
		}
		for (int k = 0; k < et.size(); ++k)
		{
			if (et[k].first != c[k].first)
			{
				return string("Fegla Won");
			}
		}
	}

	int groupsSize = groups.size();
	int answer = 0;
	for (int i = 0; i < et.size(); ++i)
	{
		int minV = et[i].second;
		int maxV = et[i].second;
		for (int k = 0; k < groupsSize; k++)
		{
			minV = min(minV, groups[k][i].second);
			maxV = max(maxV, groups[k][i].second);
		}

		int bestResult = 999999999;
		for (int k = minV; k <= maxV; ++k)
		{
			int currentResult = 0;
			for (int j = 0; j < groupsSize; ++j)
			{
				currentResult += abs(k - groups[j][i].second);
			}
			bestResult = min(bestResult, currentResult);
		}
		answer += bestResult;
	}
	ostringstream oss;
	oss << answer;
	return oss.str();
}

int _tmain(int argc, _TCHAR* argv[])
{
   if (argc != 3)
   {
      std::cerr << "Usage: applicationName inputFileName outputFileName";
      return -1;
   }
   fstream inputFile(argv[1], fstream::in);
   fstream outputFile(argv[2], fstream::out);

   std::string line;
   getline(inputFile, line);
   int testCasesQty = atoi( line.c_str() );
   int testCasesProcessed = 0;
   while (true)
   {
      outputFile << "Case #" << ++testCasesProcessed << ": " << processTestCase(inputFile);
      if (testCasesProcessed == testCasesQty)
         break;
      else
         outputFile  << '\n';
   }
	return 0;
}

