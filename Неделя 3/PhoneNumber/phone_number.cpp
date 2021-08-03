#include "phone_number.h"
#include <sstream>
#include <stdexcept>
using namespace std;

PhoneNumber::PhoneNumber(const string &internatioanal_number)
{
	istringstream phone_number(internatioanal_number);
	char sign = phone_number.get();
	getline(phone_number, country_code_, '-');
	getline(phone_number, city_code_, '-');
	getline(phone_number, local_number_);

	if(sign != '+' || country_code_.empty() || city_code_.empty() || local_number_.empty())
	{
		throw invalid_argument("Wrong international number");
	}
}

string PhoneNumber::GetCountryCode() const
{
	return country_code_;
}

string PhoneNumber:: GetCityCode() const
{
	return city_code_;
}

string PhoneNumber:: GetLocalNumber() const
{
	return local_number_;
}

string PhoneNumber:: GetInternationalNumber() const
{
	return '+' + country_code_ + '-' + city_code_ + '-' + local_number_;
}
