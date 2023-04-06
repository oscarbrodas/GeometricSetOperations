#ifndef GEOMETRICSETOPERTATIONSPOINTSDIVIDEANDCONQUER_H
#define GEOMETRICSETOPERTATIONSPOINTSDIVIDEANDCONQUER_H

#include "Point2D.h"

// Intersection
Point2D IntersectionDC(const Point2D& a, const Point2D& b);

// Union
Point2D UnionDC(const Point2D& a, const Point2D& b);

// Difference
Point2D DifferenceDC(const Point2D& a, const Point2D& b);
#endif