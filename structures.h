/** @file */

#ifndef STRUCTURES_H
#define STRUCTURES_H

// A Tree node
struct Node
{
	char ch;
	int freq;
	Node *left, *right;
};

// Comparison object to be used to order the heap
struct comp
{
	bool operator()(Node* l, Node* r)
	{
		// highest priority item has lowest frequency
		return l->freq > r->freq;
	}
};

#endif