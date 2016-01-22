/*
 * main.cpp
 *
 *  Created on: Nov 29, 2015
 *      Author: Ella
 */

#include "PrimMST.h"

int main(int argc, char* argv[])
{
    string file_name;
    string file_name2;
    string file_name3;
    PrimMST *MST;
    int N, Ni, Nj,cost;
    int total_cost = 0;
   
    int no_forever_loop_count = 0;

    if (argc < 3)
    {
      std::cout << "usage : " << argv[0] << " <input file>  <output file> <output file>\n";
      return -1;
    }
    else
    {
        file_name = argv[1];
        file_name2=argv[2];
        file_name3=argv[3];
    }

    ifstream source_f(file_name.c_str(),ios::in|ios::binary);
    ofstream output_f1(file_name2.c_str(),ios::out|ios::binary);
    ofstream output_f2(file_name3.c_str(),ios::out|ios::binary);

    if (!source_f || !output_f1 || !output_f2)
    {
        cout << "Error: unable to open file!" << endl;
        return -1;
    }

	// step 0
	// read N
	source_f>>N;//N = number of nodes
	// initialize PrimMst class
	MST = new PrimMST(N);

	//step 1 - 2: read in data from input file, and insert into edgeList
	
	while(source_f >>Ni && source_f >>Nj && source_f >>cost)
	{
		MST->insertEdge(Ni, Nj, cost);
		MST->stepNodeIDArray(Ni);
		MST->stepNodeIDArray(Nj);
	} // step 2, repeat until the input file is empty
	
	cout << "Reading complete" << endl;

	//Step3: print graphNodeIDarray and edgeList to output-2 file
	MST->printGraphNodeIDarray(output_f2);
	MST->printEdgeNode(output_f2);
	
	// step 4 - 10
	total_cost = MST->PrimsMST();

	MST->printMSTofG(output_f1);
	cout << "Complete" << endl;
	output_f1 << "Complete" << endl;
	cout << "Total cost = " << total_cost << endl;
	output_f1 << "Total cost = " << total_cost << endl;

    source_f.close();
    output_f1.close();
    output_f2.close();
	return 0;
}
