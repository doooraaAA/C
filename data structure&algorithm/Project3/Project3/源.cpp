#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include"stdlib.h"
#define MaxVertexNum 100     //������󶥵���
typedef struct {
    char vexs[MaxVertexNum];        //�����
    int edges[MaxVertexNum][MaxVertexNum];   //�ڽӾ���
    int n, e;          //ͼ�еĶ�����n�ͱ���e
}MGraph;
//=========�����ڽӾ���=======
void CreatMGraph(MGraph& G)
{
    int i, j, k;
    char a;
    printf("Input VertexNum(n) and EdgesNum(e): ");
    scanf("%d,%d", &G.n, &G.e);         //���붥�����ͱ���
    scanf("%c", &a);
    printf("Input Vertex string:");
    for (i = 0; i < G.n; i++)
    {
        scanf("%c", &a);
        G.vexs[i] = a;             //���붥����Ϣ�����������
    }
    for (i = 0; i < G.n; i++)
        for (j = 0; j < G.n; j++)
            G.edges[i][j] = 0;    //��ʼ���ڽӾ���
    printf("Input edges,Creat Adjacency Matrix\n");
    for (k = 0; k < G.e; k++) {       //����e���ߣ������ڽӾ���
        scanf("%d%d", &i, &j);        //����ߣ�Vi��Vj���Ķ������
        G.edges[i][j] = 1;
        G.edges[j][i] = 1;
    }
}

//=========�����־������Ϊȫ�ֱ���=======
typedef enum { FALSE, TRUE } Boolean;
Boolean visited[MaxVertexNum];

//========DFS��������ȱ����ĵݹ��㷨======
void DFSM(MGraph& G, int i)
{
    printf("%c", G.vexs[i]);  // ���ʶ���Vi
    visited[i] = TRUE;  // ������Vi���Ϊ�ѷ���

    for (int j = 0; j < G.n; j++) {
        if (G.edges[i][j] == 1 && !visited[j]) {
            DFSM(G, j);  // �ݹ������Vi������δ���ʹ��Ķ���
        }
    }
}
void DFS(MGraph& G)
{
    int i;
    for (i = 0; i < G.n; i++)
        visited[i] = FALSE;            //��־������ʼ��
    for (i = 0; i < G.n; i++)
        if (!visited[i])              //Viδ���ʹ�
            DFSM(G, i);               //��ViΪԴ�㿪ʼDFS����
}
//===========BFS��������ȱ���=======
void BFS(MGraph& G, int k)
{   //��VkΪԴ������ڽӾ����ʾ��ͼG���й����������
    int i, j, f = 0, r = 0;
    int cq[MaxVertexNum];        //�������
    for (i = 0; i < G.n; i++)
        visited[i] = FALSE;             //��־������ʼ��
    for (i = 0; i < G.n; i++)
        cq[i] = -1;                    //���г�ʼ��
    printf("%c", G.vexs[k]);     //����Դ��Vk
    visited[k] = TRUE;
    cq[r] = k;          //Vk�ѷ��ʣ�������ӡ�
    while (cq[f] != -1 && f < G.n) {
        i = cq[f]; f = f + 1;
        for (j = 0; j < G.n; j++)
        {
            if (G.edges[i][j] == 1 && !visited[j]) {
                visited[j] = TRUE;
                r = r + 1;
                cq[r] = j;
                printf("%c", G.vexs[j]);
            }
        }
    }
}
//==========main=====
int main()
{
    MGraph G;
    CreatMGraph(G);          //�����ڽӾ���
    printf("Print Graph DFS: ");
    DFS(G);                  //������ȱ���
    printf("\n");
    printf("Print Graph BFS: ");
    BFS(G, 3);             //�����Ϊ3�Ķ��㿪ʼ������ȱ���
    printf("\n");
}
