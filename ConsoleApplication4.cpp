
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

bool prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}


int main()
{
	vector<unsigned long long> mnList;
	
	unsigned long long number = 0;
	int mn1 = 0;
	int mn2 = 0;

	int ls = 0;

	//уменьшение диапазона до значений от 30109 до 33212 уменьшит время выполнения минимум в 320 раз,
	//т.к. множители максимального числа-палиндрома находятся именно в этом диапазоне, однако
	//определить это можно только пройдя полный интервал от 10 000 до 100 000
	for (int i = 10000; i < 100000; i++) {
		if (prime(i)) {
			mnList.push_back(i);
		}
	}


	for (int k = 0; k < mnList.size(); k++) {
		for (ls; ls < mnList.size(); ls++) {
			unsigned long long result = mnList[k] * mnList[ls];
			string str = to_string(result);   
			string str2 = str; 
			reverse(str.begin(), str.end()); //быстрее метода equal на 30%
			if (str == str2) { //на 5% быстрее сравнивать с переменной, чем со снова вызываемой функцией to_string(result)
				if (result > number) {
					number = result;
					mn1 = mnList[k];
					mn2 = mnList[ls];
				}
			}		
		}
		ls = k+1;
	}
	
	cout << mn1 << ' ' << mn2 << ' ' << number << endl;
	//1 множитель - 30109, 2 - 33211, максимальное число-палиндром - 999949999
	system("pause");
    return 0;
}

