#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>
#include <iomanip>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h> 
#include <limits.h>
#include <locale.h> 
#include <math.h> 
#include <setjmp.h>
#include <signal.h> 
#include <stdarg.h> 
#include <stddef.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <time.h>

void newLotteryGame(const char* filename)
{
	std::ifstream fin;
	fin.open(filename);
	std::ofstream fout;
	std::string str = filename;
	str = str.substr(0, str.size() - 3) + ".out";
	fout.open(str.c_str());
	int T;
	fin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int A, B, K;
		fin >> A >> B >> K;
		int cnt = 0;
		for (int i = 0; i < A; ++i)
			for (int j = 0; j < B; ++j)
			{
				if ((i & j) < K)
					++cnt;
			}
		
		fout << "Case #" << t << ": " << cnt << "\n";
	}

	fin.close();
	fout.close();
}

int main()
{
	newLotteryGame("B-small-attempt0.in");
	return 0;
}
