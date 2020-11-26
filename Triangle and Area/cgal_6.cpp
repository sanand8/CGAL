#include <bits/stdc++.h>
#include <fstream> //cpp header for file handling
#include <QtGui>
#include <CGAL/Qt/GraphicsViewNavigation.h>
#include <QApplication> 
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem> 
#include <QPen> //QT header for colors and styles
#include <CGAL/Cartesian.h> //CGAL header for Cartesian Coordinates
#include <CGAL/Point_2.h> //CGAL header for 2D points

using namespace std;
typedef CGAL::Cartesian<double> K;
typedef K::Point_2 Point_2;

struct Vertex {

	double Coordinates[2];
	bool ear;
	struct Vertex * next;
	struct Vertex * prev;
};

typedef struct Vertex *vertices;

vertices newVertex() {
	vertices pt = (struct Vertex*) malloc(sizeof(struct Vertex));
	if(pt==NULL)
		exit(0);
	return pt;
}

struct Vertex * head = NULL;

//2*Area of Triangle
double Area(Point_2 p1, Point_2 p2, Point_2 p3) {
    return (p2.x() - p1.x()) * (p3.y() - p1.y()) -
	   (p3.x() - p1.x()) * (p2.y() - p1.y()); 
	
}
//boolean XOR
bool XOR(bool a, bool b) {
    if((a&&!b)||(!a&&b))
	return true;
    else
	return false;
}

//LeftOp operation
bool LeftOp(Point_2 p1, Point_2 p2, Point_2 p3) {
    return Area(p1, p2, p3) > 0.0;
}

//LeftOnOp operation
bool LeftOnOp(Point_2 p1, Point_2 p2, Point_2 p3) {
    return Area(p1, p2, p3) >= 0.0;
}

//Collinear check
bool Collinear(Point_2 p1, Point_2 p2, Point_2 p3) {
    return Area(p1, p2, p3) == 0.0;
}

//for improper intersection
bool Between(Point_2 p1, Point_2 p2, Point_2 p3) {
    if(!Collinear(p1, p2, p3))
	return false;
    else
    {
	if(p1.x()!=p2.x())
	    return ((p1.x() <= p3.x()) && (p3.x()<= p2.x())) ||
		   ((p1.x() >= p3.x()) && (p3.x()>= p2.x()));
	else
	    return ((p1.y() <= p3.y()) && (p3.y()<= p2.y())) ||
		   ((p1.y() >= p3.y()) && (p3.y()>= p2.y()));
    }
}
 

//Proper Intersection
bool IntersectProp(Point_2 p1, Point_2 p2, Point_2 p3, Point_2 p4) {
     if(Collinear(p1, p2, p3) ||
        Collinear(p1, p2, p4) ||
	Collinear(p3, p4, p1) ||
	Collinear(p3, p4, p2))
	return false;

     return XOR(LeftOp(p1, p2, p3), LeftOp(p1, p2, p4)) &&
	    XOR(LeftOp(p3, p4, p1), LeftOp(p3, p4, p2));
}

//Intersection
bool Intersect(Point_2 p1, Point_2 p2, Point_2 p3, Point_2 p4) {
    if(IntersectProp(p1, p2, p3, p4))
	return true;
    else if(Between(p1, p2, p3) ||
	    Between(p1, p2, p4) ||
	    Between(p3, p4, p1) ||
	    Between(p3, p4, p2))
	return true;
    else return false;
}

bool Diagonalie(vertices a, vertices b) {

    vertices c,c1;
    c = head;

    do
    {
		c1 = c->next;
        Point_2 p1(a->Coordinates[0],a->Coordinates[1]);
        Point_2 p2(b->Coordinates[0],b->Coordinates[1]);
        Point_2 p3(c->Coordinates[0],c->Coordinates[1]);
        Point_2 p4(c1->Coordinates[0],c1->Coordinates[1]);

		if((c!=a) && (c1!=a) && 
		   (c!=b) && (c1!=b) && 
		   Intersect(p1, p2, p3, p4)
		   )
			return false;
		c = c->next;
	} while(c!=head);
	return true;

}

bool InCone(vertices a, vertices b) {

   vertices a0,a1;
   //a0,a,a1 are cop1.x()<<" "<<p1.y()<<" "nsequtive
   a1=a->next;
   a0=a->prev;
    Point_2 p1(a->Coordinates[0],a->Coordinates[1]);
    Point_2 p2(b->Coordinates[0],b->Coordinates[1]);
    Point_2 p3(a0->Coordinates[0],a0->Coordinates[1]);            

    Point_2 p4(a1->Coordinates[0],a1->Coordinates[1]);
    //cout<<p1.x()<<" "<<p1.y()<<" "<<p2.x()<<" "<<p2.y()<<" "<<p3.x()<<" "<<p3.y()<<" "<<p4.x()<<" "<<p4.y()<<endl;


   //convex case
   if( LeftOnOp(p1, p4, p3))
   	{   //cout<<"convexcase"<<endl;
        return LeftOp(p1, p2, p3) &&
   		  	   LeftOp(p2, p1, p4);
    }
   else { //cout<<"reflexcase\n";
   	return !( LeftOnOp(p1, p2, p4) &&
   			  LeftOnOp(p2, p1, p3)
   			);}
}

bool Diagonal(vertices a, vertices b) {
    bool p1, p2, p3;
    p1 = InCone(a,b);
    p2 = InCone(b, a);
    p3 = Diagonalie(a, b);
    //cout<<a->Coordinates[0]<<" "<<b->Coordinates[0]<<" "<<p1<<" "<<p2<<" "<<p3<<endl;
    return InCone(a,b) && InCone(b, a) && Diagonalie(a, b);

}

void EarInit(void) {

    vertices v0,v1,v2; //consequtive
    v1=head;
    do
    {
    	v2 = v1->next;
    	v0 = v1->prev;
        //cout<<v0->Coordinates[0]<<" "<<v1->Coordinates[0]<<" "<<v2->Coordinates[0]<<endl;
    	v1->ear = Diagonal(v0,v2);
    	v1=v1->next;
    } while(v1!=head);
    return;
}




int main(int argc, char **argv)
{
    Point_2 p1; //variable of type Point_2;
    std::ifstream iFile("input3.txt", std::ios::in); //opening the file for reading

    QApplication app(argc, argv);
	
    QGraphicsScene scene; 
    scene.setSceneRect(0,0, 500, 300);

    QPen pen; //variable of type pen
    pen.setColor(Qt::red); //setting the color as red

    QColor colors[10] = {Qt::red,Qt::black,Qt::blue,Qt::green,Qt::black,Qt::darkGreen,Qt::yellow,Qt::darkRed,Qt::darkBlue,Qt::gray};

    
    Point_2 lowright;
    iFile >> p1;
    lowright = p1;
    vector<Point_2> polygonv;int index = 0;
    polygonv.push_back(p1);
    while(iFile >> p1)
    {
        polygonv.push_back(p1);
        if(lowright.x()>p1.x())
        {
            lowright=p1;
            index=polygonv.size()-1;
        }
        else if(lowright.x() == p1.x())
        {
            if(lowright.y()<p1.y())
            {
                lowright=p1;
                index=polygonv.size()-1;
            }
        }
    }
    int pr,nx;
    if(index==0)
        pr=polygonv.size()-1;
    else
        pr=index-1;
    nx=(index+1)%polygonv.size();
    bool counterclockwise;
    counterclockwise = LeftOp(polygonv[pr],lowright,polygonv[nx]);
    if(counterclockwise)
    {
        struct Vertex * ptr;
        ptr = (struct Vertex *) malloc(sizeof(struct Vertex));
        ptr->Coordinates[0]=polygonv[0].x();
        ptr->Coordinates[1]=polygonv[0].y();
        head = ptr;
        vertices mvptr = ptr;
        for(int i=1;i<polygonv.size();i++)
        {
            ptr = (struct Vertex *) malloc(sizeof(struct Vertex));
    
            p1=polygonv[i];
            ptr->Coordinates[0]=p1.x();
            ptr->Coordinates[1]=p1.y();
            mvptr->next=ptr;
            ptr->prev=mvptr;
            mvptr=ptr;
        }
        mvptr->next=head;
        head->prev=mvptr;
    }
    else
    {
        struct Vertex * ptr;
        ptr = (struct Vertex *) malloc(sizeof(struct Vertex));
        ptr->Coordinates[0]=polygonv[polygonv.size()-1].x();
        ptr->Coordinates[1]=polygonv[polygonv.size()-1].y();
        head = ptr;
        vertices mvptr = ptr;
        for(int i=polygonv.size()-2;i>=0;i--)
        {
            ptr = (struct Vertex *) malloc(sizeof(struct Vertex));
    
            p1=polygonv[i];
            ptr->Coordinates[0]=p1.x();
            ptr->Coordinates[1]=p1.y();
            mvptr->next=ptr;
            ptr->prev=mvptr;
            mvptr=ptr;
        }
        mvptr->next=head;
        head->prev=mvptr;

    }
    QPolygonF polygon;
    for(int i=0;i<polygonv.size();i++)
    {
        polygon << QPointF(polygonv[i].x(), polygonv[i].y());
    }
    scene.addPolygon(polygon);
    vertices v0,v1,v2,v3,v4;
    
    EarInit();
    
    vertices mvptr = head;
    do {
        cout<<mvptr->Coordinates[0]<<" "<<mvptr->Coordinates[1]<<" "<<mvptr->ear<<endl;
        mvptr=mvptr->next;
    } while(mvptr!=head);
    int n = polygonv.size();
    while(n>3)
    {
    	v2 = head;
    	do {
	    	if(v2->ear)
	    	{
	    		v3 = v2->next; v4 = v3->next;
	    		v1 = v2->prev; v0 = v1->prev;

	    		//v1-v3 is diagonal
	    		QPolygonF triangle;
	    		triangle << QPointF(v1->Coordinates[0], v1->Coordinates[1]);
	    		triangle << QPointF(v2->Coordinates[0], v2->Coordinates[1]);
	    		triangle << QPointF(v3->Coordinates[0], v3->Coordinates[1]);
                scene.addLine(QLine(v1->Coordinates[0], v1->Coordinates[1],v3->Coordinates[0], v3->Coordinates[1]));
	    		scene.addPolygon(triangle, pen, QBrush(colors[n%10]));

                v1->ear=Diagonal(v0, v3);
                v3->ear=Diagonal(v1, v4);

	    		v1->next = v3;
	    		v3->prev = v1;
	    		head = v3;
	    		n--;
	    		break;
	    	}
	    	v2 = v2->next;
	    } while(v2!=head);
    	
    }
    
    string str = "Triangulation";
    QGraphicsTextItem *text = scene.addText(str.c_str());
    text->setPos(5, 280);

    QGraphicsView* view = new QGraphicsView(&scene);
    CGAL::Qt::GraphicsViewNavigation navigation;
    view->installEventFilter(&navigation);
    view->viewport()->installEventFilter(&navigation);
    view->setRenderHint(QPainter::Antialiasing);

    view->show();
    return app.exec();
}

