# 基础算法（simple-algorithms）总览

> 2026-10 二次整理：把原来散落在根目录的六个基础算法目录合并到这里，并新增 `sort` 与 `hash`。

| 子目录 | 内容 | 题数 |
| --- | --- | --- |
| `simple-algorithms/sort` | 排序与排序后处理 | 15 |
| `simple-algorithms/hash` | 哈希与计数数组 | 9 |
| `simple-algorithms/binary-search` | 二分 | 5 |
| `simple-algorithms/two-pointers` | 双指针与滑动窗口 | 4 |
| `simple-algorithms/divide-and-conquer` | 分治 | 1 |
| `simple-algorithms/greedy` | 贪心 | 13 |
| `simple-algorithms/brute-force` | 暴力与枚举 | 7 |
| `simple-algorithms/implementation` | 模拟与实现 | 15 |
| **合计** | | **69** |

## 建议学习顺序

1. `implementation` —— 先把模拟写稳，练下标与边界。
2. `brute-force` + `sort` —— 先会暴力，再学会"排序之后怎么用"。
3. `hash` + `greedy` —— 把 O(n²) 降到 O(n)，同时建立贪心直觉。
4. `binary-search` + `two-pointers` —— 两大线性/对数工具，是后面所有优化的基础。
5. `divide-and-conquer` —— 最后补，因为它的难点在"合并"而不是递归。
