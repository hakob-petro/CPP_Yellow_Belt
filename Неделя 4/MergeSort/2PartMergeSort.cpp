#include <iostream>
#include <vector>
#include <iterator>
#include  <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
	if (next(range_begin) == range_end)
	{
        return;
	}else
	{
        //vector<typename RandomIt::value_type> elements(range_begin, range_end);
        int number_of_elements = distance(range_begin, range_end);
        vector<typename RandomIt::value_type> r_vector(range_begin, range_begin + number_of_elements/2),
											  l_vector(range_begin + number_of_elements/2, range_end);
        MergeSort(begin(r_vector), end(r_vector));
        MergeSort(begin(l_vector), end(l_vector));
        merge(begin(r_vector), end(r_vector), begin(l_vector), end(l_vector), range_begin);		
	}	
}


int main() {
    vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1 };
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}