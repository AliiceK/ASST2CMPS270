#include <iostream>
#include "vector"

using namespace std;
template <class T>
struct treeNode {
    T *data;
    struct treeNode * left;
    struct treeNode * right;
};
template <class T>
struct BinarySearchTREE {

private:
    vector< treeNode<T>*> listofnodez ;

    // parentIndex takes as paramters the node and will return its parent
    int parentIndex(int node){
        return (node-1)/2;
    }

    // treesize will take as parameter the root of the tree and will return its size
    int treeSize(treeNode<T>* root){
        if (root == NULL) return 0;
        return 1 + treeSize(root->left) + treeSize(root->right);
    }

    
    // postorderprint will take as parameters the root of the tree and will return the post order print
    void postOrderPrint(treeNode<T>* root){
        if (root == NULL) return;
        postOrderPrint(root->left);
        postOrderPrint(root->right);
        cout<<*(root->data);
    }
    // preorderprint will take as parameters the root of the tree and will return the preorder print
    void preOrderPrint(treeNode<T>* root){
        if (root == NULL) return;
        cout<<*(root->data);
        preOrderPrint(root->left);
        preOrderPrint(root->right);
    }
public:
// Paramters : The function add node will take as parameter the root of the data
// Returns : Return type of void . The tree will have the new node added

// Test cases : if both the children of the node are null, then the node added is added on the left first 
// if we find a node whose left child is empty, we will make the new value added as the left child of the node
// if we find a node whose right child is empty, then we will make a the new value added as the right child of the node

    void addNode(T data){
        int *newnode = new int;
        *newnode = data;
        treeNode<T> *temp = new treeNode<T>;
        *temp = {newnode,NULL,NULL};
        int index;
        for (int i = 0; i < listofnodez.size(); ++i) {
            if(listofnodez[i] == NULL){
                index = i;
                break;
            }
            else index = i+1;
        }
        if (index < listofnodez.size()) {
           listofnodez[index] = temp; 
        } else {
            listofnodez.push_back(temp);
        }
        if (index != 0) {
            int parent = parentIndex(index);
            if (listofnodez[parent]->left != NULL) {
                listofnodez[parent]->right = temp;
            } else {
                listofnodez[parent]->left = temp;
        }
    }
}

//the function delete node will take as paramters the data to be added and will return the tree with the new data added

// Test Cases: when a node cannot be deleted the function will print out CANNOT DELETE NODE
// If the node deleted is a leaf we will simply remove it
// if the node to be deleted has 2 children we will find the inorder successor , copy its contents then delete it 
// if the node to be delted has one child , we will copy the child to the node and delete the child
    void deleteNode(T data){
        int index = -1;
        for(int i = 0; i < listofnodez.size(); i++){
            if (listofnodez[i] != NULL && *(listofnodez[i]->data) == data){
                index = i;
            }
        }
        if (index != -1 && listofnodez[index]->left == NULL && listofnodez[index]->right == NULL){
            treeNode<T> *temp = listofnodez[index];
            listofnodez[index] = NULL;
            if (index != 0){
                int parent = parentIndex(index);
                if (index%2 == 0) {
                    listofnodez[parent]->right = NULL;
                } else {
                    listofnodez[parent]->left = NULL;
                }
            }
            free(temp);
        }
        else {
            cout<<"CANNOT DELETE NODE"<<endl;
        }
    }

    int treeSize(){
        if (listofnodez.size() == 0) return 0;
        return treeSize(listofnodez[0]);
    }
//  the function subtree will take as parameters the the value for which we are going to find the subtree and 
//  return the subtree of that node
    int subtreeSize(T data){
        int ind = -1;
        for(int i = 0; i<listofnodez.size(); i++){
            if (listofnodez[i] != NULL && *(listofnodez[i]->data) == data){
                ind = i;
            }
        }
        if (ind != -1) return treeSize(listofnodez[ind]);
        return 0;
    }
    void postOrderPrint(){
        postOrderPrint(listofnodez[0]);
    }
    void preOrderPrint(){
        preOrderPrint(listofnodez[0]);
    }
};

int main() {
    BinarySearchTREE<int> tree;
    tree.addNode(1);
    tree.addNode(2);
    tree.addNode(3);
    tree.addNode(4);
    tree.addNode(5);
    cout<<tree.treeSize()<<endl;
    tree.addNode(8);
    tree.addNode(7);
    cout<<endl;
    tree.postOrderPrint();
    cout<<endl;
    tree.preOrderPrint();
    return 0;
}



