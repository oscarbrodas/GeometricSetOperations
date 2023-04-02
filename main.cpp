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

void test_GeomSetOps1()
{
    std::cout << "Testing Geometric Set Operations" << std::endl;

    std::vector<Number> nums = {"1.0", "2.0", "3.0", "4.0"};

    std::vector<SimplePoint2D> pointVector;
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
    Point2D C = IntersectionDC(A, B);

    for (auto itr = C.begin(); itr != C.end(); itr++)
    {
        std::cout << "(" << itr->x << " , " << itr->y << ")" << std::endl;
    }
}

int main (void)
{

    test_GeomSetOps1();
    test_GeomSetOps2();

    return 0;
}