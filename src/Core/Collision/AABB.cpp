#include "AABB.h"
namespace crynn
{
    bool AABBSolver::Compare(const AABB& one, const AABB& two)
    {
        //x collision
        bool x = one.Transform.GetPosition().x + one.Size.x >= two.Transform.GetPosition().x &&
            two.Transform.GetPosition().x + two.Size.x >= one.Transform.GetPosition().x;

        if (!x)
            return false;

        //y collision
        bool y = one.Transform.GetPosition().y + one.Size.y >= two.Transform.GetPosition().y &&
            two.Transform.GetPosition().y + two.Size.y >= one.Transform.GetPosition().y;

        if (!y)
            return false;

        //z collision
        bool z = one.Transform.GetPosition().z + one.Size.z >= two.Transform.GetPosition().z &&
            two.Transform.GetPosition().z + two.Size.z >= one.Transform.GetPosition().z;

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