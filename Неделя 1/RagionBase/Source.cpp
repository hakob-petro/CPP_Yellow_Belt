#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
using namespace std;


enum class Lang {
    DE, FR, IT
};


struct Region {
	string std_name;
	string parent_std_name;
	map<Lang, string> names;
	int64_t population;
};

bool operator<(const Region& lhs, const Region& rhs) {
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
        tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
    int result = 0;
    map<Region, int> repetion_count;
    for (const Region& region : regions) {
        result = max(result, ++repetion_count[region]);
    }
    return result;
}
/*
bool operator!=(const map<Lang, string> &mp1, const map<Lang, string> &mp2)
{
    if (mp1.size() != mp2.size()) return true;
    else
    {
		for(const auto& item : mp1)
		{
            try {
                if (item.second != mp2.at(item.first)) return true;
            }
			catch(out_of_range){}
		}
        return false;
    }
};

bool operator!=(const Region &reg1, const Region &reg2)
{
    if (reg1.std_name != reg2.std_name) return true;
    else if (reg1.parent_std_name != reg2.parent_std_name) return true;
    else if (reg1.names != reg2.names) return true;
    else if (reg1.population != reg2.population) return true;
    else return false;
}

bool operator==(const Region &reg1, const Region &reg2)
{
    return !(reg1 != reg2);
}

int FindMaxRepetitionCount(const vector<Region>& regions)
{
    if (regions.empty()) return 0;
    else
    {
        map<Region, int> counts;
        for (const Region &reg : regions)
        {
	        for (const Region &check : regions)
	        {
                if (reg == check) counts[reg]++;
	        }
        }
        int maxval = 0;
    	for (const auto &elem : counts)
    	{
            if (elem.second > maxval) maxval = elem.second;
    	}
        return maxval;
    }
}
*/
int main() {
    cout << FindMaxRepetitionCount({
        {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89
        },
        }) << endl;

    cout << FindMaxRepetitionCount({
        {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Toulouse",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            31
        },
        }) << endl;

    return 0;
}
