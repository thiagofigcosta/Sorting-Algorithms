#include "nTFile.h"

int main(int argc, char** argv){
	
	int NTESTES=30;

	nTFile cruzes;
	cruzes.init("saida.csv");
	
	if(argc<=1){
		for(int t=0;t<NTESTES;t++){
			cruzes.run(10);
			cruzes.run(20);
			cruzes.run(50);
			cruzes.run(100);
			cruzes.run(200);
			cruzes.run(500);
			cruzes.run(1000);
			cruzes.run(5000);
		}
	}else{
		for(int i=1;i<argc;i++){
			for(int t=0;t<NTESTES;t++){
				cout<<"test "<<(t+1)<<" of "<<NTESTES<<endl;
				cruzes.run(atoi(argv[i]));
			}
		}
	}
	cruzes.dispose();
	return 0;
}

