#include <iostream>
#include<memory.h>
#include <map>
#include <list>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
using namespace std;

/*
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	for (int i = 1; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			cnt = 0;
			for (int k = j; k < n; k+= i)
			{
				if (s[k] != '*') break;
				else cnt++;
			}
			if (cnt >= 5)
			{
				cout<<"yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"no"<<endl;
}


int a[100001] = {-1};
int n;
pair<int, int> dfs(int i)
{
	if (i*2 > 100000 || a[i*2] == -1) return make_pair(0,0);
	pair<int, int> r;
	pair<int, int> c1 = dfs(i*2);
	c1.second += a[i*2];
	pair<int, int> c2 = dfs(i*2+1);
	c2.second += a[i*2+ 1];
	r.first = c1.first + c2.first;
	r.first += abs(c1.second-c2.second);
	r.second = max(c1.second,c2.second);
	return r;
}
int main()
{
	cin>>n;
	int N = (1<<(n+1)) - 2;
	for (int i = 2; i <= N+1; i++)
	{
		cin>>a[i];
	}
	int r = dfs(1).first;
	cout<<r<<endl;
}


long long extended_euclid(long long a, long long b, long long &x, long long &y) {  
  long long xx = y = 0;
  long long yy = x = 1;
  while (b) {
    long long q = a/b;
    long long t = b; b = a%b; a = t;
    t = xx; xx = x-q*xx; x = t;
    t = yy; yy = y-q*yy; y = t;
  }
  return a;
}


int main()
{
	long long c,h1,h2,w1,w2;
	cin>>c>>h1>>h2>>w1>>w2;
	long long lo = 1;
	long long hi = 1000000000;
	long long x, y;
	long long md;
	long long d = extended_euclid(h1, h2, x, y);
	if (h1*w2 >= h2*w1)
	{
		long long k = y/(h2/d);
		if (y < 0)
		{
			if (y%(h2/d) != 0) k--;
		}
		long long x1 = x + (h1/d)*k;
		long long y1 = y - (h2/d)*k;
		x = x1;
		y = y1;
	}
	else
	{
		long long k = x/(h1/d);
		if (x < 0)
		{
			if (x%(h1/d) != 0) k--;
		}
		long long x1 = x + (h1/d)*k;
		long long y1 = y - (h2/d)*k;
		x = x1;
		y = y1;
	}
	while (lo <= hi)
	{
		md = (lo+hi)/2;
		
		long long x0 = x*md;
		long long y0 = y*md;
		if (w1*x0+y0*w2 <= c)
		{
			lo = md+1;
		}
		else
		{
			hi = md - 1;
		}
	}
	cout<<d<<" "<<lo<<endl;
	cout<<d*(lo-1)<<endl;
}


int t[4][20000000];
int get(int i, int in, int x1,int x2,int y1,int y2, int X1, int X2, int Y1, int Y2)
{

	if (x1 > x2 || y1 > y2)
	{
		if (i == 0 || i == 2) return 10000;
		else return -1;
	}
	if (X2 < x1 || X1 > x2 || Y1 > y2 || Y2 < y1)
	{
		if (i == 0 || i == 2) return 10000;
		else return -1;
	}
	if (x1 >= X1 && x2 <= X2 && y1 >= Y1 && y2 <= Y2)
	{
		return t[i][in];
	}
	int r1, r2, r3, r4;
	r1 = get(i, in*4, x1, (x1+x2)/2, y1, (y1+y2)/2, X1, X2, Y1,Y2);
	r2 = get(i, in*4+1, x1, (x1+x2)/2, (y1+y2)/2+1, y2, X1, X2, Y1,Y2);
	r3 = get(i, in*4+2, (x1+x2)/2 + 1, x2, y1, (y1+y2)/2, X1, X2, Y1,Y2);
	r4 = get(i, in*4+3, (x1+x2)/2+1, x2, (y1+y2)/2+1, y2, X1, X2, Y1,Y2);
	if (i == 0 || i == 2) return min(min(r1, r2), min(r3, r4));
	else return max(max(r1, r2), max(r3, r4));
}

int update(int i, int in, int x1,int x2,int y1,int y2, int X, int Y, int val)
{
	if (x1 > x2 || y1 > y2)
	{
		if (i == 0 || i == 2) return 10000;
		else return -1;
	}
	if (X < x1 || X > x2 || Y > y2 || Y < y1)
	{
		return t[i][in];
	}
	if (x1 >= X && x2 <= X && y1 >= Y && y2 <= Y)
	{
		return t[i][in] = val;
	}

	int r1, r2, r3, r4;
	r1 = update(i, in*4, x1, (x1+x2)/2, y1, (y1+y2)/2, X,Y, val);
	r2 = update(i, in*4+1, x1, (x1+x2)/2, (y1+y2)/2+1, y2, X,Y, val);
	r3 = update(i, in*4+2, (x1+x2)/2 + 1, x2, y1, (y1+y2)/2, X,Y, val);
	r4 = update(i, in*4+3, (x1+x2)/2+1, x2, (y1+y2)/2+1,y2, X,Y, val);
	if (i == 0 || i == 2) return t[i][in] = min(min(r1, r2), min(r3, r4));
	else return t[i][in] = max(max(r1, r2), max(r3, r4));
}



int n, m;

int main()
{
	scanf("%d %d",&n,&m);
	char mat[2005][2005];
	int t[4][2005][2005];
	for (int i = 0; i < n; i++)
	{
		scanf("%s",mat[i]);
		for (int j = 1; j <= m; j++) A[i+1][j] = mat[i][j-1];
	}
	for (int i = 0; i < n; i++)
	{
		int val = m-1;
		for (int j = m-1; j>= 0; j--)
		{
			if (j == m-1)
			{
				t[0][i][j] = val;
			}
			else
			{
				if (!(mat[i][j+1] == '.'))
					val = j;
				t[0][i][j] = val;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		int val = n-1;
		for (int j = n-1; j>= 0; j--)
		{
			if (j == n-1)
			{
				t[1][j][i] = val;
			}
			else
			{
				if (!(mat[j+1][i] == '.'))
					val = j;
				t[1][j][i] = val;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		int val = 0;
		for (int j = 0; j < m; j++)
		{
			if (j == 0)
			{
				t[2][i][j] = val;
			}
			else
			{
				if (!(mat[i][j-1] == '.'))
					val = j;
				t[2][i][j] = val;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		int val = 0;
		for (int j = 0; j< n; j++)
		{
			if (j == 0)
			{
				t[3][j][i] = val;
			}
			else
			{
				if (!(mat[j-1][i] == '.'))
					val = j;
				t[3][j][i] = val;
			}
		}
	}
	vector<vector<bool> > tk(n, vector<bool> (m, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tk[i][j]) continue;
			if (mat[i][j] == '*')continue;
			tk[i][j] = true;
			pair<int, int> r;
			pair<int, int> d;
			pair<int, int> u;
			pair<int, int> l;
			r.first = j;
			r.second = t[0][i][j];
			d.first = i;
			d.second = t[1][i][j];
			l.first = j;
			l.second = t[2][i][j];
			u.first = i;
			u.second = t[3][i][j];
			while (r.first < r.second || d.first < d.second || l.first > l.second || u.first > u.second)
			{
				pair<int, int> R;
				pair<int, int> D;
				pair<int, int> U;
				pair<int, int> L;
				R.first = R.second = r.second;
				D.first = D.second = d.second;
				U.first = U.second=u.second;
				L.first = L.second=l.second;
				
				for (int x = u.second; x <= d.second; x++)
				{
					for (int y = r.first+1; y <= r.second; y++)
					{
						mat[x][y] = '.';
						tk[x][y] = true;
						R.second = max(R.second, t[0][x][y]);
						D.second = max(D.second, t[1][x][y]);
						L.second = min(L.second, t[2][x][y]);
						U.second = min(U.second, t[3][x][y]);
					}
				}
				for (int x = u.second; x <= d.second; x++)
				{
					for (int y = l.second; y < l.first; y++)
					{
						mat[x][y] = '.';
						tk[x][y] = true;
						R.second = max(R.second, t[0][x][y]);
						D.second = max(D.second, t[1][x][y]);
						L.second = min(L.second, t[2][x][y]);
						U.second = min(U.second, t[3][x][y]);
					}
				}
				for (int x = u.second; x < u.first; x++)
				{
					for (int y = l.first; y <= r.first; y++)
					{
						mat[x][y] = '.';
						tk[x][y] = true;
						R.second = max(R.second, t[0][x][y]);
						D.second = max(D.second, t[1][x][y]);
						L.second = min(L.second, t[2][x][y]);
						U.second = min(U.second, t[3][x][y]);
					}
				}
				for (int x = d.first+1; x <= d.second; x++)
				{
					for (int y = l.first; y <= r.first; y++)
					{
						mat[x][y] = '.';
						tk[x][y] = true;
						R.second = max(R.second, t[0][x][y]);
						D.second = max(D.second, t[1][x][y]);
						L.second = min(L.second, t[2][x][y]);
						U.second = min(U.second, t[3][x][y]);
					}
				}
				r = R;
				d = D;
				l = L;
				u = U;
			}

		}
	}
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++) if (tk[i][j]) printf(".");else printf("*");
		printf("\n");
	}
}


int main()
{
	int n, k;
	long long S;
	cin>>n>>k>>S;
	int a[30];
	for (int i = 0; i < n; i++) cin>>a[i];
	long long fac[50];
	fac[0] = 1;
	for (int i = 1; i < 50; i++)
	{
		fac[i] = i*fac[i-1];
		if (fac[i] > 10000000000000000ll)
			fac[i] = 10000000000000001ll;
	}
	int bit = n/2;
	bit++;
	map<pair<long long,int>, long long> mp;
	int lim = pow(3ll, (long long)bit);
	for (int i = 0; i < lim; i++)
	{
		int rem = i;
		int cnt = 0;
		long long sm = 0;
		for (int j = 0; j < bit; j++)
		{
			if (rem%3 == 2)
			{
				cnt++;
				sm += fac[min(49,a[j])];
			}
			else if (rem%3 == 1)
				sm += a[j];
			rem /=3;
		}
		if (cnt > k || sm > S) continue;
		pair<long long, int> p = make_pair(sm ,cnt);
		mp[p]++;
	}
	long long r = 0;
	int bit2 = n-bit;
	lim = pow(3ll, (long long)bit2);
	for (int i = 0; i < lim; i++)
	{
		int rem = i;
		int cnt = 0;
		long long sm = 0;
		for (int j = 0; j < bit2; j++)
		{
			if (rem%3 == 2)
			{
				cnt++;
				sm += fac[min(49,a[j+bit])];
			}
			else if (rem%3 == 1)
				sm += a[j+bit];
			rem /=3;
		}
		if (sm > S) continue;
		for (int K = cnt; K <= k; K++)
		{
			pair<long long, int> p = make_pair(S - sm , k-K);
			if (mp.count(p))
				r += mp[p];
		}
	}
	cout<<r<<endl;
}


int main()
{
	ifstream cin;
	cin.open("in.in");
	ofstream cout;
	cout.open("out.out");
	int T;
	cin>>T;
	for (int z = 1; z <= T; z++)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		int r = 0;
		int cnt = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] > '0') r += max(0, i-(r+cnt));
			cnt += s[i]-'0';
		}
		cout<<"Case #"<<z<<": "<<r<<endl;
	}
}


int main()
{

	ifstream cin;
	cin.open("in.in");
	ofstream cout;
	cout.open("out.out");
	int T;
	cin>>T;
	for (int z = 1; z <= T; z++)
	{
		int n;
		cin>>n;
		vector<int> a(n);
		int sm = 0;
		for (int i = 0; i < n; i++) {
		cin>>a[i];
		sm += a[i];
		}
		int r = 1000;
		for (int i = 1; i <= 1000; i++)
		{
			int mn = 0;
			for (int j = 0; j < n; j++)
			{
				mn += max(0, (int)ceil((a[j]-i+0.0) / i));
			}
			r = min(r, i+mn);
		}
		cout<<"Case #"<<z<<": "<<r<<endl;
	}
}


int dp[10001][9][3];
int mat[9][9];
string s;
int sol(int i, int cur, int l)
{
	if (i == s.size() && l == 2 && cur == 3) return 1;
	if (i == s.size()) return 0;
	if (dp[i][cur][l] != -1) return dp[i][cur][l];
	int r = 0;
	int in = s[i]-'i';
	in++;
	r |= sol(i+1, mat[cur][in], l);
	if (l < 2 && cur == l+1)
		r |= sol(i+1, in, l+1);
	return dp[i][cur][l] = r;
}

int main()
{

	ifstream cin;
	cin.open("in.in");
	ofstream cout;
	cout.open("out.out");
	
	int T;
	for (int i = 0; i < 8; i++) mat[0][i] = mat[i][0] = i;
	mat[1][1] = 4;
	mat[1][2] = 3;
	mat[1][3] = 6;
	mat[2][1] = 7;
	mat[2][2] = 4;
	mat[2][3] = 1;
	mat[3][1] = 2;
	mat[3][2] = 5;
	mat[3][3] = 4;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 4; j < 8; j++)
		{
			if (mat[i][j-4] < 4) mat[i][j] = mat[i][j-4]+4;
			else mat[i][j] = mat[i][j-4]-4;
		}
	}
	
	
	for (int i = 4; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (mat[i-4][j] < 4) mat[i][j] = mat[i-4][j]+4;
			else mat[i][j] = mat[i-4][j]-4;
		}
	}
	
	cin>>T;
	for (int z = 1; z <= T; z++)
	{
		int L, X;
		cin>>L>>X;
		string S;
		cin>>S;
		s = "";
		for (int j = 0; j < X; j++) s += S;
		for (int i = 0; i < 10001; i++) for (int j = 0; j < 9; j++) dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;
		int r = sol(0,0,0);
		if (r) cout<<"Case #"<<z<<": YES"<<endl;
		else cout<<"Case #"<<z<<": NO"<<endl;
	}
	
}
*/

int mat[9][9];
string s;
set<pair<int, int> > vis;
long long L, X;
int sol(int i, int cur, int want)
{
	int cur2 = cur;
	for (long long j = i; j < L*X; j++)
	{
		if (vis.count(make_pair(j%L, cur2))>0) return -1;
		int in = 1+s[j%L]-'i';
		if (mat[cur][in] == want) return j;
		vis.insert(make_pair(j%L, cur));
		cur2 = mat[cur2][in];
	}
}

int pw(int cur, long long p)
{
	if (p == 1) return cur;
	if (p%2==0)
	{
		int r = pw(cur, p/2);
		return mat[r][r];
	}
	else
	{
		int r = pw(cur, p-1);
		return mat[r][cur];
	}
}
int main()
{

	ifstream cin;
	cin.open("in.in");
	ofstream cout;
	cout.open("out.out");
	
	int T;
	for (int i = 0; i < 8; i++) mat[0][i] = mat[i][0] = i;
	mat[1][1] = 4;
	mat[1][2] = 3;
	mat[1][3] = 6;
	mat[2][1] = 7;
	mat[2][2] = 4;
	mat[2][3] = 1;
	mat[3][1] = 2;
	mat[3][2] = 5;
	mat[3][3] = 4;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 4; j < 8; j++)
		{
			if (mat[i][j-4] < 4) mat[i][j] = mat[i][j-4]+4;
			else mat[i][j] = mat[i][j-4]-4;
		}
	}
	
	
	for (int i = 4; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (mat[i-4][j] < 4) mat[i][j] = mat[i-4][j]+4;
			else mat[i][j] = mat[i-4][j]-4;
		}
	}
	
	cin>>T;
	for (int z = 1; z <= T; z++)
	{
		cin>>L>>X;
		cin>>s;
		vis.clear();
		int cur = 0;
		for (int i = 0; i < s.size(); i++)
		{
			cur = mat[cur][s[i]-'i'+1];
		}
		int tot = pw(cur, X);
		if (tot != 4)
		{
			cout<<"Case #"<<z<<": NO"<<endl;
			continue;
		}
		int in = sol(0, 0, 1);
		if (in == -1)
		{
			cout<<"Case #"<<z<<": NO"<<endl;
			continue;
		}
		vis.clear();
		in = sol(in+1, 0, 2);
		if (in == -1)
		{
			cout<<"Case #"<<z<<": NO"<<endl;
			continue;
		}
		cout<<"Case #"<<z<<": YES"<<endl; 
	}
	
}