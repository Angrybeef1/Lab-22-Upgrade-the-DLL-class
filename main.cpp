//comsc 210 | Lab22 Upgrade the DLL class | Robert Stonemetz

#include <iostream>

using namespace std;

//const to generate numbers
const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    //node for Doubly linked list
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    //pointer to the first node (head) and last node (tail)
    Node* head; 
    Node* tail;

public:
    // constructor to create an empty list
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    // Add a new node to the end of the list
    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Add a new node to the beginning of the list
    void push_front(int value) {
        Node* newNode = new Node(value);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert a new node after the specified position
    void insert_after(int value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // Inserting at the end
        temp->next = newNode;
    }

    // Delete the first occurrence of a node with the specified value
    void delete_val(int value) {
        if (!head) return; // Empty list

        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; // Value not found

        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Deleting the head
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev; // Deleting the tail
        }

        delete temp;
    }

    // Delete the node at the specified position
    void delete_pos(int position) {
        if (!head || position < 0){
            cout << "invalid position or empty list." << endl;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; i++) {
            temp=temp->next;
        }

        if (!temp) {
            cout << "Position exceeds list size." << endl;
            return;
        }
        
        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Deleting the head
        }
        
        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev; // Deleting the tail
        }
        
        delete temp;
    }

    // Remove the first node (head) of the list
    void pop_front() {
        if (!head) {
            cout << "List is empty. Cannot pop front." << endl;
            return;
        }
        
        Node* temp = head;
        head = head->next;
        
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr; // List is now empty
        }
        
        delete temp;
    }

    // Remove the last node (tail) of the list
    void pop_back() {
        if (!tail) {
            cout << "List is empty. Cannot pop back." << endl;
            return;
        }
        
        Node* temp = tail;
        tail = tail->prev;
        
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr; // List is now empty
        }
        
        delete temp;
    }
    
    // Print the list from head to tail
    void print() {
        Node* current = head;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Print the list from tail to head
    void print_reverse() {
        Node* current = tail;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    // Destructor: clean up all nodes
    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    DoublyLinkedList list;
    int size = rand() % (MAX_LS-MIN_LS+1) + MIN_LS;

    for (int i = 0; i < size; ++i)
        list.push_back(rand() % (MAX_NR-MIN_NR+1) + MIN_NR);
    cout << "List forward: ";
    list.print();

    cout << "List backward: ";
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}
