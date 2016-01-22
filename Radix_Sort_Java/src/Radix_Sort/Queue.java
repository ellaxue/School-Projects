package Radix_Sort;

import java.io.BufferedWriter;
import java.io.IOException;
	
public class Queue{
	private Node head;
	private Node tail;
	Queue()
	{
		Node newNode = new Node("-9999");
		this.head = newNode;
		this.tail = newNode;
	}

	Node getHead()
	{
		return this.head;
	}
	Node getTail()
	{
		return this.tail;
	}
	void addTail(String value)
	{
		Node newItem = new Node(value);
		if(head.getNext() == null)
		{
			head.setNext(newItem);
			tail = newItem;
		}
		else
		{
			tail.setNext(newItem);
			tail = newItem;
		}
	}

	String deleteHead()
	{
		String delString;
		Node del;

		if(head.getNext().getNext() == null)
		{
			delString = head.getNext().getData();
			head.setNext(null);
		}
		else
		{
			del = head.getNext();
			delString = del.getData();
			head.setNext(head.getNext().getNext());
			del.setNext(null);
		}
		return delString;
	}

	boolean isEmpty(){	return (head.getNext() == null);	}

	void printQueue(BufferedWriter buffW)
	{
		Node current = head;
		System.out.print("Head -->");
		try {
			buffW.write("Head -->");
			while(current.getNext() != null)
			{
				if(current.getNext().getNext()!= null)
				{
					System.out.print("("+current.getData()+","+current.getNext().getData()+ ")-->");
					buffW.write("("+current.getData()+","+current.getNext().getData()+ ")-->");
					current = current.getNext();
				}
				else if(current.getNext().getNext() == null)
				{
					System.out.print("("+current.getData()+ "," +current.getNext().getData()+")"
							+"-->("+current.getNext().getData()+",-1)");
					buffW.write("("+current.getData()+ "," +current.getNext().getData()+")"
							+"-->("+current.getNext().getData()+",-1)");
					current = current.getNext();
				}
			}
			System.out.println("\r\n");
			buffW.write("\r\n");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}
