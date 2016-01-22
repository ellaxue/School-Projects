package Radix_Sort;
import java.io.BufferedWriter;

public class HashTable {
	private int TABLE_SIZE= 10;
	protected Queue[] table;

	HashTable ()
	{
		table = new Queue[TABLE_SIZE];
	    for (int i = 0; i < TABLE_SIZE; i ++)
	    {
	        this.table[i] = new Queue();
	    }
	}
	
	void printTable(BufferedWriter buffW)
	{
		for(int i = 0; i < TABLE_SIZE;i++)
		{
			this.table[i].printQueue(buffW);
		}
	}
}
