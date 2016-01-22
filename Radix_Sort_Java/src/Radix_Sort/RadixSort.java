package Radix_Sort;

import java.io.BufferedWriter;

public class RadixSort{
	private int totalDigit;
	private int index;
	private	int currentDigit;
	private int currentTable;
	private int previousTable;
	private int currentQueue;
	private static int TABLE_SIZE = 10;
	private HashTable[] hashTable;
	
	RadixSort(int totalDigit)
	{
		this.hashTable = new HashTable[2];
		hashTable[0] = new HashTable();
		hashTable[1] = new HashTable();
		this.index = 0;
		this.totalDigit = totalDigit;
		this.currentDigit = 0;
		this.currentTable = 0;
		this.previousTable = 1;
		this.currentQueue = 0;
	}

	private int Hash(String value)
	{
		int size = value.length();
		int dig  = 0;
		char digit;
		String index;
		if(size > currentDigit)
		{
			digit = value.charAt((size - 1) - currentDigit);
			index = Character.toString(digit);
			dig = Integer.parseInt(index);
			return dig;
		}
		return 0;
	}

	void printTable(int tableIndex, BufferedWriter buffW)
	{
		hashTable[tableIndex].printTable(buffW);
	}

	void copyDataToNextTable(BufferedWriter buffW)
	{
		String value;
		Queue queue;
		while(currentQueue < TABLE_SIZE)
		{
			queue = hashTable[previousTable].table[currentQueue++];
			if(!queue.isEmpty())
			{
				while(queue.getHead().getNext() != null)
				{
					value = queue.deleteHead();
					//step 5.4: call addTail to add the node at the tail of the queue
					addItemToHashTable(value,buffW);
				}
			}
		}
	}

	void addItemToHashTable(String value,BufferedWriter buffW)
	{
		index = Hash(value);
		hashTable[currentTable].table[index].addTail(value);
	}

	void swapTable()
	{
		int temp = this.currentTable;
		this.currentTable = previousTable;
		this.previousTable = temp;
		this.currentQueue = 0;
		this.currentDigit++;
	}

	int getCurrentDigit(){return currentDigit;}

	int getCurrentTable(){return currentTable;}

	int getPreviousTable(){return previousTable;}

	int getTotalDigit(){return totalDigit;}

}
