#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, temp;
	long long int sum = 0;
	vector<int> temps, index;
	cin >> N;
	while (N > 0)
	{
		cin >> temp;
		sum += temp;
		temps.push_back(temp);
		N--;
	}
	const int size = static_cast<int>(temps.size());
	sum = sum / size;
	for (int j = 0; j < size; j++)
	{
		if (temps[j] > sum)
		{
			index.push_back(j);
		}
	}
	cout << index.size() << endl;
	for (int i : index)
	{
		cout << i << " ";
	}
	//system("pause");
	return 0;
}