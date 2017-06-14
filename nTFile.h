#ifndef _NTFILE_
#define _NTFILE_
#include <fstream>
#include <iostream>
#include <string>

#include "nTVector.h"
#include "nTTimer.h"
#include "sort/selection.h"
#include "sort/insertion.h"
#include "sort/shell.h"
#include "sort/merge.h"
#include "sort/quick1.h"
#include "sort/quick2.h"
#include "sort/quickinsertion.h"
#include "sort/bubble.h"
#include "sort/counting.h"
#include "sort/heap.h"
#include "sort/radix.h"

struct nTFile{
	string filename="";

	std::ofstream file;
	nTTimer timer;
	nTVector *v;
	nTVector *selection;
	nTVector *insertion;
	nTVector *shell;
	nTVector *merge;
	nTVector *quick1;
	nTVector *quick2;
	nTVector *quickin;
	nTVector *bubble;
	nTVector *counting;
	nTVector *heap;
	nTVector *radix;

	void init(string fileName){
		v=new nTVector;
		selection=new nTVector;
		insertion=new nTVector;
		shell=new nTVector;
		merge=new nTVector;
		quick1=new nTVector;
		quick2=new nTVector;
		quickin=new nTVector;
		bubble=new nTVector;
		counting=new nTVector;
		heap=new nTVector;
		radix=new nTVector;
		filename=fileName;
		file.open(filename, std::ofstream::out);
	  	file<<"Algoritmo,Dimensao,Tempo\n";
	 	file.close();
	}

	void run(int size){
		v->alloc(size);
		v->fillRand();
		selection->setSort(&selectionSort);
		insertion->setSort(&insertionSort);
		shell->setSort(&shellSort);
		merge->setSort(&mergeSort);
		quick1->setSort(&quick1Sort);
		quick2->setSort(&quick2Sort);
		quickin->setSort(&quickInsertionSort);
		bubble->setSort(&bubbleSort);
		counting->setSort(&countingSort);
		heap->setSort(&heapSort);
		radix->setSort(&radixSort);
		v->copyTo(selection);
		v->copyTo(insertion);
		v->copyTo(shell);
		v->copyTo(merge);
		v->copyTo(quick1);
		v->copyTo(quick2);
		v->copyTo(quickin);
		v->copyTo(bubble);
		v->copyTo(counting);
		v->copyTo(heap);
		v->copyTo(radix);
		std::cout<<"running: "<<size;

		timer.start();
		quickin->sort();
		timer.end();
		if(!quickin->isOrd()) err();
		file.open(filename, std::ofstream::out|std::ofstream::app);
	  	file<<"QuickIn,"<<size<<","<<timer.count()<<"\n";
	 	file.close();
	 	std::cout<<" - 1/11(quickin)";
	 	std::cout.flush();

	 	timer.start();
		quick1->sort();
		timer.end();
		if(!quick1->isOrd()) err();
		file.open(filename, std::ofstream::out|std::ofstream::app);
	  	file<<"Quick1,"<<size<<","<<timer.count()<<"\n";
	 	file.close();
	 	std::cout<<" - 2/11(quick1)";
	 	std::cout.flush();

	 	timer.start();
		quick2->sort();
		timer.end();
		if(!quick2->isOrd()) err();
		file.open(filename, std::ofstream::out|std::ofstream::app);
	  	file<<"Quick2,"<<size<<","<<timer.count()<<"\n";
	 	file.close();
	 	std::cout<<" - 3/11(quick2)";
	 	std::cout.flush();

	 	timer.start();
		merge->sort();
		timer.end();
		if(!merge->isOrd()) err();
		file.open(filename, std::ofstream::out|std::ofstream::app);
	  	file<<"Merge,"<<size<<","<<timer.count()<<"\n";
	 	file.close();
	 	std::cout<<" - 4/11(merge)";
	 	std::cout.flush();

	 	timer.start();
		shell->sort();
		timer.end();
		if(!shell->isOrd()) err();
		file.open(filename, std::ofstream::out|std::ofstream::app);
	  	file<<"Shell,"<<size<<","<<timer.count()<<"\n";
	 	file.close();
	 	std::cout<<" - 5/11(shell)";
	 	std::cout.flush();

	 	timer.start();
		insertion->sort();
		timer.end();
		if(!insertion->isOrd()) err();
		file.open(filename, std::ofstream::out|std::ofstream::app);
	  	file<<"Insertion,"<<size<<","<<timer.count()<<"\n";
	 	file.close();
	 	std::cout<<" - 6/11(insertion)";
	 	std::cout.flush();

		timer.start();
		selection->sort();
		timer.end();
		if(!selection->isOrd()) err();
		file.open(filename, std::ofstream::out|std::ofstream::app);
	  	file<<"Selection,"<<size<<","<<timer.count()<<"\n";
	 	file.close();
	 	std::cout<<" - 7/11(selection)";
	 	std::cout.flush();

	 	timer.start();
		bubble->sort();
		timer.end();
		if(!bubble->isOrd()) err();
		file.open(filename, std::ofstream::out|std::ofstream::app);
	  	file<<"Bubble,"<<size<<","<<timer.count()<<"\n";
	 	file.close();
	 	std::cout<<" - 8/11(bubble)";
	 	std::cout.flush();

 		timer.start();
		counting->sort();
		timer.end();
		if(!counting->isOrd()) err();
		file.open(filename, std::ofstream::out|std::ofstream::app);
	  	file<<"Counting,"<<size<<","<<timer.count()<<"\n";
	 	file.close();
	 	std::cout<<" - 9/11(counting)\n";
	 	std::cout.flush();

		timer.start();
		heap->sort();
		timer.end();
		if(!heap->isOrd()) err();
		file.open(filename, std::ofstream::out|std::ofstream::app);
	  	file<<"Heap,"<<size<<","<<timer.count()<<"\n";
	 	file.close();
	 	std::cout<<" - 10/11(heap)\n";
	 	std::cout.flush();

	 	timer.start();
		radix->sort();
		timer.end();
		if(!radix->isOrd()) err();
		file.open(filename, std::ofstream::out|std::ofstream::app);
	  	file<<"Radix,"<<size<<","<<timer.count()<<"\n";
	 	file.close();
	 	std::cout<<" - 11/11(radix)\n";
	 	std::cout.flush();
	}

	void dispose(){
		insertion->dispose();
		selection->dispose();
		shell->dispose();
		merge->dispose();
		quick1->dispose();
		quick2->dispose();
		quickin->dispose();
		bubble->dispose();
		counting->dispose();
		heap->dispose();
		radix->dispose();
		v->dispose();
	}

private:
	void err(){
		std::cout<<"ERRORRRRRRRRRR\n";
		std::cout<<"ERRORRRRRRRRRR\n";
		std::cout<<"ERRORRRRRRRRRR\n";
		std::cout<<"ERRORRRRRRRRRR\n";
		std::cout<<"ERRORRRRRRRRRR\n";
		std::cout<<"ERRORRRRRRRRRR\n";
		file.open(filename, std::ofstream::out|std::ofstream::app);
	  	file<<"ERRORRRRRRRRRR\n";
	  	file<<"ERRORRRRRRRRRR\n";
	  	file<<"ERRORRRRRRRRRR\n";
	  	file<<"ERRORRRRRRRRRR\n";
	  	file<<"ERRORRRRRRRRRR\n";
	  	file<<"ERRORRRRRRRRRR\n";
	 	file.close();
	 	return;
	}

};
#endif