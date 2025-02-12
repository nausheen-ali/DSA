#include<stdio.h>
#include<limits.h>
#define N 7
#define INF INT_MAX

enum color {WHITE,GRAY,BLACK};

typedef struct QUEUE
{
    int front;
    int rear;
    int q[100];
}Queue;

struct BFSTable
{
    int clr;
    int pi;
    int dist;
}bfs[N];

void initQueue(Queue *queue)
{
    queue->front=queue->rear = -1;
}

int isEmpty(Queue *queue)
{
    if ((queue->front==-1)||(queue->front==(queue->rear+1)))
        return 1;
    else
        return 0;
}

void enqueue(Queue *queue,int ele)
{
    if(queue->front==-1)
        queue->front=0;
    queue->rear=queue->rear+1;
    queue->q[queue->rear]=ele;
}

int dequeue(Queue *queue)
{
    if(!isEmpty(queue))
    {
        int temp=queue->q[queue->front];
        queue->front = queue->front+1;
        return temp;
    }
}

void init(int G[][N],int s)
{
    int i;
    for(i=0;i<N;i++)
    {
        bfs[i].clr=WHITE;
        bfs[i].pi=-1;
        bfs[i].dist=INF;
    }
    bfs[s].clr=GRAY;
    bfs[s].dist=0;
}

void BFS (int G[][N],int s)
{
    Queue queue;
    init (G,s);
    initQueue(&queue);
    enqueue(&queue,s);
    while(!isEmpty(&queue))
    {
        int u=dequeue(&queue);
        int v;
        for(v=0;v<N;v++)
        {
            if((G[u][v]==1) && (bfs[v].clr==WHITE))
            {
                enqueue(&queue,v);
                bfs[v].clr=GRAY;
                bfs[v].pi=u;
                bfs[v].dist=bfs[u].dist+1;
            }
        }
        bfs[u].clr=BLACK;
    }
}

void printTable()
{
    int i;
    printf("\n ID \t CLR \t PI \t DIST");
    printf("\n----------------------------------------------------");
    for(i=0;i<N;i++)
    {
        printf("\n %d \t %d \t %d \t %d", i, bfs[i].clr, bfs[i].pi, bfs[i].dist);
    }
    printf("\n----------------------------------------------------");
}

int main()
{
    int G[][N]={{0,1,0,0,0,0,0},
                {1,0,0,0,0,1,1},
                {0,0,0,0,0,0,1},
                {0,0,0,0,0,0,1},
                {0,0,0,0,0,1,1},
                {0,1,0,0,1,0,0},
                {0,1,1,1,1,0,0}};
    Queue queue;
    BFS(G,0);
    printf("\n BSF Table is: \n");
    printTable();
}
