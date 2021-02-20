#include "AABB.h"
namespace crynn
{
    bool AABBSolver::Compare(const AABB& one, const AABB& two)
    {
        //x collision
        bool x = one.transform.GetPosition().x + one.Size.x >= two.transform.GetPosition().x &&
            two.transform.GetPosition().x + two.Size.x >= one.transform.GetPosition().x;

        if (!x)
            return false;

        //y collision
        bool y = one.transform.GetPosition().y + one.Size.y >= two.transform.GetPosition().y &&
            two.transform.GetPosition().y + two.Size.y >= one.transform.GetPosition().y;

        if (!y)
            return false;

        //z collision
        bool z = one.transform.GetPosition().z + one.Size.z >= two.transform.GetPosition().z &&
            two.transform.GetPosition().z + two.Size.z >= one.transform.GetPosition().z;

        if (!z)
            return false;

        // collision only if on every axes
        return true;
    }

    bool AABBSolver::Compare(const AABB& one, const AABB& two, std::function<void(const AABB& one, const AABB& two)> func)
    {
        if (Compare(one, two))
        {
            func(one, two);
            return true;
        }

        return false;
    }

    bool AABBSolver::Compare(const AABB& one, const AABB& two, std::function<void()> func)
    {
        if (Compare(one, two))
        {
            func();
            return true;
        }

        return false;
    }
}