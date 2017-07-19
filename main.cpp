/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: anirudh
 *
 * Created on 16 July, 2017, 11:11 AM
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
using namespace std;

int check(int t,int i,int s, int a, int *starting_time, int *frequency_time){
    int k; int p=starting_time[i];
    while (1){
        k= p+frequency_time[i];
        if (k>a) return p;
        else if ((k-t)>=s) return k;
        p=k;
    }
}

void sight_seeing(){
    int c,s,a;
    scanf("%d\n%d\n%d",&c,&s,&a);
    int *starting_time=(int *)calloc(c,sizeof(int));
    int *frequency_time=(int *)calloc(c,sizeof(int));
    int *duration_time=(int *)calloc(c,sizeof(int));
    int *toured_cities = (int *)calloc(c,sizeof(int));
    
    for (int i=1;i<c;i++){
        scanf("%d",&starting_time[i]);
        scanf("%d",&frequency_time[i]);
        scanf("%d",&duration_time[i]);
        toured_cities[i]=0;
    }    
    int t = 0;int x = 0;int i=1;int k;bool q;
    while (t<a){
        if (i==c) break;
    if ((starting_time[i]-t)>=s) {
        k=starting_time[i]; 
        x++;
    }
    else{
       k = check(t,i,s,a,starting_time,frequency_time);
       if ((k+duration_time[i])<a) x++;
       else if ((k+duration_time[i])==a)
       {
           if (i<c-1) k=starting_time[i];
       }
    }
    t=k+duration_time[i];
    if (t>a) toured_cities[i]=0;
    else toured_cities[i]=1;
    i++;
    }
    for (int i=1;i<c;i++){
        if (toured_cities[i]==1) q=1;
        else q=0;
    }
    if (q==1 && x>=0) printf("The maximum sightseeing possible %d \n",x);
    else printf("Sightseeing is not Impossible\n");
    starting_time = (int *)realloc(starting_time,0);
    frequency_time = (int *)realloc(frequency_time, 0);
    duration_time = (int *)realloc(duration_time,0);
    toured_cities = (int *)realloc(toured_cities,0);
}

/*
 * 
 */
int main(int argc, char** argv) {
    int n;
    scanf("%d",&n);
    while (n--){
        sight_seeing();
    }
    return 0;
}

