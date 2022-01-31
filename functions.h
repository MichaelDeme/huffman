/** @file */



#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <iostream>
#include <string>
#include <queue>

#include <unordered_map>
#include "structures.h"


/** Function to allocate a new tree node.
@param ch indicates the characters
@param freq with their occuruence or frequency 
@param left and 
@param right indicate left and right child of that node
@return a Node with ch and freq*/

Node* getNode(char ch, int freq, Node* left, Node* right);

/** Function to traverse the Huffman Tree and store Huffman Codes in map.
@param root node pointer
@param std::string str new var to track the encoded data/numbers 
@param std::unordered_map<char, std::string> &huffmanCode   map for storing char and their freq*/
void encode(Node* root, std::string str, std::unordered_map<char, std::string> &huffmanCode);

/** Function to traverse the Huffman Tree and decode the encoded string
@param index  used to check if it is not leaf then we increment index and traverse next level 

*/
void decode(Node* root, int &index, std::string str);


/** The function which Builds Huffman Tree and decode given input text
@param text is the string(collection of many characters) which are retrieved from input text file
 */
void buildHuffmanTree(std::string text);



#endif