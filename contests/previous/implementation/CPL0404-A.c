#include <stdio.h>
#include <stdbool.h>

int a[114514] ;

int main(){
    int n, u ; scanf("%d%d", &n, &u) ;
    for(int i = 1 ; i <= n ; i++) scanf("%d", &a[i]) ;
    int k ; scanf("%d", &k) ;

    int ans = 0 ;
    bool find = false ;
    for(int i = u ; i <= n ; i++){
        ans += a[i] ;
        a[i] = 0 ;
        if(i == k) {
            find = true ;
            break ;
        }
    }
    if(!find){
        for(int i = n ; i >= 1 ; i--){
            ans += a[i] ;
            a[i] = 0 ;
            if(i == k){
                find = true ;
                break ;
            }
        }
    }
    printf("%d", ans) ;
    return 0 ;
}

/* ######################################################################
 * 【题面与关键思路】CPL0404-A（环形数组模拟）
 * 标签：难度 未知来源 | 模拟
 *
 * 关键思路：从起点 u 沿环形顺序累加到目标 k 并清零，纯下标模拟。
 * ###################################################################### */
