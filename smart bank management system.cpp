#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int id;
    string type;
    float amount;
    Node *prev;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

// Add Transaction
void addTransaction()
{
    Node *newNode = new Node;

    cout << "\nEnter Transaction ID: ";
    cin >> newNode->id;

    cout << "Enter Type (Credit/Debit): ";
    cin >> newNode->type;

    cout << "Enter Amount: ";
    cin >> newNode->amount;

    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    cout << "Transaction Added Successfully!\n";
}

// Display Transactions
void display()
{
    Node *temp = head;

    if (head == NULL)
    {
        cout << "\nNo Transactions Found!\n";
        return;
    }

    cout << "\n--- Transaction History ---\n";

    while (temp != NULL)
    {
        cout << "ID: " << temp->id
             << " | " << temp->type
             << " | Rs." << temp->amount << endl;

        temp = temp->next;
    }
}

// Search Transaction
void searchTransaction()
{
    int id;
    cout << "\nEnter Transaction ID: ";
    cin >> id;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "\nTransaction Found!\n";
            cout << "ID: " << temp->id << endl;
            cout << "Type: " << temp->type << endl;
            cout << "Amount: Rs." << temp->amount << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Transaction Not Found!\n";
}

// Delete Transaction
void deleteTransaction()
{
    int id;
    cout << "\nEnter Transaction ID to Delete: ";
    cin >> id;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            else
                tail = temp->prev;

            delete temp;

            cout << "Transaction Deleted Successfully!\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Transaction Not Found!\n";
}

// Calculate Balance
void balance()
{
    float credit = 0, debit = 0;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->type == "Credit" || temp->type == "credit")
            credit += temp->amount;
        else if (temp->type == "Debit" || temp->type == "debit")
            debit += temp->amount;

        temp = temp->next;
    }

    cout << "\nTotal Credit: Rs." << credit << endl;
    cout << "Total Debit : Rs." << debit << endl;
    cout << "Balance     : Rs." << credit - debit << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n\n===== SMART BANK TRANSACTION HISTORY =====\n";
        cout << "1. Add Transaction\n";
        cout << "2. Display Transactions\n";
        cout << "3. Search Transaction\n";
        cout << "4. Delete Transaction\n";
        cout << "5. Check Balance\n";
        cout << "0. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addTransaction();
                break;

            case 2:
                display();
                break;

            case 3:
                searchTransaction();
                break;

            case 4:
                deleteTransaction();
                break;

            case 5:
                balance();
                break;

            case 0:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while (choice != 0);

    return 0;
}
