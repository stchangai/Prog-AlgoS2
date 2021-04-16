#include <QApplication>
#include <time.h>
#include "tp2.h"

MainWindow* w=nullptr;

void merge(Array& first, Array& second, Array& result);

void splitAndMerge(Array& origin)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)

	// initialisation
	Array& first = w->newArray(origin.size()/2);
	Array& second = w->newArray(origin.size()-first.size());
	
	// split
	if(origin.size()!=1){
		for(int i=0;i<first.size();i++){
			first[i]=origin[i];
		}
		int count = first.size();
		for(int j = 0;j<second.size();j++){
			second[j]=origin[count];
			count++;
		}
	}else{
		return;
	}

	// recursiv splitAndMerge of lowerArray and greaterArray
	splitAndMerge(first);
	splitAndMerge(second);

	// merge
	merge(first, second,origin);
}

void merge(Array& first, Array& second, Array& result)
{
	
}

void mergeSort(Array& toSort)
{
    splitAndMerge(toSort);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(mergeSort);
	w->show();

	return a.exec();
}
