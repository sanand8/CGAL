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

typedef CGAL::Cartesian < double > K;
typedef K::Point_2 Point_2;

Point_2 Intersection (Point_2 a, Point_2 b, Point_2 c, Point_2 d)
{
  // Line AB represented as a1x + b1y = c1 
  double a1 = b.y () - a.y ();
  double b1 = a.x () - b.x ();
  double c1 = a1 * (a.x ()) + b1 * (a.y ());

  // Line CD represented as a2x + b2y = c2 
  double
    a2 = d.y () - c.y ();
  double
    b2 = c.x () - d.x ();
  double
    c2 = a2 * (c.x ()) + b2 * (c.y ());

  double
    determinant = a1 * b2 - a2 * b1;

  if (determinant == 0)
    {
      // The lines are parallel. This is simplified 
      // by returning a pair of FLT_MAX 
      double
	x = FLT_MAX;
      double
	y = FLT_MAX;
      Point_2
      p (x, y);

      return p;
    }
  else
    {
      double
	x = (b2 * c1 - b1 * c2) / determinant;
      double
	y = (a1 * c2 - a2 * c1) / determinant;
      Point_2
      p (x, y);
      return p;
    }
}

int
main (int argc, char **argv)
{

  QPen
    pen;
  pen.setColor (Qt::blue);
  Point_2
    p1,
    p2;
  vector < Point_2 > vec1;
  vector < Point_2 > vec2;
  std::ifstream iFile ("input3.txt", std::ios::in);
  int
    count = 0;
  while (iFile >> p1)
    {
      vec1.push_back (p1);
      iFile >> p2;
      vec2.push_back (p2);
      count++;
    }

  for (int i = 0; i < count - 1; i++)
    {
      for (int j = i + 1; j < count; j++)
	{
	  Point_2
	    intersected_point = Intersection (vec1[i], vec2[i], vec1[j], vec2[j]);

	  QApplication
	  app (argc, argv);	//create qt app
	  QGraphicsScene
	    scene;		// establish a scene
	  scene.setSceneRect (0, 0, 500, 500);
	  scene.
	    addLine (QLineF (vec1[i].x (), vec1[i].y (), vec2[i].x (), vec2[i].y ()),
		     pen);
	  scene.
	    addLine (QLineF (vec1[j].x (), vec1[j].y (), vec2[j].x (), vec2[j].y ()),
		     pen);

	  double
	    x = intersected_point.x ();
	  double
	    y = intersected_point.y ();

	  if (x == FLT_MAX)
	    {
	      scene.addText ("Lines doesn't intersect");
	    }
	  else
	    {
	      if (x >= min (vec1[i].x (), vec2[i].x ())
		  && x <= max (vec1[i].x (), vec2[i].x ())
		  && y >= min (vec1[i].y (), vec2[i].y ())
		  && y <= max (vec1[i].y (), vec2[i].y ()))
		{
		  std::ostringstream ss;
		  ss << "Lines intersect at (" << x << "," << y << ")" <<
		    endl;
		  string
		    s = ss.str ();
		  scene.addText (s.c_str ());
		}
	      else
		{
		  scene.addText ("Lines do not intersect !");
		}
	    }

	  QGraphicsView *
	    view = new QGraphicsView (&scene);
	  CGAL::Qt::GraphicsViewNavigation navigation;
	  view->installEventFilter (&navigation);
	  view->viewport ()->installEventFilter (&navigation);
	  view->setRenderHint (QPainter::Antialiasing);

	  view->show ();
	  app.exec ();
	}
    }

  return 0;
}

