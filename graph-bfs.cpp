#include<iostream>
#include<queue>
using namespace std;

#define MAX 100   //节点数最大为100
typedef struct node *pnode;
struct node{
    int node_info;
    pnode next;
};

pnode graph[MAX];//邻接链表法表示图
//初始化所有节点无相邻节点
void _init_graph(int n){
    for(int i=0;i<n;i++)
        graph[i]=NULL;
}

//添加边v1-v2
void AddNode(int v1,int v2){
    pnode p=new node;
    p->next=graph[v1];
    p->node_info=v2;
    graph[v1]=p;

    pnode p1=new node;
    p1->next=graph[v2];
    p1->node_info=v1;
    graph[v2]=p1;
}

//读取具有ne个边的图信息
void ReadGraph(int ne){
    int v1,v2;
    cout<<"输入边: v1 v2"<<endl;
    for(int i=0;i<ne;i++){
        cin>>v1>>v2;
        AddNode(v1,v2);
    }
}

int visited[MAX]={0};

void bfs(int start){
    queue<int > s;
    pnode p;
    int t;
    s.push(start);
    visited[start]=1;

    while(!s.empty()){
        t=s.front();
        cout<<t<<endl;
        s.pop();
        p=graph[t];
        while(p){
            if(!visited[p->node_info]){
                s.push(p->node_info);
                visited[p->node_info]=1;
            }
            p=p->next;
        }
    }
}

int main(){
    int nv,ne;
    cout<<"输入顶点数nv和边数ne:"<<endl;
    cin>>nv>>ne;
    _init_graph(nv);
    ReadGraph(ne);
    bfs(0);
    return 0;
}
