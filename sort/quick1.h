#ifndef _NTQUICK1
#define _NTQUICK1
#include "../nTVector.h"

void quick1SortR(nTVector *v, int l, int r);

void quick1Sort(nTVector *v){
	quick1SortR(v,0,v->getSize()-1);
}

void quick1SortR(nTVector *v, int l, int r){
	int i=l,j=r;
	nTtype pivo=v->at((l+r)/2);
	while(i<=j){
		while(v->at(i)<pivo)i++;
		while(v->at(j)>pivo)j--;	
		if(i<=j) v->swap(i++,j--);
	}
	if(l<j)quick1SortR(v,l,j);	
	if(r>i)quick1SortR(v,i,r);
}
#endif