#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
private:
	vector<bool> used;
public:
	static bool cmp(const int& stick1, const int& stick2)
	{
		return stick1 > stick2;
	}
	int smallestLength(vector<int>& sticks)
	{
		sort(sticks.begin(), sticks.end(), cmp);
		int maxLen = sticks[0];
		int totalLen = 0;
		for(int i = 0; i < sticks.size(); i++)
		{
			totalLen += sticks[i];
		}
		int resultLen;
		for(resultLen = maxLen; resultLen < totalLen; resultLen++)
		{
			used.resize(sticks.size(), false);
			if((totalLen % resultLen == 0) && (findSticks(sticks, totalLen / resultLen, 0, resultLen, 0, 0)))
			{
				return resultLen;
			}
		}
		return totalLen;
	}
	bool findSticks(vector<int>& sticks, int numSticks, int haveSticks, int resultLen, int currentLen, int seekingPos)
	{
		if(haveSticks == numSticks)
		{
			return true;
		}
		bool aNewStick = (currentLen == 0) ? true : false;
		for( ; seekingPos < sticks.size(); seekingPos++)
		{
			if(used[seekingPos])
			{
				continue;
			}
			if(sticks[seekingPos] + currentLen == resultLen)
			{
				used[seekingPos] = true;
				if(findSticks(sticks, numSticks, haveSticks + 1, resultLen, 0, 0))
				{
					return true;
				}
				used[seekingPos] = false;
				return false;
			}
			else if(sticks[seekingPos] + currentLen < resultLen)
			{
				used[seekingPos] = true;
				if(findSticks(sticks, numSticks, haveSticks, resultLen, currentLen + sticks[seekingPos], seekingPos + 1))
				{
					return true;
				}
				else//don't choose sticks[seekingPos]
				{
					used[seekingPos] = false;
					if(aNewStick)// sticks[seekingPos] must be contained by one stick, so if it can't be in this stick, it can't form any stick either.
					{
						return false;
					}
					//skip the same length with sticks[seekingPos]
					while(seekingPos + 1 < sticks.size() && sticks[seekingPos + 1] == sticks[seekingPos])
					{
						seekingPos++;
					}
				}
			}
		}
		return false;
	}
};

int main()
{
	int num;
	while(cin >> num)
	{
		if(num == 0)
		{
			return 0;
		}
		vector<int> sticks(num);
		for(int i = 0; i < num; i++)
		{
			cin >> sticks[i];
		}	
		Solution s;
		cout << s.smallestLength(sticks) << endl;
	}
	return 0;
}
	
