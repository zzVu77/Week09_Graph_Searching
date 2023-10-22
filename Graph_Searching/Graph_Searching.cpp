#include <iostream>
#include "graph.h"
#include "tree.h"

int main()
{
	//1
	Node* a = new Node();
	a->label = 'A';

	//2
	Node* b = new Node();
	b->label = 'B';

	//3
	Node* c = new Node();
	c->label = 'C';

	//4
	Node* d = new Node();
	d->label = 'D';

	//5
	Node* e = new Node();
	e->label = 'E';

	//6
	Node* f = new Node();
	f->label = 'F';

	//7
	Node* g = new Node();
	g->label = 'G';

	//8
	Node* h = new Node();
	h->label = 'H';

	//9
	Node* I = new Node();
	I->label = 'I';

	a->connect(b);
	a->connect(c);
	b->connect(I);
	b->connect(c);
	c->connect(d);
	c->connect(e);
	e->connect(d);
	e->connect(f);
	e->connect(g);
	g->connect(h);
	I->connect(d);

	Tree* tree = new Tree();
	Node* nodes[] = { a, b, c, d, e, f, g, h, I };
	tree->findPathDFS(a, 'G');
	tree->findPathBFS(a, 'G');
	/*tree->addNodes(9, nodes);
	tree->print();*/
	//bool found = tree->dfs(a, 'G');
	//cout << found << endl;
}
// a di
