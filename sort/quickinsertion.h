#ifndef _NTQUICKIN
#define _NTQUICKIN
#include "../nTVector.h"

void quickInsertionSortR(nTVector *v, int l, int r);

void quickInsertionSort(nTVector *v){
	quickInsertionSortR(v,0,v->getSize()-1);
}

nTtype quickInsertionSortMed(nTtype a, nTtype b, nTtype c){
	nTtype mid=a;
    if((a<b&&b<c)||(c<b&&b<a))
        mid=b;
	else if((a<c&&c<b)||(b<c&&c<a))
        mid=c;
    return mid;
}

void quickInsertionSortInsertion(nTVector *v, int l, int r){
	for(int i=1+l;i<=r;i++){
		nTtype pivo=v->at(i);
		int j=i-1;
		while(j>=0&&pivo<v->at(j)){
			v->set(j+1,v->at(j));
			j--;
		}
		v->set(j+1,pivo);
	}
}

void quickInsertionSortR(nTVector *v, int l, int r){
	if(r-l<50){
		quickInsertionSortInsertion(v,l,r);
	}else{
		int i=l,j=r;
		nTtype pivo=quickInsertionSortMed(v->at(l),v->at((l+r)/2),v->at(r));
		while(i<=j){
			while(v->at(i)<pivo)i++;
			while(v->at(j)>pivo)j--;	
			if(i<=j) v->swap(i++,j--);
		}
		if(l<j)quickInsertionSortR(v,l,j);	
		if(r>i)quickInsertionSortR(v,i,r);
	}
}
#endif