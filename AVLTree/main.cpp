#include <iostream>
using namespace std;

class AVL {
public:
    class Node;
private:
    Node* root;
    int countLocal = 0;
public:
    AVL():root(NULL),countLocal(0){};
    int   getHeightRec(Node* root) {
        if (!root) return 0;
        else if (getHeightRec(root->LeftChild) > getHeightRec(root->RightChild)) return getHeightRec(root->LeftChild) + 1;
        else return getHeightRec(root->RightChild) + 1;
    }
    int   getHeight(){
        return getHeightRec(root);
    }
    int   balanceFactorRec(Node* root) {
        if (!root) return 0;
        return getHeightRec(root->LeftChild) - getHeightRec(root->RightChild);
    }
    int balanceFactor(){
        return balanceFactorRec(root);
    }
    Node* rotateLeft(Node* root) {
        if (root->RightChild) {
            Node* tempR = root->RightChild;
            root->RightChild = tempR->LeftChild;
            tempR->LeftChild = root;
            return tempR;
        }
        return root;
    }
    Node* rotateRight(Node* root) {
        if (root->LeftChild) {
            Node* tempL = root->LeftChild;
            root->LeftChild = tempL->RightChild;
            tempL->RightChild = root;
            return tempL;
        }
        return root;
    }
    Node* searchNodeRec(Node *root, string var) {
        if (!root || var.compare(root->key) == 0) return root;
        if (var.compare(root->key) > 0) return searchNodeRec(root->RightChild, var);
        else return searchNodeRec(root->LeftChild, var);
    }
    Node* searchNode(string var) {
        return searchNodeRec(root, var);
    }
    Node* insertAVLNodeRec(Node *root,string var, float datatype, float data){
        Node* newnode = new Node(var, datatype, data);
        if (!root) return newnode;
        else {
            if (var.compare(root->key) > 0) root->RightChild = insertAVLNodeRec(root->RightChild, var, datatype, data);
            else root->LeftChild = insertAVLNodeRec(root->LeftChild, var, datatype, data);
        }
        
        int balance = balanceFactorRec(root);
        //left left 
        if (balance > 1 && var.compare(root->LeftChild->key) < 0) return rotateRight(root);
        //left right 
        if (balance > 1 && var.compare(root->LeftChild->key) > 0) {
            root->LeftChild = rotateLeft(root->LeftChild);
            return rotateRight(root);
        }
        //right right
        if (balance < -1 && var.compare(root->RightChild->key) > 0) return rotateLeft(root);
        //right left 
        if (balance < -1 && var.compare(root->RightChild->key) < 0) {
            root->RightChild = rotateRight(root->RightChild);
            return rotateLeft(root);
        }
        return root;
    }
    void  insertAVLNode(string var, float datatype, float data) {
        root = insertAVLNodeRec(root, var, datatype, data);
    }
    Node* findparentRec(Node* root, string var, Node* parent) {
        if(root) {
            if (root->key == var) {
                return parent;
            }
            else {
                return findparentRec(root->LeftChild, var, root);
                return findparentRec(root->RightChild, var, root);
            }
        }
        return NULL;
    }
    Node* findparent(string var) {
        return findparentRec(root, var, NULL);
    }
    void  printInorder(Node *root) {
        if (root == NULL)return;
        printInorder(root->LeftChild);
        cout << root->key << " ";
        printInorder(root->RightChild);
    }
    void  printInorder(){
        printInorder(root);
    }
    int size(Node *root){
        if(!root) return 0;
        return size(root->LeftChild) + size(root->RightChild) + 1;
    }
    int sizeRec(){
        return size(root);
    }
public:
    class Node {
    private:
        string key;
        float datatype;
        float data;
        Node* LeftChild;
        Node* RightChild;
        friend class AVL;
    public:
        Node(string key,float datatype, float data) {
            this->key = key;
            this->datatype = datatype;
            this->data = data;
            LeftChild = NULL;
            RightChild = NULL;
        }
    };

};

int main(){
    AVL *sf = new AVL();
    sf->insertAVLNode("5",0,-1);
    sf->insertAVLNode("6",1,2.3);
    sf->insertAVLNode("8",1,2.3);
    sf->insertAVLNode("9",1,2.3);
    sf->insertAVLNode("10",1,2.3);
    sf->insertAVLNode("4",1,2.3);
    sf->insertAVLNode("3",1,2.3);
    sf->insertAVLNode("2",1,2.3);
    sf->insertAVLNode("-2",1,2.3);
    cout <<sf->balanceFactor()<<endl;
    cout << sf->getHeight()<<endl;
    cout << sf->sizeRec()<<endl;
    sf->printInorder();
    return 0;
}




