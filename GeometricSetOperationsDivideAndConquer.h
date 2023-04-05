#ifndef GEOMETRICSETOPERTATIONSDIVIDEANDCONQUER_H
#define GEOMETRICSETOPERTATIONSDIVIDEANDCONQUER_H

#include "Point2D.h"
#include "Line2D.h"
#include "Region2D.h"

// Intersection
Point2D IntersectionDC(const Point2D& a, const Point2D& b);
// Line2D IntersectionDC(const Line2D& a, const Line2D& b);
// Region2D IntersectionDC(const Region2D& a, const Region2D& b);

// // Union
Point2D UnionDC(const Point2D& a, const Point2D& b);
// Line2D UnionDC(const Line2D& a, const Line2D& b);
// Region2D UnionDC(const Region2D& a, const Region2D& b);

// // Difference
// Point2D DifferenceDC(const Point2D& a, const Point2D& b);
// Line2D DifferenceDC(const Line2D& a, const Line2D& b);
// Region2D DifferenceDC(const Region2D& a, const Region2D& b);
#endif