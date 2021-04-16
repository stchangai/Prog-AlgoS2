#include <QApplication>
#include <time.h>

#include "tp2.h"


MainWindow* w=nullptr;

void recursivQuickSort(Array& toSort, int size)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
	int pivot = toSort[0];
	Array& lowerArray = w->newArray(size);
	Array& greaterArray= w->newArray(size);
	int lowerSize = 0, greaterSize = 0; // effectives sizes

	// split;
	for(int n=0;n<toSort.size()){
		if(toSort[n]<pivot){
			lowerArray[lowerSize] = toSort[n];
			lowerSize++;
		}else{
			greaterArray[greaterSize] = toSort[n];
			greaterSize++;
		}
	}
	
	// recursiv sort of lowerArray and greaterArray
	recursivQuickSort(lowerArray, lowerSize);
	recursivQuickSort(greaterArray,greaterSize);
	// merge
	Array& sorted = w->newArray(size);
	for(int c=0;c<lowerSize;c++){
		toSort[c]=lowerArray[c];
	}
	toSort[lowerSize] = pivot;
	int increment = 0;
	for(int i=lowerSize+1;i<toSort.size();i++){
		toSort[i] = greaterArray[increment];
		increment++;
	}
	
}

void quickSort(Array& toSort){
	recursivQuickSort(toSort, toSort.size());
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(quickSort);
	w->show();

	return a.exec();
}
