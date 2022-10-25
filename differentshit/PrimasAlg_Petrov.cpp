// Алгоритм Прима для построения максимального дерева, Петров Артем Е., НКНбд-02-21, 1032219251

#include <cstring>
#include <iostream>
using namespace std;

// число вершин
#define V 11
// Создадим матрицу весов размера VxV

int G[V][V] = {
    {0, 12, 0, 0, 0, 0, 0, 0, 15, 0, 0},
    {12, 0, 15, 0, 40, 7, 0, 0, 0, 0, 0},
    {0, 15, 0, 20, 50, 0, 0, 0, 0, 0, 0},
    {0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 40, 50, 0, 0, 3, 0, 0, 0, 0, 0},
    {0, 7, 0, 0, 3, 0, 31, 20, 0, 0, 0},
    {0, 0, 0, 0, 0, 31, 0, 36, 30, 0, 0},
    {0, 0, 0, 0, 0, 20, 36, 0, 0, 50, 0},
    {15, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 50, 0, 0, 100},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100},
    };

int main() {
    int no_edge;  // номер вершины
    int sum=0;
    // создадим массив, чтобы проследить текущую вершину
    // позже выбранная на шаге цикла станет true, иначе false
    int selected[V];

    // Сдеалем начальную вершину false изначально
    memset(selected, false, sizeof(selected));

    // 0-первая по счету вершина
    no_edge = 0;

    // число вершины всегда будет вида V-1

    // сделаем начальную вершину true, чтобы начать с нее
    selected[0] = true;

    int x;  //  номер строки
    int y;  //  номер столбца

    // напечатаем вершины и вес их ребра
    cout << "Edge"
        << " : "
        << "Weight";
    cout << endl;
    while (no_edge < V - 1) 
    {
    // Для каждый вершины найдем все смежный вершины, вычислим расстояние от вершины. 
    //  если вершина уже в списке, то выбрасываем ее, выбираем новую, близлежайшую к прошлой

        int min = 0;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++) 
        {
            if (selected[i]) 
            {
                for (int j = 0; j < V; j++) 
                {
                    if (!selected[j] && G[i][j]) 
                    {  // вершина существует и не была выбрана еще 
                        if (min < G[i][j]) 
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        sum+=G[x][y];
        cout << x+1 << " - " << y+1 << " :  " << G[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;
    }
    cout << "T_max=" << sum << endl;
    return 0;
}
