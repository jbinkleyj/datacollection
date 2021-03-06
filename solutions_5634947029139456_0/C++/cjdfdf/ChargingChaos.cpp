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

int chargingChaosHelper(const std::vector<std::string>& devices, const std::vector<std::string>& outlets,
						int L, int k, std::vector<int>& result)
{
	if (k == L)
	{
		std::vector<std::string> tmp = outlets;
		for (int i = 0; i < result.size(); ++i)
			for (int j = 0; j < outlets.size(); ++j)
				tmp[j][result[i]] = (tmp[j][result[i]] == '1') ? '0' : '1';

		std::sort(tmp.begin(), tmp.end());
		if (devices == tmp)
			return static_cast<int>(result.size());
		else
			return INT_MAX;
	}
	else
	{
		result.push_back(k);
		int a = chargingChaosHelper(devices, outlets, L, k + 1, result);
		result.pop_back();
		int b = chargingChaosHelper(devices, outlets, L, k + 1, result);
		return std::min(a, b);
	}
}



void chargingChaos(const char* filename)
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
		int N, L;
		fin >> N >> L;
		std::vector<std::string> outlets;
		std::vector<std::string> devices;
		std::string str;
		for (int i = 0; i < N; ++i)
		{
			fin >> str;
			outlets.push_back(str);
		}

		for (int i = 0; i < N; ++i)
		{
			fin >> str;
			devices.push_back(str);
		}

		std::sort(devices.begin(), devices.end());

		std::vector<int> result;
		int ret = chargingChaosHelper(devices, outlets, L, 0, result);
		if (ret == INT_MAX)
			fout << "Case #" << t << ": NOT POSSIBLE\n";
		else
			fout << "Case #" << t << ": " << ret << "\n";
	}

	fin.close();
	fout.close();
}

int main()
{
	chargingChaos("A-small-attempt0.in");
	return 0;
}
