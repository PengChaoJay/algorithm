#include<stdlib.h>
#include<stdio.h>
#include<string.h>


//创建了next函数，使用的是nextval函数，简化类似aaaaab,设置 aaaaa的下标都是为0,只需要和0进行比较就可以了 
void Next(char * T,int * next)
{
	int i=1,j=0;
	next[1]=0;
	while(i<strlen(T)){
		if(j==0||T[i-1]==T[j-1]){
			i++;
			j++;
			if(T[i-1]!=T[j-1]){
				next[i]=j;
			}else{
				next[i]=next[j];
			}
		}else{
			j=next[j];
		}
	}
}

//参数的含义是：S表示主串，T表示子串，在主串中查找子串第一次出现的位置 
int KMP(char * S,char * T){
	if(strlen(T)==0){
		return 0;
	}
	int next[strlen(T)]; 
	int i=1,j=1;
	while(i<=strlen(S)&&j<=strlen(T)){
		if(j==0||S[i-1]==T[j-1]){
			i++;
			j++;
		}else{
			j=next[j];
		}
	}
	if(j>strlen(T))
		return i-strlen(T);
	return -1;
} 

int main()
{
	int k=KMP("abacadbade","abc");
	printf("%d\n",k);
	return 0;
}




 
