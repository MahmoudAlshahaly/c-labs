#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    void setX(int _x)
    {
        x=_x;
    }
    void setY(int _y)
    {
        y=_y;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    Point()
    {
        x=y=0;   //create start // create end
    }
    Point(int _x,int _y)
    {
        x=_x;
        y=_y;
    }
    Point(const Point& old)
    {
        x=old.x;
        y=old.y;
    }
    ~Point()
    {
        //cout<<"pnt dest";
    }

};

class Line
{
private:
    Point start;
    Point end;
public:
    void setStart(Point _start)
    {
        start=_start;
    }
    void setEnd(Point _end)
    {
        end=_end;
    }
    Point getStart()
    {
        return start;
    }
    Point getEnd()
    {
        return end;
    }
    //
    Line()
    {
    }
    Line(int x1,int y1,int x2,int y2)
    {
        start.setX(x1);
        start.setY(y1);
        end.setX(x2);
        end.setY(y2);
    }
    Line(Point _start,Point _end)
    {
        start=_start;
        end=_end;
    }
    Line(const Line& old)
    {
        start=old.start;
        end=old.end;
    }
    //~Line(){cout<<"Line dest";}
    void Print()
    {
        cout<<"Line=>"<<endl;
        cout<<"start" <<"("<<start.getX()<<","<<start.getY()<<")"<<endl;
        cout<<"end" <<"("<<end.getX()<<","<<end.getY()<<")"<<endl;
    }
};

class Rect
{
private:
    Point ul;
    Point lr;
public:
    void setUL(Point _ul)
    {
        ul=_ul;
    }
    void setLR(Point _lr)
    {
        lr=_lr;
    }
    Point getUL()
    {
        return ul;
    }
    Point getLR()
    {
        return lr;
    }
    Rect()
    {}
    Rect(int x1,int y1,int x2,int y2):ul(x1,y1),lr(x2,y2)
    {}
    Rect(Point _ul,Point _lr)
    {
        ul=_ul;
        lr=_lr;
    }
    Rect(const Rect& old)
    {
        ul=old.ul;
        lr=old.lr;
    }
    //~Rect(){cout<<"Rect dest";}
    void Print()
    {
        cout<<"Rectangle=>"<<endl;
        cout<<"ul" <<"("<<ul.getX()<<","<<ul.getY()<<")"<<endl;
        cout<<"lr" <<"("<<lr.getX()<<","<<lr.getY()<<")"<<endl;
    }
};


class Picture
{
private:
    Line* lptr;
    int lsize;
    Rect* rptr;
    int rsize;
public:
    Picture()
    {
        lptr=NULL;
        rptr=NULL;
        lsize=0;
        rsize=0;
    }
    //
    void setRects(Rect* _rptr,int _rsize)
    {
        rptr=_rptr;
        rsize=_rsize;
    }
    //
    void setLines(Line* _lptr,int _lsize)
    {
        lptr=_lptr;
        lsize=_lsize;
    }
    //
    void DoIt()
    {
        for(int i=0; i<lsize; i++)
        {
            lptr[i].Print();
        }
        cout<<"---------------"<<endl;
        for(int i=0; i<rsize; i++)
        {
            rptr[i].Print();
        }
    }

};
int main()
{


    Line larr[2]= {Line(1,2,3,4),Line(5,6,7,8)};

    Point point1(4,3),point2(5,6),point3(2,5),point4(1,4) ,point5(1,1),point6(2,2);

    Rect* rptr=new Rect[3];

    rptr[0].setLR(point1);
    rptr[0].setUL(point2);

    rptr[1].setLR(point3);
    rptr[1].setUL(point4);

    rptr[2].setLR(point5);
    rptr[2].setUL(point6);

    Picture p1;
    p1.setLines(larr,2);
    p1.setRects(rptr,3);

    p1.DoIt();
    return 0;
}
