#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string>
#include <typeinfo>

using namespace std;

vector<string> SplitIntoWords(const string& s)
{
    vector<string> result;
    string::const_iterator it = s.begin();
	while(it != s.end())
	{
        string::const_iterator prewious_it = it;
        it = find(it, s.end(), ' ');
        result.push_back(string(prewious_it, it));
		if(it != s.end()) it++;
	}
    return result;
}

int main() {
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}
