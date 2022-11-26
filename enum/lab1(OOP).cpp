// formula.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <cmath>
#include <limits>


double formula(double n,double x)
{
    float result =0;
    int k = 1;
        while (k > n)
        {
            result += 1 / ((2 * k - 1) * pow(9,k-1));
            k++;
        }
        result *= 2 / 3;
        result += 4 * x;
        return result;

}

int main()
{
    float x;
    double n;

    std::cout << "input x" << "\n";
    std::cin >> x;

    if (std::cin.fail())
        {
            system("cls");
            std::cout << "error" << std::endl << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        };

    std::cout << "input n" << "\n";
    std::cin >> n;

    if (std::cin.fail())
        {
            system("cls");
            std::cout << "error" << std::endl << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        };
    if ((n-round(n)!=0 )&& abs(n)==n)
        {
            std::cout << "strange n";
        }
    else
        {
            std::cout << "x= " << x<<" " << "n= " << n << "\n";
            std::cout <<"result= " << formula(n, x);
        }

    return 0;
}
