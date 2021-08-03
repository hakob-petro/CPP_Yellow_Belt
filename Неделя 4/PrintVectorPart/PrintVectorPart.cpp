#include <iostream>
#include <vector>	
#include <algorithm>
#include <typeinfo>

using namespace std;
using VecIt = vector<int>::const_iterator;

void PrintVectorPart(const vector<int>& numbers){
	VecIt iter = end(numbers);
	for (VecIt it = numbers.begin(); it < end(numbers); it++) {
		if(*it < 0){
			iter = it;
			break;
		}
	}

	while(iter != begin(numbers)){
		--iter;
		cout << *iter << " ";
	}	
}

int main() {
  PrintVectorPart({6, 1, 8, -5, 4});
  cout << endl;
  PrintVectorPart({-6, 1, 8, -5, 4});
  cout << endl;
  PrintVectorPart({6, 1, 8, 5, 4});
  cout << endl;
  return 0;
}
