// 广度优先 BFS 要点
// 1. 找到与一个顶点相邻的所有顶点
// 2. 标记访问过的顶点
// 3. 需要一个辅助队列标记访问过的顶点

bool visited[MAX_VERTEX_NUM];

void BFS(Graph G, int v){
    visit(v);
    visited[v] = true;
    Enqueue v;
    while(isEmpty(Q) != true){
        DeQueue(Q, v);
        for(w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)){
            if(visited[w] != true){
                visit(w);
                visited[w] = true;
                Enqueue(Q, w);
            }
        }
    }
}