#include <cmath>
#include <iostream>
#include <string>
#define pi 3.14

using namespace std;

class Curve {
    virtual string display() = 0;
    virtual float eccentricity();

public:
    float semi_focal_length, large_semi_axis;

    Curve() {
        this->semi_focal_length = 0;
        this->large_semi_axis = 0;
    }

    ~Curve() = default;

    Curve(const Curve &huinya) {
        this->semi_focal_length = huinya.semi_focal_length;
        this->large_semi_axis = huinya.large_semi_axis;
    }
    void equation_curve() {
        cout << "Equation of the second - order curve: " << display() << endl;
    }
    void variablesForEccentricity() {
        cout << "abobas semi-focal length: ";
        cin >> semi_focal_length;
        cout << endl;

        cout << "abobas large semi-axis: ";
        cin >> large_semi_axis;
        cout << endl;
        if (semi_focal_length < large_semi_axis) {
            cout << "Eccentricity for ellipse equal: " << eccentricity() << endl;
        } else if (semi_focal_length == large_semi_axis) {
            cout << "TY DOLBAEB!!" << endl;
        } else if (semi_focal_length > large_semi_axis) {
            cout << "TY DOLBAEB!!!!!!!!!!!!!!!!!!!!" << endl;
        }
    }
};
float Curve::eccentricity() {
    return 0;
}

class Ellipse : public Curve {
    string display() {
        return "The ellipse equation: x^2/a^2 + y^2/b^2 = 1";
    }
    float eccentricity() {
        return semi_focal_length / large_semi_axis;
    }
};

class Hyperbola : public Curve {
    string display() {
        return "The hyperbola equation: x^2/a^2 - y^2/b^2 = 1";
    }
    float eccentricity() {
        return semi_focal_length / large_semi_axis;
    }
};

class Circle : public Ellipse {
private:
    float radius, circumference_length, areaCircle;

public:
    Circle() {
        this->radius = radius;
        this->circumference_length = circumference_length;
        this->areaCircle = areaCircle;
    }

    ~Circle() = default;

    Circle(const Circle &zalypa) {
        this->radius = zalypa.radius;
        this->circumference_length = zalypa.areaCircle;
        this->areaCircle = zalypa.areaCircle;
    }
    void areaOfTheCircle() {
        cout << "Enter circumference length: " << endl;
        cin >> circumference_length;
        radius = circumference_length / (2 * pi);
        areaCircle = pi * pow(radius, 2);
        cout << "The area of a circle bounded by a given circle: " << areaCircle << endl;
    }
};

int main() {
    Ellipse ellipse;
    Hyperbola hyperbola;
    Circle circle;

    int n;
    cout << "Choose number from 1 to 4" << endl;
    cout << "1.Print ellipse equation" << endl;
    cout << "2.Print hyperbola equation" << endl;
    cout << "3.Print result eccentricity for ellipse" << endl;
    cout << "4.Print result eccentricity for hyperbola" << endl;
    cout << "5.Print area of the circle" << endl;
    cout << "6.Exit" << endl;
    do {
        cin >> n;
        switch (n) {
            case 1:
                ellipse.equation_curve();
                break;
            case 2:
                hyperbola.equation_curve();
                break;
            case 3:
                ellipse.variablesForEccentricity();
                break;
            case 4:
                hyperbola.variablesForEccentricity();
                break;
            case 5:
                circle.areaOfTheCircle();
            case 6:
                system("pause");
            default:
                cout << "CHOOSE NUMBER FROM 1 to 5 BLYAT" << endl;
        }
    } while (n != 5);
}