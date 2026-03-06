#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

struct Point
{
    double x, y;
};

struct Rect
{
    string id;
    string type;
    double w, h;
    double cx, cy;
    int angle;
};

bool isPointInPolygon(Point p, const vector<Point>& poly)
{
    bool inside = false;
    for (int i = 0, j = poly.size() - 1; i < poly.size(); j = i++)
    {
        if (((poly[i].y > p.y) != (poly[j].y > p.y)) &&
            (p.x < (poly[j].x - poly[i].x) * (p.y - poly[i].y) / (poly[j].y - poly[i].y) + poly[i].x))
        {
            inside = !inside;
        }
    }
    return inside;
}

bool isRectInPolygon(const Rect& r, const vector<Point>& poly)
{
    double hw = (r.angle % 180 == 0) ? r.w / 2.0 : r.h / 2.0;
    double hh = (r.angle % 180 == 0) ? r.h / 2.0 : r.w / 2.0;
    vector<Point> corners =
    {
        {r.cx - hw, r.cy - hh}, {r.cx + hw, r.cy - hh},
        {r.cx + hw, r.cy + hh}, {r.cx - hw, r.cy + hh}
    };
    for (auto& cp : corners)
    {
        if (!isPointInPolygon(cp, poly)) return false;
    }
    return true;
}

bool checkCollision(const Rect& a, const Rect& b)
{
    double aw = (a.angle % 180 == 0) ? a.w : a.h;
    double ah = (a.angle % 180 == 0) ? a.h : a.w;
    double bw = (b.angle % 180 == 0) ? b.w : b.h;
    double bh = (b.angle % 180 == 0) ? b.h : b.w;

    return !(a.cx + aw / 2 <= b.cx - bw / 2 || a.cx - aw / 2 >= b.cx + bw / 2 ||
        a.cy + ah / 2 <= b.cy - bh / 2 || a.cy - ah / 2 >= b.cy + bh / 2);
}

struct Door
{
    Point p1, p2;
    bool isOpenInward;
    double width;

    Rect getOccupiedRect() const
    {
        double dx = p1.x - p2.x;
        double dy = p1.y - p2.y;
        double d = sqrt(dx * dx + dy * dy);
        return { "DOOR_AREA", "obstacle", d, d, (p1.x + p2.x) / 2, (p1.y + p2.y) / 2, 0 };
    }
};

class Solver
{
    vector<Point> boundary;
    vector<Rect> placed;
    Door door;
    double minX, maxX, minY, maxY;

public:
    Solver(vector<Point> b, Door d) : boundary(b), door(d)
    {
        minX = maxX = b[0].x; minY = maxY = b[0].y;
        for (auto& p : b)
        {
            minX = min(minX, p.x); maxX = max(maxX, p.x);
            minY = min(minY, p.y); maxY = max(maxY, p.y);
        }
    }

    bool solve(map<string, vector<double>>& items)
    {
        vector<pair<string, vector<double>>> sortedItems(items.begin(), items.end());
        sort(sortedItems.begin(), sortedItems.end(), [](const auto& a, const auto& b)
            {
                return a.second[0] * a.second[1] > b.second[0] * b.second[1];
            });

        double step = 100.0;

        for (auto& itemData : sortedItems)
        {
            bool success = false;
            Rect r; r.id = itemData.first; r.w = itemData.second[0]; r.h = itemData.second[1];

            for (double x = minX; x <= maxX && !success; x += step)
            {
                for (double y = minY; y <= maxY && !success; y += step)
                {
                    for (int ang : {0, 90, 180, 270})
                    {
                        r.cx = x; r.cy = y; r.angle = ang;

                        if (!isRectInPolygon(r, boundary)) continue;

                        bool collision = false;

                        Rect doorLine = { "DOOR_LINE", "line", abs(door.p1.x - door.p2.x) + 10, abs(door.p1.y - door.p2.y) + 10,
                                         (door.p1.x + door.p2.x) / 2, (door.p1.y + door.p2.y) / 2, 0 };
                        if (checkCollision(r, doorLine)) collision = true;

                        if (!collision && door.isOpenInward)
                        {
                            if (checkCollision(r, door.getOccupiedRect())) collision = true;
                        }

                        if (!collision)
                        {
                            for (auto& p : placed)
                            {
                                if (checkCollision(r, p)) { collision = true; break; }
                            }
                        }

                        if (!collision && r.id.find("fridge") != string::npos)
                        {
                            Rect swing = r;
                            if (ang == 0) swing.cy += r.h;
                            else if (ang == 180) swing.cy -= r.h;
                            if (!isRectInPolygon(swing, boundary)) collision = true;
                            for (auto& p : placed) if (checkCollision(swing, p)) collision = true;
                        }

                        if (!collision)
                        {
                            placed.push_back(r);
                            success = true;
                            break;
                        }
                    }
                }
            }
            if (!success) return false;
        }
        return true;
    }

    void report()
    {
        for (auto& r : placed)
            cout << r.id << " -> Center: (" << r.cx << "," << r.cy << ") Angle: " << r.angle << endl;
    }
};

void runTest(const vector<Point>& boundary, const Door& door, const map<string, vector<double>>& items, const string& testName)
{
    cout << "===== " << testName << " =====" << endl;
    Solver s(boundary, door);
    map<string, vector<double>> itemsCopy = items;
    if (s.solve(itemsCopy))
    {
        cout << "Result: SUCCESS (Feasible)" << endl;
        //s.report();
    }
    else
    {
        cout << "Result: FAILED (Infeasible)" << endl;
    }
    cout << "==============================" << endl << endl;
}

void testCase1()
{
    vector<Point> boundary =
    {
        {7121.7357,33170.2897},{7121.7357,28741.7939},{5795.8462,28742.3812},{5614.6510,29380.5005},
        {5306.8204,29293.0914},{4423.4423,32404.1039},{7121.7357,33170.2897}
    };

    Door myDoor;
    myDoor.p1 = { 7121.7357,32746.4897 };
    myDoor.p2 = { 7121.7357, 31746.4897 };
    myDoor.isOpenInward = false;

    map<string, vector<double>> items =
    {
        {"iceMaker", {760, 850}},
        {"fridge", {1220, 1330}},
        {"shelf-1", {1000, 400}},
        {"shelf-2", {1000, 400}},
        {"shelf-3", {1000, 400}},
        {"overShelf-1", {600, 400}},
        {"overShelf-2", {600, 400}},
        {"overShelf-3", {600, 400}}
    };

    runTest(boundary, myDoor, items, "Test Case 1 (Small Room)");
}

void testCase2()
{
    vector<Point> boundary =
    {
        {31596.3885,33275.6321},{31566.3885,33275.6321},{31566.3885,33375.6321},{31596.3885,33375.6321},
        {31596.3885,34970.0295},{31196.3885,34970.0295},{28993.3885,34970.0295},{28993.3885,34205.0295},
        {28993.3885,33505.0295},{28993.3885,32755.0295},{28993.3885,32000.0295},{30996.3885,32000.0295},
        {30996.3885,32040.0295},{31596.3885,32040.0295},{31596.3885,33275.6321}
    };

    Door myDoor;
    myDoor.p1 = { 28993.3885,34205.0295 };
    myDoor.p2 = { 28993.3885, 33505.0295 };
    myDoor.isOpenInward = false;

    map<string, vector<double>> items =
    {
        {"fridge", {1220, 1330}},
        {"shelf-1", {1000, 400}},
        {"shelf-2", {1000, 400}},
        {"shelf-3", {1000, 400}},
        {"shelf-4", {1000, 400}},
        {"overShelf-1", {600, 400}},
        {"overShelf-2", {600, 400}},
        {"overShelf-3", {600, 400}}
    };

    runTest(boundary, myDoor, items, "Test Case 2 (Medium Room)");
}

void testCase3()
{
    vector<Point> boundary =
    {
        {56298.3095,37153.1070},{56298.3095,37553.1060},{58048.3095,37553.1060},{58048.3095,35453.1060},
        {57098.3095,35453.1060},{57098.3095,29483.1070},{55898.3095,29483.1070},{55898.3095,37153.1070},
        {56298.3095,37153.1070}
    };

    Door myDoor;
    myDoor.p1 = { 58048.3095,36773.106 };
    myDoor.p2 = { 58048.3095,36073.106 };
    myDoor.isOpenInward = true;

    map<string, vector<double>> items =
    {
        {"fridge", {1220, 1330}},
        {"shelf-1", {1000, 400}},
        {"shelf-2", {1000, 400}},
        {"shelf-3", {1000, 400}},
        {"shelf-4", {1000, 400}},
        {"shelf-5", {1000, 400}},
        {"overShelf-1", {600, 400}},
        {"overShelf-2", {600, 400}},
        {"overShelf-3", {600, 400}}
    };

    runTest(boundary, myDoor, items, "Test Case 3 (Large Room with Inward Door)");
}

void testCase4()
{
    vector<Point> boundary =
    {
        {182873.5924,30542.7231},{182873.5924,29542.7231},{184373.5924,29542.7231},{184373.5924,30542.7231},
        {183863.1148,30542.7231},{183863.1148,30642.7231},{184473.5924,30642.7231},{184473.5924,29642.7231},
        {184773.5924,29642.7231},{184773.5924,33102.7231},{182873.5924,33102.7231},{182873.5924,29542.7231}
    };

    Door myDoor;
    myDoor.p1 = { 184773.5924,33102.7231 };
    myDoor.p2 = { 184773.5924,32202.7231 };
    myDoor.isOpenInward = false;

    map<string, vector<double>> items =
    {
        {"fridge", {1220, 1330}},
        {"shelf-1", {1000, 400}},
        {"shelf-2", {1000, 400}},
        {"overShelf-1", {600, 400}},
        {"overShelf-2", {600, 400}},
        {"overShelf-3", {600, 400}}
    };

    runTest(boundary, myDoor, items, "Test Case 4 (Extra Large Room)");
}

int main()
{
    testCase1();
    testCase2();
    testCase3();
    testCase4();
    return 0;
}