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

class Tri
{
    private:
    Point p1,p2,p3;
    public:
    //setters& getters
    void setP1(Point _p1){p1=_p1;}
    Point getP1(){return p1;}
    void setP2(Point _p2){p2=_p2;}
    Point getP2(){return p2;}
    void setP3(Point _p3){p3=_p3;}
    Point getP3(){return p3;}
    Tri(){}
    Tri(int x1,int y1,int x2,int y2,int x3,int y3):p1(x1,y1),p2(x2,y2),p3(x3,y3)
    {}
    //
    Tri(Point _p1,Point _p2,Point _p3)
    {
        p1=_p1;
        p2=_p2;
        p3=_p3;
    }
    Tri(const Tri& old)
    {
        p1=old.p1;
        p2=old.p2;
        p3=old.p3;
    }
    ~Tri(){cout<<"tri dest"<<endl;}
    void Print()
    {
        cout<<"triangle=>"<<endl;
        cout<<"p1" <<"("<<p1.getX()<<","<<p1.getY()<<")"<<endl;
        cout<<"p2" <<"("<<p2.getX()<<","<<p2.getY()<<")"<<endl;
        cout<<"p3" <<"("<<p3.getX()<<","<<p3.getY()<<")"<<endl;
    }
    //
    //
    //
};
int main()
{
    Tri r1;
    r1.Print();
    //point def ctor ul
    //point def ctor lr
    //Rect def ctor

    Tri r2(1,2,3,4,6,8);
    r2.Print();

    Point p1(3,4),p2(5,6),p3(7,9);
    Tri r3(p1,p2,p3);
    r3.Print();

    return 0;
}
