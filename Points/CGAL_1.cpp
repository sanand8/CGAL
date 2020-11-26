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
#include <QPen> // QT header for colors and styles
#include <CGAL/Cartesian.h> //CGAL header for Cartesian coordinates
#include <CGAL/Point_2.h> //CGAL header for 2D points

//Define datatype Point_2
typedef CGAL::Cartesian<double> K; // define type K as Cartesian coordinate
typedef K::Point_2 Point_2; // define type Point_2 as 2D cartesian point.

int main(int argc, char **argv)
{
    Point_2 p; // declare the variable of type point_2
    std::ifstream iFile("input3.txt", std::ios::in); // opening the file
    QApplication app(argc, argv); // create a new QT GUI application


    QGraphicsScene scene;  // create a QT scene to display point

    scene.setSceneRect(0,0, 500, 300); // set scene size
     
    QPen pen; //Declare a variable of type pen
    pen.setColor(Qt::red); //setting the color of pen as red

    while(iFile >> p)   // read the input points into variable p
	scene.addEllipse(p.x(),p.y(),10,10,pen,QBrush(Qt::red));
	//add a point in the QT window by drawing circle of small diameter

	// display the scene
    QGraphicsView* view = new QGraphicsView(&scene);
    CGAL::Qt::GraphicsViewNavigation navigation;
    view->installEventFilter(&navigation);
    view->viewport()->installEventFilter(&navigation);
    view->setRenderHint(QPainter::Antialiasing);

    view->show();
    return app.exec();
}

