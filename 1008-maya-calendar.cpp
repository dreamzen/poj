#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	map<string, int> Haab;
	Haab["pop"] = 0;
	Haab["no"] = 20;
	Haab["zip"] = 40;
	Haab["zotz"] = 60;
	Haab["tzec"] = 80;
	Haab["xul"] = 100;
	Haab["yoxkin"] = 120;
	Haab["mol"] = 140;
	Haab["chen"] = 160;
	Haab["yax"] = 180;
	Haab["zac"] = 200;
	Haab["ceh"] = 220;
	Haab["mac"] = 240;
	Haab["kankin"] = 260;
	Haab["muan"] = 280;
	Haab["pax"] = 300;
	Haab["koyab"] = 320;
	Haab["cumhu"] = 340;
	Haab["uayet"] = 360;
	vector<string> Tzolkin(20);
	Tzolkin[0] = "ahau";//20th day
	Tzolkin[1] = "imix";
	Tzolkin[2] = "ik";
	Tzolkin[3] = "akbal";
	Tzolkin[4] = "kan";
	Tzolkin[5] = "chicchan";
	Tzolkin[6] = "cimi";
	Tzolkin[7] = "manik";
	Tzolkin[8] = "lamat";
	Tzolkin[9] = "muluk";
	Tzolkin[10] = "ok";
	Tzolkin[11] = "chuen";
	Tzolkin[12] = "eb";
	Tzolkin[13] = "ben";
	Tzolkin[14] = "ix";
	Tzolkin[15] = "mem";
	Tzolkin[16] = "cib";
	Tzolkin[17] = "caban";
	Tzolkin[18] = "eznab";
	Tzolkin[19] = "canac";
	int N;
	cin >> N;
	cout << N << endl;
	for(int i = 0; i < N; i++)
	{
		int Day;
		string Month;
		int Year;
		cin >> Day;
		cin.get();
		cin >> Month;
		cin >> Year;
		
		int days;
		days = 365*Year + Haab[Month] + Day + 1;

		int TzolkinYear = days / 260; // 13*20 = 260
		//the last day of Tzolkin Year
		if(days % 260 == 0)
		{
			TzolkinYear--;
		}
		string NameOfTheDay = Tzolkin[days % 20];
		int Number = days % 13;
		if(Number == 0)
		{
			Number = 13;
		}
		cout << Number << " " << NameOfTheDay << " " << TzolkinYear << endl;
	}
	return 0;
}
