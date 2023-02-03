#include <iostream>

using namespace std;
class Geoshape
{
protected:
    float dim1;
    float dim2;
public:
    void setDim1(float _dim1)
    {
        dim1=_dim1;
    }
    void setDim2(float _dim2)
    {
        dim2=_dim2;
    }
    float getDim1()
    {
        return dim1;
    }
    float getDim2()
    {
        return dim2;
    }
    Geoshape()
    {
        dim1=dim2=0;
    }
    Geoshape(float _dim1,float _dim2)
    {
        dim1=_dim1;
        dim2=_dim2;
    }
    ~Geoshape() {}
};
class Rect:public Geoshape
{
    //Fields???
public:
    Rect()
    {}
    Rect(float _d1,float _d2):Geoshape(_d1,_d2)
    {/*dim1=_d1;dim2=_d2;*/}
    ~Rect() {}
    float CArea()
    {
        return dim1*dim2;
    }
};

class SquareV2:public Rect
{
public:
    SquareV2() {}
    SquareV2(float _dim):Rect(_dim,_dim)
    {}
    ~SquareV2() {}
};
class Tri:public Geoshape
{
public:
    Tri() {}
    Tri(float _base,float _height):Geoshape(_base,_height)
    {
        //dim1=_base;
        //dim2=_height;
    }
    ~Tri() {}
    float CArea()
    {
        return 0.5*dim1*dim2;
    }
};
class Circle:public Geoshape
{
public:
    Circle() {}
    Circle(float _radius):Geoshape(_radius,_radius)
    {}
    ~Circle() {}
    float CArea()
    {
        return 3.14* dim1*dim2;
    }
};
int main()
{
    cout<<"rectangle"<<endl;
    Rect r1(3,4);
    cout<<r1.CArea()<<endl;
    cout<<"Square"<<endl;
    SquareV2 s1(10);
    cout<<s1.CArea()<<endl;
    cout<<"Triangle"<<endl;
    Tri t(3,4);
    cout<<t.CArea()<<endl;
    cout<<"Circle"<<endl;
    Circle c(5);
    cout<<c.CArea()<<endl;

    return 0;
}
