#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <unordered_map>
#include "structures.h"
#include "functions.h"





// Huffman coding algorithm
int main(int argc, char* argv[])


{
	const std::string IN{ "-i" };
	const std::string OUT{ "-o" };
	

	for (int i = 0; i < argc; i++)
	{
		if (std::string(argv[i]) == IN)
		{
			std::ifstream ifs("input.txt");
			std::string text((std::istreambuf_iterator<char>(ifs)),
				(std::istreambuf_iterator<char>()));

			buildHuffmanTree(text);
		}
		else {
			std::cout << "no input" << std::endl;
		}

		if (std::string(argv[i]) == "-c")
		{
			void encode(Node * root, std::string str,
				std::unordered_map<char, std::string> &huffmanCode);
		}

		//assump:- define output function and do it here


	}
	/*
	const std::string IN{ "-i" };
    const std::string OUT{ "-o" };
	/*const std::string MODE{ "-m" };
	const std::string COMPRESS{ "c" };
	const std::string DECOMPRESS{ "d" };
	const std::string DICTIONARY{ "-d" };

	std::string input_file_name;
	std::string output_file_name;

	*/



	/*
	for (int i = 0; i < argc; i++)
	{
		if (std::string(argv[i]) == IN && i + 1 < argc)
			input_file_name = argv[i + 1];
		if (std::string(argv[i]) == OUT && i + 1 < argc)
			output_file_name = argv[i + 1];
		//if (std::string(argv[i]) == MODE and std::string(argv[i + 1]) == COMPRESS);
		  compress();
		if (std::string(argv[i]) == MODE and std::string(argv[i + 1]) == DECOMPRESS);
		  decompress();
		if (std::string(argv[i]) == DICTIONARY and i + 1 < argc);
		
	}

	if (input_file_name.empty())
	      std::cout << "no input file"<<std::endl;
	else
	     std::cout << input_file_name <<std::endl;

	if(output_file_name.empty())

	    std::cout << "no output" <<std::endl;
    else  
		*/
		//buildHuffmanTree(text);

		

	
	return 0;
	/*string text = "Huffman coding is a data compression algorithm.";

	

	*/
}
/*
Huffman Codes are :

c 11111
h 111100
f 11101
r 11100
t 11011
p 110101
i 1100
g 0011
l 00101
a 010
o 000
d 10011
H 00100
. 111101
s 0110
m 0111
e 110100
  101
n 1000
u 10010

Original string was :
Huffman coding is a data compression algorithm.

Encoded string is :
00100100101110111101011101010001011111100010011110010000011101110001101010101011001101011011010101111110000111110101111001101000110011011000001000101010001010011000111001100110111111000111111101

Decoded string is: 
Huffman coding is a data compression algorithm.
*/
