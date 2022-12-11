#include <iostream>
class Remote {

};

class TV {
public:
    friend int set_volume(TV &tv, unsigned vol){
        tv.valume = vol;
        struct s {

        };
        return tv.valume;
    }
private:
    friend Remote;
    //friend int set_volume(TV &tv, unsigned vol);
    unsigned chanel;
    unsigned valume;
    unsigned model;

};

int set_valume(TV &tv, unsigned vol) {
    tv.valume = vol;
    struct s {

    };
    return tv.valume;
}

int main() {
    TV tv;
    std::cout<<set_valume(tv,2);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
