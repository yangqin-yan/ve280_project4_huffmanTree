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
// REQUIRES: The input left and right point to a dynamically allocated node object,
//           if not being NULL.
// MODIFIES: this
// EFFECTS: Construct a node with given input values.

Node* Node::leftSubtree() const{
    // TODO: implement this function.
    return left;
}
// EFFECTS: Return the pointer to the left child of the node.

Node* Node::rightSubtree() const{
    // TODO: implement this function.
    return right;
}
// MODIFIES: this
// EFFECTS: set the left child of the node to be n.

void Node::setleft(Node *n){
    left = n;
}
// EFFECTS:  Return the pointer to the right child of the node.

void Node::setright(Node *n){
    right = n;
}
// MODIFIES: this
// EFFECTS: set the right child of the node to be n.

string Node::getstr() const {
    // TODO: implement this function.
    return str;
}
// EFFECTS:  Return the “str” component of the node.

int Node::getnum() const {
    // TODO: implement this function.
    return num;
}
// EFFECTS:  Return the “num” component of the node.

void Node::incnum() {
    // TODO: implement this function.
    num++;
}
// MODIFIES: this
// EFFECTS: increment num by 1

Node *Node::mergeNodes(Node *leftNode, Node *rightNode) {
    // TODO: implement this function.
    Node* merged = new Node(leftNode->str + rightNode->str, leftNode->num + rightNode->num, leftNode, rightNode);
    return merged;
}
// REQUIRES: leftNode and rightNode points to dynamically allocated node objects.
// EFFECTS: Returns a pointer to a node with "str" being the result of appending
//          leftNode->str and rightNode->str, and "num" being leftNode->num +
//          rightNode->num. Also, Please allocate memory for this returned node
//          object.
//
//          For example, if leftNode->str = "a", and rightNode->str = "b", then
//          the "str" of the merged node is "ab".

/* =============================== Binary Tree =============================== */

BinaryTree::BinaryTree(Node *rootNode){
    // TODO: implement this function.
    root = rootNode;
}
// REQUIRES: The input rootNode points to a dynamically allocated node object,
//           if not being NULL.
// MODIFIES: this
// EFFECTS: Construct a binary tree with a root node.


static void deleteHelper(Node * root){
    if(!root)
        return;
    if(root->leftSubtree()){
        deleteHelper(root->leftSubtree());
    }
    if(root->rightSubtree()){
        deleteHelper(root->rightSubtree());
    }
    delete root;
}
// EFFECTS: execute the recursive step of delete.
// MODIFIES: all the nodes.

BinaryTree::~BinaryTree() {
    // TODO: implement this function.
    deleteHelper(root);
}
// MODIFIES: this
// EFFECTS: Free all the memory allocated for this binary tree.

static string findPathHelper(const string & s, Node *root){
    if (s == root->getstr()) {
        return "";
    }
    string result = "-1";
    if(root->leftSubtree() && result == "-1"){
        // recursion
        result = findPathHelper(s, root->leftSubtree());
        if(result != "-1"){
            result = "0" + result;
        }
    }
    if(root->rightSubtree() && result == "-1"){
        result = findPathHelper(s, root->rightSubtree());
        if(result != "-1"){
            result = "1" + result;
        }
    }
    return result;
}
// EFFECTS: execute the recursive step of finding the path and return the code of the corresponding string
//          in the binary tree.



string BinaryTree::findPath(const string &s) const {
    // TODO: implement this function.
    return findPathHelper(s,root);
}
// EFFECTS: Return the path from the root node to the node with the string s.
//          The path is encoded by a string only containing '0' and '1'. Each
//          character, from left to right, shows whether going left (encoded
//          by ‘0’) or right (encoded by ‘1’) from a node can lead to the
//		    target node.

static int sumHelper(const Node * root){
    int sum = 0;
    if(root->leftSubtree()){
        sum += sumHelper(root->leftSubtree());
    }
    if(root->rightSubtree()){
        sum += sumHelper(root->rightSubtree());
    }
    return sum + root->getnum();
}
// EFFECTS: calculate the sum of all the nodes recursively and return the sum.



int BinaryTree::sum() const {
    // TODO: implement this function.
    // base case;
    if(!root){
        return 0;
    }
    return sumHelper(root);
}
// EFFECTS: Returns the sum of "num" values of all nodes in the tree. If the tree is
//          empty, return 0.

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
// EFFECTS: find the depth recursively and return the depth.

int BinaryTree::depth() const {
    // TODO: implement this function.
    if(root == nullptr){
        return 0;
    }
    return 1 + depthHelper(root);
}
// EFFECTS: Returns the depth of the tree, which equals the number of layers of nodes
//          in the tree. Returns zero if the tree is empty.
//


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
    if(!root)
        return;
    preorderHelper(root);
    cout << endl;
}
// EFFECTS: Prints the "num" component of each node using a pre-order traversal.
//          Seperate each "num" with a space. A pre-order traversal prints the
//          current node first, then recursively visit its left subtree, and then
//          recursively visit its right subtree and so on, until the right-most
//          element is printed.

static void inorderHelper(Node * root){
    if(root->leftSubtree()){
        inorderHelper(root->leftSubtree());
    }
    cout << root->getstr() << " ";
    if(root->rightSubtree()){
        inorderHelper(root->rightSubtree());
    }
}
// EFFECTS: traverse the node in inorder recursively.

void BinaryTree::inorder_str() const {
    // TODO: implement this function.
    if(!root)
        return;
    inorderHelper(root);
    cout << endl;
}
// EFFECTS: Prints the "str" component of each node using an in-order traversal.
//          Separate each "str" with a space. An in-order traversal prints the
//          "left most" element first, then the second-left-most, and so on,
//          until the right-most element is printed.

static void postorderHelper(Node * root){
    if(root->leftSubtree()){
        postorderHelper(root->leftSubtree());
    }
    if(root->rightSubtree()){
        postorderHelper(root->rightSubtree());
    }
    cout << root->getnum() << " ";
}
// EFFECTS: traverse the node in postorder recursively.

void BinaryTree::postorder_num() const {
    // TODO: implement this function.
    if(!root)
        return;
    postorderHelper(root);
    cout << endl;
}
// EFFECTS: Prints the "num" component of each node using a post-order traversal.
//          Seperate each "num" with a space. A post-order traversal recursively
//          visit its left subtree, and then recursively visit its right subtree
//          and then print the current node.

static bool allPathSumGreaterHelper(int temp, const Node * n, int sum){
    sum += n->getnum();
    // leaf
    if(!n->leftSubtree() && !n->rightSubtree()){
        if(sum > temp){
            return true;
        }
        return false;
    }
    // having children
    if(!n->leftSubtree() && (n->rightSubtree() && allPathSumGreaterHelper(temp, n->rightSubtree(), sum))){
        return true;
    }
    if(!n->rightSubtree() && (n->leftSubtree() && allPathSumGreaterHelper(temp, n->leftSubtree(), sum))){
        return true;
    }
    if((n->leftSubtree() && allPathSumGreaterHelper(temp, n->leftSubtree(), sum))
    && (n->rightSubtree() && allPathSumGreaterHelper(temp, n->rightSubtree(), sum))){
        return true;
    }
    return false;
}
// REQUIRES: The tree is not empty.
// EFFECTS：judge whether all the paths satisfy that the sum is greater than the given number. If this tree
//          satisfies, then return true, otherwise return false.

bool BinaryTree::allPathSumGreater(int sum) const {
    // TODO: implement this function.
    return allPathSumGreaterHelper(sum, root, 0);
}
// REQUIRES: The tree is not empty
//
// EFFECTS: Returns true if and only if for each root-to-leaf path of the tree,
//          the sum of "num" of all nodes along the path is greater than "sum".
//
//          A root-to-leaf path is a sequence of nodes in a tree starting with
//          the root element and proceeding downward to a leaf (an element with
//          no children).

static bool covered_by_helper(const Node * thisnode, const Node * treenode){
    // values are different.
    if(thisnode->getnum() != treenode->getnum()){
        return false;
    }
    // this has more children
    if((thisnode->leftSubtree() && !treenode->leftSubtree()) ||
            (thisnode->rightSubtree() && !treenode->rightSubtree())){
        return false;
    }
    else{
        bool result = true;
        if(thisnode->leftSubtree()){
            result *= covered_by_helper(thisnode->leftSubtree(), treenode->leftSubtree());
        }
        if(thisnode->rightSubtree()){
            result *= covered_by_helper(thisnode->rightSubtree(), treenode->rightSubtree());
        }
        return result;
    }
}
// EFFECTS: judge whether the node is identical with the one in the tree,
//          if so, continue the step recursively to find whether the tree is
//          covered by another tree. If so, return true, otherwise return false.

bool BinaryTree::covered_by(const BinaryTree &tree) const {
    // TODO: implement this function.
    // empty tree
    if(root == nullptr){
        return true;
    }
    return covered_by_helper(root, tree.root);
}
// EFFECTS: Returns true if this tree is covered by the input binary tree "tree".
//          (only consider the "num" component)

static bool contained_by_helper(const Node * thisnode, const Node * treenode){
    if(covered_by_helper(thisnode, treenode)){
        return true;
    }
    if(treenode->leftSubtree() && treenode->rightSubtree()){
        return contained_by_helper(thisnode, treenode->leftSubtree()) +
        contained_by_helper(thisnode, treenode->rightSubtree());
    }
    if(treenode->leftSubtree() && !treenode->rightSubtree()){
        return contained_by_helper(thisnode, treenode->leftSubtree());
    }
    if(!treenode->leftSubtree() && treenode->rightSubtree()){
        return contained_by_helper(thisnode, treenode->rightSubtree());
    }
    // no subtree can cover this
    return false;
}
// EFFECTS: judge whether a tree is contained by another tree in recursive way.
//          return true if this is contained by the given tree, return false otherwise.

bool BinaryTree::contained_by(const BinaryTree &tree) const {
    // TODO: implement this function.
    return contained_by_helper(root, tree.root);
}
// EFFECTS: Returns true if this tree is contained by the input binary tree "tree".
//          (only consider the "num" component)

static Node * copyFrom(Node * n){
    Node *left, *right;
    left = nullptr;
    right = nullptr;
    if(n->leftSubtree()){
        left = copyFrom(n->leftSubtree());
    }
    if(n->rightSubtree())
    {
        right = copyFrom(n->rightSubtree());
    }

    Node * node = new Node(n->getstr(), n->getnum(), left, right);
    return node;
}
// EFFECTS: copy each node and form a new tree which is the same as the original one.

BinaryTree BinaryTree::copy() const {
    // TODO: implement this function.
    if(!root)
        return nullptr;
    return copyFrom(root);
}
// EFFECTS: Returns a copy of this tree. Hint: use deep copy.