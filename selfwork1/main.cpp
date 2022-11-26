#include <iostream>

//Описать структуру с именем AEROFLOT, содержащую следующиеполя:NAZN—название пункта назначения рейса;NUMR—номер рейса;TIP—тип самолета. Написать программу, выполняющую следующие действия: ввод с клавиатуры данных в массив AIRPORT, состоящий из семи элементов типа AEROFLOT; записи должны быть упорядочены по возрастанию номера рейса; вывод на экран номеров рейсов и типов самолетов, вылетающих в пункт назначения, название которого совпало с названием, введенным с клавиатуры;если таких рейсов нет, выдать на дисплей соответствующее сообщение.
struct AEROFLOT {
    std::string NAZN;
    std::string NUMR;
    std::string TIP;


};

int main() {
    int size=1;
    AEROFLOT aeroflot[7];
    for (int i = 0; i < 7; i++) {
        std::cout << "NAZN:";
        std::cin >> aeroflot[i].NAZN;
        std::cout << "NUMR:";
        std::cin >> aeroflot[i].NUMR;
        std::cout << "TIP:";
        std::cin >> aeroflot[i].TIP;
    }
    int doesExist = 0;
    std::string NUMR;
    std::string TIP;
    std::cout << "find NUMR:";
    std::cin >> NUMR;
    std::cout << "find TIP:";
    std::cin >> TIP;
    for (int i = 0; i < size; i++) {

        if (aeroflot[i].TIP == TIP && aeroflot[i].NAZN == TIP) {
            std::cout << aeroflot[i].TIP << " " << aeroflot[i].NAZN << " " << aeroflot[i].NUMR << std::endl;
        } else {
            doesExist++;
        }

    }
    if (doesExist == size)
    {
        std::cout<<"doesn't exist";
    }
        return 0;
}
