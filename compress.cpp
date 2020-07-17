#include "binaryTree.h"
#include "huffmanTree.h"
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

// EFFECTS: sort the nodes in descending order according to the value they hold.
// MODIFIES: node array n
void nodeSort(Node ** n, int num){
    for(int i = 1; i < num; i++){
        for(int j = 0; j < i; j++){
            if(n[i]->getnum() > n[j]->getnum() || (n[i]->getnum()  == n[j]->getnum() && n[i]->getstr() > n[j]->getstr()))
            {
                Node * temp = n[i];
                n[i] = n[j];
                n[j] = temp;
                // temp = nullptr;
            }
        }
    }

}

// EFFECTS: compress a file and give each character a suitable code.
// REQUIRES: existing file name.
void compress(string & filename, bool mode){
    ifstream file;
    file.open(filename);
    Node ** array = new Node*[28];
    int chnum = 0;
    // process the file.
    char c;
    string ch;

    // calculate the frequency.
    while(file){
        file.get(c);
        if(file){
            ch = c;
            bool process = false;
            for(int i = 0; i < chnum; i++){
                if(ch == array[i]->getstr()){
                    // character already exists, increase the frequency
                    array[i]->incnum();
                    process = true;
                    break;
                }
            }
            // new character
            if(!process){
                array[chnum] = new Node(ch, 1);
                chnum++;
            }
        }
    }

    // sort the nodes according to the frequency
    nodeSort(array, chnum);
    while(chnum > 1){
        // if chnum > 2, merge 2 nodes with fewest frequency as a parent node.
        array[chnum - 2] = array[chnum - 2]->mergeNodes(array[chnum - 2], array[chnum -1]);///
        array[chnum - 1] = nullptr;
        chnum--;
        nodeSort(array, chnum);
    }
    HuffmanTree * huf = new HuffmanTree(array[0]);

    // choose the mode
    if(mode){
        huf->printTree();
    }
    else{
        file.close();
        file.open(filename);
        while(file){
            file.get(c);
            if(file){
                ch = c;
                cout << huf->findPath(ch) << " ";
            }
        }
    }
    file.close();
    delete huf;
    delete[] array;
}

int main(int argc, char *argv[]) {
    // TODO: implement this function
    string filename;
    string str = argv[1];
    bool mode = false; // whether only to print the tree.
    if(str == "-tree"){
        filename = argv[2];
        mode = true;
    }
    else{
        filename = str;
    }
    compress(filename, mode);
    return 0;
}