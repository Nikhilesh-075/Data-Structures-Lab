#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
struct Queue
{
    int front,rear,size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue=(struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity=capacity;
    queue->front=queue->size=0;
    queue->rear=capacity-1;
    queue->array=(int*)malloc(queue->capacity*sizeof(int));
    return queue;
}

int isEmpty(struct Queue* queue)
{
    return (queue->size==0);
}

void enqueue(struct Queue* queue,int item)
{
    if (isFull(queue))
        return;
    queue->rear=(queue->rear+1)%queue->capacity;
    queue->array[queue->rear]=item;
    queue->size=queue->size+1;
}

int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return -1;
    int item=queue->array[queue->front];
    queue->front=(queue->front+1)%queue->capacity;
    queue->size=queue->size-1;
    return item;
}

int isFull(struct Queue* queue)
{
    return (queue->size==queue->capacity);
}

struct Graph
{
    int numVertices;
    int** adjMatrix;
};

struct Graph* createGraph(int numVertices)
{
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices=numVertices;
    graph->adjMatrix=(int**)malloc(numVertices*sizeof(int*));
    for(int i=0;i<numVertices;i++)
    {
        graph->adjMatrix[i]=(int*)malloc(numVertices*sizeof(int));
    }
    for(int i=0;i<numVertices;i++)
    {
        for(int j=0;j<numVertices;j++)
        {
            graph->adjMatrix[i][j]=0;
        }
    }
    return graph;
}

void addEdge(struct Graph* graph,int src,int dest)
{
    graph->adjMatrix[src][dest]=1;
    graph->adjMatrix[dest][src]=1;
}

void BFS(struct Graph* graph,int startVertex)
{
    struct Queue* queue=createQueue(MAX_VERTICES);
    int visited[MAX_VERTICES];
    for (int i=0;i<MAX_VERTICES;i++)
    {
        visited[i]=0;
    }
    visited[startVertex]=1;
    enqueue(queue,startVertex);
    while(!isEmpty(queue))
    {
        int currentVertex=dequeue(queue);
        printf("%d ",currentVertex);
        for(int i=0;i<graph->numVertices;i++)
        {
            if(graph->adjMatrix[currentVertex][i]==1 && !visited[i])
            {
                visited[i]=1;
                enqueue(queue,i);
            }
        }
    }
    free(queue);
}

void DFSUtil(struct Graph* graph,int vertex,int visited[])
{
    visited[vertex]=1;
    printf("%d ",vertex);
    for(int i=0;i<graph->numVertices;i++)
    {
        if(graph->adjMatrix[vertex][i]==1 && !visited[i])
        {
            DFSUtil(graph,i,visited);
        }
    }
}

int isConnected(struct Graph* graph)
{
    int visited[MAX_VERTICES];
    for (int i=0;i<MAX_VERTICES;i++)
    {
        visited[i]=0;
    }
    DFSUtil(graph,0,visited);
    for(int i=0;i<graph->numVertices;i++)
    {
        if(!visited[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    struct Graph* graph=createGraph(5);
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,3);
    addEdge(graph,2,4);
    printf("BFS traversal: ");
    BFS(graph,0);
    printf("\n");
    if(isConnected(graph))
    {
        printf("The graph is connected.\n");
    }
    else
    {
        printf("The graph is not connected.\n");
    }
    for(int i=0; i<graph->numVertices;i++)
    {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
    return 0;
}

