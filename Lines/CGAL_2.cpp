#include <iostream> //cpp header
#include <fstream>  //cpp header for file handling
#include <boost/format.hpp>
#include <QtGui>  // QT header for GUI 
#include <CGAL/Qt/GraphicsViewNavigation.h> // CGAL header for linking cgal and qgraphicsView
#include <QLineF>
#include <QRectF>
#include <QApplication> //QT header for creating a QT GUI Application
#include <QGraphicsScene> // QT header for 2D graphical items
#include <QGraphicsView>  // QT header for displaying the contents of a scene
#include <iostream>
#include <QPen> // QT header for colors and styles
#include <CGAL/Cartesian.h> //CGAL header for Cartesian coordinates
#include <CGAL/Point_2.h> //CGAL header for 2D points
using namespace std;
//Define datatype Point_2
typedef CGAL::Cartesian<double> K; // define type K as Cartesian coordinate
typedef K::Point_2 Point_2; // define type Point_2 as 2D cartesian point.

int main(int argc, char **argv)
{
    Point_2 p1,p2; // declare the variable of type point_2
    std::ifstream iFile("input3.txt", std::ios::in); // opening the file
    
	QApplication app(argc, argv); // create a new QT GUI application


    QGraphicsScene scene;  // create a QT scene to display point

    scene.setSceneRect(0,0, 500, 300); // set scene size
     
    QPen pen; //Declare a variable of type pen
    pen.setColor(Qt::red); //setting the color of pen as red
	int a = 2;
	while(iFile>>p1)
	{
		iFile>>p2;
		scene.addLine(QLineF(p1.x(),p1.y(),p2.x(),p2.y()));
	}
	// display the scene
    QGraphicsView* view = new QGraphicsView(&scene);
    CGAL::Qt::GraphicsViewNavigation navigation;
    view->installEventFilter(&navigation);
    view->viewport()->installEventFilter(&navigation);
    view->setRenderHint(QPainter::Antialiasing);

    view->show();
    return app.exec();
}

