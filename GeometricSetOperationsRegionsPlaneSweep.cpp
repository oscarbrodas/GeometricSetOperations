#include "GeometricSetOperationsRegionsPlaneSweep.h"
#include "AttributedHalfSegment2D.h"
#include "PlaneSweep.h"
#include "ParallelObjTraversal.h"
#include <iostream>

Region2D IntersectionPS(const Region2D& a, const Region2D& b)
{
    std::vector<AttributedHalfSegment2D> aAHS;
    std::vector<AttributedHalfSegment2D> bAHS;

    for (auto itr = a.begin(); itr != a.end(); itr++)
    {
        aAHS.push_back(*itr);
    }
    for (auto itr = b.begin(); itr != b.end(); itr++)
    {
        bAHS.push_back(*itr);
    }

    ParallelObjT traversal(aAHS, bAHS);
    PlaneSweep sweepLine;
    SimplePoint2D last_dp_in_A; // Should be empty first
    SimplePoint2D last_dp_in_B;

    // Select First
    EventPoint next = traversal.SelectNext();
    if (traversal.status != 3)
    {
        sweepLine.add_left(next.attrHalfSeg.hs.s);
    }

    while (traversal.status == 0) // Neither are empty
    {
        HalfSegment2D h;
        if (traversal.object == 1)
        {
            h = HalfSegment2D()
        }
        next = traversal.SelectNext();
        if (next.attrHalfSeg.hs.isDominatingPointLeft)
        {
            sweepLine.add_left(next.attrHalfSeg.hs.s);
        }
        else
        {
            sweepLine.del_right(next.attrHalfSeg.hs.s);
        }
    }

    //Else status == 3, nothing to do

    return Region2D();
}
