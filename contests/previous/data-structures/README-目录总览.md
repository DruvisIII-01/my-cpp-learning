# 数据结构（data-structures）总览

| 子目录 | 内容 | 题数 |
| --- | --- | --- |
| `data-structures/segment-tree` | 线段树与懒标记 | 2 |
| `data-structures/fenwick` | 树状数组 | 2 |
| `data-structures/dsu` | 并查集（含带关系的种类并查集） | 1 |
| `data-structures/stl` | STL 容器技巧 | 6 |
| `data-structures/string` | 字符串处理 | 4 |

## 通用方法论

- 先问"需要支持什么操作"，再选结构：区间修改→线段树；单点改+前缀查→BIT；只要连通性/等价类→并查集；只要极值/计数→STL。
- 能用一个 STL 容器解决的问题不要手写数据结构。
- 懒标记题一定用小数据（n = 4）手推下传顺序。
