#include "AABB.h"
namespace Crynn
{
    bool AABBSolver::Compare(const AABB& one, const AABB& two)
    {
        // collision x-axis?
        bool collisionX = one.transform.GetPosition().x + one.Size.x >= two.transform.GetPosition().x &&
            two.transform.GetPosition().x + two.Size.x >= one.transform.GetPosition().x;

        // collision y-axis?
        bool collisionY = one.transform.GetPosition().y + one.Size.y >= two.transform.GetPosition().y &&
            two.transform.GetPosition().y + two.Size.y >= one.transform.GetPosition().y;

        // collision z-axis?
        bool collisionZ = one.transform.GetPosition().z + one.Size.z >= two.transform.GetPosition().z &&
            two.transform.GetPosition().z + two.Size.z >= one.transform.GetPosition().z;

        // collision only if on both axes
        return collisionX && collisionY && collisionZ;
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