#include <iostream>
#include <vector>

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

vector<point> jarvis(vector<point> points, long long n) {
    long long minIndex = 0;
    for (long long i = 1; i < n; i++) {
        if (points[i].y < points[minIndex].y ||
            (points[i].y == points[minIndex].y && points[i].x < points[minIndex].x)) {
            minIndex = i;
        }
    } //нахожу самую нижнюю из самых левых точек и нарекаю стартовой

    swap(points[0], points[minIndex]);

    vector<point> hull;
    int cur = 0; //храню индекс нужной точки

    while (true) {
        hull.push_back(points[cur]);
        int id = -1;

        for (int i = 0; i < n; i++)
            if (i != cur && (id == -1 || cross
            (vec(points[cur], points[i]),
                    vec(points[cur], points[id])) > 0))
                id = i;
        if (id == 0) { //если id нулевая, то подарок завернут
            break;
        }
        cur = id;
    }
    return hull;
}


// сложность O(h * n), где h - точки выпуклой оболочки
// в худшем случае O(n^2)
int main()
{
    long long n;
    cin >> n;
    vector<point> P(n);

    for (auto& p : P) {
        cin >> p.x >> p.y;
    }

    vector<point> hull = jarvis(P, n);

}
