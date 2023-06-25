#include<stdio.h>
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int a[n],b[m],res[n+m],i,j,k;
//	i=0,j=0,k=0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("%d",i);
	for(j=0;j<m;j++){
		scanf("%d",&b[j]);
	}
	//for(i = 0 ; i < n+m ; i++)res[i]=0;
	i = 0;
	j = 0;
	while(i<n&&j<m){
		if(a[i]<=b[j]){
			res[k]=a[i];
			i++;
			k++;
		}
		else{
			res[k]=b[j];
			k++;
			j++;
			
		}
	}
	while(i<n){
		res[k]=a[i];
			i++;
			k++;
	}
	while(j<m){
		res[k]=b[j];
			j++;
			k++;
	}	
	
	for(k=0;k<m+n;k++){
		printf("%d ",res[k]);
	}
}
