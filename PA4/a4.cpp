// Kyle Loyka
// CSCE 221 - 505
// Assignment 4

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
#include <cmath>
using namespace std;

class binaryNode
{
private:
	binaryNode* parent;
	binaryNode* child_left;
	binaryNode* child_right;
	int val;
	int sc;

public:
	/* Constructor & Destructor */
	binaryNode(binaryNode* p = NULL, binaryNode* cl = NULL, binaryNode* cr = NULL, int k = 0)
		: parent(p), child_left(cl), child_right(cr), val(k) {}
	~binaryNode();

	/* Methods */
	bool is_root()
	{
			if (parent == NULL) return true;
			else return false;
	}
	int key() {return val;}
	binaryNode* get_left() {return child_left;}
	binaryNode* get_right() {return child_right;}
	int searchCost() {return sc;}
	void set_searchCost(int s) {sc = s;}
	void set_parent(binaryNode* p)
	{
		parent = p;
	}
	void insert_left(binaryNode* cl)
	{
		child_left = cl;
	}
	binaryNode* pop_left()
	{
		binaryNode* l = child_left;
		child_left = NULL;
		return l;
	}
	void insert_right(binaryNode* cr)
	{
		child_right = cr;
	}
	binaryNode* pop_right()
	{
		binaryNode* r = child_right;
		child_right = NULL;
		return r;
	}

};

/* number of nodes below a given node */
int node_size(binaryNode* t)
{
	if (t == NULL)
		return 0;
	else
		return 1 + node_size(t->get_left()) + node_size(t->get_right());
}

/* height of a given node */
int node_height(binaryNode* t)
{
	if (t == NULL)
		return -1;
	else
	{
		int hlf = node_height(t->get_left());
		int hrt = node_height(t->get_right());
		return (hlf > hrt) ? 1+hlf : 1+hrt;
	}
}

/* print data about a node */
void print_node2(binaryNode* node, ostream& out)
{
	out << "Key = "<< node->key() << "["<< node->searchCost()<<"] ";
}

void print_node(binaryNode* node, ostream& out)
{
	out << node->key() << " Search Cost = "<< node->searchCost() << endl;
}

/* reading file to vector */
void read_data(vector<int>& v)
{
	cout << "specify input file:\n";
	string tmp;
	cin >> tmp;
	ifstream file;
	file.open(tmp.c_str());
	string s;
	while(!file.eof())
		{
			getline(file,s);
			stringstream ss(s);
			int x;
			int number;
			number = (ss >> x ? x : -1);
			if (number != -1)
				v.push_back(number);
		}
}

/* printing input data to screen */
void print_data(vector<int>& v)
{
	cout << "input data:\n";
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " , ";
	cout << endl << endl;
}

/* insert node into tree */
void insert(binaryNode* root, int val, int c = 1)
{
	if(root->key() > val)
	{

		if(root->get_left() != NULL)
		{
			//cout <<"deeper left\n";
			insert(root->get_left(),val,++c);
		}
		else
		{
			//cout <<"making (left) node for value: "<< val<< endl;
			binaryNode* n = new binaryNode(root,NULL,NULL,val);
			n->set_searchCost(++c);
			root->insert_left(n);
			//cout <<"Key = " << root->key() << "   SearchCost = "<< root->searchCost() << endl;

		}
	}
	else
	{
		if(root->get_right() != NULL)
		{
			//cout << "deeper right\n";
			insert(root->get_right(),val,++c);
		}
		else
		{
			//cout << "making (right) node for value: "<< val << endl;
			binaryNode* n = new binaryNode(root,NULL,NULL,val);
			n->set_searchCost(++c);
			root->insert_right(n);
			//cout <<"Key = " << root->key() << "   SearchCost = "<< root->searchCost() << endl;

		}
	}
}

/* make tree from vector */
binaryNode* make_tree(vector<int>& v)
{
	//root node
	binaryNode* root = new binaryNode(NULL,NULL,NULL,v[0]);
	root->set_searchCost(1);
	//cout <<"Key = " << root->key() << "   SearchCost = "<< root->searchCost() << endl;
	for(int i = 1; i < v.size(); ++i)
	{
		insert(root,v[i]);
	}
	return root;
}

void totSearchCost(binaryNode* root, int& tot)
{
	tot = tot + root->searchCost();
	if (root->get_left() != NULL) totSearchCost(root->get_left(), tot);
	if (root->get_right() != NULL) totSearchCost(root->get_right(), tot);
}

double avgSearch(binaryNode* root)
{
	int tot;
	totSearchCost(root, tot);
	double sz = node_size(root);
	//cout <<"tot : "<<total<<edl;
	return tot/sz;
}


void inOrderTraversal(binaryNode* root, ostream& out)
{
	if (root->get_left() != NULL) inOrderTraversal(root->get_left(), out);
	print_node(root,out);
	if (root->get_right() != NULL) inOrderTraversal(root->get_right(), out);
}

void preOrderTraversal(binaryNode* root, ostream& out)
{
	print_node(root,out);
	if (root->get_left() != NULL) inOrderTraversal(root->get_left(), out);
	if (root->get_right() != NULL) inOrderTraversal(root->get_right(), out);
}

void postOrderTraversal(binaryNode* root, ostream& out)
{
	if (root->get_left() != NULL) inOrderTraversal(root->get_left(), out);
	if (root->get_right() != NULL) inOrderTraversal(root->get_right(), out);
	print_node(root,out);
}

void inOrderTraversal2(binaryNode* root, ostream& out)
{
	if (root->get_left() != NULL) inOrderTraversal2(root->get_left(), out);
	print_node2(root,out);
	if (root->get_right() != NULL) inOrderTraversal2(root->get_right(), out);
}


// void level_by_level(binaryNode* root, ostream& out)
// {
// 	 queue<binaryNode*> q;
// 	 q.push(root);
//
// 	 int currCost = 0;
// 	 int prevCost = 0;
// 	 while (!q.empty())
// 	 {
// 		binaryNode* node = q.front();
// 		q.pop();
// 		currCost = node->searchCost();
// 		if(prevCost != currCost)
// 			{
// 				out << endl;
// 				prevCost = currCost;
// 			}
//
//  		out << node->key() << " ";
//
// 		if(node->get_left() != NULL)
// 		{
// 			q.push(node->get_left());
// 		}
// 		else
// 		{
// 			out <<"X ";
// 			//++currCost;
// 		}
// 		if(node->get_right() != NULL)
// 		{
// 			q.push(node->get_right());
// 		}
// 		else
// 		{
// 			out <<"X ";
// 			//++currCost;
// 		}
// 	 }
// }

void level_by_level(binaryNode* root, ostream& out)
{
	if (root == NULL) return;

	queue<binaryNode*> q;
	q.push(root);
	bool val = true;
	while(!q.empty())
	{
		int sz = q.size();
		for (int i = 0; i < sz; ++i)
		{
			binaryNode* x = q.front();
			q.pop();

			if (x->key())
				out << x->key() << " ";
			else
				out << "X ";

			if(x->get_left() != NULL)
			{
				q.push(x->get_left());
			}
			else if (val)
			{
				q.push(new binaryNode(NULL,NULL,NULL,0));
				val = false;
			}
			else
			{
				//val = true;
			}
			if(x->get_right() != NULL)
			{
				q.push(x->get_right());
			}
			else if (val)
			{
				q.push(new binaryNode(NULL,NULL,NULL,0));
				val = false;
			}
			else
			{
				//val = true;
			}
		}
		cout << endl;
	}
}


int main(){
	//-----------------------------------------------------------
	/* reading file into vector */
	//-----------------------------------------------------------
	vector<int>input;
	read_data(input);
	print_data(input);
	cout << "done.\n";

	//-----------------------------------------------------------
	/* if data set is large, all output will be sent to a file */
	//-----------------------------------------------------------
	ofstream file;
	if (input.size() >= pow(2,4))
	{
		cout <<"large input data. ALl output will be sent to text file\n";
	 	cout <<"please enter output file name:\n";
	 	string input;
	 	cin >> input;
 		file.open(input.c_str());
	}

	//-----------------------------------------------------------
	/* making binary tree from data set */
	//-----------------------------------------------------------
	cout << "making tree\n";
	binaryNode* root = make_tree(input);
	cout << "done.\n";

	//-----------------------------------------------------------
	/* Number of nodes and average search cost */
	//-----------------------------------------------------------
	cout << "Number of nodes : "<< node_size(root) << endl;
	cout << "Average search cost : "<< avgSearch(root) << endl;

	//-----------------------------------------------------------
	/* in order traversal */
	//-----------------------------------------------------------
	if (input.size() >= pow(2,4))
	{
		file << "printing tree: in order traversal\n";
		inOrderTraversal(root,file);
	}
	else
	{
		cout<< "printing tree: in order traversal\n";
		inOrderTraversal(root,cout);
	}
	cout << "done.\n";

	//-----------------------------------------------------------
	/* pre order traversal */
	//-----------------------------------------------------------
	if (input.size() >= pow(2,4))
	{
		file << "printing tree: pre order traversal\n";
		preOrderTraversal(root,file);
	}
	else
	{
		cout<< "printing tree: pre order traversal\n";
		preOrderTraversal(root,cout);
	}
	cout << "done.\n";

	//-----------------------------------------------------------
	/* post order traversal */
	//-----------------------------------------------------------
	if (input.size() >= pow(2,4))
	{
		file << "printing tree: post order traversal\n";
		postOrderTraversal(root,file);
	}
	else
	{
		cout << "printing tree: post order traversal\n";
		postOrderTraversal(root,cout);
	}
	cout << "done.\n";

	//-----------------------------------------------------------
	/* breadth first traversal */
	//-----------------------------------------------------------
	if( input.size() < pow(2,4))
	{
		cout<<"breadth first output\n";
		level_by_level(root,cout);
	}
	cout <<"\ndone.\n";

	//-----------------------------------------------------------
	/* in order traversal with Key[SearchCost] formatting		*/
	//-----------------------------------------------------------
	if (input.size() >= pow(2,4))
	{
		file << "printing tree: in order traversal with Key[SearchCost] formatting\n";
		inOrderTraversal2(root,file);
	}
	else
	{
		cout << "printing tree: in order traversal with Key[SearchCost] formatting\n";
		inOrderTraversal2(root,cout);
	}
	cout << "\ndone.\n";


return 0;
}
