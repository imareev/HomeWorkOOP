#include <fstream>
#include <iostream>
#include <stdlib.h>

struct Scan_info {
    std::string model; // наименование модели
    int price; // цена
    double x_s1ze; // горизонтальный размер области сканирования
    double y_s1ze; // вертикальный размер области сканирования
    int optr; // оптическое разрешение
    int grey; // число градацийсерого
};

int WriteOfFile(int recorders) {
    int x = recorders;
    Scan_info scanInfo[7];

    std::ofstream fout("txt.dat", std::ios_base::binary);
    fout.write((char *) &x, sizeof(int));

    for (int i = 0; i < recorders; i++) {
        fout.write((char *) &i, sizeof(int));

        std::cout << "enter model:";
        std::cin >> scanInfo[i].model;
        fout.write((char *) &scanInfo[i].model, sizeof(std::string));

        std::cout << "enter price:";
        std::cin >> scanInfo[i].price;
        fout.write((char *) &scanInfo[i].price, sizeof(int));

        std::cout << "enter x:";
        std::cin >> scanInfo[i].x_s1ze;
        fout.write((char *) &scanInfo[i].x_s1ze, sizeof(double));

        std::cout << "enter y:";
        std::cin >> scanInfo[i].y_s1ze;
        fout.write((char *) &scanInfo[i].y_s1ze, sizeof(double));

        std::cout << "enter g:";
        std::cin >> scanInfo[i].grey;
        fout.write((char *) &scanInfo[i].grey, sizeof(int));

        std::cout << "enter o:";
        std::cin >> scanInfo[i].optr;
        fout.write((char *) &scanInfo[i].optr, sizeof(int));

        fout.write("\n", 1);

    }
}

int ReadOfFile(int ammountRecorders) {
    int x;
    std::string str;
    Scan_info scanInfo[7];

    std::ifstream fout("txt.dat", std::ios_base::binary);
    fout.read((char *) &x, sizeof(int));
    std::cout << x << " ";

    fout.read((char *) &x, sizeof(int));
    std::cout << x << " ";

    fout.read(reinterpret_cast<char >&str, sizeof(std::string));
    std::cout << "(" << str << ")" << " ";

    fout.read((char *) &x, sizeof(int));
    std::cout << x << " ";
}

int main() {
    int ammountRecorders = 2;
    //WriteOfFile(ammountRecorders);
    ReadOfFile(ammountRecorders);
    return 0;
}
