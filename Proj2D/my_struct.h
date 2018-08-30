struct Shape;

typedef struct {
	double minX;
	double maxX;	
	double minY;	
	double maxY;	
} Rectangle;

typedef struct {
	double originX;
	double originY;
	double radius;
} Circle;

typedef struct {

	double pt1X;
	double pt2X;
	double minY;
	double maxY;
} Triangle;

typedef union {
	Rectangle rectangle;
	Circle circle;
	Triangle triangle;	
} ShapeUnion;

typedef struct {
	double (*GetArea)(struct Shape*);
	void (*GetBoundingBox)(struct Shape*, double *);	
} FunctionTable;

typedef enum{
	rect,
	circ,
	tri
} ShapeType;

struct Shape {
	ShapeUnion su;
	FunctionTable ft;
	ShapeType st;
};	
