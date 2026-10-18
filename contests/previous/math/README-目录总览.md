# 数学（math）总览

| 子目录 | 内容 | 题数 |
| --- | --- | --- |
| `math/prefix-sum` | 前缀和：区间和、计数前缀和、DP 优化、二维/加权前缀和（含差分+前缀和） | 16 |
| `math/difference` | 差分：区间加减、二维差分 | 1 |
| `math/number-theory` | 数论：gcd/lcm、筛法、约数、同余、质因数分解 | 15 |
| `math/patterns` | 规律与公式推导：不变量、奇偶性、抽屉原理、分类讨论 | 18 |
| `math/geometry` | 计算几何与整点计数 | 4 |
| `math/bitwise` | 位运算与逐位贪心 | 4 |
| `math/combinatorics` | 组合数学：计数、容斥、组合数 | 3 |
| `math/fast-power` | 快速幂与模运算 | 1 |

## 为什么前缀和/差分放在 math 而不是 simple-algorithms

- 它们是"序列预处理"技巧，几乎总是服务于 DP / 数论 / 组合计数。
- `simple-algorithms` 收的是"排序、哈希"这类可独立成题的基础工具。
- 两者互为逆运算，放同一父目录便于对照。

## 学习顺序建议

1. `prefix-sum` + `difference` —— 最常用、性价比最高。
2. `number-theory` —— gcd/筛法/约数，配合 `fast-power` 学逆元。
3. `combinatorics` —— 计数与容斥。
4. `patterns` —— 无固定套路，靠积累。
5. `bitwise` / `geometry` —— 按需补。
