#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
using namespace std;

// Предварительное объявление шаблонных функций
template<typename T> T Sqr(T number);
template<typename T> vector<T> Sqr(vector<T> vec);
template<typename First, typename Second> pair<First, Second> Sqr(pair<First, Second> pr);
template<typename Key, typename Value> map<Key, Value> Sqr(map<Key, Value> mp);

// Объявляем шаблонные функции
template<typename T>
T Sqr(T number)
{
	return number * number;
}

template <typename T>
vector<T> Sqr(vector<T> vec)
{
	for (int i=0; i < static_cast<int>(vec.size()); i++)
	{
		vec[i] = Sqr(vec[i]);
	}
	return vec;
}

template<typename First, typename Second>
pair<First, Second> Sqr(pair<First, Second> pr)
{
	return make_pair(Sqr(pr.first), Sqr(pr.second));
}

template<typename Key, typename Value>
map<Key, Value> Sqr(map<Key, Value> mp)
{
	for (auto elem : mp)
	{
		mp[elem.first] = Sqr(elem.second);
	}
	return mp;
}

int main()
{
	// Пример вызова функции
	vector<int> v = { 1, 2, 3 };
	cout << "vector:";
	for (int x : Sqr(v)) {
		cout << ' ' << x;
	}
	cout << endl;

	
	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	
	return 0;
}