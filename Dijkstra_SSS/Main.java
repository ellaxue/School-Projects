import java.io.*;
import java.util.*;

public class Main {
public static void main(String[] args) throws IOException {
			
	int sourceNode, N, row, col, cost;
	DijktraSSS Di;
	
	if (args.length < 4 )
	{
		System.err.println("Invalid number of arguments.");
		System.exit(1);
	}
	else
	{
		System.out.println("args[0] : " + args[0]);
		System.out.println("args[1] : " + args[1]);
		System.out.println("args[2] : " + args[2]);
		System.out.println("args[3] : " + args[3]);
	}

	//creating input and output files
	File outFile1 	  = new File(args[2]);
	File outFile2	  = new File(args[3]);
	try 
    {
        outFile1.createNewFile();
        outFile2.createNewFile();
    } 
	catch (Exception e)
    {
        e.printStackTrace();
    }
	
	Scanner inFile1   = new Scanner(new FileReader(args[0]));
	Scanner inFile2   = new Scanner(new FileReader(args[1]));
	BufferedWriter buffW1 = new BufferedWriter(new FileWriter(outFile1));
	BufferedWriter buffW2 = new BufferedWriter(new FileWriter(outFile2));
	while(inFile2.hasNext())
	{
		sourceNode = inFile2.nextInt();//beginning node of the path to each ending node 1-N
		N = inFile1.nextInt();//number of nodes
		Di = new DijktraSSS(N, sourceNode); //instantiate a new Dijktra object
		
	    try 
	    {
	        while(inFile1.hasNext())
			{
	        	//start filling in the costArray matrix
	        	row  = inFile1.nextInt();
	        	col  = inFile1.nextInt();
	        	cost = inFile1.nextInt();
	        	System.out.println("row = " + row + "col = " + col + " cost = " + cost);
	        	Di.fillMatrix(row, col, cost);
			}
	    }
	    catch (Exception e) 
	    {
	        e.printStackTrace();
	    }
	    Di.debugPrint(buffW1,buffW2);
	    Di.Dijkstras(buffW1, buffW2);
	 
	    inFile1.close();
	    inFile1   = new Scanner(new FileReader(args[0]));
	}
    buffW1.close();
    buffW2.close();
    inFile1.close();
    inFile2.close();
}
}
	


