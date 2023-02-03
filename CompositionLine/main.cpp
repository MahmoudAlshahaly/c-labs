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

class Line
{
    private:
    Point start;
    Point end;
    public:
    void setStart(Point _start){start=_start;}
    void setEnd(Point _end){end=_end;}
    Point getStart(){return start;}
    Point getEnd(){return end;}
    //
    Line()
    {
        //compiler
        //start x0 y0   //end x0 y0
        //
        //start.x=0; start.y=0;//Compile Error Inaccessible
        //useless code
        //start.setX(0);
        //start.setY(0);
        //end.setX(0);
        //end.setY(0);
    }
    Line(int x1,int y1,int x2,int y2)
    {
        //#Jump to Point class  #2
        //Compiler start x0 y0    end x0 y0
        //
        start.setX(x1);
        start.setY(y1);
        //Compiler start x1 y2    end x0 y0
        end.setX(x2);
        end.setY(y2);
        //Compiler start x1 y2    end x3 y4
        //#Jump to Point class  #6
    }
    Line(Point _start,Point _end)
    {start=_start;end=_end;}
    Line(const Line& old){start=old.start;end=old.end;}
    ~Line(){cout<<"Line dest"<<endl;}
    void Print()
    {
        cout<<"Line=>"<<endl;
        cout<<"start" <<"("<<start.getX()<<","<<start.getY()<<")"<<endl;
        cout<<"end" <<"("<<end.getX()<<","<<end.getY()<<")"<<endl;
    }
};

int main()
{
    Line l1;  //Debugging
    l1.Print();
    Line l2(1,2,3,4);
    l2.Print();

    Point p1(3,4),p2(5,6);
    Line l3(p1,p2);
    l3.Print();
    return 0;

}
