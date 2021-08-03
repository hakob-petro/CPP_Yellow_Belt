#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

// ========================================== Class realization ==========================================

//class Person {
//public:
//	void ChangeFirstName(int year, const string& first_name) {
//		data[year].fn = first_name;
//		if (year < minyear) {
//			minyear = year;
//		}
//	}
//	void ChangeLastName(int year, const string& last_name) {
//		data[year].ln = last_name;
//		if (year < minyear) {
//			minyear = year;
//		}
//	}
//
//	string GetFullName(int year, bool history = false) {
//		int i = 0, j = 0, cnt = 0, firsthist = 0, secondhist = 0;
//		string firstsave, secondsave;
//		while (data[year - i].fn.empty() && (year - i) >= minyear) {
//			i++;
//		}
//		if (data[year - i].fn.empty()) {
//			cnt++;
//		}
//		else {
//			result = data[year - i].fn;
//			firstsave = data[year - i].fn;
//			if (history == true) {
//				for (int k = year - i - 1; k > minyear; --k) {
//					if (!data[k].fn.empty() && firsthist == 0 && data[k].fn != data[year - i].fn && data[k].fn != firstsave) {
//						result += " (" + data[k].fn;
//						firsthist++;
//						firstsave = data[k].fn;
//					}
//					else if (!data[k].fn.empty() && firsthist != 0 && data[k].fn != data[year - i].fn && data[k].fn != firstsave) {
//						result += ", " + data[k].fn;
//						firstsave = data[k].fn;
//					}
//				}
//				if (firsthist != 0) {
//					result += ")";
//				}
//
//			}
//		}
//
//		while (data[year - j].ln.empty() && (year - j) >= minyear) {
//			j++;
//		}
//		if (data[year - j].ln.empty()) {
//			if (cnt == 0) {
//				result += " with unknown last name";
//			}
//			else {
//				result = "Incognito";
//			}
//			cnt++;
//		}
//		else {
//			if (cnt == 1) {
//				result = data[year - j].ln;
//				secondsave = data[year - j].ln;
//				if (history == true) {
//					for (int k = year - j - 1; k > minyear; --k) {
//						if (!data[k].ln.empty() && secondhist == 0 && data[k].ln != data[year - j].ln && data[k].ln != secondsave) {
//							result += " (" + data[k].ln;
//							secondhist++;
//							secondsave = data[k].ln;
//						}
//						else if (!data[k].ln.empty() && secondhist != 0 && data[k].ln != data[year - j].ln && data[k].ln != secondsave) {
//							result += ", " + data[k].ln;
//							secondsave = data[k].ln;
//						}
//					}
//					if (secondhist != 0) {
//						result += ")";
//					}
//				}
//				result += " with unknown first name";
//			}
//			else {
//				result += " " + data[year - j].ln;
//				if (history == true) {
//					for (int k = year - j - 1; k > minyear; --k) {
//						if (!data[k].ln.empty() && secondhist == 0 && data[k].ln != data[year - j].ln && data[k].ln != secondsave) {
//							result += " (" + data[k].ln;
//							secondhist++;
//							secondsave = data[k].ln;
//						}
//						else if (!data[k].ln.empty() && secondhist != 0 && data[k].ln != data[year - j].ln && data[k].ln != secondsave) {
//							result += ", " + data[k].ln;
//							secondsave = data[k].ln;
//						}
//					}
//					if (secondhist != 0) {
//						result += ")";
//					}
//				}
//			}
//		}
//
//
//		return result;
//	}
//
//	string GetFullNameWithHistory(int year) {
//		return GetFullName(year, true);
//	}
//
//private:
//	struct FirstLast {
//		string fn;
//		string ln;
//	};
//	int minyear;
//	string result;
//	map<int, FirstLast> data;
//};

// ========================================== Tests Realization ==========================================

void TestNoChanges()
{
	Person person;
	person.ChangeFirstName(1965, "Polina");
	AssertEqual("Incognito", person.GetFullName(1964), "No lastname or firstname changes until 1964");
	AssertEqual("Polina with unknown last name", person.GetFullName(1965), "No lastname changes until 1964");
	person.ChangeLastName(1964, "Petrosyan");
	AssertEqual("Petrosyan with unknown first name", person.GetFullName(1964), "No firstname changes until 1964");
	
}

void Test1()
{
	Person person;

	person.ChangeFirstName(1900, "Eugene");
	person.ChangeLastName(1900, "Sokolov");
	person.ChangeLastName(1910, "Sokolov");
	person.ChangeFirstName(1920, "Evgeny");
	person.ChangeLastName(1930, "Sokolov");

	AssertEqual("Evgeny (Eugene) Sokolov", person.GetFullName(1940), " ");
}
void Test2()
{
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeFirstName(1965, "Appolinaria");

	person.ChangeLastName(1965, "Sergeeva");
	person.ChangeLastName(1965, "Volkova");
	person.ChangeLastName(1965, "Volkova-Sergeeva");

	AssertEqual("Appolinaria Volkova-Sergeeva", person.GetFullName(1965), "first one");
	AssertEqual("Appolinaria Volkova-Sergeeva", person.GetFullName(1966), "second one");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestNoChanges, "TestNoChanges");
  //runner.RunTest(Test1, "Test1");
  //runner.RunTest(Test2, "Test2");
	
  return 0;
}
