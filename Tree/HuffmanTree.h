#include"BinaryTree.h"
using namespace std;
template<typename Anytype>
struct HuffmanNode
{
	HuffmanNode<Anytype> *left_node;
	HuffmanNode<Anytype> *right_node;
	int weight;
};
template<typename Anytype>
class HuffmanTree
{
private:
	int node_number;
	HuffmanNode<Anytype> *node_list;
	HuffmanNode<Anytype> root_node;

public:
	HuffmanTree()
	{
		root_node = createHuffmanTree();
	}
	createHuffmanTree()
	{
		generateBinaryTree();
	}

};
template<typename Anytype>
HuffmanNode<Anytype> HuffmanTree<Anytype>::createHuffmanTree()
{
	bool flag = true;
	while (flag)
	{xor

	}
}