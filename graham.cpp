#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


struct point { // структура точки 
    long long x, y;
};

struct vec { // структура вектора
    long long x, y;

    vec(point a, point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
};


long long cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x; 
}

vector<point> graham(vector<point> points, long long n) {
    long long minIndex = 0;
    for (long long i = 1; i < n; i++) {
        if (points[i].y < points[minIndex].y ||
            (points[i].y == points[minIndex].y && points[i].x < points[minIndex].x)) {
            minIndex = i;
        }
    } //нахожу самую нижнюю из самых левых точек и нарекаю стартовой

    swap(points[0], points[minIndex]);

    sort(points.begin() + 1, points.end(), [&points](point a, point b) {
        return cross(vec(points[0], a), vec(points[0], b)) > 0; //порядок правильный, если знак векторного произведения положительный
        }); //сортирую все точки относительно стартовой по часовой стрелке

    vector<point> hull = { points[0], points[1] }; //оболочка будет как стек

    for (long long i = 2; i < n; i++) {
        while (hull.size() >= 2 &&
            cross(vec(hull[hull.size() - 2], hull[hull.size() - 1]), vec(hull[hull.size() - 1], points[i])) <= 0)
        { //иду по точкам против часовой стрелки
          //при этом помню, что нет углов с поворотом направо
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    return hull;
}

// сложность без учета сортировки: О(n)
// сложность c учетом сортировки: О(n log n)
// общая сложность: О(n log n)
int main()
{
    long long n;
    cin >> n;
    vector<point> P(n);

    for (auto& p : P) {
        cin >> p.x >> p.y;
    }

    vector<point> hull = graham(P, n);

}
