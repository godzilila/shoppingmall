// shoppingmall.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<iostream>
using namespace std;

typedef struct goods
{
	int sornum;
	int neednum;
	int single;
}GOO;
typedef struct ways
{
	int num;
	int strategy[101];
}Cre;
int main()
{
	GOO* good;
	int num;
	cin >> num;
	good = new GOO[num];
	for(int i=0;i<num;i++)
	{
		cin >> good[i].sornum >> good[i].neednum >> good[i].single;
	}
	Cre* ste;
	int strnum;
	cin >> strnum;
	ste = new Cre[strnum];
	for (int i = 0; i < strnum; i++)
	{
		cin >> ste[i].num;
		for (int j = 0; j < ste[i].num * 2 + 1; j++)
		{
			cin >> ste[i].strategy[j];
		}
	}
	return 0;
}

