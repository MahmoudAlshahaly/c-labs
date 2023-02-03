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

class Rect
{
    private:
    Point ul;
    Point lr;
    public:
    void setUL(Point _ul){ul=_ul;}
    void setLR(Point _lr){lr=_lr;}
    Point getUL(){return ul;}
    Point getLR(){return lr;}
    Rect()//:ul(0,0),lr() //useless code
    {
        //Compiler ul 0 0    lr 0 0
    }
    Rect(int x1,int y1,int x2,int y2):ul(x1,y1),lr(x2,y2)
    {
        //
        //Compiler ul x1 y2     lr x3 y4
        //
    }
    Rect(Point _ul,Point _lr)
    {
        ul=_ul;
        lr=_lr;
    }
    Rect(const Rect& old)
    {
        ul=old.ul;lr=old.lr;
    }
    ~Rect(){cout<<"Rect dest"<<endl;}
    void Print()
    {
        cout<<"Rectangle=>"<<endl;
        cout<<"ul" <<"("<<ul.getX()<<","<<ul.getY()<<")"<<endl;
        cout<<"lr" <<"("<<lr.getX()<<","<<lr.getY()<<")"<<endl;
    }
};
int main()
{
    Rect r1;
    r1.Print();
    //point def ctor ul
    //point def ctor lr
    //Rect def ctor

    Rect r2(1,2,3,4);
    r2.Print();

    Point p1(3,4),p2(5,6);
    Rect r3(p1,p2);
    r3.Print();
    return 0;
}
