#include "tp3.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;
using std::size_t;

int binarySearch(Array& array, int toSearch)
{
	int start=0, mid, foundIndex;
	int end = array.size();
	while(start < end){
		mid = (start+end)/2;
		if(toSearch > array[mid]){
			start=mid+1;
		}
		else if(toSearch< array[mid]){
			end=mid;
		}
		else{
			foundIndex=mid;
			return foundIndex;
			//break;
		}
	}
	return -1;
	//return -1;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 500;
	w = new BinarySearchWindow(binarySearch);
	w->show();

	return a.exec();
}
