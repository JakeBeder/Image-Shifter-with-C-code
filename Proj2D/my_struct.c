#include <prototypes.h>

void InitializeCircle(struct Shape*circle, double radius, double originX, double originY){
	circle ->ft.GetArea = GetCircleArea;
	circle->ft.GetBoundingBox = GetCircleBoundingBox;
	circle->su.circle.originX = originX;
	circle->su.circle.originY = originY;
	circle->su.circle.radius = radius;
	circle->st = circ;
};

void InitializeRectangle(struct Shape*rectangle, double minX, double maxX, double minY, double maxY){
	
	rectangle->ft.GetArea = GetRectangleArea;
	rectangle->ft.GetBoundingBox = GetRectangleBoundingBox;
	rectangle->su.rectangle.minX = minX;
	rectangle->su.rectangle.maxX = maxX;
	rectangle->su.rectangle.minY = minY;
	rectangle->su.rectangle.maxY = maxY;
	rectangle->st = rect;
};

void InitializeTriangle(struct Shape*triangle, double pt1X, double pt2X, double minY, double maxY){

	triangle->ft.GetArea = GetTriangleArea;
	triangle->ft.GetBoundingBox = GetTriangleBoundingBox;
	triangle->su.triangle.pt1X = pt1X;
	triangle->su.triangle.pt2X = pt2X;
	triangle->su.triangle.minY = minY;
	triangle->su.triangle.maxY = maxY;
	triangle ->st = tri;
};
double GetCircleArea(struct Shape*circle){
	return 3.14159 * circle->su.circle.radius * circle->su.circle. radius;
};

double GetRectangleArea(struct Shape*rectangle){
	return (rectangle->su.rectangle.maxX - rectangle->su.rectangle.minX) * (rectangle->su.rectangle.maxY - rectangle->su.rectangle.minY);
};

double GetTriangleArea(struct Shape*triangle){
	return (triangle->su.triangle.pt2X - triangle->su.triangle.pt1X) * (triangle->su.triangle.maxY - triangle->su.triangle.minY)/2;
};


void GetCircleBoundingBox(struct Shape* circle, double *bbox){
	bbox[0] = circle->su.circle.originX - circle->su.circle.radius; 
	bbox[1] = circle->su.circle.originX + circle->su.circle.radius;
	bbox[2] = circle->su.circle.originY - circle->su.circle.radius;
	bbox[3] = circle->su.circle.originY + circle->su.circle.radius;
};

void GetRectangleBoundingBox(struct Shape*rectangle, double *bbox){
	bbox[0] = rectangle->su.rectangle.minX;
	bbox[1] = rectangle->su.rectangle.maxX;
	bbox[2] = rectangle->su.rectangle.minY;
	bbox[3] = rectangle->su.rectangle.maxY;
};

void GetTriangleBoundingBox(struct Shape* triangle, double *bbox){
	bbox[0] = triangle->su.triangle.pt1X;
	bbox[1] = triangle->su.triangle.pt2X;
	bbox[2] = triangle->su.triangle.minY;
	bbox[3] = triangle->su.triangle.maxY;
};


