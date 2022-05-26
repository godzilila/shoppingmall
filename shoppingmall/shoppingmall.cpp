// shoppingmall.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<iostream>
using namespace std;
int cou = 0;
int min(int a,int b)
{
	if (a > b)
		return b;
	else
		return a;
}
int find(int curneeds[101], int single[101], int curspec[101][101], int num)
{
	int minprice=0;
	for (int i = 0; i < num; i++)
	{
		minprice += curneeds[i] * single[i];
	}
	for (int i = 0; i < cou; i++)
	{
		int specprice = curspec[i][100];
		int countnext = 0;
		int nextneeds[101];
		memset(nextneeds,0,sizeof(nextneeds));
		for (int j = 0; j < 100; j++)
		{
			if (curspec[i][j] > curneeds[j])
				break;
			nextneeds[j] = curneeds[j] - curspec[i][j];
		}
		for (int j = 0; j < 100; j++)
		{
			if (curneeds[j])
				countnext++;
		}
		if (countnext == num) {
			minprice = min(minprice, specprice + find(nextneeds, single, curspec, num));
		}
	}
	return minprice;
}
int main(){
	int sortgood[101], needs[101], single[101], specsort[101], spec[101][101], truespec[101][101];
	int num, innum, specnum;
	memset(needs, 0, sizeof(needs));
	for (int i = 0; i < 101; i++)
		memset(spec[i], 0, sizeof(spec[i]));
	for (int i = 0; i < 101; i++)
		memset(truespec[i], 0, sizeof(truespec[i]));
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin>>sortgood[i]>>needs[i]>>single[i];
	}
	cin >> specnum;
	int nn = 0;
	for (int i = 0; i < specnum; i++)
	{
		cin >> innum;
		int mm = 0;
		for (int j = 0; j < innum*2 ; j++)
		{
			if (j % 2 == 0)
				cin >> specsort[nn++];
			else
				cin >> spec[i][mm++];
		}
		cin >> spec[i][100];
	}
	for (int i = 0; i < specnum; i++)
	{
		int sum = 0;
		for (int j = 0; j < num; j++)
		{
			sum += spec[i][j] * single[j];
		}
		if (sum > spec[i][100]){
			for(int ii=0;ii<101;ii++)
				truespec[cou][ii] = spec[i][ii];
			cou++;
		}
			
	}
	cout << find(needs, single, truespec, num);
	return 0;
}
