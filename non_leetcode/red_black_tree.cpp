#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data) : data(data) {
        parent = left = right = nullptr;
        color = RED;
    }
};

class RedBlackTree {
private:
    Node *root;

    void rotateLeft(Node *&);
    void rotateRight(Node *&);
    void fixInsert(Node *&);
    void fixDelete(Node *&);
    void transplant(Node *&, Node *&);
    Node* minimum(Node *);
    void deleteNode(Node *);

public:
    RedBlackTree() { root = nullptr; }
    void insert(int);
    void remove(int);
    void inorder(Node *);
    Node* getRoot() { return root; }
};

void RedBlackTree::rotateLeft(Node *&x) {
    Node *y = x->right;
    x->right = y->left;
    if (y->left) y->left->parent = x;
    y->parent = x->parent;
    if (!x->parent)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void RedBlackTree::rotateRight(Node *&x) {
    Node *y = x->left;
    x->left = y->right;
    if (y->right) y->right->parent = x;
    y->parent = x->parent;
    if (!x->parent)
        root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;
    y->right = x;
    x->parent = y;
}

void RedBlackTree::fixInsert(Node *&k) {
    Node *parent = nullptr, *grandparent = nullptr;
    while (k != root && k->color == RED && k->parent->color == RED) {
        parent = k->parent;
        grandparent = parent->parent;
        if (parent == grandparent->left) {
            Node *uncle = grandparent->right;
            if (uncle && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                k = grandparent;
            } else {
                if (k == parent->right) {
                    rotateLeft(parent);
                    k = parent;
                    parent = k->parent;
                }
                rotateRight(grandparent);
                swap(parent->color, grandparent->color);
                k = parent;
            }
        } else {
            Node *uncle = grandparent->left;
            if (uncle && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                k = grandparent;
            } else {
                if (k == parent->left) {
                    rotateRight(parent);
                    k = parent;
                    parent = k->parent;
                }
                rotateLeft(grandparent);
                swap(parent->color, grandparent->color);
                k = parent;
            }
        }
    }
    root->color = BLACK;
}

void RedBlackTree::insert(int data) {
    Node *newNode = new Node(data);
    Node *y = nullptr;
    Node *x = root;
    while (x) {
        y = x;
        if (newNode->data < x->data)
            x = x->left;
        else
            x = x->right;
    }
    newNode->parent = y;
    if (!y)
        root = newNode;
    else if (newNode->data < y->data)
        y->left = newNode;
    else
        y->right = newNode;
    fixInsert(newNode);
}

void RedBlackTree::inorder(Node *node) {
    if (!node) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main() {
    RedBlackTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);
    cout << "Inorder traversal: ";
    tree.inorder(tree.getRoot());
    cout << endl;
    return 0;
}