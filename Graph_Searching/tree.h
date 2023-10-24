#include <iostream>
#include "graph.h"
#include <vector> 
#include<queue>
using namespace std;

struct Tree {
	Node* nodes[100] = {};
	int tSize = 0;

	void addNodes(int n, Node* newNodes[]) {
		for (int i = 0; i < n; i++) {
			nodes[i] = newNodes[i];
		}
		tSize += n;
	}

	void print() {
		for (int i = 0; i < tSize; i++) {
			cout << nodes[i]->label << ", ";
		}
		cout << endl;
	}

	bool DFS(Node* current, char end, vector<Node*>& path)
	{
		Node* turnBack;
		if (current == NULL) return false;
		if (current->statusDFS != true) { path.push_back(current); current->statusDFS = true; }
		if (current->label == end) {
			return true;
		}
		for (int i = 0; i < current->conns; i++) {
			if (current->nodes[i]->statusDFS == false && DFS(current->nodes[i], end, path)) {
				return true;
			}
			else turnBack = current->nodes[i];
		}

		//path.pop_back();
		path.push_back(turnBack);
		return false;
	}

	bool BFS(Node* root, char end, vector<Node*>& path) {
		queue<pair<Node*, vector<Node*>>> q;
		q.push({ root, {} });
		root->statusBFS = true;

		while (!q.empty()) {
			Node* current = q.front().first;
			vector<Node*> currentPath = q.front().second;
			q.pop();

			if (current->label == end) {
				path = currentPath;
				path.push_back(current);
				return true;
			}

			for (int i = 0; i < current->conns; i++) {
				if (current->nodes[i]->statusBFS == false) {
					current->nodes[i]->statusBFS = true;
					vector<Node*> newPath = currentPath;
					newPath.push_back(current);
					q.push({ current->nodes[i], newPath });
				}
			}
		}

		return false;
	}

	void findPathBFS(Node* root, char end) {
		vector<Node*> path;
		if (BFS(root, end, path)) {
			cout << "Path from root: " << root->label << " to " << end << endl;
			for (size_t i = 0; i < path.size(); i++) {
				cout << path[i]->label;
				if (i < path.size() - 1) cout << " -> ";
			}
			cout << endl;
		}
		else {
			cout << "Node " << end << " not found in the tree." << endl;
		}
	}

	void findPathDFS(Node* root, char end) {
		vector<Node*> path;
		if (DFS(root, end, path) == true) {
			cout << "Path from root: " << root->label << " to " << end << endl;
			for (size_t i = 0; i < path.size(); i++) {
				cout << path[i]->label;
				if (i < path.size() - 1) cout << " -> ";
			}
			cout << endl;
		}
		else {
			cout << "Node " << end << " not found in the tree." << endl;
		}
	}



};
