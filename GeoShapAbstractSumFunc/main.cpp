#include <iostream>

using namespace std;
class Geoshape
{
    protected:
    float dim1;
    float dim2;
    public:
    void setDim1(float _dim1){dim1=_dim1;}
    void setDim2(float _dim2){dim2=_dim2;}
    float getDim1(){return dim1;}
    float getDim2(){return dim2;}
    Geoshape(){dim1=dim2=0;}
    Geoshape(float _dim1,float _dim2)
    {dim1=_dim1;dim2=_dim2;}
    ~Geoshape(){}
    virtual float CArea()=0;
};

class Rect:public Geoshape
{
    public:
    Rect()
    {}
    Rect(float _d1,float _d2):Geoshape(_d1,_d2)
    {}
    ~Rect(){}
    float CArea() override /*safety factor*/
    {
        return dim1*dim2;
    }
};

class Square:public Geoshape
{
    public:
    Square(){}
    Square(float _dim):Geoshape(_dim,_dim)
    {}
    ~Square(){}
    float CArea() override
    {return dim1*dim2;}
};


class Circle:public Geoshape
{
    public:
    Circle(){}
    Circle(float _radius):Geoshape(_radius,_radius)
    {}
    ~Circle(){}
    float CArea()
    {
        return 3.14* dim1*dim2;
    }
};

class Tri:public Geoshape
{
    public:
    Tri(){}
    Tri(float _base,float _height):Geoshape(_base,_height)
    {
    }
    ~Tri(){}
    float CArea()
    {
        return 0.5*dim1*dim2;
    }
};
float SumOfAreasV2(Geoshape* gPtrarr[],int size)
{
    float sum=0;
    for(int i=0;i<size;i++)
    {
        sum+= gPtrarr[i]->CArea();
    }
    return sum;
}
int main()
{
    cout<<"rectangle"<<endl;
    Rect r1(3,4);
    cout<<r1.CArea()<<endl;
    cout<<"Square"<<endl;
    Square s1(10);
    cout<<s1.CArea()<<endl;
    cout<<"Triangle"<<endl;
    Tri t(3,4);
    cout<<t.CArea()<<endl;
    cout<<"Circle"<<endl;
    Circle c(5);
    cout<<c.CArea()<<endl;

    Geoshape* gPtrarr[4]={&r1,&s1,&t,&c};

    cout<<"Sum Of Areas is = "<<SumOfAreasV2(gPtrarr,4);

    return 0;
}
