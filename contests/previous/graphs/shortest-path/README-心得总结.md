# 最短路（graphs/shortest-path）

> 本目录共 **1** 个题解文件（2026-10 第三轮整理新建）。

## 一、这一类题在考什么

本目录从单源最短路起步，Dijkstra 是**非负权图**的标准解法。

## 二、关键思路与套路

- **堆优化 Dijkstra 模板（LGP4779）**：小根堆存 `(dis, u)`，弹出时 `if (d != dis[u]) continue` 跳过过期状态，松弛成功再入堆，复杂度 O((n+m) log m)。
- **为什么不能有负权**：Dijkstra 依赖"出堆即定型"，负权会破坏这个性质，此时要用 Bellman-Ford / SPFA 或 Johnson。
- **INF 的处理**：`dis[]` 初值取 `LLONG_MAX/4` 这类"足够大但不会溢出"的值，判断可达用 `dis[t] == INF`。
- **多源最短路**：把所有源点初始 `dis = 0` 一起入堆即可（与多源 BFS 同思路）。
- **后续可补**：Floyd（O(n³) 全源）、SPFA/Bellman-Ford（负权、判负环）、0-1 BFS（边权只有 0/1）、分层图最短路。

## 三、最容易踩的坑

- `#define int long long` 会让 `priority_queue<pair<int,int>, ..., greater<>>` 仍然可用，但边权与距离相乘时要留意溢出；另外注意题目是单向边还是双向边（本题是单向）。

## 四、本目录文件清单

`LGP4779.cpp`
