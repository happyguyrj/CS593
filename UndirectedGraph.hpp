#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1
/*
 * A class to represent an UndirectedGraph
 * Subclasses AbstractGraph
 */
#include "lib/stack.hpp"
#include "lib/queue.hpp"

#include "lib/AdjacencyMatrix.hpp"

#include "lib/AbstractGraph.hpp"



class UndirectedGraph : AbstractGraph {

  private:AdjacencyMatrix graphm;
        char repr;
        int num_edges;

 public:
  UndirectedGraph(int vertices);
  bool edgeExists(int i, int j);
  void print();
  int edges();
  int vertices();
  void add(int i, int j);
  void remove(int i, int j);
  int degree(int i);
};

UndirectedGraph::UndirectedGraph(int vertices)
{
     graphm.resAdjacencyMatrix(vertices);
    num_edges=0;
}

  bool UndirectedGraph::edgeExists(int i, int j)
  {
    return graphm.edgeExists(i,j);
  }

  int UndirectedGraph::edges()
  {
    return num_edges;
  }

  int UndirectedGraph::vertices()
  {
    return graphm.vertices();
  }

  void UndirectedGraph::add(int i, int j)
  {
    if(!this->edgeExists(i,j)) num_edges++;
    graphm.add(i,j);
    graphm.add(j,i);
  }

  void UndirectedGraph::remove(int i, int j)
  {
    if(this->edgeExists(i,j)) num_edges--;
    graphm.remove(i,j);
    graphm.remove(j,i);
  }

  int UndirectedGraph::degree(int i)
  {
    return graphm.outdegree(i);
  }

  void UndirectedGraph::print()
  {
    graphm.print();
  }


#endif /* ifndef UNDIRECTED_GRAPH */
