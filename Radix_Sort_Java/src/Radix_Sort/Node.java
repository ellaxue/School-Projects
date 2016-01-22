package Radix_Sort;

public class Node {

	private String data;
	private Node next;
	
	Node(String data)
	{
		this.data = data;
		next = null;
	}
	
	public Node getNext()
	{
		return this.next;
	}
	public void setNext(Node newNode)
	{
		next = newNode;
	}
	
	public String getData()	
	{
		return data;
	}
}
