#include "StdAfx.h"
#include <functional>

#include <iostream>
#include <cstring>

#include <string>
#include <cstdio>
#include <vector>



using namespace std;

int main() {
	
	freopen("A-large.in", "r", stdin);
	freopen("A_large.out", "w", stdout);
	long long Tc;
	cin >> Tc;
	for (int t = 0; t < Tc; t++) {
		string str;
		cin >> str;
		string res = "";
		for (int i = 0; i < str.size(); i++) {
			if (i == 0) res += str[i];
			else {
				if (str[i] < res[0]) res += str[i];
				else res = str[i] + res;
			}
		}
		cout << "Case #" << (t + 1) << ": " << res << endl;
	}
	return 0;
}