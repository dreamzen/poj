#include <iostream>
using namespace std;

int main()
{
	int p, e, i, d;
	int num = 0;
	while(cin >> p >> e >> i >> d)
	{
		if(p == -1)
		{
			return 0;
		}
		num ++;
		int pBeforeYear = 0;
		int eBeforeYear = 0;
		int iBeforeYear = 0;
		while((pBeforeYear + p) % 23 != 0)
		{
			pBeforeYear++;
		}
		while((eBeforeYear + e) % 28 != 0)
		{
			eBeforeYear++;
		}
		while((iBeforeYear + i) % 33 != 0)
		{
			iBeforeYear++;
		}
		int days;
		for(days = d + 1; ; days++)
		{
			if(((pBeforeYear + days) % 23 == 0) && ((eBeforeYear + days) % 28 == 0) && ((iBeforeYear + days) % 33 == 0))
			{
				break;
			}
		}
		cout << "Case " << num << ": the next triple peak occurs in " << days - d << " days." << endl;
	}
	return 0;
}
