#include "binaryTree.h"
#include "huffmanTree.h"
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

// EFFECTS: decompress the file.
// REQUIRES: correct file name of tree file and binary file.
void decompress(string & treefilename, string & binaryfilename){
    ifstream file;
    // open the file.
    file.open(binaryfilename);

    // create the corresponding huffman tree.
    HuffmanTree * huf = new HuffmanTree(treefilename);
    while(file){
        string path;
        file >> path;
        if(file){
            int i = 0;
            Node * str = huf->root;
            while(path[i] != '\0'){
                if(path[i] == '0'){
                    str = str->leftSubtree();
                }
                else{
                    str = str->rightSubtree();
                }
                i++;
            }
            //cout << str->getstr();
            cout << str->getstr();
        }
    }
    file.close();
    delete huf;
}

int main(int argc, char *argv[]) {
    // TODO: implement this function
    string treefilename = argv[1];
    string binaryfilename = argv[2];
    decompress(treefilename, binaryfilename); // decompress the file.
    return 0;
}