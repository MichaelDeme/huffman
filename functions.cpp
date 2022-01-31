
#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <unordered_map>
#include "structures.h"


// Function to allocate a new tree node
Node* getNode(char ch, int freq, Node* left, Node* right)
{
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}


// traverse the Huffman Tree and store Huffman Codes
// in a map.
void encode(Node* root, std::string str,
			std::unordered_map<char, std::string> &huffmanCode)
{
	if (root == nullptr)
		return;

	// found a leaf node
	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}


// traverse the Huffman Tree and decode the encoded string
void decode(Node* root, int &index, std::string str)
{
	if (root == nullptr) {
		return;
	}

	// found a leaf node
	if (!root->left && !root->right) // traversing and check if leaf or not
	{
		std::cout << root->ch;
		return;
	}

	index++; // if it is not leaf then we increment index and traverse next level 

	if (str[index] =='0')
		decode(root->left, index, str);
	else
		decode(root->right, index, str);
}



// Builds Huffman Tree and decode given input text
void buildHuffmanTree(std::string text)
{
	// count frequency of appearance of each character
	// and store it in a map
	std::unordered_map<char, int> freq;
	for (char ch: text) {
		freq[ch]++;
	}

	// Create a priority queue to store live nodes of
	// Huffman tree;
	std::priority_queue<Node*, std::vector<Node*>, comp> pq;

	// Create a leaf node for each character and add it
	// to the priority queue.
	for (auto pair: freq) { // for pair in freq
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}

	// do till there is more than one node in the queue
	while (pq.size() != 1)
	{
		// Remove the two nodes of highest priority(min-heap)
		// or (lowest frequency) from the queue
		Node *left = pq.top(); pq.pop(); // pq.top access the top element and pq.pop removes it
		Node *right = pq.top();	pq.pop();

		// Create a new internal node with these two nodes
		// as children and with frequency equal to the sum
		// of the two nodes' frequencies. Add the new node
		// to the priority queue.
		int sum = left->freq + right->freq;
		pq.push(getNode('\0', sum, left, right));
	}

	// root stores pointer to root of Huffman Tree
	Node* root = pq.top();

	// traverse the Huffman Tree and store Huffman Codes
	// in a map. Also prints them
	std::unordered_map<char, std::string> huffmanCode;
	encode(root, "", huffmanCode);

	std::cout << "Huffman Codes are :\n" << '\n';
	for (auto pair: huffmanCode) {
		std::cout << pair.first << " " << pair.second << '\n';
	}

	std::cout << "\nOriginal string was :\n" << text << '\n';

	// print encoded string
	std::string str = "";
	for (char ch: text) {
		str += huffmanCode[ch];
		
	}

	std::cout << "\nEncoded string is :\n" << str << '\n';
	
	std::ofstream out("output.txt");
	out << str;
	out.close();
	std::cout << "\nNumber of bits :\n" << str.length() << '\n';
	

	// traverse the Huffman Tree again and this time
	// decode the encoded string
	int index = -1;
	std::cout << "\nDecoded string is: \n";
	while (index < (int)str.size() - 2) {
		decode(root, index, str);
	}
}


