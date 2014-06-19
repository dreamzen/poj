#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double sum = 0;
	for(int i = 0; i < 12; i++)
	{
		double penny;
		cin >> penny;
		sum += penny;
	}
	cout << "$" << setiosflags(ios::fixed) << setprecision(2) << (sum / 12.0) << endl;
	return 0;
}
