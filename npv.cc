#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	float values[40], disc, npv=0, np=0, roi = 0, invest;
	int i, yrs, payb=0;
	cout << "\nEnter number of years of investment: ";
	cin >> yrs;
	cout << "\nEnter values for: \n";
	cout << "\nInitial Investment: ";
	cin >> invest;
	for (i=0;i<yrs;i++)
	{
		cout << "Profit at year " << i+1 << ": ";
		cin >> values[i];
		np += values[i];
		if (payb==0 && np > invest)
			payb = i+1;
	}
	cout << "\nEnter discount percent: ";
	cin >> disc;
	for (i=0;i<yrs;i++)
	{
		values[i]/=pow((1+disc/100), i+1);
	}
	cout << "\nAfter discounts: \n";
	cout << "\nInitial investment: " << values[0] << endl;
	for (i=0;i<yrs;i++)
	{
		npv += values[i];
		cout << "Year " << i+1 << ": " << values[i] << endl;
	}
	npv -= values[0];
	np -= values[0];
	roi = (np/yrs)/values[0]*100;
	cout << "\nNet profit is " << np << endl;
	cout << "\nNet present value after " << yrs << " years is " << npv << endl;
	cout << "\nReturn on investment is " << roi << endl;
	cout << "\nPayback period is " << payb << endl;
	return 0;
}