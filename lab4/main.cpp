#include <iostream>

enum Country {
    USA,
    RUSSIA,
    BRAZIL,
    UK,
    FINLAND
};
enum TypePlane {
    CARGO,
    PASS
};

class Airport {
public:
    Country country;
    int numberOfLandingStrips;
    int maxLoad;
    bool LandRemit;
    double maxAirWeight;
private:
    double Oil;
    int currentLoad;
};

class Plane {
public:
    TypePlane typePlane;
    Country CurrCountry;
    double weight;
    int maxPassengers;
private:
    double Oil;
};

bool operator<(Plane plane1, Plane plane2) {
    return plane1.maxPassengers < plane2.maxPassengers;
};

bool operator>(Plane plane1, Plane plane2) {
    return plane1.maxPassengers > plane2.maxPassengers;
};

bool Trip(Airport airport, Plane plane) {
    if (airport.LandRemit == true && airport.maxAirWeight >= plane.weight) {
        plane.CurrCountry = airport.country;
        return true;
    } else
        return false;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
