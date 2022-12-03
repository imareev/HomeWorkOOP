#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

struct Scan_info {
    char model[20]; // наименование модели
    int price; // цена
    double x_s1ze; // горизонтальный размер области сканирования
    double y_s1ze; // вертикальный размер области сканирования
    int optr; // оптическое разрешение
    int grey; // число градацийсерого
};

int WriteOfFile(int records) {
    int x = records;
    Scan_info scanInfo[7];

    std::ofstream fout("txt.dat", std::ios_base::binary);
    fout.write((char *) &x, sizeof(int));
    for (int i = 0; i < records; i++) {
        fout.write((char *) &i, sizeof(int));
        std::cout << "enter data for" << " " << i + 1 << " " << "model" << std::endl;
        std::cout << "enter model:";
        std::string s;
        std::cin >> s;
        s.copy(scanInfo[i].model, 19);
        scanInfo[i].model[20] = '\0';
        fout.write((char *) &scanInfo[i].model, sizeof(char[20]));

        std::cout << "enter price:";

        std::cin >> scanInfo[i].price;
        if (!std::cin) {
            std::cout << "Enter type 'int' of value! please try again ";
            exit(0);
        }
        fout.write((char *) &scanInfo[i].price, sizeof(int));

        std::cout << "enter x:";
        scanInfo[i].x_s1ze = 1;
        std::cin >> scanInfo[i].x_s1ze;
        if (!std::cin) {
            std::cout << "Enter type 'int' of value! please try again ";
            exit(0);
        }
        fout.write((char *) &scanInfo[i].x_s1ze, sizeof(double));

        std::cout << "enter y:";
        std::cin >> scanInfo[i].y_s1ze;
        if (!std::cin) {
            std::cout << "Enter type 'int' of value! please try again ";
            exit(0);
        }
        fout.write((char *) &scanInfo[i].y_s1ze, sizeof(double));

        std::cout << "enter g:";
        std::cin >> scanInfo[i].grey;
        if (!std::cin) {
            std::cout << "Enter type 'int' of value! please try again ";
            exit(0);
        }
        fout.write((char *) &scanInfo[i].grey, sizeof(int));

        std::cout << "enter optr:";
        std::cin >> scanInfo[i].optr;
        if (!std::cin) {
            std::cout << "Enter type 'int' of value! please try again ";
            exit(0);
        }
        fout.write((char *) &scanInfo[i].optr, sizeof(int));


    }
}

int ReadOfFile(int iRecorders) {
    int x;
    std::string str;
    Scan_info scanInfo[7];
    std::ifstream fout("txt.dat", std::ios_base::binary);
    fout.read((char *) &x, sizeof(int));
    std::cout << "In base save" << " " << x << " " << "model" << " ";
    if (fout.is_open() == 0) {
        return -1;
    } else {
        std::cout << '\n';

        for (int i = 0; i < iRecorders; i++) {

            fout.read((char *) &x, sizeof(int));
            std::cout << x << " ";

            fout.read((char *) &scanInfo[i].model, 20);
            std::cout <<scanInfo[i].model << " ";

            fout.read((char *) &scanInfo[i].price, sizeof(int));
            std::cout << scanInfo[i].price <<"$"<< " ";

            fout.read((char *) &scanInfo[i].x_s1ze, sizeof(double));
            std::cout << scanInfo[i].x_s1ze <<"in"<< " ";

            fout.read((char *) &scanInfo[i].y_s1ze, sizeof(double));
            std::cout << scanInfo[i].y_s1ze <<"in" " ";

            fout.read((char *) &scanInfo[i].grey, sizeof(int));
            std::cout << scanInfo[i].grey << " ";

            fout.read((char *) &scanInfo[i].optr, sizeof(int));
            std::cout << scanInfo[i].optr <<"DPI"<< " ";

            std::cout << "\n";

        }
        return 0;
    }
}

int main() {

    int ammountRecords ;
    std::cout<<"enter ammount records ";
    std::cin>>ammountRecords;
    if (!std::cin){
        std::cout<<"Enter type 'int' of value! please try again ";
        exit(0);
    }
    WriteOfFile(ammountRecords);
    ReadOfFile(ammountRecords) == 0 ? std::cout << "access" : std::cout << "error";
    return 0;
}
