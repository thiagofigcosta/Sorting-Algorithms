#ifndef _NTVECTOR_
#define _NTVECTOR_
#include <stdlib.h>
#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef int nTtype;

struct nTVector{
	
	private:
		nTtype* vec=NULL;
		bool alloqued=false;
		int size=0;
		void (*sortFunc)(nTVector*);

	public:
		int randMin=0;
		int randMax=20000;

	void fillRand(){
		if(alloqued){
			mt19937 rng;
			rng.seed(high_resolution_clock::now().time_since_epoch().count());
			uniform_int_distribution<nTtype> unif_int_d(randMin, randMax);
			for(int i=0;i<size;)
				vec[i++]=unif_int_d(rng);
		}
	}

	void copyTo(nTVector *to){
		if(alloqued){
			to->alloc(size);
			for(int i=0;i<size;i++)
				to->set(i,vec[i]);
		}
	}

	void push(nTtype v){
		alloc(++size);
		vec[size-1]=v;
	}

	void copyTo(nTVector *to, int start, int end){
		if(alloqued){
			to->alloc(end-start+1);
			for(int i=start;i<=end;i++)
				to->set(i,vec[i]);
		}
	}

	void print(){
		int maxCols=10;
		char separator=' ';

		if(alloqued){
			for(int i=0;i<size;){
				cout<<vec[i++];
				if(i%maxCols==0)
					cout<<endl;
				else
					cout<<separator;
			}
			cout<<endl;
		}
	}

	void print(int start, int end){
		int maxCols=10;
		char separator=' ';

		if(alloqued){
			for(int i=start;i<=end;){
				cout<<vec[i++];
				if(i%maxCols==0)
					cout<<endl;
				else
					cout<<separator;
			}
			cout<<endl;
		}
	}

	void setSort(void (*ptr)(nTVector*)){
		sortFunc=ptr;
	}

	int getSize(){
		return size;
	}

	void sort(){
		if(sortFunc!=NULL)
			(*sortFunc)(this);
	}

	void alloc(int size_){
		size=size_;
		if(alloqued){
			vec=(nTtype*)realloc(vec,sizeof(nTtype)*size);
			if(vec!=NULL)
				alloqued=true;
			else 
				alloqued=false;
		}else{
			vec=(nTtype*)malloc(sizeof(nTtype)*size);
			if(vec!=NULL)
				alloqued=true;
		}
	}

	void dispose(){
		if(alloqued){
			free(vec);
			alloqued=false;
		}
		free(this);
	}

	bool isOrd(){
		for(int i=1;i<size;i++)
			if(vec[i]<vec[i-1])
				return false;
		return true;
	}

	void printOrd(){
		if(isOrd()){
			cout<<"Vector is ordened\n";
		}else{
			cout<<"Vector isnt ordened\n";
		}
	}

	nTtype at(int i){
		if(i<size&&alloqued)
			return vec[i];
		return (nTtype) NULL;
	}

	void set(int i, nTtype v){
		if(i<size&&alloqued)
			vec[i]=v;
	}

	void add(int i, nTtype v){
		if(i<size&&alloqued)
			vec[i]+=v;
	}

	void swap(int a, int b){
		if(a<size&&b<size&&alloqued){
			nTtype tmp=vec[a];
			vec[a]=vec[b];
			vec[b]=tmp;
		}
	}

	void buildHeap(){
		int son;
		for(int i=1;i<=size;i++){
			son=i+1;
			while(son>1&&vec[son/2-1]<vec[son-1]){
				swap(son/2-1,son-1);
				son/=2;
			}
		}
	}
};
#endif