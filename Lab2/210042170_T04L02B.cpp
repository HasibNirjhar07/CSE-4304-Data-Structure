#include <iostream>
using namespace std;

class Node
{
public:
    string value;
    Node *next;

    Node(string val) : value(val), next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    int length;

    LinkedList() : head(nullptr), tail(nullptr), length(0) {}

    void print_list()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void insert_back(string value)
    {
        Node *new_node = new Node(value);
        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
        length++;
    }

    void remove_duplicates()
    {
        if (head == nullptr)
        {
            return;
        }

        Node *current = head;

        while (current->next != nullptr)
        {
            if (current->value == current->next->value)
            {
                Node *temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            else
            {
                current = current->next;
            }
        }
    }
};

int main()
{
    LinkedList mLinkedList;

    while (true)
    {
        string value;
        cout << "Enter a value (-1 to Stop): ";
        cin >> value;
        if (value == "-1")
        {
            break;
        }
        mLinkedList.insert_back(value);
    }

    mLinkedList.remove_duplicates();
    cout << "Linked list with duplicates removed:" << endl;
    mLinkedList.print_list();

    return 0;
}
