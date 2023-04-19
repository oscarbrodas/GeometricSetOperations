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

// Edge Case: All points on a single x value
void test_PointIntersectionDC4()
{
    std::cout << "Testing Intersection of Points" << std::endl;

    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    std::vector<SimplePoint2D> intersectionPoints;

    Number x = "1.0", y = "1.0", multiple = "0.5";

    for (int i = 0; i < 10000; i++)
    {
        if ((i % 2 == 0 || i % 5 == 0) && i % 3 == 0)
        {
            pointsA.push_back(SimplePoint2D(x, y));
        }
        if ((i % 2 == 0 || i % 5 == 0) && i % 7 == 0)
        {
            pointsB.push_back(SimplePoint2D(x, y));
        }
        if ((i % 2 == 0 || i % 5 == 0) && (i % 3 == 0 && i % 7 == 0))
        {
            intersectionPoints.push_back(SimplePoint2D(x, y));
        }
        y += multiple;
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

// Edge Case: All points on a single y value
void test_PointIntersectionDC5()
{
    std::cout << "Testing Intersection of Points" << std::endl;

    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    std::vector<SimplePoint2D> intersectionPoints;

    Number x = "1.0", y = "1.0", multiple = "0.5";

    for (int i = 0; i < 10000; i++)
    {
        if ((i % 2 == 0 || i % 5 == 0) && i % 3 == 0)
        {
            pointsA.push_back(SimplePoint2D(x, y));
        }
        if ((i % 2 == 0 || i % 5 == 0) && i % 7 == 0)
        {
            pointsB.push_back(SimplePoint2D(x, y));
        }
        if ((i % 2 == 0 || i % 5 == 0) && (i % 3 == 0 && i % 7 == 0))
        {
            intersectionPoints.push_back(SimplePoint2D(x, y));
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

// Edge Case: A is full of points and B is empty (Intersection should be empty)
void test_PointIntersectionDC6()
{
    std::cout << "Testing Intersection of Points" << std::endl;

    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    std::vector<SimplePoint2D> intersectionPoints;

    Number x = "1.0", y = "1.0", multiple = "0.5";

    for (int i = 0; i < 10000; i++)
    {
        if ((i % 2 == 0 || i % 5 == 0) && i % 3 == 0)
        {
            pointsA.push_back(SimplePoint2D(x, y));
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

// Edge Case: A and B have one point each (Different)
void test_PointIntersectionDC7()
{
    std::cout << "Testing Intersection of Points" << std::endl;

    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    std::vector<SimplePoint2D> intersectionPoints;

    Number x = "1.0", y = "1.0", multiple = "0.5";

    pointsA.push_back(SimplePoint2D(x, y));
    y += multiple;
    pointsB.push_back(SimplePoint2D(x, y));

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

// Edge Case: A and B have one point each (Same)
void test_PointIntersectionDC8()
{
    std::cout << "Testing Intersection of Points" << std::endl;

    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    std::vector<SimplePoint2D> intersectionPoints;

    Number x = "1.0", y = "1.0", multiple = "0.5";

    pointsA.push_back(SimplePoint2D(x, y));
    pointsB.push_back(SimplePoint2D(x, y));
    intersectionPoints.push_back(SimplePoint2D(x, y));

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

// Edge Case: All points on a single x value
void test_PointUnionDC4()
{
    std::cout << "Testing Union of Points" << std::endl;

    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    std::vector<SimplePoint2D> unionPoints;

    Number x = "1.0", y = "1.0", multiple = "0.5";

    for (int i = 0; i < 10000; i++)
    {
        if ((i % 2 == 0 || i % 5 == 0) && i % 3 == 0)
        {
            pointsA.push_back(SimplePoint2D(x, y));
        }
        if ((i % 2 == 0 || i % 5 == 0) && i % 7 == 0)
        {
            pointsB.push_back(SimplePoint2D(x, y));
        }
        if (((i % 2 == 0 || i % 5 == 0) && i % 3 == 0) || ((i % 2 == 0 || i % 5 == 0) && i % 7 == 0))
        {
            unionPoints.push_back(SimplePoint2D(x, y));
        }
        y += multiple;
    }

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
        std::cout << "Union Points: " << unionPoints.size() << std::endl;
    }

    if (isEqual)
        std::cout << "Union correctly found" << std::endl;
    else
        std::cout << "Union failed" << std::endl;

    std::cout << std::endl;
}

// Edge Case: All points on a single y value
void test_PointUnionDC5()
{
    std::cout << "Testing Union of Points" << std::endl;

    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    std::vector<SimplePoint2D> unionPoints;

    Number x = "1.0", y = "1.0", multiple = "0.5";

    for (int i = 0; i < 10000; i++)
    {
        if ((i % 2 == 0 || i % 5 == 0) && i % 3 == 0)
        {
            pointsA.push_back(SimplePoint2D(x, y));
        }
        if ((i % 2 == 0 || i % 5 == 0) && i % 7 == 0)
        {
            pointsB.push_back(SimplePoint2D(x, y));
        }
        if (((i % 2 == 0 || i % 5 == 0) && i % 3 == 0) || ((i % 2 == 0 || i % 5 == 0) && i % 7 == 0))
        {
            unionPoints.push_back(SimplePoint2D(x, y));
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
        std::cout << "Union Points: " << unionPoints.size() << std::endl;
    }

    if (isEqual)
        std::cout << "Union correctly found" << std::endl;
    else
        std::cout << "Union failed" << std::endl;

    std::cout << std::endl;
}

// Edge Case: A is full of points and B is empty (Union should be equal to A)
void test_PointUnionDC6()
{
    std::cout << "Testing Union of Points" << std::endl;

    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    std::vector<SimplePoint2D> unionPoints;

    Number x = "1.0", y = "1.0", multiple = "0.5";

    for (int i = 0; i < 10000; i++)
    {
        if ((i % 2 == 0 || i % 5 == 0) && i % 3 == 0)
        {
            pointsA.push_back(SimplePoint2D(x, y));
            unionPoints.push_back(SimplePoint2D(x, y));
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
        std::cout << "Union Points: " << unionPoints.size() << std::endl;
    }

    if (isEqual)
        std::cout << "Union correctly found" << std::endl;
    else
        std::cout << "Union failed" << std::endl;

    std::cout << std::endl;
}

// Edge Case: A and B have one point each (Different)
void test_PointUnionDC7()
{
    std::cout << "Testing Union of Points" << std::endl;

    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    std::vector<SimplePoint2D> unionPoints;

    Number x = "1.0", y = "1.0", multiple = "0.5";

    pointsA.push_back(SimplePoint2D(x, y));
    unionPoints.push_back(SimplePoint2D(x, y));

    y += multiple;

    pointsB.push_back(SimplePoint2D(x, y));
    unionPoints.push_back(SimplePoint2D(x, y));


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
        std::cout << "Union Points: " << unionPoints.size() << std::endl;
    }

    if (isEqual)
        std::cout << "Union correctly found" << std::endl;
    else
        std::cout << "Union failed" << std::endl;

    std::cout << std::endl;
}

// Edge Case: A and B have one point each (Same)
void test_PointUnionDC8()
{
    std::cout << "Testing Union of Points" << std::endl;

    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    std::vector<SimplePoint2D> unionPoints;

    Number x = "1.0", y = "1.0", multiple = "0.5";

    pointsA.push_back(SimplePoint2D(x, y));
    pointsB.push_back(SimplePoint2D(x, y));
    unionPoints.push_back(SimplePoint2D(x, y));

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
        std::cout << "Union Points: " << unionPoints.size() << std::endl;
    }

    if (isEqual)
        std::cout << "Union correctly found" << std::endl;
    else
        std::cout << "Union failed" << std::endl;

    std::cout << std::endl;
}

void test_PointDifferenceDC1()
{
    std::cout << "Testing difference on points" << std::endl;

    std::vector<Number> nums = {"1.0", "2.0", "3.0", "4.0"};

    std::vector<SimplePoint2D> pointVector;
    std::vector<SimplePoint2D> difPoints;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            pointVector.push_back(SimplePoint2D(nums[i], nums[j]));
        }
    }

    
    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    pointsA.push_back(pointVector.at(0));
    difPoints.push_back(pointVector.at(0));
    pointsA.push_back(pointVector.at(1));
    difPoints.push_back(pointVector.at(1));
    pointsA.push_back(pointVector.at(2));
    difPoints.push_back(pointVector.at(2));
    pointsA.push_back(pointVector.at(3));
    pointsB.push_back(pointVector.at(3));


    pointsA.push_back(pointVector.at(4));
    difPoints.push_back(pointVector.at(4));
    pointsA.push_back(pointVector.at(5));
    difPoints.push_back(pointVector.at(5));
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
    difPoints.push_back(pointVector.at(13));
    pointsA.push_back(pointVector.at(14));
    difPoints.push_back(pointVector.at(14));
    pointsB.push_back(pointVector.at(15));



    Point2D A(pointsA);
    Point2D B(pointsB);
    Point2D C = DifferenceDC(A, B);

    std::vector<SimplePoint2D> pointsC;
    for (auto itr = C.begin(); itr != C.end(); itr++)
    {
        pointsC.push_back(*itr);
    }

    bool isEqual = true;
    if (pointsC.size() == difPoints.size())
    {
        for (int i = 0; i < pointsC.size(); i++)
        {
            if (pointsC.at(i) != difPoints.at(i))
            {
                isEqual = false;
                std::cout << std::endl;
                std::cout << "(" << pointsC.at(i).x << ", " << pointsC.at(i).y << ")" << std::endl;
                std::cout << "(" << difPoints.at(i).x << ", " << difPoints.at(i).y << ")" << std::endl;
                std::cout << std::endl;
            }
        }
    }
    else
    {
        isEqual = false;
        std::cout << "Points C Size: " << pointsC.size() << std::endl;
        std::cout << "Difference Points Size: " << difPoints.size() << std::endl;
    }

    if (isEqual)
        std::cout << "Difference correctly found" << std::endl;
    else
        std::cout << "Difference failed" << std::endl;

    std::cout << std::endl;
}
void test_PointDifferenceDC2()
{
    std::cout << "Testing Difference on points" << std::endl;

    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    std::vector<SimplePoint2D> difPoints;

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
            if (k % 2 == 0 && k % 5 != 0)
            {
                difPoints.push_back(SimplePoint2D(x, y));
            }
            y += multiple;
        }
        x += multiple;
    }

    Point2D A(pointsA);
    Point2D B(pointsB);
    Point2D C = DifferenceDC(A, B);

    std::vector<SimplePoint2D> pointsC;
    for (auto itr = C.begin(); itr != C.end(); itr++)
    {
        pointsC.push_back(*itr);
    }


    bool isEqual = true;
    if (pointsC.size() == difPoints.size())
    {
        for (int i = 0; i < pointsC.size(); i++)
        {
            if (pointsC.at(i) != difPoints.at(i))
            {
                isEqual = false;
                std::cout << std::endl;
                std::cout << "(" << pointsC.at(i).x << ", " << pointsC.at(i).y << ")" << std::endl;
                std::cout << "(" << difPoints.at(i).x << ", " << difPoints.at(i).y << ")" << std::endl;
                std::cout << std::endl;
            }
        }
    }
    else
    {
        isEqual = false;
        std::cout << "Points C Size: " << pointsC.size() << std::endl;
        std::cout << "Difference Points Size: " << difPoints.size() << std::endl;
    }

    if (isEqual)
        std::cout << "Difference correctly found" << std::endl;
    else
        std::cout << "Difference failed" << std::endl;

    std::cout << std::endl;
}
void test_PointDifferenceDC3()
{
    std::cout << "Testing Difference of Points" << std::endl;

    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    std::vector<SimplePoint2D> difPoints;

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
            if (((k % 2 == 0 || k % 5 == 0) && k % 3 == 0) && !((k % 2 == 0 || k % 5 == 0) && k % 7 == 0))
            {
                difPoints.push_back(SimplePoint2D(x, y));
            }
            y += multiple;
        }
        x += multiple;
    }

    Point2D A(pointsA);
    Point2D B(pointsB);
    Point2D C = DifferenceDC(A, B);

    std::vector<SimplePoint2D> pointsC;
    for (auto itr = C.begin(); itr != C.end(); itr++)
    {
        pointsC.push_back(*itr);
    }
    

    bool isEqual = true;
    if (pointsC.size() == difPoints.size())
    {
        for (int i = 0; i < pointsC.size(); i++)
        {
            if (pointsC.at(i) != difPoints.at(i))
            {
                isEqual = false;
                std::cout << std::endl;
                std::cout << "(" << pointsC.at(i).x << ", " << pointsC.at(i).y << ")" << std::endl;
                std::cout << "(" << difPoints.at(i).x << ", " << difPoints.at(i).y << ")" << std::endl;
                std::cout << std::endl;
            }
        }
    }
    else
    {
        isEqual = false;
        std::cout << "Points C Size: " << pointsC.size() << std::endl;
        std::cout << "Difference Points Size: " << difPoints.size() << std::endl;
    }

    if (isEqual)
        std::cout << "Difference correctly found" << std::endl;
    else
        std::cout << "Difference failed" << std::endl;

    std::cout << std::endl;
}

// Edge Case: All points on a single x value
void test_PointDifferenceDC4()
{
    std::cout << "Testing Difference of Points" << std::endl;

    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    std::vector<SimplePoint2D> difPoints;

    Number x = "1.0", y = "1.0", multiple = "0.5";

    for (int i = 0; i < 10000; i++)
    {
        if ((i % 2 == 0 || i % 5 == 0) && i % 3 == 0)
        {
            pointsA.push_back(SimplePoint2D(x, y));
        }
        if ((i % 2 == 0 || i % 5 == 0) && i % 7 == 0)
        {
            pointsB.push_back(SimplePoint2D(x, y));
        }
        if (((i % 2 == 0 || i % 5 == 0) && i % 3 == 0) && !((i % 2 == 0 || i % 5 == 0) && i % 7 == 0))
        {
            difPoints.push_back(SimplePoint2D(x, y));
        }
        y += multiple;
    }

    Point2D A(pointsA);
    Point2D B(pointsB);
    Point2D C = DifferenceDC(A, B);

    std::vector<SimplePoint2D> pointsC;
    for (auto itr = C.begin(); itr != C.end(); itr++)
    {
        pointsC.push_back(*itr);
    }

    bool isEqual = true;
    if (pointsC.size() == difPoints.size())
    {
        for (int i = 0; i < pointsC.size(); i++)
        {
            if (pointsC.at(i) != difPoints.at(i))
            {
                isEqual = false;
                std::cout << std::endl;
                std::cout << "(" << pointsC.at(i).x << ", " << pointsC.at(i).y << ")" << std::endl;
                std::cout << "(" << difPoints.at(i).x << ", " << difPoints.at(i).y << ")" << std::endl;
                std::cout << std::endl;
            }
        }
    }
    else
    {
        isEqual = false;
        std::cout << "Points C Size: " << pointsC.size() << std::endl;
        std::cout << "Differece Points: " << difPoints.size() << std::endl;
    }

    if (isEqual)
        std::cout << "Difference correctly found" << std::endl;
    else
        std::cout << "Difference failed" << std::endl;

    std::cout << std::endl;
}

// Edge Case: All points on a single y value
void test_PointDifferenceDC5()
{
    std::cout << "Testing Difference of Points" << std::endl;

    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    std::vector<SimplePoint2D> difPoints;

    Number x = "1.0", y = "1.0", multiple = "0.5";

    for (int i = 0; i < 10000; i++)
    {
        if ((i % 2 == 0 || i % 5 == 0) && i % 3 == 0)
        {
            pointsA.push_back(SimplePoint2D(x, y));
        }
        if ((i % 2 == 0 || i % 5 == 0) && i % 7 == 0)
        {
            pointsB.push_back(SimplePoint2D(x, y));
        }
        if (((i % 2 == 0 || i % 5 == 0) && i % 3 == 0) && !((i % 2 == 0 || i % 5 == 0) && i % 7 == 0))
        {
            difPoints.push_back(SimplePoint2D(x, y));
        }
        x += multiple;
    }

    Point2D A(pointsA);
    Point2D B(pointsB);
    Point2D C = DifferenceDC(A, B);

    std::vector<SimplePoint2D> pointsC;
    for (auto itr = C.begin(); itr != C.end(); itr++)
    {
        pointsC.push_back(*itr);
    }
    

    bool isEqual = true;
    if (pointsC.size() == difPoints.size())
    {
        for (int i = 0; i < pointsC.size(); i++)
        {
            if (pointsC.at(i) != difPoints.at(i))
            {
                isEqual = false;
                std::cout << std::endl;
                std::cout << "(" << pointsC.at(i).x << ", " << pointsC.at(i).y << ")" << std::endl;
                std::cout << "(" << difPoints.at(i).x << ", " << difPoints.at(i).y << ")" << std::endl;
                std::cout << std::endl;
            }
        }
    }
    else
    {
        isEqual = false;
        std::cout << "Points C Size: " << pointsC.size() << std::endl;
        std::cout << "Difference Points: " << difPoints.size() << std::endl;
    }

    if (isEqual)
        std::cout << "Difference correctly found" << std::endl;
    else
        std::cout << "Difference failed" << std::endl;

    std::cout << std::endl;
}

// Edge Case: A is full of points and B is empty (Difference should be equal to A)
void test_PointDifferenceDC6()
{
    std::cout << "Testing Difference of Points" << std::endl;

    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    std::vector<SimplePoint2D> difPoints;

    Number x = "1.0", y = "1.0", multiple = "0.5";

    for (int i = 0; i < 10000; i++)
    {
        if ((i % 2 == 0 || i % 5 == 0) && i % 3 == 0)
        {
            pointsA.push_back(SimplePoint2D(x, y));
            difPoints.push_back(SimplePoint2D(x, y));
        }
        x += multiple;
    }

    Point2D A(pointsA);
    Point2D B(pointsB);
    Point2D C = DifferenceDC(A, B);

    std::vector<SimplePoint2D> pointsC;
    for (auto itr = C.begin(); itr != C.end(); itr++)
    {
        pointsC.push_back(*itr);
    }
    

    bool isEqual = true;
    if (pointsC.size() == difPoints.size())
    {
        for (int i = 0; i < pointsC.size(); i++)
        {
            if (pointsC.at(i) != difPoints.at(i))
            {
                isEqual = false;
                std::cout << std::endl;
                std::cout << "(" << pointsC.at(i).x << ", " << pointsC.at(i).y << ")" << std::endl;
                std::cout << "(" << difPoints.at(i).x << ", " << difPoints.at(i).y << ")" << std::endl;
                std::cout << std::endl;
            }
        }
    }
    else
    {
        isEqual = false;
        std::cout << "Points C Size: " << pointsC.size() << std::endl;
        std::cout << "Difference Points: " << difPoints.size() << std::endl;
    }

    if (isEqual)
        std::cout << "Difference correctly found" << std::endl;
    else
        std::cout << "Difference failed" << std::endl;

    std::cout << std::endl;
}

// Edge Case: A is empty and B is full of points (Difference should be equal to A(Empty))
void test_PointDifferenceDC7()
{
    std::cout << "Testing Difference of Points" << std::endl;

    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    std::vector<SimplePoint2D> difPoints;

    Number x = "1.0", y = "1.0", multiple = "0.5";

    for (int i = 0; i < 10000; i++)
    {
        if ((i % 2 == 0 || i % 5 == 0) && i % 3 == 0)
        {
            pointsB.push_back(SimplePoint2D(x, y));
        }
        x += multiple;
    }

    Point2D A(pointsA);
    Point2D B(pointsB);
    Point2D C = DifferenceDC(A, B);

    std::vector<SimplePoint2D> pointsC;
    for (auto itr = C.begin(); itr != C.end(); itr++)
    {
        pointsC.push_back(*itr);
    }
    

    bool isEqual = true;
    if (pointsC.size() == difPoints.size())
    {
        for (int i = 0; i < pointsC.size(); i++)
        {
            if (pointsC.at(i) != difPoints.at(i))
            {
                isEqual = false;
                std::cout << std::endl;
                std::cout << "(" << pointsC.at(i).x << ", " << pointsC.at(i).y << ")" << std::endl;
                std::cout << "(" << difPoints.at(i).x << ", " << difPoints.at(i).y << ")" << std::endl;
                std::cout << std::endl;
            }
        }
    }
    else
    {
        isEqual = false;
        std::cout << "Points C Size: " << pointsC.size() << std::endl;
        std::cout << "Difference Points: " << difPoints.size() << std::endl;
    }

    if (isEqual)
        std::cout << "Difference correctly found" << std::endl;
    else
        std::cout << "Difference failed" << std::endl;

    std::cout << std::endl;
}

// Edge Case: A and B have one point each (Different)
void test_PointDifferenceDC8()
{
    std::cout << "Testing Difference of Points" << std::endl;

    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    std::vector<SimplePoint2D> difPoints;

    Number x = "1.0", y = "1.0", multiple = "0.5";

    pointsA.push_back(SimplePoint2D(x, y));
    difPoints.push_back(SimplePoint2D(x, y));

    y += multiple;

    pointsB.push_back(SimplePoint2D(x, y));


    Point2D A(pointsA);
    Point2D B(pointsB);
    Point2D C = DifferenceDC(A, B);

    std::vector<SimplePoint2D> pointsC;
    for (auto itr = C.begin(); itr != C.end(); itr++)
    {
        pointsC.push_back(*itr);
    }
    

    bool isEqual = true;
    if (pointsC.size() == difPoints.size())
    {
        for (int i = 0; i < pointsC.size(); i++)
        {
            if (pointsC.at(i) != difPoints.at(i))
            {
                isEqual = false;
                std::cout << std::endl;
                std::cout << "(" << pointsC.at(i).x << ", " << pointsC.at(i).y << ")" << std::endl;
                std::cout << "(" << difPoints.at(i).x << ", " << difPoints.at(i).y << ")" << std::endl;
                std::cout << std::endl;
            }
        }
    }
    else
    {
        isEqual = false;
        std::cout << "Points C Size: " << pointsC.size() << std::endl;
        std::cout << "Difference Points: " << difPoints.size() << std::endl;
    }

    if (isEqual)
        std::cout << "Difference correctly found" << std::endl;
    else
        std::cout << "Difference failed" << std::endl;

    std::cout << std::endl;
}

// Edge Case: A and B have one point each (Same)
void test_PointDifferenceDC9()
{
    std::cout << "Testing Difference of Points" << std::endl;

    std::vector<SimplePoint2D> pointsA;
    std::vector<SimplePoint2D> pointsB;
    std::vector<SimplePoint2D> difPoints;

    Number x = "1.0", y = "1.0", multiple = "0.5";

    pointsA.push_back(SimplePoint2D(x, y));
    pointsB.push_back(SimplePoint2D(x, y));

    Point2D A(pointsA);
    Point2D B(pointsB);
    Point2D C = DifferenceDC(A, B);

    std::vector<SimplePoint2D> pointsC;
    for (auto itr = C.begin(); itr != C.end(); itr++)
    {
        pointsC.push_back(*itr);
    }
    

    bool isEqual = true;
    if (pointsC.size() == difPoints.size())
    {
        for (int i = 0; i < pointsC.size(); i++)
        {
            if (pointsC.at(i) != difPoints.at(i))
            {
                isEqual = false;
                std::cout << std::endl;
                std::cout << "(" << pointsC.at(i).x << ", " << pointsC.at(i).y << ")" << std::endl;
                std::cout << "(" << difPoints.at(i).x << ", " << difPoints.at(i).y << ")" << std::endl;
                std::cout << std::endl;
            }
        }
    }
    else
    {
        isEqual = false;
        std::cout << "Points C Size: " << pointsC.size() << std::endl;
        std::cout << "Difference Points: " << difPoints.size() << std::endl;
    }

    if (isEqual)
        std::cout << "Difference correctly found" << std::endl;
    else
        std::cout << "Difference failed" << std::endl;

    std::cout << std::endl;
}

void test_ObjectSweep()
{

    std::cout << "[Testing AttributedHalfSegment2D]" << endl;

    Number one = "1.0";
    Number two = "2.0";
    Number three = "3.0";
    Number four = "4.0";

    SimplePoint2D pointA(one, one);
    SimplePoint2D pointB(one,two);
    SimplePoint2D pointC(two, one);
    SimplePoint2D pointD(two, two);

    // Segment objects for testing
    Segment2D segA(pointA, pointB);
    Segment2D segB(pointB, pointD);
    Segment2D segC(pointD, pointC);
    Segment2D segD(pointC, pointA);

    Segment2D segE(pointB, pointC);


    std::vector<Segment2D> ahsA = {segA, segB, segC, segD};
    std::vector<Segment2D> ahsB = {segA, segE, segD};


    Region2D a(ahsA);
    Region2D b(ahsB);

    IntersectionPS(a, b);

}

int main (void)
{
    test_PointIntersectionDC1();
    test_PointIntersectionDC2();
    test_PointIntersectionDC3();
    test_PointIntersectionDC4();
    test_PointIntersectionDC5();
    test_PointIntersectionDC6();
    test_PointIntersectionDC7();
    test_PointIntersectionDC8();


    test_PointUnionDC1();
    test_PointUnionDC2();
    test_PointUnionDC3();
    test_PointUnionDC4();
    test_PointUnionDC5();
    test_PointUnionDC6();
    test_PointUnionDC7();
    test_PointUnionDC8();
    

    test_PointDifferenceDC1();
    test_PointDifferenceDC2();
    test_PointDifferenceDC3();
    test_PointDifferenceDC4();
    test_PointDifferenceDC5();
    test_PointDifferenceDC6();
    test_PointDifferenceDC7();
    test_PointDifferenceDC8();
    test_PointDifferenceDC9();

}
    