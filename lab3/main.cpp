#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>


struct Scan_info {
    std::string model; // наименование модели
    int price; // цена
    double x_size; // горизонтальный размер области сканирования
    double y_size; // вертикальный размер области сканирования
    int optr; // оптическое разрешение
    int grey; // число градацийсерого
};

int WriteOfFile(int records) {
    int x = records;
    Scan_info info[7];
    std::ifstream fin("C:\\Users\\MiBook\\Desktop\\lab3\\scan_info.txt", std::ios::in);
    if (fin.is_open())
    {
        fin.seekg(0, std::ios::end);
        int bytes = fin.tellg();
        int count = 0;
        fin.seekg(0, std::ios::beg);
        fin.read((char*)&count, sizeof(int));
        char* readBytes = new char[bytes - 4];
        fin.read(readBytes, bytes - 4);
        fin.close();

        std::ofstream fout("C:\\Users\\MiBook\\Desktop\\lab3\\scan_info.txt", std::ios::out | std::ios::binary);
        count++;
        fout.write((char*)&count, sizeof(int));
        fout.write((char*)&info->price, sizeof(int));
        fout.write((char*)&info->x_size, sizeof(double));
        fout.write((char*)&info->y_size, sizeof(double));
        fout.write((char*)&info->optr, sizeof(int));
        fout.write((char*)&info->grey, sizeof(int));
        fout.write(info->model.c_str(), info->model.size() + 1);
        fout.write(readBytes, bytes - 4);
        fout.close();
        delete[] readBytes;
    }
    else
    {
        std::ofstream fout("C:\\Users\\MiBook\\Desktop\\lab3\\scan_info.txt", std::ios::out | std::ios::binary);
        int count = 1;
        fout.write((char*)&count, sizeof(int));
        fout.write((char*)&info->price, sizeof(int));
        fout.write((char*)&info->x_size, sizeof(double));
        fout.write((char*)&info->y_size, sizeof(double));
        fout.write((char*)&info->optr, sizeof(int));
        fout.write((char*)&info->grey, sizeof(int));
        fout.write(info->model.c_str(), info->model.size() + 1);
        fout.close();
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

            fout.read((char *) &scanInfo[i].x_size, sizeof(double));
            std::cout << scanInfo[i].x_size <<"in"<< " ";

            fout.read((char *) &scanInfo[i].y_size, sizeof(double));
            std::cout << scanInfo[i].y_size <<"in" " ";

            fout.read((char *) &scanInfo[i].grey, sizeof(int));
            std::cout << scanInfo[i].grey << " ";

            fout.read((char *) &scanInfo[i].optr, sizeof(int));
            std::cout << scanInfo[i].optr <<"DPI"<< " ";

            std::cout << "\n";

        }
        return 0;
    }
    fout.close();
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
