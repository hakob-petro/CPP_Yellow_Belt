#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename It > 
void PrintRange(It range_begin, It range_end)
{ 
    for (auto it = range_begin; it != range_end; ++it) {
        cout << *it << " ";
    }
}


ostream& operator<<(ostream& stream, vector<int> elements){
    for(auto elem : elements)
    {
        stream << elem << " " ;
    }
    return stream;
}

void Permutations(int& N)
{
    vector<int> numbers;
    while(N > 0){
        numbers.push_back(N);
        N--;
    }
    do
    {
        cout << numbers << '\n';
    } while(prev_permutation(numbers.begin(), numbers.end()));
}

int main()
{
    int N;
    cin >> N;
    Permutations(N);
    system("pause");
    return 0;
}
