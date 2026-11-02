# 最短路

> 1 题。Dijkstra 适合非负权。

## 要点

- 堆优化：出堆即定型
- 过期状态 if(d!=dis[u]) continue
- INF 取 LLONG_MAX/4

## 易错

- 有负权要换 Bellman-Ford/SPFA。

## 文件

`LGP4779.cpp`
