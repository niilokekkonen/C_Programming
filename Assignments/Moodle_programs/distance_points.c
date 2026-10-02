#include <math.h>

struct point 
{ 
    double x; 
    double y; 
};


double distance(struct point a, struct point b);

double distance(struct point a, struct point b)
{
    double x1 = a.x;
    double y1 = a.y;
    double x2 = b.x;
    double y2 = b.y;
    double x_diffsq = pow((x2 - x1), 2);
    double y_diffsq = pow((y2 - y1), 2);
    double in_par = (x_diffsq + y_diffsq); 
    double distance = sqrt(in_par);
    return distance;
}


