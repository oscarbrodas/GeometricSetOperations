#include "GeometricSetOperationsDivideAndConquer.h"
#include "iostream"

bool calculateRangeIntersection(bool isX, std::vector<SimplePoint2D>::iterator& aBegin, std::vector<SimplePoint2D>::iterator& aEnd,
                                           std::vector<SimplePoint2D>::iterator& bBegin, std::vector<SimplePoint2D>::iterator& bEnd, 
                                           std::vector<SimplePoint2D>& interSectionPoints, Number& max, Number& min)
{
    
    if ((aEnd - aBegin) <= 0 || (bEnd - bBegin) <= 0) // If one of the lists is empty
        return true;

    Number aMin, aMax, bMin, bMax;

    std::vector<SimplePoint2D>::iterator aBack = aEnd;
    aBack--;
    std::vector<SimplePoint2D>::iterator bBack = bEnd;
    bBack--;

    if (isX) // X Range
    {
        aMin = aBegin->x;
        bMin = bBegin->x;
        aMax = aBack->x;
        bMax = bBack->x;
    }
    else // Y Range 
    {
        aMin = aBegin->y;
        bMin = bBegin->y;
        aMax = aBack->y;
        bMax = bBack->y;
    }

    if (aMin >= bMin)
            min = aMin;
        else
            min = bMin;
        
        if (aMax <= bMax)
            max = aMax;
        else
            max = bMax;
    
    if (isX)
    {
        while (aBegin->x < min)
            aBegin++;

        while (bBegin->x < min)
            bBegin++;

        while (aBack->x > max)
        {
            aBack--;
            aEnd--;
        }
        
        while (bBack->x > max)
        {  
            bBack--;
            bEnd--;
        }
    }
    else 
    {
        while (aBegin->y < min)
            aBegin++;

        while (bBegin->y < min)
            bBegin++;

        while (aBack->y > max)
        {
            aBack--;
            aEnd--;
        }

        while (bBack->y > max)
        {
            bBack--;
            bEnd--;
        }
    }

    return false;
}

bool calculateRangeUnion(bool isX, std::vector<SimplePoint2D>::iterator& aBegin, std::vector<SimplePoint2D>::iterator& aEnd,
                                           std::vector<SimplePoint2D>::iterator& bBegin, std::vector<SimplePoint2D>::iterator& bEnd, 
                                           std::vector<SimplePoint2D>& unionPoints, Number& max, Number& min)
{
    if ((aEnd - aBegin) <= 0 && (bEnd - bBegin) <= 0) // if both are empty
        return true;

    if ((aEnd - aBegin) <= 0) // If A is empty, but B isn't empty
    {
        while (bBegin != bEnd) // Add all the points in B to the union
        {
            unionPoints.push_back(*bBegin);
            bBegin++;
        }
        return true;
    }

    if ((bEnd - bBegin) <= 0) // If B is empty, but A isn't empty
    {
        while (aBegin != aEnd) // Add all the points in A to the union
        {
            unionPoints.push_back(*aBegin);
            aBegin++;
        }
        return true;
    }

    // Else both lists still have at least a point

    std::vector<SimplePoint2D>::iterator aBack = aEnd;
    aBack--;
    std::vector<SimplePoint2D>::iterator bBack = bEnd;
    bBack--;

    Number aMin, aMax, bMin, bMax;

    if (isX)
    {
        aMin = aBegin->x;
        aMax = aBack->x;
        bMin = bBegin->x;
        bMax = bBack->x;
    }
    else
    {
        aMin = aBegin->y;
        aMax = aBack->y;
        bMin = bBegin->y;
        bMax = bBack->y;
    }

    if (aMin >= bMin)
        min = bMin;
    else
        min = aMin;
        
    if (aMax <= bMax)
        max = bMax;
    else
        max = aMax;

    return false;

}

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
            while (mid != end && mid->x == split)
            {
                mid++;
            }
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
            while (mid != end && mid->y == split)
            {
                mid++;
            }
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

    Number yMin, yMax;

    if (calculateRangeIntersection(false, aBegin, aEnd, bBegin, bEnd, intersectionPoints, yMax, yMin))
        return;


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
    

    Number yRange = yMax - yMin;
    Number split = (yRange/two) + yMin; 

    std::vector<SimplePoint2D>::iterator aBack = aEnd;
    if (aEnd - aBegin > 0)
        aBack--;
    std::vector<SimplePoint2D>::iterator bBack = bEnd;
    if (aEnd - aBegin > 0)
        bBack--;

    // Base Case  - handle intersection
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
void CompareUnion(std::vector<SimplePoint2D>::iterator aBegin, std::vector<SimplePoint2D>::iterator aEnd, std::vector<SimplePoint2D>::iterator bBegin,
                      std::vector<SimplePoint2D>::iterator bEnd, std::vector<SimplePoint2D>& unionPoints)
{
    Number zero = "0.0";
    Number two = "2.0";

    Number yMax, yMin;

    if (calculateRangeUnion(false, aBegin, aEnd, bBegin, bEnd, unionPoints, yMax, yMin))
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

    Number yRange = yMax - yMin;
    Number split = (yRange/two) + yMin;

    // Base Case - Handle Union
    if (yRange == zero) // Because we know there are points in each, this only happens when the only points coincide
    {
        unionPoints.push_back(*aBegin);
        return;
    }
    
    // Recurse Case
    std::vector<SimplePoint2D>::iterator aSplit = BinarySplitY(aBegin, aEnd, split);
    std::vector<SimplePoint2D>::iterator bSplit = BinarySplitY(bBegin, bEnd, split);

    CompareUnion(aBegin, aSplit, bBegin, bSplit, unionPoints);
    CompareUnion(aSplit, aEnd, bSplit, bEnd, unionPoints);
}


// Divide and Conquer (Recursion)
void DivideAndConquer(std::vector<SimplePoint2D>::iterator aBegin, std::vector<SimplePoint2D>::iterator aEnd, std::vector<SimplePoint2D>::iterator bBegin,
                      std::vector<SimplePoint2D>::iterator bEnd, std::vector<SimplePoint2D>& intersectionPoints, 
                      void (*compare)(std::vector<SimplePoint2D>::iterator, std::vector<SimplePoint2D>::iterator,
                                      std::vector<SimplePoint2D>::iterator, std::vector<SimplePoint2D>::iterator, std::vector<SimplePoint2D>&),
                      bool (*findRange)(bool, std::vector<SimplePoint2D>::iterator&, std::vector<SimplePoint2D>::iterator&,
                                        std::vector<SimplePoint2D>::iterator&, std::vector<SimplePoint2D>::iterator&, std::vector<SimplePoint2D>&, Number&, Number&) )
{

    Number zero = "0.0";
    Number two = "2.0";

    Number xMax, xMin;

    if (findRange(true, aBegin, aEnd, bBegin, bEnd, intersectionPoints, xMax, xMin))
        return;


    
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

    Number xRange = xMax - xMin;
    Number split = (xRange/two) + xMin;
    

    // Base Case (xRange == 0)
    if (xRange == zero)
    {
        compare(aBegin, aEnd, bBegin, bEnd, intersectionPoints);
        return;
    }
    
    // Recurse Case
    std::vector<SimplePoint2D>::iterator aSplit = BinarySplitX(aBegin, aEnd, split);
    std::vector<SimplePoint2D>::iterator bSplit = BinarySplitX(bBegin, bEnd, split);
    
    DivideAndConquer(aBegin, aSplit, bBegin, bSplit, intersectionPoints, compare, findRange);
    DivideAndConquer(aSplit, aEnd, bSplit, bEnd, intersectionPoints, compare, findRange);
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
    
    DivideAndConquer(pointCollectionA.begin(), pointCollectionA.end(), pointCollectionB.begin(), pointCollectionB.end(), intersectionPoints, &CompareIntersection, &calculateRangeIntersection);
    

    return Point2D(intersectionPoints);

}

// Line2D IntersectionDC(const Line2D& a, const Line2D& b)
// {

// }
// Region2D IntersectionDC(const Region2D& a, const Region2D& b)
// {

// }

// Union
Point2D UnionDC(const Point2D& a, const Point2D& b)
{
    std::vector<SimplePoint2D> unionPoints;
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
    DivideAndConquer(pointCollectionA.begin(), pointCollectionA.end(), pointCollectionB.begin(), pointCollectionB.end(), unionPoints, &CompareUnion, &calculateRangeUnion);

    return Point2D(unionPoints);

}
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