#include<iostream>
using namespace std;
class Complex
{
    int real,img;
    public:
    void setReal(int _real){real=_real;}
    void setImg(int _img){img=_img;}
    int getReal(){return real;}
    int getImg(){return img;}
    Complex()
    {
        //cout<<"ctor";
        real=img=0;
    }
    Complex(int _r,int _i)
    {
        real=_r;
        img=_i;
    }
    ~Complex()
    {
    }
    //
    void printComplex()
    {
        cout<<real<<"+"<<img<<"i"<<endl;
    }
    //-----------------------------------------------
    //cpy ctor
    Complex(const Complex& old)
    {
        real=old.real;
        img=old.img;
    }
    //c1+c2
    Complex operator + (Complex right)
    {
        Complex retVal;
        retVal.real=real+right.real;
        retVal.img=img+right.img;
        return retVal;
    }
    //c1+=c2
    Complex& operator += (Complex right)
    {
        real=real+right.real;
        img+=right.img;
        return *this;
    }

    //++c1
    Complex& operator ++ ()
    {
        real++;
        img++;
        return *this;
    }

    //c1++
    Complex operator ++ (int)
    {
        Complex retVal(real,this->img);
        real++;
        img++;
        return retVal;
    }

    //c1+10
    Complex operator + (int num)
    {
        Complex retVal(real+num,img);
        return retVal;
    }
    //c1>c2
    int operator > (Complex right)
    {
        return real > right.real && img > right.img;
    }
    //(int)c1
    operator int()
    {
        return real;
    }

    //c1=c3   USELESS
    Complex& operator = (Complex right)
    {
        real = right.real;
        img = right.img;
        return *this;
    }
};

//10+c1
Complex operator + (int num,Complex right)
{
    Complex retVal(right.getReal()+num,right.getImg());
    return retVal;
}

int main()
{
    Complex c1(2,5),c2(6,4),c3;
    c3=c1+c2;
    cout<<endl;
    cout<<" value of    c1+c2 => ";
    c3.printComplex();


    c1+=c2;
    cout<<endl;
    cout<<" value of    c1+=c2 => ";
    c3.printComplex();

    c3=++c1;

    cout<<endl;
    cout<<" value of    c3=++c1 => ";
    c3.printComplex();


    c3=c1++;

    cout<<endl;
    cout<<" value of    c3=c1++ => ";
    c3.printComplex();

    c3=c1+10;
    cout<<endl;
    cout<<" value of    c3=c1+10 => ";
    c3.printComplex();

    c3=10+c1;
    cout<<endl;
    cout<<" value of    c3=10+c1 => ";
    c3.printComplex();

     if(c1>c2){
           cout<<"true"<<endl;
     }
     else{
          cout<<"false"<<endl;
     }

    c3=c1;
    cout<<endl;
    cout<<" value of    c3=c1 => ";
    c3.printComplex();//13 4
}

