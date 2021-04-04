#include "tp4.h"
#include "mainwindow.h"

#include <QApplication>
#include <time.h>
#include <stdio.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;

int Heap::leftChild(int nodeIndex)
{
    return nodeIndex * 2 + 1;
	//return 0;
}

int Heap::rightChild(int nodeIndex)
{
	return nodeIndex *2 +2;
    //return 0;
}

void Heap::insertHeapNode(int heapSize, int value)
{
	// use (*this)[i] or this->get(i) to get a value at index i
	int i = heapSize;
	this->get(i)=value;
	while(i>0 && this->get(i) > this->get((i-1)/2)){
		swap(i,(i-1)/2);
		i = (i-1)/2;
	}
}

void Heap::heapify(int heapSize, int nodeIndex)
{
	// use (*this)[i] or this->get(i) to get a value at index i
	//int i_max = nodeIndex;
	int i = nodeIndex;
	int largest = i;
	if(leftChild(i)<heapSize && this->get(leftChild(i)) > this->get(i)){
		largest = leftChild(i);
	}
	if(rightChild(i)<heapSize && this->get(rightChild(i)) > this->get(largest)){
		largest = rightChild(i);
	}
	if(largest != i){
		swap(i,largest);
		heapify(heapSize,largest);
	}
}

void Heap::buildHeap(Array& numbers)
{
	for(int i=numbers.size()-1;i>=0;i--){
		insertHeapNode(i,numbers[i]);
	}
}

void Heap::heapSort()
{
	for(int i=this->size()-1;i>=0;i--){
		swap(i,0);
		heapify(i,0);
	}
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow::instruction_duration = 50;
    w = new HeapWindow();
	w->show();

	return a.exec();
}
