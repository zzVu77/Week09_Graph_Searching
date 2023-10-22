#pragma once
#include <iostream>
using namespace std;

struct Node {
	Node* nodes[100] = {};
	int conns = 0;
	char label;
	bool status=false;

	void connect(Node* node) {
		if (isConnected(node) == true)
			return;
		nodes[conns] = node;
		conns++;
		node->connect(this);
	}

	bool isConnected(Node* node) {
		for (int i = 0; i < conns; i++) {
			if (node == nodes[i])
				return true;
		}
		return false;
	}
};

struct Graph {
	Node* nodes[100] = {};
	int gSize = 0;

	void addNodes(int n, Node* newNodes[]) {
		for (int i = 0; i < n; i++) {
			nodes[i] = newNodes[i];
		}
		gSize += n;
	}

	void print() {
		for (int i = 0; i < gSize; i++) {
			cout << nodes[i]->label << ", ";
		}
		cout << endl;
	}
};