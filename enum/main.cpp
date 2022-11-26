 #include <iostream>

using namespace std;
enum operation
{

    _plus,
    _minus,
    _div,
    _mul

};
float cal(float n1,float n2,operation op)
{
    switch(op){
    case(0):
        return n1+n2;
    case(1):
        return n1-n2;
    case(2):
        return n1/n2;
    case(3):
        return n1*n2;
    default:
      cout<<"error!";

    }

}
void consolMenu()
{
    short codeoperator;
    bool flag=true;
    float a;
    float b;
    while(flag!=false)
        {
            cout <<"input a"<<"\n";
            cin>>a;
            cout <<"input b"<<"\n";
            cin>>b;

            if ( a &&  b)
                {
                    cout<<"\n"<<"1.plus"<<"\n"<<"2.minus"<<"\n"<<"3.div"<<"\n"<<"4.mull"<<"\n"<<"5.exit"<<"\n";
                    cin>>codeoperator;
                    if(codeoperator==1)
                    {
                        system("cls");
                        cout <<"\n"<<"answear="<<cal(a,b,_plus)<<"\n";

                    }
                    else if(codeoperator==2)
                    {
                        system("cls");
                        cout <<"\n"<<"answear:"<<cal(a,b,_minus)<<"\n";
                    }
                    else if(codeoperator==3)
                    {
                        system("cls");
                        cout <<"answear:"<<cal(a,b,_div)<<"\n";
                        flag=false;
                    }
                    else if(codeoperator==4)
                    {
                        system("cls");
                        cout <<"\n"<<"answear="<<cal(a,b,_mul)<<"\n";
                    }
                    else if(codeoperator==5)
                    {
                        flag=false;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n"
                        <<"strange operation";
                        flag=false;
                    }
                    }
                    else
                    {
                        cout << "Incorrect input" << endl;
                        flag=false;
                    }
                }
}
int main()
{
    consolMenu();
    return 0;
}
