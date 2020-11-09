#include "SV_Country.h"
#include "pch.h"

using namespace std;

SV_Country::SV_Country()
{
	name = "KOR";
	budget = 80000;
	gdp = 2000;
	taxRate = 0.10f;

	policyCost = 1000;
}

void SV_Country::CollectTaxes()
{
	//부동 소수점을 피하기 위해서 최적화 필요한 부분.
	budget = budget + static_cast <long long>  (static_cast<double> (taxRate) * gdp);
}

void SV_Country::EnforcePolicy()
{
	budget -= policyCost;
}

void SV_Country::PrintState()
{
	cout << "***Country Class***" << endl;
	cout << "name:  " << name << endl;
	cout << "budget:     " << budget << endl;
	cout << "GDP:        " << gdp << endl;
	cout << "taxRate:    " << taxRate << endl;
	cout << "policyCost: " << policyCost << endl;
}

long long SV_Country::GetBudget()
{
	return budget;
}