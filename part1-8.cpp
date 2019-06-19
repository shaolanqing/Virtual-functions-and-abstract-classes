/*8、 虚函数和抽象类
定义一个抽象类shape，包括公有的计算面积area函数，计算体积volume函数，输出基本信息函数printinfo（三个函数均为纯虚函数）。
从shape公有派生point类，增加私有数据成员x,y坐标，以及构造函数，析构函数。从point公有派生circle类，增加私有数据成员
半径r，以及构造函数，析构函数。从circle公有派生cylinder类，增加私有数据成员高度h，以及构造函数，析构函数。
（在定义三个派生类的过程中，自己考虑需要重定义哪个虚函数）。在main函数中，定义shape类的指针，
指向派生类的对象，输出三类对象的基本信息，面积，体积；（将shape指针改为引用再尝试）。*/
#include<iostream>
#include<cmath>
using namespace std;
class Shape
{	
	public:
		Shape()
		{
		}
	    
		virtual double Area()=0;    //纯虚函数
	
		virtual double Volume()=0;
	
        virtual void printinfo()=0;
        virtual ~Shape()          //虚函数 
        {
           cout<<"shape is construction!"<<endl;	
		}
      
};
class Point:public Shape           //父类中定义的纯虚函数，子类继承纯虚函数需全部继承 
{
	private:
		float x,y;
	public:
		Point()
		{
			x=0;
			y=0;
		}
		Point(float xx,float yy)
		{
			x=xx;
			y=yy;
		}
		double Area()          //子类继承父类的纯虚函数，需要全部继承
		{
			return 0;
		}
        double Volume()
		{
			return 0;
		}
	     void printinfo()
	     {
	     	cout<<"(x,y):"<<"("<<x<<","<<y<<")"<<endl;
		 }
		float  getR()    //得到坐标与原点的距离 
		 {
		 	float r;
		 	r=sqrt(x*x+y*y);
		 	return r;
		 }

	   virtual 	~Point()
		{
			cout<<"Point is construction!"<<endl;
		}
};

class Circle:public Point
{
   private:
   	   float r;
   	   const double pi;          //定义常数据成员pi 
   public: 
   	Circle():pi(3.14)          //在构造函数列表中初始化pi 
   	{
   		r=0;
	}
	Circle(float rr):pi(3.14)
	{
		r=rr;
		
	}
	double Area()        //得到圆的面积 
	{ 
		double area;
		area=pi*r*r;
		return area;
	}
	double Volume() 
	{
		return 0;
	}
	void printinfo()
	{
		cout<<"Circle's area: "<< Area()<<endl;
		cout<<"Circle's voiume:"<<Volume()<<endl;
	}
	virtual ~Circle()
	{
		cout<<"Circle is construction!"<<endl;
	}
		
};			
class Cylinder:public Circle    //圆柱 
{
	private:
		float h;
    public:
    	Cylinder(double r):Circle(r)
    	{
    		h=0;
    		
		}
		Cylinder(float hh,double r):Circle(r)
		{
			h=hh;
		}
		double Area()
		{
			 return Circle::Area();
		}
		double Volume()             //得到圆柱的体积 
		{
			double v;
			v= Area()*h;
			return v;
		}
		void printinfo()
		{
            cout<<"the Cylinder's area:"<<Area()<<endl;
			cout<<"the Cylinder's Volume:"<<Volume()<<endl;
		}
		 
		virtual ~Cylinder()
		{
			cout<<"Cylinder is construction!"<<endl;
		}
		 	
};		
int main()
{
	 /*利用指针
	 Point p(3,9);
	 Shape *s;
	 s=&p;
	 cout<<"point's area:"<<s->Area()<<endl;
	 cout<<"volume:"<<s->Volume()<<endl;
	 s->printinfo();
	 cout<<"-------------------------------"<<endl;
	 Circle c(4);
	 s=&c;
	 cout<<"circle's area:"<<s->Area()<<endl;
	 cout<<"Circle's volume:"<<s->Volume()<<endl;
	 s->printinfo();
	 cout<<"----------------------------------"<<endl;
	 Cylinder cy(6,4);   //高为6，半径为4
	 s=&cy;
	 cout<<"cylinder's area:"<<s->Area()<<endl;
	 cout<<"cylinder's volume:"<<s->Volume()<<endl;
	 s->printinfo();
	 */


	//利用引用
	Point p(3,9);    
	 Shape &s=p;
	 
	 cout<<"point's area:"<<s.Area()<<endl;
	 cout<<"volume:"<<s.Volume()<<endl;
	 s.printinfo();
	 cout<<"-------------------------------"<<endl;
	 Circle c(4);
	 Shape &s1=c;
	 cout<<"circle's area:"<<s1.Area()<<endl;
	 cout<<"Circle's volume:"<<s1.Volume()<<endl;
	 s1.printinfo();
	 cout<<"----------------------------------"<<endl;
	 Cylinder cy(6,4);   //高为6，半径为4
	 Shape &s2=cy;
	 cout<<"cylinder's area:"<<s2.Area()<<endl;
	 cout<<"cylinder's volume:"<<s2.Volume()<<endl;
	 s2.printinfo();	
	return 0;
}
	
		
		
		
		
			


	
