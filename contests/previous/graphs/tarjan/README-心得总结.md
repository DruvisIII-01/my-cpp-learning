# Tarjan 与强连通分量

> 2 题。dfn/low + 栈，SCC/割点/割边通用。

## 要点

- low[v]>=dfn[u] 判割点
- low[u]==dfn[u] 弹栈得 SCC
- 与 2-SAT 联用

## 易错

- 多测清 dfn/low/top。

## 文件

`ABC478-E.cpp` · `LGB3609.cpp`
