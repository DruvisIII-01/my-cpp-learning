# 快速幂与模运算

> 1 题。O(log b) 求 a^b mod m，也是逆元/矩阵快速幂基础。

## 要点

- while(b){if(b&1)ans=ans*base%m;base=base*base%m;b>>=1;}
- 模素数逆元 a^(p-2)
- 指数底数都要 long long

## 易错

- mod==1 要特判。

## 文件

`ABC448-E.cpp`
