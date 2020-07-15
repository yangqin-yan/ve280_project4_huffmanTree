#include "binaryTree.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

/* ================================== Node =================================== */
Node::Node(const std::string &str, int num, Node *left, Node *right) :
str(str), num(num), left(left), right(right){
    // TODO: implement this function.
}

Node* Node::leftSubtree() const{
    // TODO: implement this function.
    return left;
}

Node* Node::rightSubtree() const{
    // TODO: implement this function.
    return right;
}

void Node::setleft(Node *n){
    left = n;
}

void Node::setright(Node *n){
    right = n;
}

string Node::getstr() const {
    // TODO: implement this function.
    return str;
}

int Node::getnum() const {
    // TODO: implement this function.
    return num;
}

void Node::incnum() {
    // TODO: implement this function.
    num++;
}

Node *Node::mergeNodes(Node *leftNode, Node *rightNode) {
    // TODO: implement this function.
    Node* merged = new Node(leftNode->str + rightNode->str, leftNode->num + rightNode->num);
    return merged;
}

/* =============================== Binary Tree =============================== */

BinaryTree::BinaryTree(Node *rootNode){
    // TODO: implement this function.
    root = rootNode;
}


static void deleteHelper(Node * root){
    if(root->leftSubtree()){
        deleteHelper(root->leftSubtree());
    }
    if(root->rightSubtree()){
        deleteHelper(root->rightSubtree());
    }
    delete root;
}

BinaryTree::~BinaryTree() {
    // TODO: implement this function.
    deleteHelper(root);
}

static string findPathHelper(const string & s, Node *root){
    if (s == root->getstr()) {
        return "";
    }
    string result = "-1";
    if(root->leftSubtree() && result == "-1"){
        // recursion
        result = findPathHelper(s, root->leftSubtree());
        if(result != "-1"){
            result += "0";
        }
    }
    if(root->rightSubtree() && result == "-1"){
        result = findPathHelper(s, root->rightSubtree());
        if(result != "-1"){
            result += "1";
        }
    }
    return result;
}


string BinaryTree::findPath(const string &s) const {
    // TODO: implement this function.
    return findPathHelper(s,root);
}

static int sumHelper(const Node * root){
    int sum = 0;
    if(root->rightSubtree()){
        sum = sumHelper(root->leftSubtree());
    }
    if(root->rightSubtree()){
        sum = sumHelper(root->rightSubtree());
    }
    return sum + root->getnum();
}


int BinaryTree::sum() const {
    // TODO: implement this function.
    // base case;
    if(!root){
        return 0;
    }
    return sumHelper(root);

}

static int depthHelper(Node * root){
    int depth = 0;
    int cnt = 0;
    if(root->leftSubtree()){
        cnt =  1 + depthHelper(root->leftSubtree());
    }
    if(cnt > depth){
        depth = cnt;
    }
    if(root->rightSubtree()){
        cnt = 1 + depthHelper(root->rightSubtree());
    }
    if(cnt > depth){
        depth = cnt;
    }
    return depth;
}

int BinaryTree::depth() const {
    // TODO: implement this function.
    if(root == nullptr){
        return 0;
    }
    return depthHelper(root);
}
// EFFECTS: Returns the depth of the tree, which equals the number of layers of nodes
//          in the tree. Returns zero if the tree is empty.
//
// For example, the tree
//
//                           a
//                         /   \
//                        /      \
//                       b        c
//                      / \      / \
//                         d        e
//                        / \      / \
//                       f   g
//                      / \ / \
//
// has depth 4.
// The node a is on the first layer.
// The nodes b and c are on the second layer.
// The nodes d and e are on the third layer.
// The nodes f and g are on the fourth layer.

static void preorderHelper(Node * root){
    cout << root->getnum() << " ";
    if(root->leftSubtree()){
        preorderHelper(root->leftSubtree());
    }
    if(root->rightSubtree()){
        preorderHelper(root->rightSubtree());
    }
}
// EFFECTS: traverse the node in preorder recursively.

void BinaryTree::preorder_num() const {
    // TODO: implement this function.
    preorderHelper(root);
    cout << endl;
}

static void inorderHelper(Node * root){
    if(root->leftSubtree()){
        inorderHelper(root->leftSubtree());
    }
    cout << root->getnum() << " ";
    if(root->rightSubtree()){
        inorderHelper(root->rightSubtree());
    }
}
// EFFECTS: traverse the node in inorder recursively.

void BinaryTree::inorder_str() const {
    // TODO: implement this function.
    inorderHelper(root);
    cout << endl;
}

static void postorderHelper(Node * root){
    if(root->leftSubtree()){
        inorderHelper(root->leftSubtree());
    }
    if(root->rightSubtree()){
        inorderHelper(root->rightSubtree());
    }
    cout << root->getnum() << " ";
}
// EFFECTS: traverse the node in postorder recursively.

void BinaryTree::postorder_num() const {
    // TODO: implement this function.
    postorderHelper(root);
    cout << endl;
}

bool BinaryTree::allPathSumGreater(int temp) const {
    // TODO: implement this function.

}

bool BinaryTree::covered_by(const BinaryTree &tree) const {
    // TODO: implement this function.
}

bool BinaryTree::contained_by(const BinaryTree &tree) const {
    // TODO: implement this function.
}

BinaryTree BinaryTree::copy() const {
    // TODO: implement this function.
}
