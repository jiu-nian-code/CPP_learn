#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_set>

struct Point
{
    int _x, _y;
    Point(int x, int y) : _x(x), _y(y) {}

    bool operator==(const Point& other) const
    {
        return _x == other._x && _y == other._y;
    }
};

namespace std
{
    template<>
    struct hash<Point> // 给自定义结构体 Point 提供哈希函数特化，提供具体比较逻辑，也可以使用仿函数
    {
        size_t operator()(const Point& p) const
        {
            return hash<int>()(p._x) ^ (hash<int>()(p._y) << 1); // << 1 防止xy位置交换出现哈希冲突
        }
    };
}

double getDistance(const Point& a, const Point& b)
{
    long long dx = a._x - b._x;
    long long dy = a._y - b._y;
    return sqrt(dx * dx + dy * dy);
}

bool isTriangle(const Point& p1, const Point& p2, const Point& p3)
{
    std::unordered_set<Point> pointSet;
    pointSet.insert(p1);
    pointSet.insert(p2);
    pointSet.insert(p3);
    if (pointSet.size() != 3) return false;

    double d1 = getDistance(p1, p2);
    double d2 = getDistance(p2, p3);
    double d3 = getDistance(p1, p3);

    std::vector<double> edges = { d1, d2, d3 };
    std::sort(edges.begin(), edges.end());
    double a = edges[0], b = edges[1], c = edges[2];

    const double eps = 1e-8;
    return (a + b) > c + eps;
}

int main()
{
    Point A(0, 0), B(0, 3), C(4, 0);
    if (isTriangle(A, B, C)) std::cout << "true\n";
    else std::cout << "false\n";

    Point D(1, 1), E(1, 1), F(5, 5);
    if (isTriangle(D, E, F)) std::cout << "true\n";
    else std::cout << "false\n";

    Point M(0, 0), N(1, 1), P(2, 2);
    if (isTriangle(M, N, P)) std::cout << "true\n";
    else std::cout << "false\n";

    return 0;
}