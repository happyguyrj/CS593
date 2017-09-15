#include "UndirectedGraph.hpp"
#include <cstring>
#include <string>
#include <fstream>

int main(int argc, char *argv[])
{
	int num=0, total=0 ,k, numcity = 0;
	char mode[10];

	if(argc==2)
	{
		string fname=argv[1];

		//cout<<fname
		string line;
	    ifstream myfile;
	    myfile.open(fname.c_str());

	    // if(myfile.is_open())
	    // {
	        // while(!myfile.eof())
	        // {
	        //     getline(myfile,line);
	        //     //cout<< line << endl;
	        //     total++;
	        // }
	        // num = total - 3;
					// num = num/2;
	        // myfile.close();
					//
	        // myfile.open(fname.c_str());

					myfile>>mode;
					myfile>>numcity;

					std::cout << mode << endl << numcity << '\n';

					double cities[numcity][2]={0};

					for(int i=0;i<numcity;i++)
	        {
	          		myfile>>cities[i][0]>>cities[i][1];
	        }

					for (int i = 0; i < numcity; i++) {
						cout << cities[i][0] << " - " << cities[i][1] <<endl;
					}

					UndirectedGraph g(numcity);

	        for(int i=0;i<numcity;i++)
	        {
	          	for(int j=0;j<numcity;j++)
	          	{
	          	 	g.add(i,j);
	          	}
	          	//cout<<endl;
	        }
	        myfile.close();
	        cout<<g.edges();
	        cout<<endl;
	        g.print();
	        cout<<endl;
	    // }
	}

  else
  {
      printf("Enter all the arguments correctly\n");
  }
	return 0;
}
