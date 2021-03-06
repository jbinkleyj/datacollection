//#include "stdafx.h"
//#include <time.h>
//#include "ryx_bignum.h"
/*基础题。
http://acm.hdu.edu.cn/discuss/problem/post/reply.php?postid=3238&messageid=1&deep=0*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
int local = 0;
double a1[1005], a2[1005];
int n, used[1005];
int comp(const void *d1, const void *d2)
{
	double *p1, *p2;
	p1 = (double *)d1;
	p2 = (double *)d2;
	if (*p1<*p2)
		return -1;
	else if (*p1 == *p2)
		return 0;
	else 
		return 1;
}
int DWar(void)
{
	int r = 0, i, j;
	for(i=0; i<n; i++)
		used[i] = 0;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if (a1[j]>a2[i] && used[j] == 0) {
				used[j] = 1;
				r++;
				break;
			}
		}
		if (j == n) {
			for(j=0; j<n; j++) {
				if (used[j] == 0) {
					used[j] = 1;
					break;
				}
			}
		}
	}
	return r;
}
int War(void)
{
	int r = 0, i, j;
	for(i=0; i<n; i++)
		used[i] = 0;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++){
			if (a2[j]>a1[i] && used[j] == 0) {
				used[j] = 1;
				r++;
				break;
			}
		}
		if (j == n) {
			for(j=0; j<n; j++)
				if (used[j] == 0) {
					used[j] = 1;
					break;
				}
		}
	}
	return n-r;
}
int main()
{
	FILE *fi, *fo;
	fi = fopen("D-large.in", "r");
	fo = fopen("result.txt", "wb");
	int t, r, i;
	int y, z;
	if (local) scanf("%d", &t);
	else  fscanf(fi, "%d", &t);
	for(r=1; r<=t; r++) {
		if (local) scanf("%d", &n);
		else  fscanf(fi, "%d", &n);
		for(i=0; i<n; i++) {
			if (local) scanf("%lf", &a1[i]);
			else  fscanf(fi, "%lf", &a1[i]);
		}
		for(i=0; i<n; i++) {
			if (local) scanf("%lf", &a2[i]);
			else  fscanf(fi, "%lf", &a2[i]);
		}
		qsort(a1, n, sizeof(double), comp);
		qsort(a2, n, sizeof(double), comp);
		y = DWar();
		z = War();
		if (local) printf("Case #%d: %d %d\n", r, y, z);
		else  fprintf(fo, "Case #%d: %d %d\n", r, y, z);
	}
	return 0;
}