
#include <stdio.h>

int graph[10][10];
int visited[10];
int queue[10];
int n;

void BFS(int start)
{
    int front = 0, rear = 0;
    int i, v;

    visited[start] = 1;
    queue[rear] = start;
    rear++;

    while(front < rear)
    {
        v = queue[front];
        front++;

        printf("%d ", v);

        for(i = 0; i < n; i++)
        {
            if(graph[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear] = i;
                rear++;
            }
        }
    }
}

int main()
{
    int e, i, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize graph
    for(i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for(i = 0; i < e; i++)
    {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    BFS(start);

    return 0;
}
