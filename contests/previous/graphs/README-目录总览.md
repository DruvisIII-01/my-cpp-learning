# 图论（graphs）总览

| 子目录 | 内容 | 题数 |
| --- | --- | --- |
| `graphs/bfs` | 广搜：无权最短路、多源扩散、染色 | 2 |
| `graphs/dfs` | 深搜：遍历、回溯、子树统计 | 2 |
| `graphs/shortest-path` | 最短路：Dijkstra 等 | 1 |
| `graphs/mst` | 最小生成树：Kruskal / Prim | 2 |
| `graphs/toposort` | 拓扑排序、DAG 上 DP | 3 |
| `graphs/tarjan` | Tarjan / 强连通分量 | 2 |
| `graphs/2sat` | 2-SAT | 1 |

> 树形 DP 已移到 `dp/tree`（按"DP 的应用场景"归类，避免与图论遍历混在一起）。

## 学习顺序建议

1. `bfs` / `dfs` —— 先把图的遍历写熟（邻接表 + 访问标记）。
2. `toposort` —— DAG 线性化与 DAG 上 DP。
3. `shortest-path` + `mst` —— 两大经典图论算法，注意非负权/连通性等前提。
4. `tarjan` + `2sat` —— 强连通分量及其最重要的应用。

## 缺口提示

- 还没有**二分图匹配、网络流、树上倍增 LCA、树链剖分、差分约束、欧拉路**的题。
