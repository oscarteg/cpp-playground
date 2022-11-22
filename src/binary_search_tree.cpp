/**
 * \file
 * \brief A simple tree implementation using structured nodes
 *
 * \todo update code to use C++ STL library features and OO structure
 * \warning This program is a poor implementation - C style - and does not
 * utilize any of the C++ STL features.
 */
#include <iostream>

struct Node {
  int val;
  Node *left;
  Node *right;
};

struct Queue {
  Node *t[100];
  int front;
  int rear;
};

Queue queue;

void enqueue(Node *n) { queue.t[queue.rear++] = n; }

Node *dequeue() { return (queue.t[queue.front++]); }

void Insert(Node *n, int x) {
  if (x < n->val) {
    if (n->left == NULL) {
      Node *temp = new Node;
      temp->val = x;
      temp->left = NULL;
      temp->right = NULL;
      n->left = temp;
    } else {
      Insert(n->left, x);
    }
  } else {
    if (n->right == NULL) {
      Node *temp = new Node;
      temp->val = x;
      temp->left = NULL;
      temp->right = NULL;
      n->right = temp;
    } else {
      Insert(n->right, x);
    }
  }
}

int findMaxInLeftST(Node *n) {
  while (n->right != NULL) {
    n = n->right;
  }
  return n->val;
}

void Remove(Node *p, Node *n, int x) {
  if (n->val == x) {
    if (n->right == NULL && n->left == NULL) {
      if (x < p->val) {
        p->right = NULL;
      } else {
        p->left = NULL;
      }
    } else if (n->right == NULL) {
      if (x < p->val) {
        p->right = n->left;
      } else {
        p->left = n->left;
      }
    } else if (n->left == NULL) {
      if (x < p->val) {
        p->right = n->right;
      } else {
        p->left = n->right;
      }
    } else {
      int y = findMaxInLeftST(n->left);
      n->val = y;
      Remove(n, n->right, y);
    }
  } else if (x < n->val) {
    Remove(n, n->left, x);
  } else {
    Remove(n, n->right, x);
  }
}

void BFT(Node *n) {
  if (n != NULL) {
    std::cout << n->val << "  ";
    enqueue(n->left);
    enqueue(n->right);
    BFT(dequeue());
  }
}

void Pre(Node *n) {
  if (n != NULL) {
    std::cout << n->val << "  ";
    Pre(n->left);
    Pre(n->right);
  }
}

void In(Node *n) {
  if (n != NULL) {
    In(n->left);
    std::cout << n->val << "  ";
    In(n->right);
  }
}

void Post(Node *n) {
  if (n != NULL) {
    Post(n->left);
    Post(n->right);
    std::cout << n->val << "  ";
  }
}

int main() {
  queue.front = 0;
  queue.rear = 0;
  int value;
  int ch;
  Node *root = new Node;
  std::cout << "\nEnter the value of root node :";
  std::cin >> value;
  root->val = value;
  root->left = NULL;
  root->right = NULL;
  do {
    std::cout << "\n1. Insert"
              << "\n2. Delete"
              << "\n3. Breadth First"
              << "\n4. Preorder Depth First"
              << "\n5. Inorder Depth First"
              << "\n6. Postorder Depth First";

    std::cout << "\nEnter Your Choice : ";
    std::cin >> ch;
    int x;
    switch (ch) {
    case 1:
      std::cout << "\nEnter the value to be Inserted : ";
      std::cin >> x;
      Insert(root, x);
      break;
    case 2:
      std::cout << "\nEnter the value to be Deleted : ";
      std::cin >> x;
      Remove(root, root, x);
      break;
    case 3:
      BFT(root);
      break;
    case 4:
      Pre(root);
      break;
    case 5:
      In(root);
      break;
    case 6:
      Post(root);
      break;
    }
  } while (ch != 0);

  return 0;
}
