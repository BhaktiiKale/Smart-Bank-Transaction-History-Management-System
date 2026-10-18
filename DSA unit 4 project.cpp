#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    int id, height;
    string name;
    Node *left, *right;

    Node(int i, string n) {
        id = i;
        name = n;
        height = 1;
        left = right = NULL;
    }
};

int h(Node *n) {
    return n ? n->height : 0;
}

void show(Node *n, string space = "") {
    if (!n) return;

    cout << space << n->id << " (" << n->name << ")\n";
    show(n->left, space + "L-- ");
    show(n->right, space + "R-- ");
}

Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *t = x->right;

    x->right = y;
    y->left = t;

    y->height = 1 + max(h(y->left), h(y->right));
    x->height = 1 + max(h(x->left), h(x->right));

    return x;
}

Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *t = y->left;

    y->left = x;
    x->right = t;

    x->height = 1 + max(h(x->left), h(x->right));
    y->height = 1 + max(h(y->left), h(y->right));

    return y;
}

Node* insert(Node *root, int id, string name) {
    if (!root)
        return new Node(id, name);

    if (id < root->id)
        root->left = insert(root->left, id, name);
    else if (id > root->id)
        root->right = insert(root->right, id, name);
    else {
        cout << "Ticket ID already exists!\n";
        return root;
    }

    root->height = 1 + max(h(root->left), h(root->right));
    int b = h(root->left) - h(root->right);

    // LR Rotation
    if (b > 1 && id > root->left->id) {
        cout << "\nLR ROTATION - BEFORE:\n";
        show(root);

        root->left = leftRotate(root->left);
        cout << "\nAfter Left Rotation:\n";
        show(root);

        root = rightRotate(root);
        cout << "\nAfter Right Rotation:\n";
        show(root);
    }

    // RL Rotation
    else if (b < -1 && id < root->right->id) {
        cout << "\nRL ROTATION - BEFORE:\n";
        show(root);

        root->right = rightRotate(root->right);
        cout << "\nAfter Right Rotation:\n";
        show(root);

        root = leftRotate(root);
        cout << "\nAfter Left Rotation:\n";
        show(root);
    }

    else if (b > 1)
        return rightRotate(root);
    else if (b < -1)
        return leftRotate(root);

    return root;
}

int main() {
    Node *root = NULL;
    int choice, id;
    string name;

    do {
        cout << "\n========================================\n";
        cout << "   FLIGHT TICKET MANAGEMENT SYSTEM\n";
        cout << "             USING AVL TREE\n";
        cout << "========================================\n";

        cout << "1. Book Ticket\n";
        cout << "2. Display Tickets\n";
        cout << "3. Demonstrate LR and RL Rotations\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1) {
            cout << "Enter Ticket ID: ";
            if (!(cin >> id)) {
                cout << "Invalid Ticket ID!\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            cout << "Enter Passenger Name: ";
            cin >> name;

            root = insert(root, id, name);
        }
        else if (choice == 2) {
            cout << "\nBOOKED FLIGHT TICKETS:\n";
            if (root == NULL)
                cout << "No tickets booked yet.\n";
            else
                show(root);
        }
        else if (choice == 3) {
            cout << "\n========== LR ROTATION DEMO ==========\n";
            Node *demo = NULL;
            demo = insert(demo, 30, "Amit");
            demo = insert(demo, 10, "Ravi");
            demo = insert(demo, 20, "Neha");

            cout << "\nFinal LR Tree:\n";
            show(demo);

            cout << "\n========== RL ROTATION DEMO ==========\n";
            demo = NULL;
            demo = insert(demo, 10, "Amit");
            demo = insert(demo, 30, "Ravi");
            demo = insert(demo, 20, "Neha");

            cout << "\nFinal RL Tree:\n";
            show(demo);
        }
        else if (choice == 4) {
            cout << "Thank you for using the system!\n";
        }
        else {
            cout << "Please enter choice from 1 to 4.\n";
        }

    } while (choice != 4);

    return 0;
}
