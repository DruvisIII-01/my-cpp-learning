#include <stdio.h>
#include <stdbool.h>
#include <string.h>


int main(){
    int M ; scanf("%d", &M) ;
    char word[300][30] ;
    int cnt[300] = {0} ;
    int len[300] = {0} ;
    bool is_valid = true ; 
    for(int t = 1 ; t <= M ; t++){
        scanf("%s", word[t]) ;
        len[t] = strlen(word[t]) ;
    }char sen[114514] ;
    scanf("%s", sen) ;
    int l = strlen(sen) ;

    char token[11111][30] ;
    bool is_spaced = false ;
    int add1 = 0, add2 = 0 ;

    for(int t = 0 ; t < l ; t++){
        token[add1][add2] = sen[t] ;
        bool find = false, is_exact = false ;
        for(int i = 1 ; i <= M ; i++){
            if(add2 + 1 > len[i]) continue ;
            bool cmp = true ;
            for(int j = 0 ; j <= add2 ; j++){
                if(token[add1][j] != word[i][j]){
                    cmp = false ;
                    break ;
                }
            }
            if(cmp) {
                find = true ;
                if(add2 + 1 == len[i]) {
                    is_exact = true ;
                    cnt[i]++ ;
                }
            }
        }is_spaced = !find || is_exact ;
        if(!find) is_valid = false ;
        if(is_spaced) {
            add1++ ;
            add2 = 0 ;
            if(t == l - 1) add1-- ;
        }
        else add2++ ;
    }

    if(is_valid) printf("T\n") ;
    else printf("F\n") ;
    for(int i = 0 ; i <= add1 ; i++) {
        printf("%s ", token[i]) ;
    }printf("\n") ;
    for(int i = 1 ; i <= M ; i++){
        printf("%d\n", cnt[i]) ;
    }
    return 0 ;
}

/* ######################################################################
 * 【题面与关键思路】CPL0404-B（字符串分词与词典匹配）
 * 标签：难度 未知来源 | 字符串模拟
 *
 * 关键思路：逐字符累积并与词典做前缀比对来切分句子，同时统计每个词的出现次数；注意 C 语言的字符串边界处理。
 * ###################################################################### */
