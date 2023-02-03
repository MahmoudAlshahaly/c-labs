#include <iostream>

using namespace std;


int FunVal(int a)
{
    a++;
    return a;
}

int* FunAdd(int* a)
{
    (*a)++;
    return a;
}

int& FunRef(int& a)
{
    a++;
    return a;
}
int main()
{
     //pass/return by reference
     int x=60;
     cout<<FunRef(x)<<endl; //61
     FunRef(x)=900;
     cout<<x<<endl;; //900

     cout<<"----------------------"<<endl;
     //pass/Return by address
     int y=3; //in address 0x10
     cout<< FunAdd(&y)<<endl;; //AddressOfx //0x10
     cout<< *(FunAdd(&y))<<endl;  ; //4
     //
     *(FunAdd(&y))=100; //True
     cout<<y<<endl;; //100
     //
    cout<<"----------------------"<<endl;
    //pass/Return By Value
     int z=3;
     int result=FunVal(z); //4
     cout<<FunVal(z)<<endl;; //4

    //Compile Error //LVALUE
     //FunVal(z)=33;

}
