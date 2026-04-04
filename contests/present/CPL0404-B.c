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