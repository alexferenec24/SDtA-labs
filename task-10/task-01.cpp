#include <iostream>
#include <iomanip>

using namespace std;

const int N = 6;
const int INF = 1000000;

void fillMatrix(int a[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            a[i][j] = 0;

    a[0][2] = 2;
    a[2][0] = 2;

    a[1][2] = 6;
    a[2][1] = 6;

    a[1][3] = 4;
    a[3][1] = 4;

    a[3][4] = 4;
    a[4][3] = 4;

    a[0][4] = 8;
    a[4][0] = 8;

    a[2][5] = 9;
    a[5][2] = 9;
}

void printMatrix(int a[N][N])
{
    cout << "1. Adjacency matrix:\n\n";
    cout << "    ";
    for (int i = 0; i < N; i++)
        cout << setw(4) << i + 1;
    cout << "\n";

    for (int i = 0; i < N; i++)
    {
        cout << setw(4) << i + 1;
        for (int j = 0; j < N; j++)
            cout << setw(4) << a[i][j];
        cout << "\n";
    }
    cout << "\n";
}

bool isCompleteGraph(int a[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i != j && a[i][j] == 0)
                return false;

    return true;
}

void printAdjList(int a[N][N])
{
    cout << "3. Adjacency list:\n\n";
    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << ": ";
        bool first = true;
        for (int j = 0; j < N; j++)
        {
            if (a[i][j] != 0)
            {
                if (!first)
                    cout << ", ";
                cout << "(" << j + 1 << ", weight = " << a[i][j] << ")";
                first = false;
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

void floyd(int a[N][N], int dist[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else if (a[i][j] != 0)
                dist[i][j] = a[i][j];
            else
                dist[i][j] = INF;
        }

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}

double averagePathLength(int dist[N][N])
{
    int sum = 0;
    int count = 0;

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (dist[i][j] != INF)
            {
                sum += dist[i][j];
                count++;
            }

    if (count == 0)
        return 0;

    return (double)sum / count;
}

int degreeOfVertex(int a[N][N], int v)
{
    int degree = 0;
    for (int i = 0; i < N; i++)
        if (a[v][i] != 0)
            degree++;
    return degree;
}

void findSingleNeighborVertices(int a[N][N])
{
    cout << "5. Vertices connected with only one other vertex:\n";
    bool found = false;

    for (int i = 0; i < N; i++)
    {
        if (degreeOfVertex(a, i) == 1)
        {
            found = true;
            for (int j = 0; j < N; j++)
            {
                if (a[i][j] != 0)
                {
                    cout << "Vertex " << i + 1
                         << ", distance to nearest vertex = "
                         << a[i][j] << "\n";
                }
            }
        }
    }

    if (!found)
        cout << "There are no such vertices.\n";

    cout << "\n";
}

void countSingleNeighborVertices(int a[N][N])
{
    int count = 0;

    cout << "6. Number of vertices connected with only one other vertex:\n";
    cout << "Count = ";

    for (int i = 0; i < N; i++)
        if (degreeOfVertex(a, i) == 1)
            count++;

    cout << count << "\n";

    if (count > 0)
    {
        cout << "Their numbers: ";
        for (int i = 0; i < N; i++)
            if (degreeOfVertex(a, i) == 1)
                cout << i + 1 << " ";
        cout << "\n";
    }

    cout << "\n";
}

void findMaxThreeCityRoute(int a[N][N])
{
    int maxSum = -1;
    int v1 = -1, v2 = -1, v3 = -1;
    int w1 = 0, w2 = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (a[i][j] != 0)
            {
                for (int k = 0; k < N; k++)
                {
                    if (a[j][k] != 0 && i != k && i != j && j != k)
                    {
                        int sum = a[i][j] + a[j][k];
                        if (sum > maxSum)
                        {
                            maxSum = sum;
                            v1 = i;
                            v2 = j;
                            v3 = k;
                            w1 = a[i][j];
                            w2 = a[j][k];
                        }
                    }
                }
            }
        }
    }

    cout << "7. Route through three cities with the largest total distance:\n";
    if (maxSum != -1)
    {
        cout << "(" << v1 + 1 << ") --- " << w1
             << " --- (" << v2 + 1 << ") --- " << w2
             << " --- (" << v3 + 1 << ")\n";
        cout << "Total distance = " << maxSum << "\n";
    }
    else
    {
        cout << "Such route was not found.\n";
    }
    cout << "\n";
}

bool used[N];
int path[N];
bool hamiltonFound = false;

void hamiltonDfs(int a[N][N], int pos)
{
    if (hamiltonFound)
        return;

    if (pos == N)
    {
        hamiltonFound = true;
        return;
    }

    int last = path[pos - 1];

    for (int next = 0; next < N; next++)
    {
        if (!used[next] && a[last][next] != 0)
        {
            used[next] = true;
            path[pos] = next;

            hamiltonDfs(a, pos + 1);

            if (hamiltonFound)
                return;

            used[next] = false;
        }
    }
}

void findHamiltonPath(int a[N][N])
{
    hamiltonFound = false;

    for (int start = 0; start < N; start++)
    {
        for (int i = 0; i < N; i++)
            used[i] = false;

        used[start] = true;
        path[0] = start;

        hamiltonDfs(a, 1);

        if (hamiltonFound)
        {
            cout << "8. It is possible to visit all vertices only once.\n";
            cout << "One of the possible routes: ";
            for (int i = 0; i < N; i++)
            {
                cout << path[i] + 1;
                if (i != N - 1)
                    cout << " -> ";
            }
            cout << "\n\n";
            return;
        }
    }

    cout << "8. It is impossible to visit all vertices only once.\n\n";
}

int main()
{
    int a[N][N];
    int dist[N][N];

    fillMatrix(a);

    printMatrix(a);

    cout << "2. Is the graph complete?\n";
    if (isCompleteGraph(a))
        cout << "Yes, the graph is complete.\n\n";
    else
        cout << "No, the graph is not complete.\n\n";

    printAdjList(a);

    floyd(a, dist);
    cout << "4. Average path length between all vertices = "
         << fixed << setprecision(2)
         << averagePathLength(dist) << "\n\n";

    findSingleNeighborVertices(a);
    countSingleNeighborVertices(a);
    findMaxThreeCityRoute(a);
    findHamiltonPath(a);

    return 0;
}