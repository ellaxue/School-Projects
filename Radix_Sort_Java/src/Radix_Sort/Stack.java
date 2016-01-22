package Radix_Sort;
import java.io.*;

public class Stack{
	
	private Node Top;

	Stack(){Top = null;}

	void Push(String data)
	{
		// push a node on the top of stack
		Node newNode = new Node(data);
		newNode.setNext(Top);
		Top = newNode;
	}

	Node Pop()
	{
		// pop a node from the top of stack
		Node return_top = Top;
		Top = Top.getNext();
		return return_top;
	}

	boolean isEmpty() {	return (Top == null);	}

	void printStack(BufferedWriter buffW) throws IOException
	{
		Node current = Top;
		System.out.print("Top -->");
		buffW.write("Top -->");
		while(current.getNext() != null)
		{
			if(current.getNext().getNext()!= null)
			{
				System.out.print("("+current.getData()+","+current.getNext().getData() +")-->");
				buffW.write("(" + current.getData() + "," + current.getNext().getData() +")-->");
				current = current.getNext();
			}
			else if(current.getNext().getNext() == null)
			{
				System.out.print("("+current.getData() +","+ current.getNext().getData()+")" +
						 "-->("+current.getNext().getData()+",-1)");
				buffW.write("("+current.getData() +"," +current.getNext().getData()+")"+
						"-->("+current.getNext().getData()+",-1)");
				current = current.getNext();
			}
		}
		System.out.println();
		buffW.write(" \r\n");
	}
}
