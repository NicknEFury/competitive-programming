//#include <iostream>
//
//#define all(x) x.begin(), x.end()
//#define fori(x, a, b) for (int i = x; i < a; i += b)
//#define forj(x, a, b) for (int j = x; j < a; j += b)
//#define fork(x, a, b) for (int k = x; k < a; k += b)
//
//using namespace std;
//
//void floydWarshall(vector<vector<int>> &matrix){
//    vector<vector<int>> dist = matrix;
//    fori (1, n, 1) {
//        forj (1, n, 1) {
//            if (i == j)
//                matrix[i][j] = 0;
//            else if (matrix[i][j])
//                dist[i][j] = matrix[i][j];
//            else
//                dist[i][j] = 1e9;
//        }
//    }
//    fork (0, n, 1) {
//        fori (0, n, 1) {
//            forj (0, n , 1) {
//                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//            }
//        }
//    }
//}
