import java.io.BufferedWriter;
import java.io.IOException;

public class DijktraSSS {
	private int N, sourceNode, minNode, currentNode, newCost;
	private int costMatrix[][];//size of N x N  
	private int fatherArray[];//size of N
	private int markedArray[];//size of N
	private int bestCostArray[];//size of N
	private int printCount = 0;
	private int k = 1;
	
	public DijktraSSS(int n, int source)
	{
		N = n + 1;//Skip the zero index in the array
		sourceNode  = source;
		minNode     = 0;
		currentNode = 0;
		newCost		= 0;
		costMatrix    = new int[N][N];
		fatherArray	  = new int[N];
		markedArray   = new int[N];
		bestCostArray = new int[N];
		
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				if (i == j) costMatrix[i][j] = 0;
				else costMatrix[i][j] = 999999;
			}
			fatherArray[i]   = i;
			markedArray[i]   = 0;
			bestCostArray[i] = 999999;
		}
		bestCostArray[sourceNode] = 0;
	}
	public void fillMatrix(int row, int col, int cost)
	{
		costMatrix[row][col] = cost;
	}
	public void expandNode(BufferedWriter output1, BufferedWriter output2) throws IOException
	{
		//expand the min_node to all unmarked nodes, and compute each node's cost 
		for(int i = 1; i < N; i++)
		{
			if(markedArray[i] == 0)
			{
				currentNode = i;
				newCost = computeCost(minNode, currentNode);
				if(newCost < bestCostArray[currentNode])
				{
					updateFatherArray(currentNode,minNode);
					updateBestCostArray(currentNode,newCost);
				}
			}
		}
	}
	public int findBestCostToBeNewMinNode(BufferedWriter output1, BufferedWriter output2) throws IOException
	{
		int min = 9999999;
		int min_node = 0;
		int count = 0;
		output2.write("find best cost to be the new min node\r\n");
		
		while(++count < N )
		{//find the currently unmarked node to be the new min_node
			if(markedArray[count] == 0 && bestCostArray[count] < min)
			{//pick the bestCost among unmarked nodes, and update it as min_node
				min = bestCostArray[count];
				min_node = count;
			}
		}
		output2.write("Current min_node: " + min_node + " \r\n");
		return min_node;
	}
	public void Dijkstras(BufferedWriter output1, BufferedWriter output2) throws IOException
	{
		//keep expanding the unmarked nodes from current min_node, until all nodes are marked
		while(!isAllNodesMarked())
		{
			minNode = findBestCostToBeNewMinNode(output1,output2);
			updateMarkedArray(minNode);
			expandNode(output1,output2);
			debugPrint(output1,output2);
		}

		output1.write("--------------------------------------------------------\r\n");
		output1.write("<<<The graph has " + (N -1) + " nodes, the source node is " + sourceNode +">>>\r\n") ;
		output1.write("--------------------------------------------------------\r\n");
		while(k < N)
		{
			output1.write("The path from " + sourceNode  + " to " + k + ": ");
			findNprintShortestPath(k, output1, output2);
			output1.write(": cost = " + bestCostArray[k]+ "\r\n");
			k++;
		}
		output1.write("--------------------------------------------------------\r\n");
		output1.write("End of <<<Path from Source Node to each 1 - K nodes>>>\r\n");
		output1.write("--------------------------------------------------------\r\n");
		
	}
	public void findNprintShortestPath(int k,BufferedWriter output1, BufferedWriter output2) throws IOException
	{//base case, when reach the sourceNode, print it
		if(fatherArray[k] == k)
		{
			output1.write(fatherArray[k] + " --> " + k+"");
			return;
		}
		if(fatherArray[k] == sourceNode) 
		{
			output1.write(fatherArray[k] + " --> " + k+"");
			return;
		}//otherwise, continue finding the sourceNode in the father array
		else findNprintShortestPath(fatherArray[k],output1,output2);
		output1.write(" --> " + k);
	}
	boolean isAllNodesMarked()
	{
		int count = 0;
		while(++count < N)
		{
			if(markedArray[count] == 0){return false;}
		}
		return true;
	}
	public int computeCost(int minNode, int currentNode)
	{
		return bestCostArray[minNode]+costMatrix[minNode][currentNode];
	}

	public void updateMarkedArray(int min_node)
	{
		markedArray[min_node] = 1;
	}
	public void updateFatherArray(int curNode,int min_Node)
	{
		fatherArray[curNode] = min_Node;
		
	}
	public void updateBestCostArray(int cur_node, int new_cost)
	{
		bestCostArray[cur_node] = new_cost;
	}
	public void print(String msg)
	{
		System.out.print(msg);
	}
	public void debugPrint(BufferedWriter output1, BufferedWriter output2) throws IOException
	{	
		
		if(printCount++ == 0)
		{
			output2.write("N = " + (N - 1) + "\r\n-----------<<<The best cost maxtrix:>>>--------------\r\n ");
			for(int i = 0; i < N; i++)
			{
				for(int j = 0; j < N; j++)
				{
					try {output2.write(costMatrix[i][j]+" ");}
					catch (IOException e) {e.printStackTrace();}
					print(costMatrix[i][j]+" ");
				}
				output2.write("\r\n");
				print("\n");
			}
		}	
		output2.write("*********************\r\nEnd of <<<best cost matrix>>>\r\n--------------------\r\n");
		
		output2.write("*********************\r\nCurrent fatherArray:\r\n--------------------\r\n");
		for(int i = 1; i < N; i++)
		{
			output2.write("Node " + i + " current father: " + fatherArray[i]+" \r\n");
		}
		output2.write("*********************\r\nEnd of fatherArray:\r\n--------------------\r\n");
		
		output2.write("*********************\r\nCurrent BestCostArray:\r\n--------------------\r\n");
		for(int i = 1; i < N; i++)
		{
			output2.write("Node " + i + " current best cost: " + bestCostArray[i]+" \r\n");
		}
		output2.write("*********************\r\nEnd of BestCostArray\r\n--------------------\r\n");
		
		output2.write("*********************\r\nCurrent MarkedArray:\r\n--------------------\r\n");
		for(int i = 1; i < N; i++)
		{
			output2.write("Node " + i + " current mark: " + markedArray[i]+" \r\n");
		}
		output2.write("*********************\r\nEnd of markedArray\r\n--------------------\r\n");
	}

	
}
