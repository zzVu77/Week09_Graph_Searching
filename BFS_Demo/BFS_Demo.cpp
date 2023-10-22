#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#pragma once
#include <iostream>
using namespace std;

struct Node {
    Node* nodes[100] = {};
    int conns = 0;
    char label;
    bool status = false;

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

    bool BFS(Node* root, char end, vector<Node*>& path) {
        queue<pair<Node*, vector<Node*>>> q;
        q.push({ root, {} });

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
                if (current->nodes[i]->status == false) {
                    current->nodes[i]->status = true;
                    vector<Node*> newPath = currentPath;
                    newPath.push_back(current);
                    q.push({ current->nodes[i], newPath });
                }
            }
        }

        return false;
    }

    void findPath(Node* root, char end) {
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
};
