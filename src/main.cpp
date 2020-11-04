#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = 3.14;

class Figure {
public:
	virtual string Name() const = 0;
	virtual double Perimeter() const = 0;
	virtual double Area() const = 0;
};

class Triangle: public Figure {
public:
	Triangle(const double &a, const double &b, const double &c) :
			a_(a), b_(b), c_(c) {
	}

	string Name() const override {
		return name_;
	}

	double Perimeter() const override {
		return a_ + b_ + c_;
	}

	double Area() const override {
		double p = (a_ + b_ + c_) / 2.;
		return sqrt(p * (p - a_) * (p - b_) * (p - c_));
	}
private:
	const double a_, b_, c_;
	const string name_ = "TRIANGLE";
};

class Rect: public Figure {
public:
	Rect(const double &width, const double &height) :
			width_(width), height_(height) {
	}

	string Name() const override {
		return name_;
	}

	double Perimeter() const override {
		return 2. * (width_ + height_);
	}

	double Area() const override {
		return width_ * height_;
	}
private:
	const double width_, height_;
	const string name_ = "RECT";
};

class Circle: public Figure {
public:
	Circle(const double &r) :
			r_(r) {
	}

	string Name() const override {
		return name_;
	}

	double Perimeter() const override {
		return 2. * PI * r_;
	}

	double Area() const override {
		return PI * pow(r_, 2.);
	}
private:
	const double r_;
	const string name_ = "CIRCLE";
};

shared_ptr<Figure> CreateFigure(istream &input) {
	string type = "";
	input >> type;
	if (type == "TRIANGLE") {
		double a, b, c;
		input >> a >> b >> c;
		return make_shared<Triangle>(a, b, c);
	} else if (type == "RECT") {
		double width, height;
		input >> width >> height;
		return make_shared<Rect>(width, height);
	} else if (type == "CIRCLE") {
		double r;
		input >> r;
		return make_shared<Circle>(r);
	}
}

int main() {
	vector<shared_ptr<Figure>> figures;
	for (string line; getline(cin, line);) {
		istringstream is(line);

		string command;
		is >> command;
		if (command == "ADD") {
			is >> ws;
			figures.push_back(CreateFigure(is));
		} else if (command == "PRINT") {
			for (const auto &current_figure : figures) {
				cout << fixed << setprecision(3) << current_figure->Name()
						<< " " << current_figure->Perimeter() << " "
						<< current_figure->Area() << endl;
			}
		}
	}
	return 0;
}
