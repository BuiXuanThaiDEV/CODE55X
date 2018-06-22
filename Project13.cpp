#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
using namespace std;

//==============================================================================================================================
void table();
void gotoxy(int x, int y);
void Random(int *prt, int elements);
void swapswap(int *ptr1,int *ptr2);
void InsertionSort(int *ptr,int elements);
void SelectionSort(int *ptr, int elements);
void BubbleSort(int *ptr,int elements);
void QuickSort(int *ptr, int left , int right);
void mmerge(int *ptr, int left, int m, int right);
void MergeSort(int *ptr, int left, int right);
void ExecutionTime(int algorithm, int elements);
double RealTime(int *ptr, int elements, int algorithm);

clock_t G_start, G_finish;
int *OriginalArray;

//==============================================================================================================================
int main(){
    int elements, algorithm=1;
    srand(time(NULL));
    table();
    cout<<"Enter the Array's Elements: ";
    cin>>elements;
    OriginalArray = new int[elements];
    Random(OriginalArray,elements);
    for(algorithm=5;algorithm>0;algorithm--)
        ExecutionTime(algorithm,elements);
    delete[]OriginalArray;
    gotoxy(0,13);
    return 0;
}

//==============================================================================================================================
void Random(int *ptr, int elements){
   for(int i = 0; i < elements; i++)
      *(ptr+i) = -6969+rand();
}

//==============================================================================================================================
void ExecutionTime(int algorithm, int elements){
    int *ReplicaArray=new int[elements];
    int *ReverseArray=new int[elements], i;
    // các lệnh gotoxy dùng để in số liệu vào bảng tạo sẵn
    for(i = 0; i < elements; i++) *(ReplicaArray+i)=*(OriginalArray+i);
    gotoxy(22,1+algorithm*2);
    printf("%.2f",RealTime(ReplicaArray,elements,algorithm));

    gotoxy(39,1+algorithm*2);
    printf("%.2f",RealTime(ReplicaArray,elements,algorithm));

    for(i = 0; i < elements; i++) *(ReverseArray+i)=*(ReplicaArray+elements-1-i);
    gotoxy(56,1+algorithm*2);
    printf("%.2f",RealTime(ReverseArray,elements,algorithm));
    delete[]ReplicaArray;
    delete[]ReverseArray;
}

//==============================================================================================================================
double RealTime(int *ptr, int elements, int algorithm){
    G_start=clock();
    switch(algorithm){
        case 1:
            InsertionSort(ptr,elements);   break;
        case 2:
            BubbleSort(ptr,elements);  break;
        case 3:
            SelectionSort(ptr,elements);   break;
        case 4:
            QuickSort(ptr,0,elements-1);   break;
        case 5:
            MergeSort(ptr,0,elements-1);   break;
    }
    G_finish=clock();
    return (double)(G_finish-G_start);// Tính theo đơn vị ms
}

//==============================================================================================================================
void swapswap(int *ptr1,int *ptr2){
    int temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}

//==============================================================================================================================
void InsertionSort(int *ptr,int elements){
    int i=0,j=0,key=0;
    for(i=1;i<elements;i++){
        key=*(ptr+i);
        j=i-1;
        while(j>=0&&(*(ptr+j)>key)){
            *(ptr+j+1)=*(ptr+j);
            j=j-1;
        }
        *(ptr+j+1)=key;
    }
}

//==============================================================================================================================
void SelectionSort(int *ptr, int elements){
    int i=0,j=0,mmin=0;
    for(i=0;i<elements-1;i++){
        mmin=i;
        for(j=i+1;j<elements;j++)
            if(*(ptr+j)<*(ptr+mmin))
            mmin=j;
        swapswap(ptr+mmin,ptr+i);
    }
}

//==============================================================================================================================
void BubbleSort(int *ptr,int elements){
    int i=0,j=0;
    for(i=0;i<elements-1;i++)
        for(j=0;j<elements-1-i;j++)
        if(*(ptr+j)>*(ptr+j+1))
        swapswap(ptr+j,ptr+j+1);
}

//==============================================================================================================================
void QuickSort(int *ptr, int left , int right){
	if (left <= right){
		int pivot = *(ptr+(left+right)/2);
		int i = left;
		int j = right;
		while (i <= j){
			while (*(ptr+i) < pivot)
				i++;
			while (*(ptr+j) > pivot)
				j--;
			if (i <= j){
				swapswap(ptr+i,ptr+j);
				i++;
				j--;
			}
		}
		if (left < j)
			QuickSort(ptr, left, j);
		if (right > i)
			QuickSort(ptr, i, right);
	}
}

//==============================================================================================================================
void MergeSort(int *ptr, int left, int right){
    if(left<right){
        int m = left+(right-left)/2;
        MergeSort(ptr,left,m);
        MergeSort(ptr,m+1,right);
        mmerge(ptr,left,m,right);
    }
}

void mmerge(int *ptr, int left, int m, int right){
    int i=0,j=0,k=0;
    int *ptrtemp1 = new int[m-left+1];
    int *ptrtemp2 = new int[right-m];
    for(i=0;i<m-left+1;i++)
        *(ptrtemp1+i)=*(ptr+left+i);
    for(j=0;j<right-m;j++)
        *(ptrtemp2+j)=*(ptr+m+j+1);
    i=0;j=0;k=left;
    while(i<m-left+1&&j<right-m){
        if(*(ptrtemp1+i)<*(ptrtemp2+j)){
            *(ptr+k)=*(ptrtemp1+i);
            i++;
        }
        else{
            *(ptr+k)=*(ptrtemp2+j);
            j++;
        }
        k++;
    }
    while(i<m-left+1){
        *(ptr+k)=*(ptrtemp1+i);
        i++;
        k++;
    }
    while(j<right-m){
        *(ptr+k)=*(ptrtemp2+j);
        j++;
        k++;
    }
}

//==============================================================================================================================
void gotoxy(int x, int y){
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}

//==============================================================================================================================
void table(){
    cout<<" ___________________________________________________________________"<<endl;
    cout<<"|  ALG  \\ ARRAY  |     RANDOM     |     SORTED     | REVERSE SORTED |"<<endl;
    cout<<"|________\\_______|________________|________________|________________|"<<endl;
    cout<<"|  INSERTION     |                |                |                |"<<endl;
    cout<<"|________________|________________|________________|________________|"<<endl;
    cout<<"|  BUBBLE        |                |                |                |"<<endl;
    cout<<"|________________|________________|________________|________________|"<<endl;
    cout<<"|  SELECTION     |                |                |                |"<<endl;
    cout<<"|________________|________________|________________|________________|"<<endl;
    cout<<"|  QUICK         |                |                |                |"<<endl;
    cout<<"|________________|________________|________________|________________|"<<endl;
    cout<<"|  MERGE         |                |                |                |"<<endl;
    cout<<"|________________|________________|________________|________________|"<<endl;
    gotoxy(0,13);
}
