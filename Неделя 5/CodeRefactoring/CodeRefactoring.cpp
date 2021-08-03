#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person(const string& name, const string& profession) : name_(name),
	profession_(profession) {}

	virtual void Walk(const string& destination) const {
        cout << get_profession() << ": " << get_name() << " walks to: " << destination << endl;
    }
	
	const string& get_profession() const {
        return profession_;
    }
	
    const string& get_name() const {
        return name_;
    }

private:
	const string name_, profession_;
};


class Student : public Person{
public:

    Student(const string& name, const string& favouriteSong) : Person(name, "Student"),
	FavouriteSong(favouriteSong) {}

    void Learn() const{
        cout << get_profession()<< ": " << get_name() << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        cout << get_profession() << ": " << get_name() << " walks to: " << destination << endl;
        SingSong();
    }

    void SingSong() const {
        cout << get_profession() << ": " << get_name() << " sings a song: " << FavouriteSong << endl;
    }

private:
    string FavouriteSong;
};


class Teacher : public Person {
public:

    Teacher(const string& name, const string& subject) : Person(name, "Teacher"),
	Subject(subject) {}

    void Teach() const {
        cout << get_profession() << ": " << get_name() << " teaches: " << Subject << endl;
    }

private:
    string Subject;
};


class Policeman : public Person {
public:
    Policeman(const string& name) : Person(name, "Policeman") {}
    
    void Check(const Person& p) const {
        cout << get_profession() << ": " << get_name() << " checks " <<
            p.get_profession() << ". " << p.get_profession() << "'s name is: " << p.get_name() <<  endl;
    }
};


void VisitPlaces(const Person& person, const vector<string>& places) {
    for (auto& p : places) {
        person.Walk(p);
    }
}


int main() {
    const Teacher t("Jim", "Math");
    const Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, { "Moscow", "London" });
    p.Check(s);
    VisitPlaces(s, { "Moscow", "London" });
    return 0;
}
