#include "Graph.h"
#include "disjointset.h"
#include "TemplateDoublyLinkedList.h"
#include <iostream>
#include <vector>

using namespace std;

void Graph::buildGraph() {
  if((n<0) || (e<0)){
    throw GraphException("either row or column is negative!");
  }
  /* initializing empty adjacency list */
  for(int i = 0; i < n; ++i){
    AdjacencyList.push_back(new DListNode<Vertex>(0,i));
  }
  /* do nothing for edges */
}

void Graph::insertEdge(int i, int j, double w) {
  if(curEdges >= e){
    throw GraphException("edge number is not correct!");
  }
  /* don't have to check if edge has been created, the input operator already
     does this                                                               */
  EdgeList.push_back(new Edge(i,j,w));
  /* update 2 adjacency lists, first for index i, then index j */
  /* step 1: updating i's Adjacency List */
  DListNode<Vertex>* ptr = AdjacencyList[i];
  while(ptr != NULL){
    if (ptr->getNext() == NULL){
      Vertex tmp(j);
      tmp.edge = EdgeList[EdgeList.size()-1];
      ptr->setNext(new DListNode<Vertex>(0,tmp));
      ptr = NULL;
    }
    else{
      ptr = ptr->getNext();
    }
  }
  /* step 2: updating j's Adjacency List */
  ptr = AdjacencyList[j];
  while (ptr != NULL){
    if(ptr->getNext() == NULL){
      Vertex tmp(i);
      tmp.edge = EdgeList[EdgeList.size()-1];
      ptr->setNext(new DListNode<Vertex>(0,tmp));
      ptr = NULL;
    }
    else{
      ptr = ptr->getNext();
    }
  }
  /* updating current Edge counter */
  curEdges++;
  return;
}

double Graph::getWeight(int i, int j) {
  DListNode<Vertex>* ptr = AdjacencyList[i]->getNext();
  while(ptr != NULL){
    if (ptr->getElem().index == j){
      return ptr->getElem().edge->weight;
    }
    else{
      ptr = ptr->getNext();
    }
  }
  return 0;
}

void Graph::sortEdge() {
  vector<Edge*> copy_EdgeList = EdgeList;
  vector<Edge*> sorted_list;

  double min = 0;
  int index = 0;
  int count = 0;

  while(count < EdgeList.size()){
    min = copy_EdgeList[0]->weight;
    for(int i = 0; i < copy_EdgeList.size(); ++i){
      if (copy_EdgeList[i]->weight < min){
        min = copy_EdgeList[i]->weight;
        index = i;
      }
    }
    sorted_list.push_back(copy_EdgeList[index]);
    copy_EdgeList.erase(copy_EdgeList.begin()+index);
    index = 0;
    min = 0;
    ++count;
  }

  EdgeList = sorted_list;
}

double Graph::MSTAlgo() {

  sortEdge();

  DisjointSet<int> djSet(n);
  for (int i = 0; i < n; ++i){
    djSet.MakeSet(AdjacencyList[i]->getElem().index,AdjacencyList[i]->getElem().index);
  }

  for (int i = 0; i < EdgeList.size(); ++i){
    if (djSet.FindSet(EdgeList[i]->vertex_i) != djSet.FindSet(EdgeList[i]->vertex_j)){
      // adding edges to minimum spanning tree edge list
      MST.push_back(EdgeList[i]);
      DListNode<int>* ptr = djSet.Union(*djSet.FindSet(EdgeList[i]->vertex_i),*djSet.FindSet(EdgeList[i]->vertex_j));
      // cout << ptr<<endl;
    }
  }

  double total_weight = 0;
  for (int i = 0; i < MST.size(); ++i){
    total_weight = total_weight + MST[i]->weight;
  }
  return total_weight;
}
