#include "GeometricSetOperationsDivideAndConquer.h"
#include "iostream"

std::vector<SimplePoint2D>::iterator BinarySplitX(std::vector<SimplePoint2D>::iterator begin, std::vector<SimplePoint2D>::iterator end, const Number& split)
{
    if (begin == end)
    {
        return begin;
    }
    else
    {
        std::vector<SimplePoint2D>::iterator mid = begin + (end - begin)/2;
        if (mid->x < split)
        {
            return BinarySplitX(++mid, end, split);
        }
        else if (mid->x > split)
        {
            return BinarySplitX(begin, mid, split);
        }
        else // mid->x == split
        {
            while (mid->x == split)
                mid++;
            return mid;
        }
    }
}
std::vector<SimplePoint2D>::iterator BinarySplitY(std::vector<SimplePoint2D>::iterator begin, std::vector<SimplePoint2D>::iterator end, const Number& split)
{
    if (begin == end)
    {
        return begin;
    }
    else
    {
        std::vector<SimplePoint2D>::iterator mid = begin + (end - begin)/2;
        if (mid->y < split)
        {
            return BinarySplitY(++mid, end, split);
        }
        else if (mid->y > split)
        {
            return BinarySplitY(begin, mid, split);
        }
        else // mid->y == split
        {
            while (mid->y == split)
                mid++;
            return mid;
        }
            
    }
}

// Compare (Handles intersection, union, or difference)
void CompareIntersection(std::vector<SimplePoint2D>::iterator aBegin, std::vector<SimplePoint2D>::iterator aEnd, std::vector<SimplePoint2D>::iterator bBegin,
                      std::vector<SimplePoint2D>::iterator bEnd, std::vector<SimplePoint2D>& intersectionPoints)
{
    Number zero = "0.0";
    Number two = "2.0";

    if ((aEnd - aBegin) <= 0 || (bEnd - bBegin) <= 0) // If one of the lists is empty
        return;

    std::vector<SimplePoint2D>::iterator aBack = aEnd;
    aBack--;
    std::vector<SimplePoint2D>::iterator bBack = bEnd;
    bBack--;

    Number aYMin = aBegin->y;
    Number bYMin = bBegin->y;
    Number aYMax = aBack->y;
    Number bYMax = bBack->y;

    Number yMin;
    Number yMax;

    if (aYMin >= bYMin)
        yMin = aYMin;
    else
        yMin = bYMin;
        
    if (aYMax <= bYMax)
        yMax = aYMax;
    else
        yMax = bYMax;

    if ((yMax - yMin) < zero) // Range has no possible intersection
        return;

    // if (aBegin->y != yMin)
    //     aBegin = BinarySplitY(aBegin, aEnd, yMin);
    // if (bBegin->y != yMin)
    //     bBegin = BinarySplitY(bBegin, bEnd, yMin);

    // if (aBack->y != yMax)
    //     aEnd = BinarySplitY(aBegin, aEnd, yMax);
    // if (bBack->y != yMax)
    //     bEnd = BinarySplitY(bBegin, bEnd, yMax);

    // aBack = aEnd;
    // aBack--;
    // bBack = bEnd;
    // bBack--;
    
    while (aBegin->y < yMin)
        aBegin++;
    while (bBegin->y < yMin)
        bBegin++;
    while (aBack->y > yMax)
    {
        aBack--;
        aEnd--;
    }
    while (bBack->y > yMax)
    {
        bBack--;
        bEnd--;
    }

    Number yRange = yMax - yMin;
    Number split = (yRange/two) + yMin; 

    // Base Case (yRange == 0), potential intersection
    if (aBegin->y == bBack->y && aBack->y == bBegin->y) // We have found an intersection point
     {
        intersectionPoints.push_back(*aBegin);
        return;
    }
    
    
    // Recurse Case
    std::vector<SimplePoint2D>::iterator aSplit = BinarySplitY(aBegin, aEnd, split);
    std::vector<SimplePoint2D>::iterator bSplit = BinarySplitY(bBegin, bEnd, split);

    CompareIntersection(aBegin, aSplit, bBegin, bSplit, intersectionPoints);
    CompareIntersection(aSplit, aEnd, bSplit, bEnd, intersectionPoints);
}

// Divide and Conquer (Recursion)
void DivideAndConquer(std::vector<SimplePoint2D>::iterator aBegin, std::vector<SimplePoint2D>::iterator aEnd, std::vector<SimplePoint2D>::iterator bBegin,
                      std::vector<SimplePoint2D>::iterator bEnd, std::vector<SimplePoint2D>& intersectionPoints, 
                      void (*func)(std::vector<SimplePoint2D>::iterator, std::vector<SimplePoint2D>::iterator, std::vector<SimplePoint2D>::iterator, std::vector<SimplePoint2D>::iterator, std::vector<SimplePoint2D>&))
{

    Number zero = "0.0";
    Number two = "2.0";

    std::vector<SimplePoint2D>::iterator aBack = aEnd;
    aBack--;
    std::vector<SimplePoint2D>::iterator bBack = bEnd;
    bBack--;

    Number aXMin = aBegin->x;
    Number bXMin = bBegin->x;
    Number aXMax = aBack->x;
    Number bXMax = bBack->x;
    
    Number xMin;
    Number xMax;

    if (aXMin >= bXMin)
        xMin = aXMin;
    else
        xMin = bXMin;
        
    if (aXMax <= bXMax)
        xMax = aXMax;
    else
        xMax = bXMax;
    
    if ((xMax-xMin) < zero) // Range has no possible intersection
        return;
    
    // if (aBegin->x != xMin)
    //     aBegin = BinarySplitX(aBegin, aEnd, xMin);
    // if (bBegin->x != xMin)
    //     bBegin = BinarySplitX(bBegin, bEnd, xMin);

    // if (aBack->x != xMax)
    //     aEnd = BinarySplitX(aBegin, aEnd, xMax);
    // if (bBack->x != xMax)
    //     bEnd = BinarySplitX(bBegin, bEnd, xMax);

    // aBack = aEnd;
    // aBack--;
    // bBack = bEnd;
    // bBack--;

    while (aBegin->x < xMin)
        aBegin++;
    while (bBegin->x < xMin)
        bBegin++;
    while (aBack->x > xMax)
    {
        aBack--;
        aEnd--;
    }
    while (bBack->x > xMax)
    {
        bBack--;
        bEnd--;
    }
    
    Number xRange = xMax - xMin;
    Number split = (xRange/two) + xMin; 

    // Base Case (xRange == 0)
    if (xRange == zero)
    {
        func(aBegin, aEnd, bBegin, bEnd, intersectionPoints);
        return;
    }
    
    // Recurse Case
    std::vector<SimplePoint2D>::iterator aSplit = BinarySplitX(aBegin, aEnd, split);
    std::vector<SimplePoint2D>::iterator bSplit = BinarySplitX(bBegin, bEnd, split);
    
    DivideAndConquer(aBegin, aSplit, bBegin, bSplit, intersectionPoints, func);
    DivideAndConquer(aSplit, aEnd, bSplit, bEnd, intersectionPoints, func);
}



// Intersection
Point2D IntersectionDC(const Point2D& a, const Point2D& b)
{
    std::vector<SimplePoint2D> intersectionPoints;
    std::vector<SimplePoint2D> pointCollectionA;
    std::vector<SimplePoint2D> pointCollectionB;
    
    for (Point2D::Iterator itr = a.begin(); itr != a.end(); itr++)
    {
        pointCollectionA.push_back(*itr);
    }
    for (Point2D::Iterator itr = b.begin(); itr != b.end(); itr++)
    {
        pointCollectionB.push_back(*itr);
    }
    
    DivideAndConquer(pointCollectionA.begin(), pointCollectionA.end(), pointCollectionB.begin(), pointCollectionB.end(), intersectionPoints, &CompareIntersection);
    
    Point2D intersection(intersectionPoints);

    return intersection;
}

// Line2D IntersectionDC(const Line2D& a, const Line2D& b)
// {

// }
// Region2D IntersectionDC(const Region2D& a, const Region2D& b)
// {

// }

// // Union
// Point2D UnionDC(const Point2D& a, const Point2D& b)
// {

// }
// Line2D UnionDC(const Line2D& a, const Line2D& b)
// {

// }
// Region2D UnionDC(const Region2D& a, const Region2D& b)
// {

// }

// // Difference
// Point2D DifferenceDC(const Point2D& a, const Point2D& b)
// {

// }
// Line2D DifferenceDC(const Line2D& a, const Line2D& b)
// {

// }
// Region2D DifferenceDC(const Region2D& a, const Region2D& b)
// {

// }