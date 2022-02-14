https://www.acmicpc.net/problem/5639

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Node {
	public int data;
	public Node left;
	public Node right;
	
	Node(int data){
		this.data = data;
		left = null;
		right = null;
	}
}

public class B5639 {
	static Node root;
	
	static void insert(Node node, int data) {
		if (node.data > data) {	
			if (node.left != null) 
				insert(node.left, data);
			else 
				node.left = new Node(data);
		}
		else {
			if (node.right != null) 
				insert(node.right, data);	
			else 				
				node.right = new Node(data);
		}
	}

	static void postOrder(Node node) {
		if (node.left != null)
			postOrder(node.left);
		if (node.right != null)
			postOrder(node.right);
		System.out.println(node.data);
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String data;
		
		root = new Node(Integer.parseInt(br.readLine()));
		while ((data = br.readLine()) != null) {
			if (data.isEmpty())
				break;
			insert(root, Integer.parseInt(data));
		}
		
		postOrder(root);
	}
}
