#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
	Person(const string &name, const string &outputPrefix) :
			Name(name), PersonType(outputPrefix) {
	}
	virtual ~Person() = default;
	virtual void Walk(const string &destination) const {
		cout << PersonType << ": " << Name << " walks to: " << destination
				<< endl;
	}
	;
public:
	const string Name;
	const string PersonType;
};

class Student: public Person {
public:
	Student(const string &name, const string &favouriteSong) :
			Person(name, "Student"), FavouriteSong(favouriteSong) {
	}

	void Learn() const {
		cout << PersonType << ": " << Name << " learns" << endl;
	}

	void Walk(const string &destination) const override {
		cout << PersonType << ": " << Name << " walks to: " << destination
				<< endl;
		SingSong();
	}

	void SingSong() const {
		cout << PersonType << ": " << Name << " sings a song: " << FavouriteSong
				<< endl;
	}
private:
	const string FavouriteSong;
};

class Teacher: public Person {
public:
	Teacher(const string &name, const string &subject) :
			Person(name, "Teacher") {
	}

	void Teach() const {
		cout << PersonType << ": " << Name << " teaches: " << Subject << endl;
	}
private:
	const string Subject;
};

class Policeman: public Person {
public:
	Policeman(const string &name) :
			Person(name, "Policeman") {
	}

	void Check(const Person &p) const {
		cout << PersonType << ": " << Name << " checks " << p.PersonType << ". "
				<< p.PersonType << "'s name is: " << p.Name << endl;
	}
};

void VisitPlaces(const Person &p, const vector<string> &places) {
	for (const auto &place : places) {
		p.Walk(place);
	}
}

int main() {
	Teacher t("Jim", "Math");
	Student s("Ann", "We will rock you");
	Policeman p("Bob");

	VisitPlaces(t, { "Moscow", "London" });
	p.Check(s);
	VisitPlaces(s, { "Moscow", "London" });
	return 0;
}
