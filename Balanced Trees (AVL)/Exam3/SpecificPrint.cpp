#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    Node *left;
    Node *right;
    int value;
    Node(int value){
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{

public:
    BST(){
        root = NULL;
    }
    void insert(int value){
        root = insert(root, value);
    }
    
    void OrderTree(Node* curr,int Div)
    {
        if(!curr)
        {
            return;
        }
        
        if(curr->value%Div==0 && (curr->left || curr->right))
        {
            std::cout<<curr->value<<" ";
        }
        
        OrderTree(curr->left,Div);
        OrderTree(curr->right,Div);
    }
    
	void printSpecific(int dividedBy){
        
        OrderTree(this->root,dividedBy);
        // TODO implement this function
    }

private:
	// you can implemented helper functions if you want


    Node* root;

    Node* insert(Node *curNode, int value){
        if(curNode == NULL){
            curNode =  new Node(value);
        }else if(curNode->value < value){
            curNode->right = insert(curNode->right, value);
        }else if(curNode->value > value){
            curNode->left = insert(curNode->left, value);
        }else {
        	//if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};
int main() {
    int n;
  	cin >> n;
  	int value;
  	BST tree;
  	for(int i = 0 ; i < n; i++){
      cin >> value;
      tree.insert(value);
    }
  	int dividedBy;
  	cin >> dividedBy;
  	tree.printSpecific(dividedBy);
    return 0;
}