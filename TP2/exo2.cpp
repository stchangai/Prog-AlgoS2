#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;

void insertionSort(Array& toSort){
	Array& sorted=w->newArray(toSort.size());
	sorted[0] = toSort[0];
	int pos;
	// insertion sort from toSort to sorted
	for(int n = 1;n<toSort.size();n++){
		for(int j=n-1;j>=0;j--){
			if(toSort[n]<sorted[j]){
				//sorted.insert(j,toSort[n]);
				pos = j;
			}else{
				//sorted.insert(n,toSort[n]);
				pos = n;
			}
		}
		sorted.insert(pos, toSort[n]);
	}
	
	toSort=sorted; // update the original array
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    uint elementCount=15; // number of elements to sort
    MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    w = new TestMainWindow(insertionSort); // window which display the behavior of the sort algorithm
	w->show();

	return a.exec();
}
