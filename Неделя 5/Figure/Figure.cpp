#include <iostream>
#include <iomanip>
#include <sstream>
#include <memory>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

const double PI = 3.14;

class Figure {
public:
	Figure(const string name = "Figure",
        const double perimeter = 0,
        const double area = 0) : name_(name), perimeter_(perimeter), area_(area){}
    virtual string Name() = 0;
    virtual double Perimeter() = 0;
    virtual double Area() = 0;

protected:
    string name_;
    double perimeter_, area_;
};

class Rect : public Figure {
public:
	Rect(double& width, double& height) : Figure(), width_(width), height_(height){}

	string Name() override {
        name_ = "RECT";
        return name_;
    }
    double Perimeter() override {
        perimeter_ = 2 * (width_ + height_);
        return  perimeter_;
    }
    double Area() override {
        area_ = width_ * height_;
        return area_;
    }

private:
    const double width_;
    const double height_;
};

class Triangle : public Figure {
public:
    Triangle(double& a, double& b, double& c) : Figure(),a_(a), b_(b), c_(c) {}
	
    string Name() override {
        name_ = "TRIANGLE";
        return name_;
    }
    double Perimeter() override {
        perimeter_ = a_ + b_ + c_;
        return  perimeter_;
    }
    double Area() override {
        const double halp_per = Perimeter()/2;
        area_ = sqrt(halp_per * (halp_per - a_) * (halp_per - b_) * (halp_per - c_));
        return area_;
    }

private:
    const double a_, b_, c_;
};

class Circle : public Figure {
public:
    Circle(double& r) : Figure(), r_(r) {}
	
    string Name() override {
        name_ = "CIRCLE";
        return name_;
    }
    double Perimeter() override {
        perimeter_ = 2 * PI * r_;
        return  perimeter_;
    }
    double Area() override {
        area_ = PI * pow(r_, 2);
        return area_;
    }

private:
    const double r_;
};

shared_ptr<Figure> CreateFigure(istringstream& is)
{
    string command;
    is >> command;
    if (command == ("RECT"))
    {
	    double width, height;
    	is >> width >> height;
    	return make_shared<Rect>(width, height);
    }
    else if (command == ("TRIANGLE"))
    {
        double a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    }else
    {
        double r;
        is >> r;
        return make_shared<Circle>(r);
    }
}
int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            // Пропускаем "лишние" ведущие пробелы.
            // Подробнее об std::ws можно узнать здесь:
            // https://en.cppreference.com/w/cpp/io/manip/ws
            is >> ws;
            figures.push_back(CreateFigure(is));
        }
        else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                    << current_figure->Name() << " "
                    << current_figure->Perimeter() << " "
                    << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}