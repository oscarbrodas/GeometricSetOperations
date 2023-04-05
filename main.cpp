#include "Number.h"
#include <iostream>
#include "SimplePoint2D.h"
#include "Segment2D.h"
#include "HalfSegment2D.h"
#include "AttributedHalfSegment2D.h"
#include "Line2D.h"
#include "Point2D.h"
#include "Region2D.h"
#include "GeometricSetOperationsDivideAndConquer.h"

void test_PointIntersectionDC1()
{
    std::cout << "Testing interseciton on points" << std::endl;

    std::vector<Number> nums = {"1.0", "2.0", "3.0", "4.0"};

    std::vector<SimplePoint2D> pointVector;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            pointVector.push_back(SimplePoint2D(nums[i], nums[j]));
        }
    }

    std::vector<SimplePoint2D> intersectionPoints;
    
    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    pointsA.push_back(pointVector.at(0));
    pointsA.push_back(pointVector.at(1));
    pointsA.push_back(pointVector.at(2));
    pointsA.push_back(pointVector.at(3));
    pointsB.push_back(pointVector.at(3));

    intersectionPoints.push_back(pointVector.at(3));

    pointsA.push_back(pointVector.at(4));
    pointsA.push_back(pointVector.at(5));
    pointsA.push_back(pointVector.at(6));
    pointsB.push_back(pointVector.at(6));
    pointsB.push_back(pointVector.at(7));

    intersectionPoints.push_back(pointVector.at(6));
    

    pointsB.push_back(pointVector.at(8));
    pointsA.push_back(pointVector.at(9));
    pointsB.push_back(pointVector.at(9));
    pointsB.push_back(pointVector.at(10));
    pointsB.push_back(pointVector.at(11));

    intersectionPoints.push_back(pointVector.at(9));


    pointsA.push_back(pointVector.at(12));
    pointsB.push_back(pointVector.at(12));
    pointsA.push_back(pointVector.at(13));
    pointsA.push_back(pointVector.at(14));
    pointsB.push_back(pointVector.at(15));

    intersectionPoints.push_back(pointVector.at(12));


    Point2D A(pointsA);
    Point2D B(pointsB);
    Point2D C = IntersectionDC(A, B);

    std::vector<SimplePoint2D> pointsC;
    for (auto itr = C.begin(); itr != C.end(); itr++)
    {
        pointsC.push_back(*itr);
    }

    bool isEqual = true;
    if (pointsC.size() == intersectionPoints.size())
    {
        for (int i = 0; i < pointsC.size(); i++)
        {
            if (pointsC.at(i) != intersectionPoints.at(i))
            {
                isEqual = false;
                std::cout << std::endl;
                std::cout << "(" << pointsC.at(i).x << ", " << pointsC.at(i).y << ")" << std::endl;
                std::cout << "(" << intersectionPoints.at(i).x << ", " << intersectionPoints.at(i).y << ")" << std::endl;
                std::cout << std::endl;
            }
        }
    }
    else
    {
        isEqual = false;
        std::cout << "Points C Size: " << pointsC.size() << std::endl;
        std::cout << "Intersection Points: " << intersectionPoints.size() << std::endl;
    }

    if (isEqual)
        std::cout << "Intersection correctly found" << std::endl;
    else
        std::cout << "Intersection failed" << std::endl;

    std::cout << std::endl;
}

void test_PointIntersectionDC2()
{
    std::cout << "Testing Intersection on points" << std::endl;

    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    std::vector<SimplePoint2D> intersectionPoints;

    Number x = "1.0", y = "1.0", multiple = "1.0";

    for (int i = 0; i < 100; i++)
    {
        y = "1.0";
        for (int j = 0; j < 100; j++)
        {
            int k = (i * 100) + j;
            if (k % 2 == 0)
            {
                pointsA.push_back(SimplePoint2D(x, y));
            }
            if (k % 5 == 0)
            {
                pointsB.push_back(SimplePoint2D(x, y));
            }
            if (k % 2 == 0 && k % 5 == 0)
            {
                intersectionPoints.push_back(SimplePoint2D(x, y));
            }
            y += multiple;
        }
        x += multiple;
    }

    Point2D A(pointsA);
    Point2D B(pointsB);
    Point2D C = IntersectionDC(A, B);

    std::vector<SimplePoint2D> pointsC;
    for (auto itr = C.begin(); itr != C.end(); itr++)
    {
        pointsC.push_back(*itr);
    }


    bool isEqual = true;
    if (pointsC.size() == intersectionPoints.size())
    {
        for (int i = 0; i < pointsC.size(); i++)
        {
            if (pointsC.at(i) != intersectionPoints.at(i))
            {
                isEqual = false;
                std::cout << std::endl;
                std::cout << "(" << pointsC.at(i).x << ", " << pointsC.at(i).y << ")" << std::endl;
                std::cout << "(" << intersectionPoints.at(i).x << ", " << intersectionPoints.at(i).y << ")" << std::endl;
                std::cout << std::endl;
            }
        }
    }
    else
    {
        isEqual = false;
        std::cout << "Points C Size: " << pointsC.size() << std::endl;
        std::cout << "Intersection Points: " << intersectionPoints.size() << std::endl;
    }

    if (isEqual)
        std::cout << "Intersection correctly found" << std::endl;
    else
        std::cout << "Intersection failed" << std::endl;

    std::cout << std::endl;
}

void test_PointIntersectionDC3()
{
    std::cout << "Testing Intersection of Points" << std::endl;

    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    std::vector<SimplePoint2D> intersectionPoints;

    Number x = "1.0", y = "1.0", multiple = "1.0";

    for (int i = 0; i < 100; i++)
    {
        y = "1.0";
        for (int j = 0; j < 100; j++)
        {
            int k = (i * 100) + j;
            if ((k % 2 == 0 || k % 5 == 0) && k % 3 == 0)
            {
                pointsA.push_back(SimplePoint2D(x, y));
            }
            if ((k % 2 == 0 || k % 5 == 0) && k % 7 == 0)
            {
                pointsB.push_back(SimplePoint2D(x, y));
            }
            if ((k % 2 == 0 || k % 5 == 0) && (k % 3 == 0 && k % 7 == 0))
            {
                intersectionPoints.push_back(SimplePoint2D(x, y));
            }
            y += multiple;
        }
        x += multiple;
    }

    Point2D A(pointsA);
    Point2D B(pointsB);
    Point2D C = IntersectionDC(A, B);

    std::vector<SimplePoint2D> pointsC;
    for (auto itr = C.begin(); itr != C.end(); itr++)
    {
        pointsC.push_back(*itr);
    }
    
    std::cout << std::endl;

    bool isEqual = true;
    if (pointsC.size() == intersectionPoints.size())
    {
        for (int i = 0; i < pointsC.size(); i++)
        {
            if (pointsC.at(i) != intersectionPoints.at(i))
            {
                isEqual = false;
                std::cout << std::endl;
                std::cout << "(" << pointsC.at(i).x << ", " << pointsC.at(i).y << ")" << std::endl;
                std::cout << "(" << intersectionPoints.at(i).x << ", " << intersectionPoints.at(i).y << ")" << std::endl;
                std::cout << std::endl;
            }
        }
    }
    else
    {
        isEqual = false;
        std::cout << "Points C Size: " << pointsC.size() << std::endl;
        std::cout << "Intersection Points: " << intersectionPoints.size() << std::endl;
    }

    if (isEqual)
        std::cout << "Intersection correctly found" << std::endl;
    else
        std::cout << "Intersection failed" << std::endl;
}

void test_PointUnionDC1()
{
    std::cout << "Testing union on points" << std::endl;

    std::vector<Number> nums = {"1.0", "2.0", "3.0", "4.0"};

    std::vector<SimplePoint2D> pointVector;
    std::vector<SimplePoint2D> unionPoints;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            pointVector.push_back(SimplePoint2D(nums[i], nums[j]));
            unionPoints.push_back(SimplePoint2D(nums[i], nums[j]));
        }
    }

    
    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    pointsA.push_back(pointVector.at(0));
    pointsA.push_back(pointVector.at(1));
    pointsA.push_back(pointVector.at(2));
    pointsA.push_back(pointVector.at(3));
    pointsB.push_back(pointVector.at(3));


    pointsA.push_back(pointVector.at(4));
    pointsA.push_back(pointVector.at(5));
    pointsA.push_back(pointVector.at(6));
    pointsB.push_back(pointVector.at(6));
    pointsB.push_back(pointVector.at(7));

    

    pointsB.push_back(pointVector.at(8));
    pointsA.push_back(pointVector.at(9));
    pointsB.push_back(pointVector.at(9));
    pointsB.push_back(pointVector.at(10));
    pointsB.push_back(pointVector.at(11));



    pointsA.push_back(pointVector.at(12));
    pointsB.push_back(pointVector.at(12));
    pointsA.push_back(pointVector.at(13));
    pointsA.push_back(pointVector.at(14));
    pointsB.push_back(pointVector.at(15));



    Point2D A(pointsA);
    Point2D B(pointsB);
    Point2D C = UnionDC(A, B);

    std::vector<SimplePoint2D> pointsC;
    for (auto itr = C.begin(); itr != C.end(); itr++)
    {
        pointsC.push_back(*itr);
    }

    bool isEqual = true;
    if (pointsC.size() == unionPoints.size())
    {
        for (int i = 0; i < pointsC.size(); i++)
        {
            if (pointsC.at(i) != unionPoints.at(i))
            {
                isEqual = false;
                std::cout << std::endl;
                std::cout << "(" << pointsC.at(i).x << ", " << pointsC.at(i).y << ")" << std::endl;
                std::cout << "(" << unionPoints.at(i).x << ", " << unionPoints.at(i).y << ")" << std::endl;
                std::cout << std::endl;
            }
        }
    }
    else
    {
        isEqual = false;
        std::cout << "Points C Size: " << pointsC.size() << std::endl;
        std::cout << "Union Points Size: " << unionPoints.size() << std::endl;
    }

    if (isEqual)
        std::cout << "Union correctly found" << std::endl;
    else
        std::cout << "Union failed" << std::endl;

    std::cout << std::endl;
}

void test_PointUnionDC2()
{
    std::cout << "Testing union on points" << std::endl;

    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    std::vector<SimplePoint2D> unionPoints;

    Number x = "1.0", y = "1.0", multiple = "1.0";

    for (int i = 0; i < 100; i++)
    {
        y = "1.0";
        for (int j = 0; j < 100; j++)
        {
            int k = (i * 100) + j;
            if (k % 2 == 0)
            {
                pointsA.push_back(SimplePoint2D(x, y));
            }
            if (k % 5 == 0)
            {
                pointsB.push_back(SimplePoint2D(x, y));
            }
            if (k % 2 == 0 || k % 5 == 0)
            {
                unionPoints.push_back(SimplePoint2D(x, y));
            }
            y += multiple;
        }
        x += multiple;
    }

    Point2D A(pointsA);
    Point2D B(pointsB);
    Point2D C = UnionDC(A, B);

    std::vector<SimplePoint2D> pointsC;
    for (auto itr = C.begin(); itr != C.end(); itr++)
    {
        pointsC.push_back(*itr);
    }

    std::cout << std::endl;

    bool isEqual = true;
    if (pointsC.size() == unionPoints.size())
    {
        for (int i = 0; i < pointsC.size(); i++)
        {
            if (pointsC.at(i) != unionPoints.at(i))
            {
                isEqual = false;
                std::cout << std::endl;
                std::cout << "(" << pointsC.at(i).x << ", " << pointsC.at(i).y << ")" << std::endl;
                std::cout << "(" << unionPoints.at(i).x << ", " << unionPoints.at(i).y << ")" << std::endl;
                std::cout << std::endl;
            }
        }
    }
    else
    {
        isEqual = false;
        std::cout << "Points C Size: " << pointsC.size() << std::endl;
        std::cout << "Union Points Size: " << unionPoints.size() << std::endl;
    }

    if (isEqual)
        std::cout << "Union correctly found" << std::endl;
    else
        std::cout << "Union failed" << std::endl;

    std::cout << std::endl;
}

void test_PointUnionDC3()
{
    std::cout << "Testing Union of Points" << std::endl;

    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    std::vector<SimplePoint2D> unionPoints;

    Number x = "1.0", y = "1.0", multiple = "1.0";

    for (int i = 0; i < 100; i++)
    {
        y = "1.0";
        for (int j = 0; j < 100; j++)
        {
            int k = (i * 100) + j;
            if ((k % 2 == 0 || k % 5 == 0) && k % 3 == 0)
            {
                pointsA.push_back(SimplePoint2D(x, y));
            }
            if ((k % 2 == 0 || k % 5 == 0) && k % 7 == 0)
            {
                pointsB.push_back(SimplePoint2D(x, y));
            }
            if (((k % 2 == 0 || k % 5 == 0) && k % 3 == 0) || ((k % 2 == 0 || k % 5 == 0) && k % 7 == 0))
            {
                unionPoints.push_back(SimplePoint2D(x, y));
            }
            y += multiple;
        }
        x += multiple;
    }

    Point2D A(pointsA);
    Point2D B(pointsB);
    Point2D C = UnionDC(A, B);

    std::vector<SimplePoint2D> pointsC;
    for (auto itr = C.begin(); itr != C.end(); itr++)
    {
        pointsC.push_back(*itr);
    }
    
    std::cout << std::endl;

    bool isEqual = true;
    if (pointsC.size() == unionPoints.size())
    {
        for (int i = 0; i < pointsC.size(); i++)
        {
            if (pointsC.at(i) != unionPoints.at(i))
            {
                isEqual = false;
                std::cout << std::endl;
                std::cout << "(" << pointsC.at(i).x << ", " << pointsC.at(i).y << ")" << std::endl;
                std::cout << "(" << unionPoints.at(i).x << ", " << unionPoints.at(i).y << ")" << std::endl;
                std::cout << std::endl;
            }
        }
    }
    else
    {
        isEqual = false;
        std::cout << "Points C Size: " << pointsC.size() << std::endl;
        std::cout << "Union Points Size: " << unionPoints.size() << std::endl;
    }

    if (isEqual)
        std::cout << "Union correctly found" << std::endl;
    else
        std::cout << "Union failed" << std::endl;
}
int main (void)
{
    test_PointIntersectionDC1();
    test_PointIntersectionDC2();
    test_PointIntersectionDC3();
    test_PointUnionDC1();
    test_PointUnionDC2();
    test_PointUnionDC3();
}
    