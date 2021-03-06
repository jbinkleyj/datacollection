/*#include "stdafx.h"
#include <time.h>
#include "ryx_bignum.h"*/
/**/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define INPUT fi
#define OUTPUT fo
FILE *fi, *fo;
#define NUM 105
#define LEN 105
char data[NUM][LEN];
int n, num1[NUM], num2[NUM];
int comp(const void *a1, const void *a2)
{
	char *p1, *p2;
	p1 = (char *)a1;
	p2 = (char *)a2;
	return strcmp(p1, p2);
}
int comp1(const void *a1, const void *a2)
{
	int *p1, *p2;
	p1 = (int *)a1;
	p2 = (int *)a2;
	return (*p1)-(*p2);
}
int mabs(int k)
{
	if (k>=0) return k;
	else return -1*k;
}
int Process(int k)
{
	int i, j, r, l;
	if (k>=strlen(data[0])) {
		for(i=0; i<n; i++)
			if (num1[i]<strlen(data[i]))
				return -1;
		return 0;
	}
	for(i=0; i<n; i++) num2[i] = 0;
	if (data[0][num1[0]] != data[n-1][num1[n-1]])
		return -1;
	for(i=0; i<n; i++) {
		l = strlen(data[i]);
		for(j=num1[i]; j<l; j++) {
			if (data[i][j] == data[i][num1[i]])
				num2[i]++;
			else 
				break;
		}
		num1[i] += num2[i];
	}
	r = 0;
	qsort(num2, n, sizeof(int), comp1);
	for(i=0; i<n; i++)
		r += mabs(num2[i]-num2[n/2]);
	l = Process(num1[0]);
	if (l == -1) return -1;
	else return l+r;
}
int main()
{
	fi = fopen("A-small-attempt1.in", "r");
	fo = fopen("result.txt", "wb");
	int i, t, r, j, re;
	fscanf(INPUT, "%d", &t);
	for(r=0; r<t; r++) {
		fscanf(INPUT, "%d", &n);
		for(j=0; j<n; j++)
			fscanf(INPUT, "%s", data[j]);
		qsort(data, n, sizeof(data[0]), comp);
		for(i=0; i<n; i++) num1[i] = num2[i] = 0;
		re = Process(0);
		fprintf(OUTPUT, "Case #%d: ", r+1);
		if (re == -1) fprintf(OUTPUT, "Fegla Won\n");
		else fprintf(OUTPUT, "%d\n", re);
	}
	return 0;
}	