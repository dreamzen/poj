#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		double x, y;
		cin >> x >> y;
		double r = sqrt(x * x + y * y);
		double inc = 50 * 2 / 3.14;
		double old = inc;
		//maxR = sqrt((oldArea + 50) * 2 / pi)// we can skip multiply and divide
		int j;
		for(j = 1; ; j++)
		{
			if(sqrt(old) > r)
			{
				break;
			}
			else
			{
				old += inc;// just one more add
			}
		}
		cout << "Property " << i << ": This property will begin eroding in year " << j << "." << endl;
	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}
