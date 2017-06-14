#ifndef _NTQUICK2
#define _NTQUICK2
#include "../nTVector.h"

void quick2SortR(nTVector *v, int l, int r);

void quick2Sort(nTVector *v){
	quick2SortR(v,0,v->getSize()-1);
}

nTtype quick2SortMed(nTtype a, nTtype b, nTtype c){
	nTtype mid=a;
    if((a<b&&b<c)||(c<b&&b<a))
        mid=b;
	else if((a<c&&c<b)||(b<c&&c<a))
        mid=c;
    return mid;
}

void quick2SortR(nTVector *v, int l, int r){
	int i=l,j=r;
	nTtype pivo=quick2SortMed(v->at(l),v->at((l+r)/2),v->at(r));
	while(i<=j){
		while(v->at(i)<pivo)i++;
		while(v->at(j)>pivo)j--;	
		if(i<=j) v->swap(i++,j--);
	}
	if(l<j)quick2SortR(v,l,j);	
	if(r>i)quick2SortR(v,i,r);
}
#endif