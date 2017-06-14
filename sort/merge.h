#ifndef _NTMERGE
#define _NTMERGE
#include "../nTVector.h"

void mergeSortR(nTVector *v, int l, int r);
void mergeVec(nTVector *v, int l, int m, int r);

void mergeSort(nTVector *v){
	mergeSortR(v,0,v->getSize()-1);
}

void mergeSortR(nTVector *v, int l, int r){
	if(l<r){
		int m=(l+r)/2;
		mergeSortR(v,l,m);
		mergeSortR(v,m+1,r);
		mergeVec(v,l,m,r);
	}
}

void mergeVec(nTVector *v, int l, int m, int r){
	nTVector *aux=new nTVector;
	aux->alloc(r-l+1);
	int idx1=l;
	int idx2=m+1;
	int idx0=0;
	while(1){
		if(idx1<=m&&idx2<=r){
			if(v->at(idx1)<v->at(idx2)){
				aux->set(idx0++,v->at(idx1++));
			}else{
				aux->set(idx0++,v->at(idx2++));
			}
		}else{
			while(idx1<=m)
				aux->set(idx0++,v->at(idx1++));
			while(idx2<=r)
				aux->set(idx0++,v->at(idx2++));
			aux->copyTo(v);
			aux->dispose();
			break;
		}
	}
}
#endif