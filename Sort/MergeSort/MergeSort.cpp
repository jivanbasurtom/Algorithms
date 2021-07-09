#include "MergeSort.h"

MergeSort::MergeSort(int *DirArray,int *DirAux,int *Data)
{
    Dir_Array=DirArray;
    Dir_Aux=DirAux;
    NumDat=Data;
    for(int i=0;i<*NumDat;i++)
    {
        *(Dir_Aux+i)=*(DirArray+i);
    }
}

MergeSort::~MergeSort()
{
    Dir_Array=new int;
    delete Dir_Array;
    Dir_Array=NULL;
    Dir_Aux=new int;
    delete Dir_Aux;
    Dir_Aux=NULL;
}

void MergeSort::Merge(int low,int middle,int high)
{
    int i=low;
    int j=middle+1;
    for(int k=low;k<=high;k++)
    {
        if(i>middle)                            *(Dir_Array+k)=*(Dir_Aux+(j++));
        else if(j>high)                         *(Dir_Array+k)=*(Dir_Aux+(i++));
        else if((*(Dir_Aux+i)-*(Dir_Aux+j))>0)  *(Dir_Array+k)=*(Dir_Aux+(j++));
        else                                    *(Dir_Array+k)=*(Dir_Aux+(i++)); 
    }

    for(int k=low;k<=high;k++)  
    {
        *(Dir_Aux+k)=*(Dir_Array+k);
    }
}

void MergeSort::Sort(int low,int high)
{
    if(high<=low) return;
    int middle=low+(high-low)/2;
    Sort(low,middle);
    Sort(middle+1,high);
    if(*(Dir_Array+middle+1)-*(Dir_Array+middle)>0) return; //stop if already sort
    Merge(low,middle,high);
}

void MergeSort::InitSort()
{
    Sort(0,*NumDat-1);
}