
typedef struct point POINT;

typedef struct circle CIRCLE;

CIRCLE* createCircle(float rad, float cX, float cY);

void accessCoordinates(CIRCLE* c);

void calcArea(CIRCLE* c);

void checkPosition(POINT* p, CIRCLE* c);

POINT* definePoint(float x, float y);

void freeMemory(CIRCLE* c);
