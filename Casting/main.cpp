#include <iostream>

using namespace std;
class Point2D
 {
     int x;
     int y;
     public:
     void setX(int _x){x=_x;}
     void setY(int _y){y=_y;}
     int getY(){return y;}
     int getX(){return x;}
     Point2D(){x=y=0;}
     Point2D(int _x,int _y){x=_x;y=_y;}
     Point2D(int _num){x=y=_num;}
     ~Point2D(){cout<<"dest";}
     Point2D(const Point2D& old){x=old.x;y=old.y;}
     void print(){cout<<"("<<x<<","<<y<<")"<<endl;}
 };

 class Point3D
 {
     int x;
     int y;
     int z;
     public:
     void setX(int _x){x=_x;}
     void setY(int _y){y=_y;}
     void setZ(int _z){z=_z;}
     int getY(){return y;}
     int getX(){return x;}
     int getZ(){return z;}
     Point3D(){x=y=z=0;}
     Point3D(int _x,int _y,int _z){x=_x;y=_y;z=_z;}
     Point3D(const Point3D& old){x=old.x;y=old.y;z=old.z;}
     ~Point3D(){}
     void print()
     {
         cout<< "("<<x<<","<<y<<","<<z<<")"<<endl;
     }
     //cast to point2d  (point2D)obj
     operator Point2D()
     {
         Point2D retVal(this->x,this->y);
         return retVal;
     }
     //
 };
int main()
{
     Point2D p2d(3,4);   //8B
     p2d.print(); //(3,4)

     Point3D p3d(11,22,33); //12B
     p3d.print(); //(11,22,33)

     //casting
     Point2D obj=p3d;
     //Point2D obj=(Point2D)p3d;
     obj.print();  //(11,22)
    return 0;
}
