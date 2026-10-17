# 数学（math）总览

| 子目录 | 内容 | 题数 |
| --- | --- | --- |
| `math/prefix-sum` | 前缀和：区间和、计数前缀和、DP 优化、二维/加权前缀和 | 16 |
| `math/difference` | 差分：区间加减、二维差分（前缀和的逆运算） | 2 |
| `math/number-theory` | 数论：gcd/lcm、筛法、约数、同余、质因数分解 | 15 |
| `math/combinatorics` | 组合数学：计数、容斥、组合数 | 2 |
| `math/patterns` | 规律与公式推导：不变量、奇偶性、分类讨论 | 14 |
| `math/bitwise` | 位运算与逐位贪心 | 4 |
| `math/geometry` | 计算几何与整点计数 | 3 |
| `math/fast-power` | 快速幂与模运算（逆元、矩阵快速幂的基础） | 1 |

## 为什么前缀和/差分放在 math 而不是 simple-algorithms

- 它们是"**序列预处理**"技巧，和 DP、数论、组合数学一起用（例如 `LGP6323` 是前缀和优化 DP、`CF993H` 是加权前缀和）。
- `simple-algorithms` 收的是"排序、哈希"这类**可以独立成题的基础工具**；而前缀和/差分几乎总是**服务于别的算法**，放在 math 更贴近使用场景。
- 两者互为逆运算，放同一个父目录便于对照学习。

## 学习顺序建议

1. `prefix-sum` + `difference` —— 先掌握这对互逆技巧（最常用、性价比最高）。
2. `number-theory` —— gcd/筛法/约数，配合 `fast-power` 学逆元。
3. `combinatorics` —— 计数与容斥。
4. `patterns` —— 没有固定套路，靠积累。
5. `bitwise` / `geometry` —— 按兴趣和比赛需要补。
