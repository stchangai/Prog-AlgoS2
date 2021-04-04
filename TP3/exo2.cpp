#include "tp3.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;
using std::size_t;


void binarySearchAll(Array& array, int toSearch, int& indexMin, int& indexMax)
{
	indexMin = indexMax = -1;
	int start=0, mid;
	int end = array.size();
	while(start < end){
		mid = (start+end)/2;
		if(toSearch > array[mid]){
			start=mid+1;
		}
		else if(toSearch < array[mid]){
			end=mid;
		}
		else{
			indexMin=mid;
			end= indexMin;
		}
	}
	if(indexMin!=-1){

	
		start=indexMin;
		indexMax =indexMin;
		while(start < end){
			mid = (start+end)/2;
			if(toSearch < array[mid]){
				end=mid;
			}
			else{
				indexMax=mid;
				end=indexMin;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 500;
	w = new BinarySearchAllWindow(binarySearchAll);
	w->show();

	return a.exec();
}
