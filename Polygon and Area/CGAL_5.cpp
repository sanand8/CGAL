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



int main(int argc, char **argv)
{   
    QApplication app(argc, argv); //create qt app

    QGraphicsScene scene; // establish a scene
    scene.setSceneRect(0,0, 500, 500);
    
    Point_2 p;
    std::ifstream iFile("input1.txt", std::ios::in);

    QPen pen;
    pen.setColor(Qt::blue);

    vector<Point_2> vec;
    int count = 0;
    while(iFile >> p) {
	count++;
	vec.push_back(p);
    }

	double area = 0.0;
	for(int i=0;i<count;i++) {
		int j = i+1;
		if(j == count)
			j = 0; 
		scene.addLine(vec[i].x(), vec[i].y(), vec[j].x(), vec[j].y(), pen);
		area += (vec[i].x() + vec[j].x()) * (vec[i].y() - vec[j].y());
		
	}

	std::ostringstream ss;
	ss << "Area is " << abs(area/2.0) << endl;	
	string s = ss.str();
	scene.addText(s.c_str());

    QGraphicsView* view = new QGraphicsView(&scene);
    CGAL::Qt::GraphicsViewNavigation navigation;
    view->installEventFilter(&navigation);
    view->viewport()->installEventFilter(&navigation);
    view->setRenderHint(QPainter::Antialiasing);

    view->show();
    return app.exec();
}

