// 1. 单源最短路径问题
    // 无权图的单源最短路径
    // 无权图是一种特殊的带权图，只是权值都是1。
    // 1. BFS算法求单源最短路径
    bool visited[MAX_VERTEX_NUM];

    void BFS_Min_Distance(Graph G, int u){
        for(int i = 0; i < G.vexnum; i++){
            d[i] = INFINITY; // 1. 初始化最短路径长度
            path[i] = -1;   // 2. 最短路径的前驱结点
        }

        d[u] = 0;
        visited[u] = true;
        EnQueue(Q, u);
        while(isEmpty(Q) != true){
            DeQueue(Q, v);
            for(w = FirstNeighbor(G, u); w >= 0; w = NextNeighbor(G, u, w)){
                if(visited[w] == false){
                    d[w] = d[v] + 1; // 1. 更新最短路径长度
                    path[w] = u; // 2. 更新路径的前驱结点
                    visited[w] = true;
                    Enqueue(Q, w);
                }
            }
        }
    }

    // 2. 带权图的单源最短路径
    // Dijkstra算法求单源最短路径
    // 初始： 从 V0 开始，初始化三个数组信息如下：
    // 1. final[]，标记各个顶点是否已求出最短路径
    // 2. dist[]，存放各个顶点到 V0 的最短路径长度
    // 3. path[]，存放各个顶点的前驱结点
    // 第一步，循环遍历所有结点，找到final[]为false的结点中dist[]最小的结点Vi，令false[i] = true
    // 第二步，检查所有与Vi相邻的结点V，若final[j]为false，则更新dist[]和path[]
    // 重复以上两步，直到final[]全部为true
    // 时间复杂度：O(n^2) = O(|V|^2)

    // 如果权值为负数，Dijkstra 算法不适用







// 2. 每对顶点间的最短路径