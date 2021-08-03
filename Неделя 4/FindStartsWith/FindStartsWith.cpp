#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;

// The most competent solutions

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end, char prefix) {
	
    auto left = lower_bound(range_begin, range_end, string(1, prefix));
    const char next_prefix = static_cast<char>(prefix + 1);
    auto right = lower_bound(range_begin, range_end, string(1, next_prefix));

    return { left, right };
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end, const string prefix) {
	
    auto left = lower_bound(range_begin, range_end, prefix);
    string next_prefix = prefix;
    ++next_prefix[next_prefix.size() - 1];
    auto right = lower_bound(range_begin, range_end, next_prefix);

    return { left, right };
}

// Try another

//bool Comp(const string& elem1, const string& elem2)
//{
//    return elem2.find(elem1) != string::npos;
//}
//
//template <typename RandomIt>
//pair<RandomIt, RandomIt> FindStartsWith(
//    RandomIt range_begin, RandomIt range_end, const string& prefix) {
//    sort(range_begin, range_end, Comp);
//	return equal_range(range_begin, range_end, prefix, Comp);
//}

int main() {
    //const vector<string> sorted_strings = { "moscow", "murmansk", "vologda" };
    const vector<string> sorted_strings = { "moscow", "motovilikha", "murmansk" };

    const auto m_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto p_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    cout << (p_result.first - begin(sorted_strings)) << " " <<
        (p_result.second - begin(sorted_strings)) << endl;

    const auto z_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    cout << (z_result.first - begin(sorted_strings)) << " " <<
        (z_result.second - begin(sorted_strings)) << endl;

    const auto mo_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
    for (auto it = mo_result.first; it != mo_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto mt_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
    cout << (mt_result.first - begin(sorted_strings)) << " " <<
        (mt_result.second - begin(sorted_strings)) << endl;

    const auto na_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
    cout << (na_result.first - begin(sorted_strings)) << " " <<
        (na_result.second - begin(sorted_strings)) << endl;

    return 0;
}
