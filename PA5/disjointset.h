// Kyle Loyka
// CSCE 221 - 505
// Programming Assignment 5

#pragma once

#include "TemplateDoublyLinkedList.h"
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Disjoint Set
template <typename T>
class DisjointSet {
private:
	vector<DListNode<T>*> nodeLocator;
public:
	~DisjointSet(){
		for (int i = 0; i < nodeLocator.size(); ++i){
			DListNode<T>* node = nodeLocator[i];
			delete node;
			}
	};

	DisjointSet(int n){
		if (n > 0){
			DListNode<T>* ptr = new DListNode<T>(0,T());
			for (int i = 0; i < (n+1); ++i){
				nodeLocator.push_back(ptr);
			}
		}
		else
			cout <<"Error, invalid DisjointSet allocated size\n";
	};

	vector<DListNode<T>*> getNodeLocator() const{
		return nodeLocator;
	};

	DListNode<T>* MakeSet(int key, T node){
		if (key > nodeLocator.size()){
			cout << "Error, key larger than DisjointSet size\n";
			return NULL;
		}

		DListNode<T>* ptr = new DListNode<T>(key,node);
		ptr->setListSize(1);
		ptr->setRepresentative(ptr);
		nodeLocator[key] = ptr;
		return ptr;
	};

	DListNode<T>* Union(DListNode<T> &nodeI, DListNode<T> &nodeJ){

		/* make sure user doesn't merge the same two sets */
		if (nodeI.getRepresentative() == nodeJ.getRepresentative()){
			cout <<"Error, same sets\n";
			return nodeI.getRepresentative();
		}

		if( (nodeI.getListSize() == 1) && (nodeJ.getListSize() == 1) ){
			nodeI.setRepresentative(&nodeI);
			nodeI.setNext(&nodeJ);
			nodeI.setTrailer(&nodeJ);
			nodeI.setListSize(2);

			nodeJ.setPrevious(&nodeI);
			nodeJ.setRepresentative(&nodeI);
			nodeJ.setListSize(2);
		}

		else {
			DListNode<T>* TrailI = nodeI.getRepresentative()->getTrailer();
			DListNode<T>* RepJ = nodeJ.getRepresentative();

			nodeJ.getRepresentative()->setPrevious(nodeI.getRepresentative()->getTrailer());
			nodeI.getRepresentative()->getTrailer()->setNext(nodeJ.getRepresentative());

			nodeI.getRepresentative()->setTrailer(nodeJ.getTrailer());
			nodeJ.setRepresentative(nodeI.getRepresentative());
			nodeJ.setTrailer(NULL);

			int newSize = nodeI.getListSize() + nodeJ.getListSize();
			DListNode<T>* itr = nodeJ.getRepresentative();
			while(itr != NULL){
				itr->setListSize(newSize);
				itr->setRepresentative(nodeI.getRepresentative());
				itr = itr->getNext();
			}
		}

		return nodeI.getRepresentative();
	};

	DListNode<T>* FindSet(DListNode<T> node){
		return node.getRepresentative();
	};

	DListNode<T>* FindSet(int nodeKey){
		/* make sure nodeKey and node exist */
		if( (nodeKey>=0) & (nodeKey < nodeLocator.size()))
			return nodeLocator[nodeKey]->getRepresentative();
		else{
			cout <<"Error\n";
			return NULL;
		}
	};
};

template <typename T>
ostream& operator<<(ostream& out, const DisjointSet<T>& ds) {

	/* data */
	vector<DListNode<T>*> v = ds.getNodeLocator();
	vector<DListNode<T>*> pointers;
	bool print = true;

	/* printing loop */
	for(int i = 1; i < v.size(); ++i){
		DListNode<T>* itr = v[i];
		itr = itr->getRepresentative();

		/* see if representative has already been printed */
		for(int i = 0; (i < pointers.size()) & print; ++i){
			if ( pointers[i] == itr)
				print = false;
			else
				print = true;
		}

		if(print){
			/* add pointer to list of representatives that have been printed */
			pointers.push_back(itr);
			/* print formatting */
			out << "{";
			for (int k = 0; k < itr->getListSize(); ++k){
				out << itr->getElem();
				if( itr->getNext() != NULL)
					itr = itr->getNext();
			}
				out << "}";
				out << endl << endl;
		}
		print = true;
	}
	return out;
}
