#include <iostream>
#include <vector>
using namespace std;

class Real
{
public:
	string value;
	Real(string str) : value(str) {}
};

const Real operator*(const Real& r1, const Real& r2)
{
	string s1 = r1.value;
	string s2 = r2.value;
	int pos1 = 0;
	while(pos1 < s1.length() && s1[pos1] != '.')
	{
		pos1++;
	}
	int pos2 = 0;
	while(pos2 < s2.length() && s2[pos2] != '.')
	{
		pos2++;
	}
	int subLen = s1.length() - pos1 - 1 + s2.length() - pos2 - 1;
	string newS1 = s1.substr(0, pos1) + s1.substr(pos1 + 1, s1.length() - pos1 - 1);
	string newS2 = s2.substr(0, pos2) + s2.substr(pos2 + 1, s2.length() - pos2 - 1);
	vector<int> result(newS1.length() + newS2.length() - 1, 0);
	for(int i = newS1.length() - 1; i >= 0; i--)
	{
		for(int j = newS2.length() - 1; j >=0; j--)
		{
			int pos = i + j;
			result[pos] += (newS1[i] - '0') * (newS2[j] - '0');
		}
	}
	//deal with carry
	int carry = 0;
	for(int i = result.size() - 1; i >= 0; i--)
	{
		int sum = result[i] + carry;
		result[i] = sum % 10;
		carry = sum / 10;	
	}
	//get result
	string str;
	if(carry)
	{
		str += (carry + '0');
	}
	for(int i = 0; i < result.size(); i++)
	{
		str += (result[i] + '0');
	}
	//insert '.'
	string head, tail;
	if(subLen < str.length())
	{
		head = str.substr(0, str.length() - subLen);
		tail = str.substr(str.length() - subLen, subLen);
	}
	else
	{
		head = '0';
		int numZero = subLen - str.length();
		for(int i = 0; i < numZero; i++)
		{
			tail += '0';
		}
		tail += str;
	}
	string finalResult = head + '.' + tail;
	return Real(finalResult);
}

class Solution
{
public:
	Real exp(Real r, int n)
	{
		if(n == 0)
		{
			return Real("1.0");
		}
		if(n == 1)
		{
			return r;
		}
		Real value = exp(r, n / 2);
		if(n % 2)
		{
			return (value * value * r);
		}
		else
		{
			return (value * value);
		}
	}
};

int main()
{
	string str;
	int n;
	while(cin >> str >> n)
	{
		//str must contain '.'
		Real r(str);
		Solution s;
		Real rResult = s.exp(r, n);
		string result = rResult.value;
		int pos = 0;
		while(pos < result.length() && result[pos] != '.')
		{
			pos++;
		}
		//erase leading zeros
		if(result[0] == '0' && pos == 1)
		{
			result = result.substr(1, result.length() - 1);
		}
		//erase trailing zeros
		int numZeros = 0;
		for(int i = result.length() - 1; i >= 0; i--)
		{
			if(result[i] == '0')
			{
				numZeros++;
			}
			else
			{
				break;
			}
		}
		result = result.substr(0, result.length() - numZeros);
		//deal with int  2.0
		if(result[result.length() - 1] == '.')
		{
			result = result.substr(0, result.length() - 1);
		}
		//deal with 0.0
		if(result == "")
		{
			cout << 0 << endl;
		}
		else
		{
			cout << result << endl;
		}
	}
	return 0;
}
