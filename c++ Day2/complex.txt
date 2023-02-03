#include <iostream>

using namespace std;

class Complex {
private:
    int real;
    int img;
public:
    Complex(){
    cout<<"Complex Constructor\n";
    }
    ~Complex(){
    cout<<"Complex Destructor\n";
    }
    void setReal(int _real){
    this->real=_real;
    }
    void setImg(int _img){
    this->img=_img;
    }
    void print(){
           switch(real)
        {
        case 0:
            if(img>1)
            {
                cout<<img<<"i\n";
            }
            else if(img==0)
            {
                cout<<"Null";
            }
            else if(img==1)
            {
                cout<<"i";
            }
            else
            {
                cout<<img<<"i";
            }
            break;
        default:
            if(img>1)
            {
                cout<<real<<"+"<<img<<"i\n";
            }
            else if(img==0)
            {
                cout<<real;
            }
            else if(img==1)
            {
                cout<<real<<"+i";
            }
            else
            {
                cout<<real<<img<<"i\n";
            }
        };
    }
    int getReal(){return this->real;}

    int getImg(){return this->img;}

    Complex add(Complex para){
    Complex temp;
    temp.setReal(this->real+para.getReal());
    temp.setImg(this->img+para.getImg());
    return temp;
    }
};


Complex Sub(Complex left,Complex right){
Complex temp;
temp.setReal(left.getReal()-right.getReal());
temp.setImg(left.getImg()-right.getImg());
return temp;
}

int main()
{
    Complex s1,s2,s3,s4;
    s1.setReal(5);
    s1.setImg(8);
    s2.setReal(9);
    s2.setImg(13);
    s3=s1.add(s2);
    s4=Sub(s1,s2);
    cout<<"The First Complex ";
    s1.print();
    cout<<"The Second Complex ";
    s2.print();
    cout<<"The Add Result ";
    s3.print();
    cout<<"The Sub Result ";
    s4.print();
    return 0;
}
