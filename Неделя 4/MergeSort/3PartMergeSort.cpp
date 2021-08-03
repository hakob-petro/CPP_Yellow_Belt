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
        vector<typename RandomIt::value_type> first_vector(range_begin, range_begin + number_of_elements/3),
											  second_vector(range_begin + number_of_elements/3, range_begin + 2*number_of_elements / 3),
											  third_vector(range_begin + 2*number_of_elements/3, range_end);
		
		MergeSort(begin(first_vector), end(first_vector));
        MergeSort(begin(second_vector), end(second_vector));
        MergeSort(begin(third_vector), end(third_vector));

        vector<typename RandomIt::value_type> temp_vector;
        merge(begin(first_vector), end(first_vector),
              begin(second_vector), end(second_vector),
                back_inserter(temp_vector));
        merge(begin(temp_vector), end(temp_vector), begin(third_vector), end(third_vector), range_begin);
	}	
}


int main() {
    vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1 , 1};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}