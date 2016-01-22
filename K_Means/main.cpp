/*
 * main.cpp
 *
 *  Created on: 11/29/2015
 *      Author: Ella Xue
 */



#include "Kmeans.h"
#include <iostream>

int main(int argc, char* argv[])
{
    string file_name;
    string file_name2;
    string file_name3;
    
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

	//step 0:K, numRow, numCol <-- get from input file
	int k, numRow, numCol,x_coordinate,y_coordinate,ClusterLabel,count = 0;
	source_f>>k;
	source_f>>numRow;
	source_f>>numCol;
	KMean *kmean = new KMean(k,numRow,numCol);
	kmean->list = new LinkedList();

	//step 1: Assign each point in the linked list to a label, from 1 to K.
	while(source_f >>x_coordinate && source_f >>y_coordinate)
	{
		ClusterLabel = ((count++ % k)+1);
		kmean->list->insert(x_coordinate,y_coordinate,ClusterLabel);
	}

	//step 6: keep computing for the min-distance of each point from K groups until no label changes
	while(kmean->isLabelChanged())
	{
		//step 2: Output the 2-D array of pixels with their labels in output-2 file.
		kmean->displayImage(output_f2);
		cout<<"-------------------------------before centroid---------------------------------------" <<endl;
		kmean->printXYcoord();
		//step 3: Go thru the entire linked list to compute the centroids of the K clusters.
		kmean->centroid();
		cout<<"after centroid=== k means will be changed to new x-y coordinates(center of each group point)====" <<endl;
		kmean->printXYcoord();
		//step 4: compute distance for each point and assign new labels if necessary
		kmean->KMeanCluster();
	}

	//step 7: output newly grouped list of points into output1.txt
	output_f1<<kmean->getK()<<"\r\n"<<kmean->getNumRow()<<" "<<kmean->getNumCol()<<"\r\n";
	kmean->list->printList(output_f1);

	source_f.close();
	output_f1.close();
	output_f2.close();

	delete kmean->list;
	return 0;
}

