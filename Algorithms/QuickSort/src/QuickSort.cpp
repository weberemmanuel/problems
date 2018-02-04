//============================================================================
// Name        : QuickSort.cpp
// Author      : Emmanuel Weber
// Version     :
// Copyright   : Your copyright notice
// Description : QuickSort basic implementation
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

using namespace std;

long comp = 0;
int mode = 2;

int QuickChoosePivot(std::vector<int>& v,int i,int j)
{
	if(mode == 0)
	{
		return i;
	}
	if(mode == 1)
	{
		return j-1;
	}

	// Median
	j--;
	int half = (i+j)/2;
	int median = max(min(v[i],v[j]), min(max(v[i],v[j]),v[half]));
	if(median == v[i]) return i;
	if(median == v[j]) return j;
	return half;
}

int QuickSortPivot(std::vector<int>& v,int l,int r)
{
	int i=l+1;
	int p = v[l];

	for(int j=l+1;j<r;j++)
	{
		if(v[j] < p)
		{
			std::swap(v[j],v[i]);
			i++;
		}
	}
	std::swap(v[l],v[i-1]);
	return i-1;
}

void QuickSort(std::vector<int>& v,int l,int r)
{
	if(l>=r) return;

	comp += r-l-1;

	int p = QuickChoosePivot(v,l,r);
	std::swap(v[p],v[l]);
	p = QuickSortPivot(v,l,r);
	QuickSort(v,l,p);
	QuickSort(v,p+1,r);
}

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		cout << "Usage: Inversions filename" << endl;
		exit(0);
	}

	for(mode=0;mode<3;mode++)
	{
		comp = 0;
		std::vector<int> inputData;


		std::ifstream infile(argv[1]);

		int a;
		while (infile >> a)
		{
			inputData.push_back(a);
		}

		QuickSort(inputData,0,inputData.size());

	//	for(auto a:inputData)
	//		cout << a << endl;

		cout << comp << endl;
	}
	return 0;
}
