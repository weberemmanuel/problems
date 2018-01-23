//============================================================================
// Name        : Karatsuba.cpp
// Author      : Emmanuel Weber
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class BigNumber
{
public:

	BigNumber()
	{

	}

	BigNumber(const BigNumber& copy)
	{
		digits= copy.digits;
	}

	BigNumber(const std::string& str)
	{
		fillVec(str);
	}

	void fillVec(const string& str)
	{
		auto it = str.rbegin();
		while(it != str.rend())
			digits.push_back((int)*it++-48);
	}

	void print(std::ostream& stream) const
	{
		auto it = digits.rbegin();
		while(it != digits.rend())
			stream << std::to_string((*it++));
	}

	BigNumber operator+(const BigNumber& num2)
	{
		BigNumber result;
		int n1 = digits.size();
		int n2 = num2.digits.size();
		bool carry=false;
		result.digits.reserve(max(n1,n2)+1);
		for(int i=0;i<std::max(n1,n2);i++)
		{
			int sum = (int)carry;
			if(n1>i) sum+=digits[i];
			if(n2>i) sum+=num2.digits[i];

			carry = bool(sum>9);
			result.digits.push_back(sum % 10);
		}
		if(carry)
			result.digits.push_back(1);
		return result;
	}

	BigNumber operator*(const BigNumber& num2)
	{
		BigNumber result;
		return result;
	}

	size_t numDigits(void) const
	{
		return digits.size();
	}

	friend std::ostream& operator<< (std::ostream& stream, const BigNumber& num)
	{
		num.print(stream);
		return stream;
	}

private:
	vector<int> digits;
};




int main() {

	BigNumber num1("3141592653589793238462643383279502884197169399375105820974944592");
	BigNumber num2("2718281828459045235360287471352662497757247093699959574966967627");

	BigNumber num3("1");
	BigNumber num4("9999");

	cout << "Num1       : " << num1<< endl;
	cout << "Num2       : " << num2<< endl;
	cout << "Num1 + Num2: " << num1+num2<< endl;
	cout << "Num3 + Num4: " << num3+num4<< endl;
	return 0;
}
