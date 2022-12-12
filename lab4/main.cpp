#include <iostream>

enum Country {
    USA,
    RUSSIA,
    BRAZIL,
    UK,
    FINLAND
};
class Airport {
public:
    Country country;
    int numberOfLandingStrips;
    int maxLoad;
    bool LandRemit;
    double maxAirWeight;
    Airport(Country country,int numberOfLandingStrips,int maxLoad,bool LandRemit,double maxAirWeight;)
    {
        this->country=country;
        this->numberOfLandingStrips=numberOfLandingStrips;
        this->maxLoad=maxLoad;
        this->LandRemit=LandRemit;
        this->maxAirWeight=maxAirWeight;
    }

private:
    double Oil;
    int currentLoad;
};

class Plane {
public:
    Country CurrCountry;
    double weight;
private:
    double Oil;
};

class passPlane : public Plane {
public:
    double MaxPessengeres;
    bool PlaceForEat;

    passPlane(Country country, double weight, double MaxPessengeres, bool PlaceForEat) {
        this->country = country;
        this->weight = weight;
        this->MaxPessengeres = MaxPessengeres;
        this->PlaceForEat = PlaceForEat;
    }
    void PrintINF(){
        std::cout<< this->CurrCountry<<" "<<this->weight<<" "<<this->MaxPessengeres<<" "<< this->PlaceForEat;
    }

};

class Cargo : public Plane {
public:
    double MaxWight;
    int PilotSeat;
    Cargo(Country country, double weight, double MaxW, int Pilot) {
        this->country = country;
        this->weight = weight;
        this->MaxWight = MaxW;
        this->PilotSeat = Pilot;
    }
    void PrintINF(){
        std::cout<< this->CurrCountry<<" "<<this->weight<<" "<<this->MaxWight<<" "<< this->PilotSeat;
    }
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
    return 0;
}
