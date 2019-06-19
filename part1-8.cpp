/*8�� �麯���ͳ�����
����һ��������shape���������еļ������area�������������volume���������������Ϣ����printinfo������������Ϊ���麯������
��shape��������point�࣬����˽�����ݳ�Աx,y���꣬�Լ����캯����������������point��������circle�࣬����˽�����ݳ�Ա
�뾶r���Լ����캯����������������circle��������cylinder�࣬����˽�����ݳ�Ա�߶�h���Լ����캯��������������
���ڶ�������������Ĺ����У��Լ�������Ҫ�ض����ĸ��麯��������main�����У�����shape���ָ�룬
ָ��������Ķ�������������Ļ�����Ϣ����������������shapeָ���Ϊ�����ٳ��ԣ���*/
#include<iostream>
#include<cmath>
using namespace std;
class Shape
{	
	public:
		Shape()
		{
		}
	    
		virtual double Area()=0;    //���麯��
	
		virtual double Volume()=0;
	
        virtual void printinfo()=0;
        virtual ~Shape()          //�麯�� 
        {
           cout<<"shape is construction!"<<endl;	
		}
      
};
class Point:public Shape           //�����ж���Ĵ��麯��������̳д��麯����ȫ���̳� 
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
		double Area()          //����̳и���Ĵ��麯������Ҫȫ���̳�
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
		float  getR()    //�õ�������ԭ��ľ��� 
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
   	   const double pi;          //���峣���ݳ�Աpi 
   public: 
   	Circle():pi(3.14)          //�ڹ��캯���б��г�ʼ��pi 
   	{
   		r=0;
	}
	Circle(float rr):pi(3.14)
	{
		r=rr;
		
	}
	double Area()        //�õ�Բ����� 
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
class Cylinder:public Circle    //Բ�� 
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
		double Volume()             //�õ�Բ������� 
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
	 /*����ָ��
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
	 Cylinder cy(6,4);   //��Ϊ6���뾶Ϊ4
	 s=&cy;
	 cout<<"cylinder's area:"<<s->Area()<<endl;
	 cout<<"cylinder's volume:"<<s->Volume()<<endl;
	 s->printinfo();
	 */


	//��������
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
	 Cylinder cy(6,4);   //��Ϊ6���뾶Ϊ4
	 Shape &s2=cy;
	 cout<<"cylinder's area:"<<s2.Area()<<endl;
	 cout<<"cylinder's volume:"<<s2.Volume()<<endl;
	 s2.printinfo();	
	return 0;
}
	
		
		
		
		
			


	
