#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
	map<string, int> findTelNumber(vector<string> book)
	{
		map<string, int> result;
		for(int i = 0; i < book.size(); i++)
		{
			string telNumber = changeIntoTelNumber(book[i]);
			result[telNumber]++;
		}
		return result;
	}

	string changeIntoTelNumber(string str)
	{
		string result;
		for(int i = 0; i < str.length(); i++)
		{
			if(str[i] == '-')
			{
				continue;
			}
			result += changeIntoNum(str[i]);
		}
		return result;
	}
	char changeIntoNum(char c)
	{
		if(c >= '0' && c <= '9')
		{
			return c;
		}
		else if((c >= 'a' && c <= 'c') || (c >= 'A' && c <= 'C'))
		{
			return '2';
		}
		else if((c >= 'd' && c <= 'f') || (c >= 'D' && c <= 'F'))
		{
			return '3';
		}
		else if((c >= 'g' && c <= 'i') || (c >= 'G' && c <= 'I'))
		{
			return '4';
		}
		else if((c >= 'j' && c <= 'l') || (c >= 'J' && c <= 'L'))
		{
			return '5';
		}
		else if((c >= 'm' && c <= 'o') || (c >= 'M' && c <= 'O'))
		{
			return '6';
		}
		else if((c >= 'p' && c <= 's') || (c >= 'P' && c <= 'S'))
		{
			return '7';
		}
		else if((c >= 't' && c <= 'v') || (c >= 'T' && c <= 'V'))
		{
			return '8';
		}
		else if((c >= 'w' && c <= 'y') || (c >= 'W' && c <= 'Y'))
		{
			return '9';
		}
		else
		{
			return ' ';
			//no way here
		}
	}
};			

int main()
{
	int n;
	cin >> n;
	vector<string> book(n);
	for(int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		book[i] = str;
	}
	Solution s;
	map<string, int> result = s.findTelNumber(book);
	vector<string> vNumber;
	map<string, int>::iterator ite;
	for(ite = result.begin(); ite != result.end(); ite++)
	{
		vNumber.push_back(ite->first);
	}
	sort(vNumber.begin(), vNumber.end());
	bool hasDuplicates = false;
	for(int i = 0; i < vNumber.size(); i++)
	{
		string number = vNumber[i];
		string finalNumber = number.substr(0, 3);
		finalNumber += '-';
		finalNumber += number.substr(3, 4);
		int duplicates = result[number];
		if(duplicates > 1)
		{
			hasDuplicates = true;
			cout << finalNumber << " "  << duplicates << endl;
		}
	}
	if(!hasDuplicates)
	{
		cout << "No duplicates." << endl;
	}
	return 0;
}
