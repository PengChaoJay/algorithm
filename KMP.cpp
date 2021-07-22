#include<stdlib.h>
#include<stdio.h>
#include<string.h>


//������next������ʹ�õ���nextval������������aaaaab,���� aaaaa���±궼��Ϊ0,ֻ��Ҫ��0���бȽϾͿ����� 
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

//�����ĺ����ǣ�S��ʾ������T��ʾ�Ӵ����������в����Ӵ���һ�γ��ֵ�λ�� 
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




 
