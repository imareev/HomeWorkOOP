#include <iostream>
int m=3;
int n=3;

int main() {
    int Matrix[m][n];
    int tmp[n];
    int t,i,j,k, min;

    for(i=0;i<m;i++) {
        for (j=0;j<n;j++) {
            *(*(Matrix+i)+j)=rand();
        }
    }

    std::cout <<"input matrix:\n";
    for (i=0;i<m;i++) {
        for (j=0;j<n;j++)
            std::cout <<"\t"<< *(*(Matrix+i)+j);
        std::cout <<("\n");
    }
    for(j=0;j<n;j++) {
        for(i=1, min=Matrix[0][j];i<m;i++) {
            if (min>*(*(Matrix+i)+j)) {
                min=*(*(Matrix+i)+j);
            }
        }
        *(tmp+j)=min;
    }
    std::cout <<("Min num:\n");
    for (j=0;j<n;j++) {
        std::cout <<"\t"<< *(tmp+j);
    }
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if (*(tmp+i)>*(tmp+j)) {
                t=*(tmp+i);
                *(tmp+i)=*(tmp+j);
                *(tmp+j)=t;
                for (k=0;k<m;k++) {
                    t=*(*(Matrix+k)+i);
                    *(*(Matrix+k)+i)=*(*(Matrix+i)+j);
                    *(*(Matrix+k)+j)=t;
                }
            }
        }
    }


    std::cout <<("\n\nResult matrix:\n\n");
    for (i=0;i<m;i++) {
        for (j=0;j<n;j++)
            std::cout <<"\t"<< *(*(Matrix+i)+j);
        std::cout <<("\n");
    }
    std::cout <<("Min num:\n");
    for (j=0;j<n;j++) {
        std::cout <<"\t"<< *(tmp+j);
    }
    return 0;
}