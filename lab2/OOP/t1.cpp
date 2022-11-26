#include <iostream>
//Сформировать массив строк. Удалить из него самую короткую строку.
int main() {
    int n = 5;
    std::string a[5] = {"qwqe", "2332", "fnklsd", "fdsfd", "fgd"};
    int min_l;
    std::string *minElem = &(*(a));
    int IndexM;
    for (int i = 0; i < n; i++) {
        std::cout << "a[" << i << "]: address=" << a + i << "\tvalue " << (*(a + i)) << std::endl;
    }
    std::cout << '\n';
    for (int i = 0; i < n; i++) {
        if ((*(a + i)).length() < (*minElem).length()) {
            minElem = &(*(a + i));
            IndexM = i;
        }
    }
    for (int i = IndexM; i < n - 1; ++i)
        a[i] = a[i + 1];
    n--;
    for (int i = 0; i < n; i++) {
        std::cout << "a[" << i << "]: address=" << a + i << "\tvalue " << (*(a + i)) << std::endl;
    }
    return 0;
}

