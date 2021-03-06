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
FILE *fi, *fo;
int local = 0;
int row, col, m, empty, cur;
char mines[505][505];
int used[505][505];
int n1[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int n2[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
bool DFS(int a, int b)
{
	char temp[3][3];
	int i, e = 0, oldc;
	bool r;
	for(i=0; i<9; i++)
		if (mines[a+n1[i]][b+n2[i]] == '#')
			e++;
	if (cur+e>empty) return false;
	//save old state
	for(i=0; i<9; i++)
		temp[1+n1[i]][1+n2[i]] = mines[a+n1[i]][b+n2[i]];
	oldc = cur;
	//update state
	used[a][b] = 1;
	cur = cur+e;
	mines[a][b]  = '.';
	for(i=0; i<9; i++)
		if (mines[a+n1[i]][b+n2[i]] == '#')
			mines[a+n1[i]][b+n2[i]] = '.';
	if (cur == empty) return true;
	for(i=0; i<9; i++) {
		if (used[a+n1[i]][b+n2[i]] == 0) {
			r = DFS(a+n1[i], b+n2[i]);
			if (r) return r;
		}
	}
	//restore state
	used[a][b] = 0;
	cur = oldc;
	mines[a][b] = '#';
	for(i=0; i<9; i++)
		mines[a+n1[i]][b+n2[i]] = temp[1+n1[i]][1+n2[i]];
	return false;
}
void Process(void)
{
	int i, j;
	bool r;
	if (m == 0) {
		if (local) printf("c");
		else  fprintf(fo, "c");
		for(i=1; i<col; i++) {
			if (local) printf(".");
			else  fprintf(fo, ".");
		}
		if (local) printf("\n");
		else  fprintf(fo, "\n");
		for(i=1; i<row; i++) {
			for(j=0; j<col; j++) {
				if (local) printf(".");
				else  fprintf(fo, ".");
			}
			if (local) printf("\n");
			else  fprintf(fo, "\n");
		}
		return ;
	}
	if (empty == 1) {
		if (local) printf("c");
		else  fprintf(fo, "c");
		for(i=1; i<col; i++) {
			if (local) printf("*");
			else  fprintf(fo, "*");
		}
		if (local) printf("\n");
		else  fprintf(fo, "\n");
		for(i=1; i<row; i++) {
			for(j=0; j<col; j++) {
				if (local) printf("*");
				else  fprintf(fo, "*");
			}
			if (local) printf("\n");
			else  fprintf(fo, "\n");
		}
		return ;
	}
	if (row == 1) {
		if (local) printf("c");
		else  fprintf(fo, "c");
		for(i=1; i<empty; i++) {
			if (local) printf(".");
			else  fprintf(fo, ".");
		}
		for(i=0; i<m; i++) {
			if (local) printf("*");
			else  fprintf(fo, "*");
		}
		if (local) printf("\n");
		else  fprintf(fo, "\n");
		return ;
	}
	if (col == 1) {
		if (local) printf("c\n");
		else  fprintf(fo, "c\n");
		for(i=1; i<empty; i++) {
			if (local) printf(".\n");
			else  fprintf(fo, ".\n");
		}
		for(i=0; i<m; i++) {
			if (local) printf("*\n");
			else  fprintf(fo, "*\n");
		}
		return ;
	}
	for(i=0; i<row+2; i++) {
		for(j=0; j<col+2; j++) {
			used[i][j] = 0;
			mines[i][j] = '#';
		}
	}
	for(i=0; i<row+2; i++) {
		mines[i][0] = mines[i][col+1] = '$';
		used[i][0] = used[i][col+1] = 1;
	}
	for(i=0; i<col+2; i++) {
		mines[0][i] = mines[row+1][i] = '$';
		used[0][i] = used[row+1][i] = 1;
	}
	cur = 0;
	r = DFS(1, 1);
	if (r) {
		for(i=1; i<=row; i++)
			for(j=1; j<=col; j++)
				if (mines[i][j] == '#')
					mines[i][j] = '*';
		mines[1][1] = 'c';
		for(i=1; i<=row; i++) {
			for(j=1; j<=col; j++) {
				if (local) printf("%c", mines[i][j]);
				else  fprintf(fo, "%c", mines[i][j]);
			}
			if (local) printf("\n");
			else  fprintf(fo, "\n");
		}
	}
	else {
		if (local) printf("Impossible\n");
		else  fprintf(fo, "Impossible\n");
	}
	return ;
}
int main()
{
	fi = fopen("C-small-attempt1.in", "r");
	fo = fopen("result.txt", "wb");
	int t, r, i;
	if (local) scanf("%d", &t);
	else  fscanf(fi, "%d", &t);
	for(r=1; r<=t; r++) {
		if (local) scanf("%d %d %d", &row, &col, &m);
		else  fscanf(fi, "%d %d %d", &row, &col, &m);
		empty = row*col-m;
		if (local) printf("Case #%d:\n", r);
		else  fprintf(fo, "Case #%d:\n", r);
		Process();
	}
	return 0;
}