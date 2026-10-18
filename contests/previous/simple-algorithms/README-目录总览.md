# 基础算法（simple-algorithms）总览

| 子目录 | 内容 | 题数 |
| --- | --- | --- |
| `simple-algorithms/implementation` | 模拟与实现 | 18 |
| `simple-algorithms/greedy-or-games` | 贪心与博弈 | 17 |
| `simple-algorithms/brute-force` | 暴力与枚举 | 11 |
| `simple-algorithms/sort` | 排序与排序后处理 | 8 |
| `simple-algorithms/hash` | 哈希与计数数组 | 5 |
| `simple-algorithms/binary-search` | 二分 | 3 |
| `simple-algorithms/two-pointers` | 双指针与滑动窗口 | 3 |
| `simple-algorithms/divide-and-conquer` | 分治 | 1 |

## 2026-10 复核后的收窄说明

- `sort` 只保留"**排序本身是解题突破口**"的题（排序后配对、相邻差、装箱、排序后枚举候选）。
- 纯网格模拟、纯枚举、纯公式题已分别移到 `implementation` / `brute-force` / `math/patterns`。
- `hash` 只保留"**用桶/哈希表把值映射成下标或计数**"的题；纯奇偶公式、纯模拟已移出。

## 建议学习顺序

1. `implementation` 2. `brute-force` + `sort` 3. `hash` + `greedy-or-games`
4. `binary-search` + `two-pointers` 5. `divide-and-conquer`
