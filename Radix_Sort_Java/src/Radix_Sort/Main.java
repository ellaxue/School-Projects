package Radix_Sort;
import java.io.*;
import java.util.*;

public class Main {
public static void main(String[] args) throws IOException {
		
	if (args.length < 3)
	{
		System.err.println("Invalid number of arguments.");
		System.exit(1);
	}
	System.out.println("args[0] : " + args[0]);
	System.out.println("args[1] : " + args[1]);
	
	//creating output file
	File outFile = new File(args[1]);
	try 
    {
        outFile.createNewFile();
    } 
	catch (Exception e)
    {
        e.printStackTrace();
    }
	int max_value = 0;
	Stack stack = new Stack();
	
	FileWriter fileW = new FileWriter(outFile);
	Scanner inFile = new Scanner(new FileReader(args[0]));
	BufferedWriter buffW = new BufferedWriter(fileW);
	
    try 
    {
        while(inFile.hasNext())
		{
        	//start reading data from the input file
			int value = inFile.nextInt();
			max_value = findMax(value);
			stack.Push(Integer.toString(value));
		}
        stack.printStack(buffW);
    }
    catch (Exception e) 
    {
        e.printStackTrace();
    }
	
    String value;
    RadixSort radixSort = new RadixSort(totalDigit(max_value));
	while(!stack.isEmpty())
	{
		value = stack.Pop().getData();
		System.out.println("pop out stack " +value);
		radixSort.addItemToHashTable(value,buffW);
	}
	
	
	//step 3: print current table
	System.out.println("=============================current table:====================================" );
	buffW.write("==============================current table:====================================\r\n\r\n" );
	radixSort.printTable(radixSort.getCurrentTable(),buffW);
	radixSort.swapTable();
	
	//step 5.0: print previous table
	System.out.println("=============================previous table:===================================" );
	buffW.write("==============================previous table:===================================\r\n\r\n" );
	radixSort.printTable(radixSort.getPreviousTable(),buffW);
	
	//Step 5: copy data from hashTable[0] to hahsTable[1]
	while(radixSort.getCurrentDigit() < radixSort.getTotalDigit())
	{
	radixSort.copyDataToNextTable(buffW);
	radixSort.swapTable();
	}
	//step 8: print the final table
	System.out.println("=============================Final table:====================================");
	buffW.write("==============================Final table:====================================\r\n\r\n" );
	radixSort.swapTable();
	radixSort.printTable(radixSort.getCurrentTable(),buffW);
	System.out.println("=============================================================================" );
	buffW.write("==============================================================================\r\n\r\n" );

	buffW.close();
    inFile.close();
}
	
static int findMax(int value)
{
	int max = 0;
	if(max < value)
	{
		//compare with the new value, return the new max value
		max = value;
		return max;
	}
	return max;
}
static int totalDigit(int num)
{
	 int totalDigit = 0;
	 do
	 {
		 num = num / 10;
		 totalDigit++;
	 }
	 while(num != 0);

	 return totalDigit;
}
}
