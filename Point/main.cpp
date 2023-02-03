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
    ~Point(){cout<<"pnt dest"<<endl;}
    void Print()
    {
        cout<<"point=>"<<endl;
        cout<<"(x,y) =" <<"("<<x<<","<<y<<")"<<endl;
    }
};

int main()
{
    Point p1(3,4),p2(5,6);
    p1.Print();
    p2.Print();
    return 0;
}
