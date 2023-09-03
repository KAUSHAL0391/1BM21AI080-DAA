#include <iostream>
using namespace std;
int a[20][20], reach[20], n;
void dfs(int v) {
    reach[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (a[v][i] && !reach[i]) {
            cout << " " << v << "->" << i;
            dfs(i);
        }
    }
}
int main() {
    int count = 0;
    cout << "\nEnter number of vertices: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        reach[i] = 0;
        for (int j = 1; j <= n; j++) {
            a[i][j] = 0;
        }
    }
    cout << "\nEnter the adjacency matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    dfs(1);
    cout << "\n";
    
    for (int i = 1; i <= n; i++) {
        if (reach[i]) {
            count++;
        }
    }
    if (count == n) {
        cout << "\nGraph is connected";
    } else {
        cout << "\nGraph is not connected";
    }
    return 0;
}