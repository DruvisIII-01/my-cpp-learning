# 前缀和与差分

> 19 题。互逆的一对：前缀和"区间→单点"，差分"单点→区间"。

## 要点

- pre[r]-pre[l-1]；d[l]+=x,d[r+1]-=x
- 计数前缀和 / 前缀和优化 DP
- 二维容斥四个符号别错

## 易错

- 下标统一 1-indexed，前缀和开 long long。

## 文件

`ABC474-E.CPP` · `ABC475-F.CPP` · `ABC478-D.cpp` · `CF1080-D.cpp` · `CF1109-D.cpp` · `CF1125-E.cpp` · `CF640-E.cpp` · `CF784-F.cpp` · `CF790-E.cpp` · `CF806-F.cpp` · `CF817-E.cpp` · `CF827-E.cpp` · `CF898-E.CPP` · `CF971-F.cpp` · `CF993-H.cpp` · `LGB4426.cpp` · `LGP2727.cpp` · `LGP4954.cpp` · `LGP6323.cpp`
