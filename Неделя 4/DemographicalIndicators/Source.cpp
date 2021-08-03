#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//enum class Gender {
//	FEMALE,
//	MALE
//};
//
//
//struct Person {
//	int age;
//	Gender gender;
//	bool is_employed;
//};
//
//void PrintStats(vector<Person> persons);
//
//template <typename InputIt>
//int ComputeMedianAge(InputIt range_begin, InputIt range_end);
//
//template <typename InputIt>
//int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
//    if (range_begin == range_end) {
//        return 0;
//    }
//    vector<typename InputIt::value_type> range_copy(range_begin, range_end);
//    auto middle = begin(range_copy) + range_copy.size() / 2;
//    nth_element(
//        begin(range_copy), middle, end(range_copy),
//        [](const Person& lhs, const Person& rhs) {
//            return lhs.age < rhs.age;
//        }
//    );
//    return middle->age;
//}

void PrintStats(vector<Person> persons)
{
    cout << "Median age = " << ComputeMedianAge(begin(persons), end(persons)) << endl;
	
    auto female_it = partition(begin(persons), end(persons),
        [](Person person) {return static_cast<int>(person.gender) == 0; });
    cout << "Median age for females = " << ComputeMedianAge(begin(persons), female_it) << endl;

    auto male_it = partition(begin(persons), end(persons),
        [](Person person) {return static_cast<int>(person.gender) == 1; });
    cout << "Median age for males = " << ComputeMedianAge(begin(persons), male_it) << endl;

    auto female_employed_it = partition(begin(persons), end(persons),
        [](Person person) {return static_cast<int>(person.gender) == 0 && person.is_employed; });
    cout << "Median age for employed females = " << ComputeMedianAge(begin(persons), female_employed_it) << endl;

    auto female_unemployed_it = partition(begin(persons), end(persons),
        [](Person person) {return static_cast<int>(person.gender) == 0 && !person.is_employed; });
    cout << "Median age for unemployed females = " << ComputeMedianAge(begin(persons), female_unemployed_it) << endl;

    auto male_employed_it = partition(begin(persons), end(persons),
        [](Person person) {return static_cast<int>(person.gender) == 1 && person.is_employed; });
    cout << "Median age for employed males = " << ComputeMedianAge(begin(persons), male_employed_it) << endl;

    auto male_unemployed_it = partition(begin(persons), end(persons),
        [](Person person) {return static_cast<int>(person.gender) == 1 && !person.is_employed; });
    cout << "Median age for unemployed males = " << ComputeMedianAge(begin(persons), male_unemployed_it) << endl;
}

int main() {
    vector<Person> persons = {
        {31, Gender::MALE, false},
        {40, Gender::FEMALE, true},
        {24, Gender::MALE, true},
        {20, Gender::FEMALE, true},
        {80, Gender::FEMALE, false},
        {78, Gender::MALE, false},
        {10, Gender::FEMALE, false},
        {55, Gender::MALE, true},
    };
    PrintStats(persons);
    return 0;
}