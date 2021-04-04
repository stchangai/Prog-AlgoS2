#include "mainwindow.h"
#include "tp3.h"
#include <QApplication>
#include <time.h>
#include <stack>
#include <queue>
#include <iostream>

MainWindow* w = nullptr;
using std::size_t;

struct BinarySearchTree : public BinaryTree
{    
    Node* left;
    Node* right;
    int value;

    void initNode(int value)
    {
        this->left=NULL;
        this->right=NULL;
        this->value=value;
    }

	void insertNumber(int value) {
        // create a new node and insert it in right or left child
        if(this->value > value){
            this->left = value;
        }
        else if(this->value < value){
            this->right=value;
        }
    }

	uint height() const	{
        // should return the maximum height between left child and
        // right child +1 for itself. If there is no child, return
        // just 1
        int heightG, heightD, maxheight;
        Node* brancheG = this->left;
        Node* brancheD = this->right;
        while(this->left!=NULL){
            heightG++;
        }
        heightG += 1;
        while(this->right!=NULL){
            heightD++;
        }
        heightD += 1;
        if(heightD < heightG){
            return heightG;
        }
        else{ return heightD; }

        return 1;
    }

	uint nodesCount() const {
        // should return the sum of nodes within left child and
        // right child +1 for itself. If there is no child, return
        // just 1
        int compteur = 1; // compte la racine dès le départ
        if(this->left != NULL){
            compteur += nodesCount();
        }
        else if(this->right != NULL){
            compteur += nodesCount();
        }
        return compteur;
	}

	bool isLeaf() const {
        // return True if the node is a leaf (it has no children)
        if(this->left == NULL && this->right == NULL){
            return true;
        }
        return false;
	}

	void allLeaves(Node* leaves[], uint& leavesCount) {
        // fill leaves array with all leaves of this tree
        if(this->left == NULL && this->right == NULL){
            leaves[leavesCount]= this;
            leavesCount++;
        }
        if(this->left != NULL){
            allLeaves(leaves, leavesCount);
        }
        if(this->right != NULL){
            allLeaves(leaves, leavesCount);
        }
	}

	void inorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with inorder travel
	}

	void preorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with preorder travel
	}

	void postorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with postorder travel
	}

	Node* find(int value) {
        // find the node containing value
		return nullptr;
	}

    void reset()
    {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
        left = right = NULL;
    }

    BinarySearchTree(int value) : BinaryTree(value) {initNode(value);}
    ~BinarySearchTree() {}
    int get_value() const {return value;}
    Node* get_left_child() const {return left;}
    Node* get_right_child() const {return right;}
};

Node* createNode(int value) {
    return new BinarySearchTree(value);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 200;
    w = new BinarySearchTreeWindow<BinarySearchTree>();
	w->show();

	return a.exec();
}
