using namespace std;
template<typename Anytype>
struct BinaryNode
{
	Anytype Data;
	BinaryNode<Anytype> *LeftChild;
	BinaryNode<Anytype> *RightChild;
};
template<typename Anytype>
class BinaryTree
{
private:
	BinaryNode<Anytype> *Root;
	BinaryNode<Anytype> *BuildBinaryTree(BinaryNode<Anytype>*);
	int CountNode(BinaryNode<Anytype>*);
	void ReleaseBinaryTree(BinaryNode<Anytype>*);
	void PreOrder(BinaryNode<Anytype>*);
	void InOrder(BinaryNode<Anytype>*);
	void PostOrder(BinaryNode<Anytype>*);
	int CountLeafNode(BinaryNode<Anytype>*);
	void DemonstrateLeafNode(BinaryNode<Anytype>*);
	int getTreeDepth(BinaryNode<Anytype>*);
	void getParents(BinaryNode<Anytype>*,Anytype);
	void initiateSubTree(BinaryNode<Anytype>*, Anytype);
	void exchangeLeftRightChild(BinaryNode<Anytype>*);
	void reversePostOrder(BinaryNode<Anytype>*);
	bool findWayToTarget(BinaryNode<Anytype>*, Anytype, Anytype*, int&);
public:
	BinaryTree()
	{
		Root = BuildBinaryTree(Root);
	}
	~BinaryTree()
	{
		ReleaseBinaryTree(Root);
	}
	void PreOrder()
	{
		if (Root != NULL)
		{
			PreOrder(Root);
		}
		else
		{
			cout << "Empty tree" << endl;
		}
	}
	void InOrder()
	{
		if (Root != NULL)
		{
			InOrder(Root);
		}
		else
		{
			cout << "Empty tree" << endl;
		}
	}
	void PostOrder()
	{
		if (Root != NULL)
		{
			PostOrder(Root);
		}
		else
		{
			cout << "Empty tree" << endl;
		}
	}
	void LeverOrder();
	int CountNode()
	{
		return CountNode(Root);
	}
	int CountLeafNode()
	{
		return CountLeafNode(Root);
	}
	void DemonstrateLeafNode()
	{
		DemonstrateLeafNode(Root);
	}
	int getTreeDepth()
	{
		return getTreeDepth(Root);
	}
	void getParents()
	{
		Anytype Child,temp;
		cout <<"Who's parents would you like to know?" << endl;
		cin >> Child;
		getParents(Root, Child);
	}
	void initiateSubTree()
	{
		cout << "Would you kindly tell me the node'value that I will completely initiate its sub tree" <<endl;
		Anytype Data;
		cin >> Data;
		initiateSubTree(Root, Data);
	}
	void exchangeLeftRightChild()
	{
		exchangeLeftRightChild(Root);
	}
	void reversePostOrder()
	{
		reversePostOrder(Root);
	}  
	void findWayToTarget()
	{
		Anytype Target;
		Anytype *Arr = new Anytype[getTreeDepth()];
		int i = 0;
		cout << "Would you kindly tell me who would you want to find and I will show you" << endl;
		cin >> Target;
		if (Target == Root->Data)
		{
			cout << "Well it's a root node and you can find it even you are blind" << endl;
		}
		else if (!findWayToTarget(Root, Target, Arr, i))
		{
			cout << "No such node exists" << endl;
		}
		else
		{
			for (int j = i - 1; j >= 0; j--)
			{
				cout << Arr[j] << "-->" ;
			}
			cout << Target << endl;
		}
		delete[]Arr;
	}
	void printBinaryTree();
};
template<typename Anytype>
void BinaryTree<Anytype>::printBinaryTree()
{
	if (Root != NULL)
	{
		int Depth = getTreeDepth(Root);
		int MaxsizeNode = (int)pow(2, Depth) - 1;
		BinaryNode<Anytype>** Queue = new BinaryNode<Anytype>*[MaxsizeNode];
		for (int i = 0; i < MaxsizeNode; i++)
		{
			Queue[i] = NULL;
		}
		int Front = 0, Rear = -1;
		Queue[Front] = Root;
		for (Rear = 0; Rear < MaxsizeNode;Rear++)
		{
			if (Queue[Rear] != NULL)
			{
				Front++;
				if (Queue[Rear]->LeftChild != NULL)
				{
					Queue[Front] = Queue[Rear]->LeftChild;
				}
				Front++;
				if (Queue[Rear]->RightChild != NULL)
				{
					Queue[Front] = Queue[Rear]->RightChild;
				}
			}
			else
			{
				Front = Front + 2;
			}
		} 
		Front = -1;
		for (int i = 0; i < Depth; i++)
		{
			int LeverNodeNumber = (int)pow(2, i);
			for (int k = 0; k < LeverNodeNumber; k++)
			{
				for (int j = 0; j < pow(2, Depth - i) - 1; j++)
				{
					cout << " ";
				}
				Front++;
				if (Queue[Front] == NULL)
				{
					cout << " ";
				}
				else
				{
					cout << Queue[Front]->Data;
				}
				for (int j = 0; j <= pow(2, Depth - i) - 1; j++)
				{
					cout << " ";
				}
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Empty Tree" << endl;
	}
}
template<typename Anytype>
bool BinaryTree<Anytype>::findWayToTarget(BinaryNode<Anytype>* TheBinaryNode, Anytype Target, Anytype* Arr,int &i )
{
	if (TheBinaryNode != NULL)
	{
		if (TheBinaryNode->Data == Target)
		{
			return true;
		}
		else
		{
			if (findWayToTarget(TheBinaryNode->LeftChild, Target, Arr, i) || findWayToTarget(TheBinaryNode->RightChild, Target, Arr, i))
			{
				Arr[i] = TheBinaryNode->Data;
				i++;
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
}
template<typename Anytype>
void BinaryTree<Anytype>::reversePostOrder(BinaryNode<Anytype>* TheBinaryNode)
{
	if (TheBinaryNode != NULL)
	{
		cout << TheBinaryNode->Data << " ";
		reversePostOrder(TheBinaryNode->RightChild);
		reversePostOrder(TheBinaryNode->LeftChild);
	}
}
template<typename Anytype>
void BinaryTree<Anytype>::exchangeLeftRightChild(BinaryNode<Anytype>* TheBinaryNode)
{
	if (TheBinaryNode != NULL)
	{
		BinaryNode<Anytype>* temp = TheBinaryNode->LeftChild;
		TheBinaryNode->LeftChild = TheBinaryNode->RightChild;
		TheBinaryNode->RightChild = temp;
		exchangeLeftRightChild(TheBinaryNode->LeftChild);
		exchangeLeftRightChild(TheBinaryNode->RightChild);
	}
}
template<typename Anytype>
void BinaryTree<Anytype>::initiateSubTree(BinaryNode<Anytype>* TheBinaryNode, Anytype Data)
{
	if (TheBinaryNode != NULL)
	{
		if (TheBinaryNode->Data == Data)
		{
			ReleaseBinaryTree(TheBinaryNode);
			Root = NULL;
		}
	}
	if (TheBinaryNode->LeftChild != NULL)
	{
		if (TheBinaryNode->LeftChild->Data == Data)
		{
			ReleaseBinaryTree(TheBinaryNode->LeftChild);
			TheBinaryNode->LeftChild = NULL;
		}
		else
		{
			initiateSubTree(TheBinaryNode->LeftChild, Data);
		}
	}
	if (TheBinaryNode->RightChild != NULL)
	{
		if (TheBinaryNode->RightChild->Data == Data)
		{
			ReleaseBinaryTree(TheBinaryNode->RightChild);
			TheBinaryNode->RightChild = NULL;
		}
		else
		{
			initiateSubTree(TheBinaryNode->RightChild, Data);
		}
	}
	if (TheBinaryNode == Root)
	{
		cout << "No such sub tree exists" << endl;
	}
}
template<typename Anytype>
void BinaryTree<Anytype>::getParents(BinaryNode<Anytype>* TheBinaryNode,Anytype Child)
{
	if (TheBinaryNode->Data == Child)
	{
		cout << "Root node doesn't have parents" << endl;
	}
	else
	{
		BinaryNode<Anytype>** Queue = new BinaryNode<Anytype>*[CountNode()];
		int Front = 0, Rear = -1;
		Queue[Front] = TheBinaryNode;
		while (Front != Rear)
		{
			Rear++;
			if (Queue[Rear]->LeftChild != NULL)
			{
				if (Queue[Rear]->LeftChild->Data == Child)
				{
					cout << "The Child's parents are " << Queue[Rear]->Data << endl;
					break;
				}
				else
				{
					Front++;
					Queue[Front] = Queue[Rear]->LeftChild;
				}
			}
			if (Queue[Rear]->RightChild != NULL)
			{
				if (Queue[Rear]->RightChild->Data == Child)
				{
					cout << "The Child's parents are " << Queue[Rear]->Data << endl;
					break;
				}
				else
				{
					Front++;
					Queue[Front] = Queue[Rear]->RightChild;
				}
			}
		}
		if (Front == Rear)
		{
			cout << "There is no child named " << Child << endl;
		}
	}
}
template<typename Anytype>
int BinaryTree<Anytype>::getTreeDepth(BinaryNode<Anytype>* TheBinaryNode)
{
	if(TheBinaryNode!=NULL)
	{
		if ((TheBinaryNode->LeftChild != NULL) && (TheBinaryNode->RightChild != NULL))
		{
			return 1 + max(getTreeDepth(TheBinaryNode->LeftChild), getTreeDepth(TheBinaryNode->RightChild));
		}
		else if(TheBinaryNode->LeftChild != NULL)
		{
			return 1+getTreeDepth(TheBinaryNode->LeftChild);
		}
		else if(TheBinaryNode->RightChild != NULL)
		{
			return 1+getTreeDepth(TheBinaryNode->RightChild);
		}
		else
		{
			return 1;
		}
	}
}
template<typename Anytype>
void BinaryTree<Anytype>::DemonstrateLeafNode(BinaryNode<Anytype>* TheBinaryNode)
{
	if (TheBinaryNode != NULL)
	{
		if (TheBinaryNode->LeftChild == NULL&&TheBinaryNode->RightChild==NULL)
		{
			cout << TheBinaryNode->Data << " ";
		}
		DemonstrateLeafNode(TheBinaryNode->LeftChild);
        DemonstrateLeafNode(TheBinaryNode->RightChild);
	}
}
template<typename Anytype>
int BinaryTree<Anytype>::CountNode(BinaryNode<Anytype>* TheBinaryNode)
{
	if (TheBinaryNode != NULL)
	{
		return 1 + CountNode(TheBinaryNode->LeftChild) + CountNode(TheBinaryNode->RightChild);
	}
	else
	{
		return 0;
	}
}
template<typename Anytype>
int BinaryTree<Anytype>::CountLeafNode(BinaryNode<Anytype>* TheBinaryNode)
{
	int i = 0;
	if (TheBinaryNode != NULL)
	{
		if (TheBinaryNode->LeftChild == NULL&&TheBinaryNode->RightChild==NULL)
		{
			i = 1;
		}
		return i + CountLeafNode(TheBinaryNode->LeftChild) + CountLeafNode(TheBinaryNode->RightChild);
	}
	else
	{
		return i;
	}
}
template<typename Anytype>
BinaryNode<Anytype>* BinaryTree<Anytype>::BuildBinaryTree(BinaryNode<Anytype>* TheBinaryNode)
{
	Anytype value;
	cin >> value;
	if (value == '#')
	{
		TheBinaryNode = NULL;
	}
	else
	{
		TheBinaryNode = new BinaryNode<Anytype>();
		TheBinaryNode->Data = value;
		TheBinaryNode->LeftChild = BuildBinaryTree(TheBinaryNode->LeftChild);
		TheBinaryNode->RightChild = BuildBinaryTree(TheBinaryNode->RightChild);
	}
	return TheBinaryNode;
}
template<typename Anytype>
void BinaryTree<Anytype>::PreOrder(BinaryNode<Anytype>* TheBinaryNode)
{
	if (TheBinaryNode != NULL)
	{
		cout << TheBinaryNode->Data << " ";
		PreOrder(TheBinaryNode->LeftChild);
		PreOrder(TheBinaryNode->RightChild);
	}
}
template<typename Anytype>
void BinaryTree<Anytype>::InOrder(BinaryNode<Anytype>* TheBinaryNode)
{
	if (TheBinaryNode != NULL)
	{
		InOrder(TheBinaryNode->LeftChild);
		cout << TheBinaryNode->Data << " ";
		InOrder(TheBinaryNode->RightChild);
	}
}
template<typename Anytype>
void BinaryTree<Anytype>::PostOrder(BinaryNode<Anytype>* TheBinaryNode)
{
	if (TheBinaryNode != NULL)
	{
		PostOrder(TheBinaryNode->LeftChild);
		PostOrder(TheBinaryNode->RightChild);
		cout << TheBinaryNode->Data << " ";
	}
}
template<typename Anytype>
void BinaryTree<Anytype>::LeverOrder()
{
	if (Root != NULL)
	{
		BinaryNode<Anytype>** Queue = new BinaryNode<Anytype>* [CountNode()];
		int Front = 0, Rear = -1;
		Queue[Front] = Root;
		while (Front != Rear)
		{
			Rear++;
			cout << Queue[Rear]->Data << ' ';
			if (Queue[Rear]->LeftChild != NULL)
			{
				Front++;
				Queue[Front] = Queue[Rear]->LeftChild;
			}
			if (Queue[Rear]->RightChild != NULL)
			{
				Front++;
				Queue[Front] = Queue[Rear]->RightChild;
			}
		}
	}
	else
	{
		cout << "Empty Tree" << endl;
	}
}
template<typename Anytype>
void BinaryTree<Anytype>::ReleaseBinaryTree(BinaryNode<Anytype>* TheBinaryNode)
{
	if (TheBinaryNode != NULL)
	{
		ReleaseBinaryTree(TheBinaryNode->LeftChild);
		ReleaseBinaryTree(TheBinaryNode->RightChild);
		delete TheBinaryNode;
	}
}
void RunBinaryTree()
{
	cout << "Would you kindly build your binary tree by preorder?" << endl;
	BinaryTree<char> MyBinaryTree;
	bool flag = true;
	while (flag)
	{
		cout << endl << "Menu" << endl;
		cout << "1.PreOrder" << endl;
		cout << "2.InOrder" << endl;
		cout << "3.PostOrder" << endl;
		cout << "4.LeverOrder" << endl;
		cout << "5.Count node" << endl;
		cout << "6.Count leaf node" << endl;
		cout << "7.Display leaf node" << endl;
		cout << "8.Get depth of the tree" << endl;
		cout << "9.Get parents" << endl;
		cout << "10.Initiate sub tree" << endl;
		cout << "11.Exchange left and right child" << endl;
		cout << "12.Reverse postorder" << endl;
		cout << "13.Find way to target" << endl;
		cout << "14.Print binary tree" << endl;
		cout << "Any other number to exit" << endl;
		int i;
		cin >> i;
		switch (i)
		{
		case 1:
			cout << "Now the tree is demonstrated as preorder" << endl;
			MyBinaryTree.PreOrder();
			break;
		case 2:
			cout << "Now the tree is demonstrated as inorder" << endl;
			MyBinaryTree.InOrder();
			break;
		case 3:
			cout << "Now the tree is demonstrated as postorder" << endl;
			MyBinaryTree.PostOrder();
			break;
		case 4:
			cout << "Now the tree is demonstrated as leverorder" << endl;
			MyBinaryTree.LeverOrder();
			break;
		case 5:
			cout << "The number of node is " << MyBinaryTree.CountNode() << endl;
			break;
		case 6:
			cout << "The number of leaf node is " << MyBinaryTree.CountLeafNode() << endl;
			break;
		case 7:
			MyBinaryTree.DemonstrateLeafNode();
			break;
		case 8:
			cout << "The depth of tree is " << MyBinaryTree.getTreeDepth() << endl;
			break;
		case 9:
			MyBinaryTree.getParents();
			break;
		case 10:
			MyBinaryTree.initiateSubTree();
			MyBinaryTree.PreOrder();
			break;
		case 11:
			MyBinaryTree.exchangeLeftRightChild();
			MyBinaryTree.LeverOrder();
			break;
		case 12:
			MyBinaryTree.reversePostOrder();
			break;
		case 13:
			MyBinaryTree.findWayToTarget();
			break;
		case 14:
			MyBinaryTree.printBinaryTree();
			break;
		default:
			flag = false;
			break;
		}
	}
}