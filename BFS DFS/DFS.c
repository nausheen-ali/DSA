#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define N 6

int time;

enum color{WHITE,GRAY,BLACK};

struct DFSTable
{
    int st;
    int ft;
    int pi;
    int color;
} dfs[N];

void initGraph(int G[][N])
{
    int u;
    for (u = 0; u < N; u++)
    {
        dfs[u].color = WHITE;
        dfs[u].pi = -1;
        dfs[u].st = dfs[u].ft = 0;
    }
}

void DFS_VISIT(int G[][N], int u)
{
    time = time + 1;
    dfs[u].color = GRAY;
    dfs[u].st = time;

    int v;
    for (v = 0; v < N; v++)
    {
        if (G[u][v] == 1)
        {
            if (dfs[v].color == WHITE)
            {
                dfs[v].pi = u;
                DFS_VISIT(G, v);
            }
        }
    }
    time = time + 1;
    dfs[u].color = BLACK;
    dfs[u].ft = time;
}

void DFS(int G[][N])
{
    initGraph(G);
    time = 0;

    int u;
    for (u = 0; u < N; u++)
    {
        if (dfs[u].color == WHITE)
            DFS_VISIT(G, u);
    }
}

void printTable()
{
    int v;

    printf("\n DFS Table: \n");
    printf("\n ID \t CLR \t PI \t ST \t FT");

    for (v = 0; v < N; v++)
    {
        printf("\n %d \t %d \t %d \t %d \t %d", v, dfs[v].color, dfs[v].pi, dfs[v].st, dfs[v].ft);
    }
}

int main()
{
    int G[][N] = {{0, 1, 0, 1, 0, 0},
                  {0, 0, 0, 0, 1, 0},
                  {0, 0, 0, 0, 1, 1},
                  {0, 1, 0, 0, 0, 0},
                  {0, 0, 0, 1, 0, 0},
                  {0, 0, 0, 0, 0, 1}};

    DFS(G);

    printTable();
}
