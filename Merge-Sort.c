#include<stdio.h>

void Merge(int arr[],int p, int q, int r)
{
	int n1,n2,i,j,k;
	
	n1 = q-p+1;//# de elementos que tendrá el arreglo izquierdo
	n2 = r-q;//# de elementos que tendrá el arreglo derecho 
	
	//Se agrega un elemento en cada nodo ya que se utilizara un sentinela
	int L[n1+1],R[n2+1]; 

	for(i=1;i<=n1;i++)
		L[i]=arr[p+i-1];
	for(j=1;j<=n2;j++)
		R[j]=arr[q+j];
	
	L[n1+1]=10000002;
	R[n2+1]=10000002;
	
	i=1;
	j=1;
	
	for(k=p;k<=r;k++)
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}
	}
}

void Merge_Sort(int arr[],int p,int r)
{
	int q;
	if(p<r)
	{
		q = ((p+r)/2);
		Merge_Sort(arr,p,q);
		Merge_Sort(arr,q+1,r);
		Merge(arr,p,q,r);
	}
}

int main()
{
	
	int i = 0;
	int arr[6];
	
	for(i=0;i<6;i++)
	{
		scanf("%d",&arr[i]);
	}
	
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    Merge_Sort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
