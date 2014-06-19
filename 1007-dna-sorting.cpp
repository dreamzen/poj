#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node
{
	string str;
	int num;
	Node(string s, int n) : str(s), num(n) {}
};

int dnaSorting(string &s)
{
	int len = s.length();
	if(len == 1)
	{
		return 0;
	}
	string s1 = s.substr(0, len / 2);
	string s2 = s.substr(len / 2, len - len / 2);
	//divide
	int numLeft = dnaSorting(s1);
	int numRight = dnaSorting(s2);
	//conquer
	int i = 0;
	int j = 0;
	int k = 0;
	int num = 0;
	while(i < s1.length() && j < s2.length())
	{
		if(s1[i] <= s2[j])
		{
			s[k++] = s1[i++];
		}
		else
		{
			num += (s1.length() - i);
			s[k++] = s2[j++];
		}
	}
	if(i < s1.length())
	{
		while(i < s1.length())
		{
			s[k++] = s1[i++];
		}
	}
	else
	{
		while(j < s2.length())
		{
			s[k++] = s2[j++];
		}
	}
	return num + numLeft + numRight;
}
		
bool cmp(const Node& n1, const Node& n2)
{
	return n1.num < n2.num;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<Node> vec;
	for(int i = 0; i < m; i++)
	{
		string str;
		cin >> str;
		string tmp = str;
		int num = dnaSorting(tmp);
		Node node(str, num); 
		vec.push_back(node);
	}
	sort(vec.begin(), vec.end(), cmp);
	for(int i = 0; i < m; i++)
	{
		cout << vec[i].str << endl;
	}
	return 0;
}
