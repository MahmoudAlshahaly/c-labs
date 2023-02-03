#include <iostream>

using namespace std;

class Point
{
    private:
    int x;
    int y;
    public:
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    int getX(){return x;}
    int getY(){return y;}
    Point(){x=y=0;}  //create start // create end
    Point(int _x,int _y){x=_x;y=_y;}
    Point(const Point& old){x=old.x;y=old.y;}
    ~Point(){cout<<"pnt dest";}

};

class Circle
{
    private:
    Point center;
    int radius;
    public:
    void setCenter(Point _center){center=_center;}
    Point getCenter(){return center;}
    void setRadius(int _radius){radius=_radius;}
    int getRadius(){return radius;}
    Circle()
    {
        radius=0;
    }
    Circle(int x,int y,int _radius):center(x,y)
    {
        radius=_radius;
    }
    Circle(Point _center,int _radius)
    {
        center=_center;
        radius=_radius;
    }
    Circle(const Circle& old)
    {
        center=old.center;
        radius=old.radius;
    }
    ~Circle(){}
    void Print()
    {
        cout<<"Circle=>"<<endl;
        cout<<"center" <<"("<<center.getX()<<","<<center.getY()<<")"<<endl;
        cout<<"radius " <<radius<<endl;
    }
};

int main()
{
    Circle r1;
    r1.Print();
    //point def ctor ul
    //point def ctor lr
    //Rect def ctor

    Circle r2(1,2,3);
    r2.Print();

    Point p1(3,4);
    int reduis=10;
    Circle r3(p1,reduis);
    r3.Print();
    return 0;
}
