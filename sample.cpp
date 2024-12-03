#include <bits/stdc++.h>
using namespace std;

struct Node {
    int num;
    Node* next;
};

Node* insertAtEnd(Node* head, int num) {
    Node* newNode = new Node();
    newNode->num = num;
    newNode->next = nullptr;

    if (head == nullptr) {
        return newNode;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

int searchList(Node* head, int target) {
    int pos = 1;
    while (head != nullptr) {
        if (head->num == target) {
            return pos;
        }
        head = head->next;
        pos++;
    }
    return -1;  // Return -1 if not found
}

Node* SortedLinkedList(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;
    
    do {
        swapped = true;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->num > ptr1->next->num) {
                swap(ptr1->num, ptr1->next->num);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
    } while (swapped);
    
    return head;
}

Node* deleteLinkedElement(Node* head, int target) {
    if (head == nullptr) {
        cout << "Linked List is empty\n";
        return head;
    }

    if (head->num == target) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Element " << target << " deleted successfully\n";
        return head;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->num != target) {
        current = current->next;
    }

    if (current->next == nullptr) {
        cout << target << " not found\n";
    } else {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        cout << target << " deleted successfully!!\n";
    }

    return head;
}

void printList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    while (head != nullptr) {
        cout << head->num << "->";
        head = head->next;
    }
    cout << "NULL\n";
}

// Function to count the number of even elements in the list
int countEven(Node* head) {
    int evenCount = 0;
    while (head != nullptr) {
        if (head->num % 2 == 0) {
            evenCount++;
        }
        head = head->next;
    }
    return evenCount;
}

int main() {
    Node* head = nullptr;
    int n, num;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> num;
        head = insertAtEnd(head, num);
    }

    cout << "Initial List: ";
    printList(head);

    // Count and print the number of even elements
    int evenCount = countEven(head);
    cout << "Number of even elements in the list: " << evenCount << endl;

    int target;
    cout << "Enter element to search: ";
    cin >> target;
    
    int position = searchList(head, target);
    if (position == -1) {
        cout << target << " not found in the list.\n";
    } else {
        cout << "Element " << target << " found at position " << position << ".\n";
    }

    cout << "Enter element to delete: ";
    cin >> target;

    head = deleteLinkedElement(head, target);

    cout << "Updated List: ";
    printList(head);

    return 0;
}
