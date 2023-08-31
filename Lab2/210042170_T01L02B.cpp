#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList
{
private:
    ListNode *head;

public:
    LinkedList() : head(nullptr) {}

    void insertFront(int key)
    {
        ListNode *newNode = new ListNode(key); // create a new node
        newNode->next = head;
        head = newNode;
    }

    void insertBack(int key)
    {
        ListNode *newNode = new ListNode(key);
        if (!head)
        {
            head = newNode;
            return;
        }

        ListNode *ptr = head;
        while (ptr->next) // while ptr->next is not null
            ptr = ptr->next;
        ptr->next = newNode;
    }

    void insertAfterNode(int key, int v)
    {
        ListNode *newNode = new ListNode(key);
        ListNode *ptr = head;

        while (ptr)
        {
            if (ptr->val == v)
            {
                newNode->next = ptr->next; // newNode->next points to the node after ptr
                ptr->next = newNode;
                return;
            }
            ptr = ptr->next;
        }

        cout << "Node with value " << v << " not found." << endl;
    }

    void updateNode(int key, int v)
    {
        ListNode *ptr = head;

        while (ptr)
        {
            if (ptr->val == v)
            {
                ptr->val = key;
                return;
            }
            ptr = ptr->next;
        }

        cout << "Node with value " << v << " not found." << endl;
    }

    void removeHead()
    {
        if (head)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void removeElement(int key)
    {
    }

    void removeEnd()
    {
    }

    void printList()
    {
        ListNode *ptr = head;
        while (ptr)
        {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    ~LinkedList()
    {
    }
};

int main()

{
    LinkedList list;
    int choice;

    do
    {
        cout << "Press 1 to insert at front" << endl;
        cout << "Press 2 to insert at back" << endl;
        cout << "Press 3 to insert after a node" << endl;
        cout << "Press 4 to update a node" << endl;
        cout << "Press 5 to remove the first node" << endl;
        cout << "Press 6 to remove a node" << endl;
        cout << "Press 7 to remove the last node" << endl;
        cout << "Press 8 to exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            int frontValue;
            cout << "Enter value to insert at front: ";
            cin >> frontValue;
            list.insertFront(frontValue);
            list.printList();
            break;

        case 2:
            int backValue;
            cout << "Enter value to insert at back: ";
            cin >> backValue;
            list.insertBack(backValue);
            list.printList();
            break;

        case 3:
            int insertValue, afterValue;
            cout << "Enter value to insert: ";
            cin >> insertValue;
            cout << "Enter value after which to insert: ";
            cin >> afterValue;
            list.insertAfterNode(insertValue, afterValue);
            list.printList();
            break;

        case 4:
            int updateValue, updateKey;
            cout << "Enter value to update to: ";
            cin >> updateValue;
            cout << "Enter value to update: ";
            cin >> updateKey;
            list.updateNode(updateValue, updateKey);
            list.printList();
            break;

        case 5:
            list.removeHead();
            list.printList();
            break;

        case 6:
            int removeValue;
            cout << "Enter value to remove: ";
            cin >> removeValue;
            list.removeElement(removeValue);
            list.printList();
            break;

        case 7:
            list.removeEnd();
            list.printList();
            break;

        case 8:
            list.printList();
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 8);

    return 0;
}