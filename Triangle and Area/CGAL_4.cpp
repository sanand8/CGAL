#include <iostream>
#include <fstream>
#include <QtGui>
#include <CGAL/Qt/GraphicsViewNavigation.h>
#include <QApplication> 
#include <QGraphicsScene>
#include <QGraphicsView> 
#include <CGAL/Cartesian.h>
#include <CGAL/Point_2.h>
#include <QPen>
#include <QLineF>
#include <string>

using namespace std;

typedef CGAL::Cartesian<double> K;
typedef K::Point_2 Point_2;

double Area(double a, double b, double c) {
	double s = (a+b+c)/2;
	return pow(s*(s-a)*(s-b)*(s-c), 0.5);
}

double Distance(Point_2 p1, Point_2 p2) {
	return pow(pow(p1.x()-p2.x(), 2) + pow(p1.y()-p2.y(), 2), 0.5);
}

int main(int argc, char **argv)
{   
    QApplication app(argc, argv); //create qt app

    QGraphicsScene scene; // establish a scene
    scene.setSceneRect(0,0, 500, 500);
    
    Point_2 p;
    std::ifstream iFile("input1.txt", std::ios::in);

    QPen pen;
    pen.setColor(Qt::red);

    vector<Point_2> vertex;
    while(iFile >> p) {
	vertex.push_back(p);
    }

	double D1 = Distance(vertex[0], vertex[1]);
	double D2 = Distance(vertex[1], vertex[2]);
	double D3 = Distance(vertex[2], vertex[0]);

	for(int i=0;i<2;i++) {
		for(int j=i+1;j<3;j++) {
			scene.addLine(vertex[i].x(), vertex[i].y(), vertex[j].x(), vertex[j].y(), pen);
		}
	}

	if((D1+D2 < D3) || (D2+D3 < D1) || (D3+D1 < D2)) {
		scene.addText("GIVEN INPUT WILL NOT FORM A TRIANGLE");
	}
	else {
		double area = Area(D1, D2, D3);
		std::ostringstream ss;
		ss << "Area is " << area << endl;	
		string s = ss.str();
		scene.addText(s.c_str());
	}

    QGraphicsView* view = new QGraphicsView(&scene);
    CGAL::Qt::GraphicsViewNavigation navigation;
    view->installEventFilter(&navigation);
    view->viewport()->installEventFilter(&navigation);
    view->setRenderHint(QPainter::Antialiasing);

    view->show();
    return app.exec();
}

