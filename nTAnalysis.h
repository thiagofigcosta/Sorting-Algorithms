#include <fstream>
#include <string>
#include "nTVector.h"
#include "sort/quick2.h"

using namespace std;

int nTceil(double a) {
    int inum=(int)a;
    if (a==(int)a)
        return (int)a;
    return ((int)a)+1;
}

int nTfloor(double a){
	return (int)a;
}

int nTround(double a){
	return floor(a+0.5);
}

bool strkeycmp(string a, string b){
	for(int i=0;i<b.size();i++){
		if(a[i]!=b[i])
			return false;
	}
	if(b[b.size()-1]==','||a[b.size()]==',')
		return true;
	return false;
}

int getValue(string a){
	int virgula=0;
	string tmp="0";
	for(int i=0;i<a.size();i++){
		if(virgula<=1){
			if(a[i]==','){
				if(virgula==1)
					tmp="";
				virgula++;
			}
		}else{
			tmp+=a[i];
		}
	}
	return atoi(tmp.c_str());
}

string rmVirgula(string a,bool rm){
	if(!rm) return a;
	for(int i=0;i<a.size();i++)
		if(a[i]==',')
			a[i]='_';
	return a;
}

int* getQuantis(nTVector *v){
	int *out=new int[5];
	out[0]=v->at(nTround(0.1*v->getSize())-1);
	out[1]=v->at(nTround(0.25*v->getSize())-1);
	out[2]=v->at(nTround(0.5*v->getSize())-1);
	out[3]=v->at(nTround(0.75*v->getSize())-1);
	out[4]=v->at(nTround(0.9*v->getSize())-1);
	return out;
}


int getMediana(nTVector *v){
	return v->at(nTround(0.5*v->getSize())-1);
}

void analyse(string keyName, string fileIn, string fileOut, bool fullAnalysis,bool rmvirgula){
	ifstream file;
	ofstream fileout;
	nTVector *values;
	if(keyName==""){
		fileout.open(fileOut, ofstream::out);
		if(fullAnalysis)
			fileout<<"Algoritmo,Quantil 0.1,Quantil 0.25,Quantil 0.5,Quantil 0.75,Quantil 0.9\n";
		else
			fileout<<"Algoritmo,Dimensao,Mediana\n";
		fileout.close();
		return;
	}
	file.open(fileIn, ifstream::in);
	string line;
	values=new nTVector;
	values->setSort(&quick2Sort);
	while(getline(file, line)){
	   if(strkeycmp(line,keyName)){
			values->push(getValue(line));
	   }
	}
	file.close();
	values->sort();
	int *quantis;
	int med;
	if(fullAnalysis)
		quantis=getQuantis(values);
	else
		med=getMediana(values);
	fileout.open(fileOut, ofstream::app);
	if(fullAnalysis)
		fileout<<rmVirgula(keyName,rmvirgula)<<","<<quantis[0]<<","<<quantis[1]<<","<<quantis[2]<<","<<quantis[3]<<","<<quantis[4]<<"\n";
	else
		fileout<<rmVirgula(keyName,rmvirgula)<<","<<med<<"\n";
	fileout.close();
	if(fullAnalysis)
		free(quantis);
	values->dispose();
}