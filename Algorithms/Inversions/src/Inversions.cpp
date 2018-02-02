//============================================================================
// Name        : Inversions.cpp
// Author      : Emmanuel Weber
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

using namespace std;

std::tuple<std::vector<int>,long>
MergeAndCountSplitInv(std::vector<int> C,std::vector<int> D)
{
	std::vector<int> B;
	size_t i = 0;
	size_t j = 0;
	long inversions = 0;
	size_t CMax= C.size();
	size_t DMax= D.size();

	for(size_t k=0;k<CMax+DMax&&i<CMax&&j<DMax;k++)
	{
		if(C[i]<=D[j])
		{
			B.push_back(C[i]);
			i++;
		}
		else
		{
			B.push_back(D[j]);
			j++;
			inversions += C.size()-i;
		}
	}

	while(i<C.size())
	{
		B.push_back(C[i++]);
	}
	while(j<D.size())
	{
		B.push_back(D[j++]);
	}
	return std::make_tuple(B,inversions);
}

std::tuple<std::vector<int>,long>
SortAndCountInv(std::vector<int> A)
{
	if(A.size()<=1)
		return std::make_tuple(A,0L);
	vector<int>::const_iterator first = A.begin();
	vector<int>::const_iterator mid   = first + A.size()/2;
	vector<int>::const_iterator last  = A.end();
	std::vector<int> C(first,mid);
	std::vector<int> D(mid,last);
	std::tuple<std::vector<int>,long> leftInv  = SortAndCountInv(C);
	std::tuple<std::vector<int>,long> rightInv = SortAndCountInv(D);
	std::tuple<std::vector<int>,long> splitInv = MergeAndCountSplitInv(std::get<0>(leftInv),std::get<0>(rightInv));

	long inversions = std::get<1>(splitInv)+std::get<1>(leftInv)+std::get<1>(rightInv);
	return std::make_tuple(std::get<0>(splitInv),inversions);
}

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		cout << "Usage: Inversions filename" << endl;
		exit(0);
	}

	std::vector<int> inputData;

	std::ifstream infile(argv[1]);

	int a;
	while (infile >> a)
	{
		inputData.push_back(a);
	}

	auto inversions = SortAndCountInv(inputData);
	for(auto a:std::get<0>(inversions))
		cout << a << endl;
	cout << "Inversions : " << std::get<1>(inversions) << endl;

	return 0;
}
