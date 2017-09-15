#include <iostream>
using namespace std;
#include "GraphAdjacencyBase.hpp"

#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1


#include "seqLinearList.hpp"

class AdjacencyMatrix : public GraphAdjacencyBase {

private:
	LinearList<LinearList<int> > AdMatrix;
	double v;
	double e;
public:

   AdjacencyMatrix()
   {
   	v=0;
   	e=0;
   }

   void resAdjacencyMatrix(int V);

  ~AdjacencyMatrix();

  bool edgeExists(int i, int j);

  double vertices();

  double edges();

  void add(int i, int j);

  void remove(int i, int j);

  int indegree(int i);

  int outdegree(int i);

  void print();
};

  void AdjacencyMatrix::resAdjacencyMatrix(int V)
  {
  	AdMatrix.resize(V);

  	for(int i=0;i<V;i++)
  		{
        AdMatrix[i].resize(V);
        AdMatrix[i].fill(0);
      }
  	v=V;
  	e=0;
  }

  AdjacencyMatrix::~AdjacencyMatrix()
  {

  }

  bool AdjacencyMatrix::edgeExists(int i, int j)
  {
  	if(AdMatrix[i][j]==1)
  		return true;

  	else
  		return false;
  }

  double AdjacencyMatrix::vertices()
  {
  	return v;
  }

  double AdjacencyMatrix::edges()
  {
  	return e;
  }

  void AdjacencyMatrix::add(int i, int j)
  {
    if(!(this->edgeExists(i,j)))
    {
  	AdMatrix[i][j]=1;
  	e++;
    }
  }

  void AdjacencyMatrix::remove(int i, int j)
  {
    if(this->edgeExists(i,j))
    {
    AdMatrix[i][j]=0;
    e--;
    }
  }

  int AdjacencyMatrix::outdegree(int i)
  {
  	int c=0;
  	for(int j=0;j<v;j++)
  	{
  		if(edgeExists(i,j)) c++;
  	}
  	return c;

  }

   int AdjacencyMatrix::indegree(int i)
  {
  	int c=0;
  	for(int j=0;j<v;j++)
  	{
  		if(edgeExists(j,i)) c++;
  	}
  	return c;

  }

    void AdjacencyMatrix::print()
  {
    for(int i=0;i<v;i++)
    	{
    		for(int j=0;j<v;j++)
    			cout<<AdMatrix[i][j]<<" ";
    		cout<<endl;
    	}
  }


#endif /* ifndef ADJACENCY_MATRIX */
