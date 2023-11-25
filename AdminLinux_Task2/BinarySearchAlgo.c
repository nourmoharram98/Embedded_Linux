#include<stdio.h>

int Binary_Search(int *arr, int size,int key)
{
   int low=0,high=0,mid=0;
   high = size-1;
  // mid = (high+low)/2;
   while(high>=low)
   {
	mid= (high+low)/2;
	if(arr[mid]==key)
	{
	   printf("element found at index %d \n",mid);
	   return mid;
	}
	else if(arr[mid]<key)
	{
           printf("key value is larger than middle value \n");
           low=mid+1;	   
	}
	else if(arr[mid]>key)
	{
           printf("key value is smaller than middle value \n");
	   high=mid-1;
	}
   }
   return -1;
}

void Bubble_Sort(int *arr, int size)
{
   int temp=0;
   int flag=0;
   for(int i=0;i<size-1;i++)
   {
       flag=1;
       for(int j=0;j<size-i-1;j++)
       {
	  if(arr[j]>arr[j+1])
	  {
             temp=arr[j];
	     arr[j]=arr[j+1];
             arr[j+1]=temp;
             flag=0;	     
	  }

       }
   }
}

int main(void)
{
   int array[10]={12,5,64,2,7,9,0,8,4,1};
   int result=999;
   Bubble_Sort(array,10);
   result=Binary_Search(array,10,9);
   if(result != -1 )
   {
      printf("element found at index %d \n",result);
   }
   else
   {
      printf("element not found \n");	   
   }
   return 0;

}



