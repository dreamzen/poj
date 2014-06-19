#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<double> allSum;
	double sum = 0.0;
	for(int i = 2; ; i++)
	{
		sum += (1.0 / i);
		if(sum > 5.20) 
		{
			break;
		}
		else
		{
			allSum.push_back(sum);
		}
	}
	float value;
	while(cin >> value)
	{
		if(value == 0.00)
		{
			return 0;
		}
		else
		{
			int i = 0;
			while(i < allSum.size() && allSum[i] < value)
			{
				i++;
			}
			cout << i + 1 << " card(s)" << endl;
		}
	}
	return 0;
}
		
