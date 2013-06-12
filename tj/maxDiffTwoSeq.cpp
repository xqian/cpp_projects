// TestC1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

//void calculateMaxSumsBeforePosition(const vector<int> & a, int begin, int end, int step, function<bool(int,int)>comp, vector<int> & x)
template<class Compare>
void calculateMaxSumsBeforePosition(const vector<int> & a, int begin, int end, int step, Compare comp, vector<int> & x) {
	int bestSum = a[begin];
	int curSum = 0;
	for(int i=begin; i != end; i+=step) { //BUG: <
		if ( curSum == 0) {
			if ( comp(a[i], 0) ) {
				curSum = a[i];
			}
			if ( comp(a[i], bestSum)) {
				bestSum = a[i];
			}
		}
		else {
			curSum += a[i];
			if (comp(curSum, bestSum)) {
				bestSum = curSum;
			}
			if (!comp(curSum, 0)) {
				curSum = 0;
			}
		}
		x[i] = bestSum;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	vector<int> a(8);
	generate(a.begin(), a.end(), []() {
		return rand()%10 * ((rand() & 0x1)*2-1);
	});
	for( auto i : a) {
		cout << i << " ";
	}
	cout << endl;

	vector<int> x1(a.size(), 0);
	vector<int> x2(a.size(), 0);

	calculateMaxSumsBeforePosition(a, 0, a.size(), 1, greater<int>(), x1); //BUG size()-1
	for(auto i : x1) {
		cout << i << " ";
	}
	cout << endl;

	calculateMaxSumsBeforePosition(a, a.size()-1, -1, -1, less<int>(), x2);//BUG: size(), 0
	for(auto i : x2) {
		cout << i << " ";
	}
	cout << endl;

	int maxDiff = x1[0] - x2[1];
	for( int i=1; i < x1.size()-1; ++i) {
		maxDiff = max(maxDiff, x1[i] - x2[i+1]);
	}


	calculateMaxSumsBeforePosition(a, 0, a.size(), 1, less<int>(), x1); //BUG size()-1
	for(auto i : x1) {
		cout << i << " ";
	}
	cout << endl;

	calculateMaxSumsBeforePosition(a, a.size()-1, -1, -1, greater<int>(), x2);//BUG: size(), 0
	for(auto i : x2) {
		cout << i << " ";
	}
	cout << endl;

	for( int i=0; i < x1.size()-1; ++i) {
		maxDiff = max(maxDiff, x2[i+1] - x1[i]); //BUG: x1[i] - x2[i+1]
	}
	
	cout << maxDiff << endl;
	return 0;
}



