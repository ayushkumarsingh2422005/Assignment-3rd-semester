#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

struct node* linkedList(int arr[], int n) {
    struct node* head = new node{arr[0], nullptr};
    struct node* temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = new node{arr[i], nullptr};
        temp = temp->next;
    }
    // temp->next = head;
    return head;
}

struct node* insertAfter(struct node* head, int after, int data) {
    struct node* temp = head;
    while (temp->next != nullptr) {
        if (temp->data == after) {
            struct node* newNode = new node{data, nullptr};
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
            break;
        }
        temp = temp->next;
    }
    return head;
}

struct node* insertBefore(struct node* head, int before, int data) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->data == before) {
        struct node* newNode = new node{data, head};
        return newNode;
    }

    struct node* temp1 = head->next;
    struct node* temp2 = head;

    while (temp1 != nullptr) {
        if (temp1->data == before) {
            struct node* newNode = new node{data, temp1};
            temp2->next = newNode;
            return head;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }
    return head;
}

struct node* update(struct node* head, int prev, int updated) {
    struct node* temp = head;
    while (temp != nullptr) {
        if (temp->data == prev) {
            temp->data = updated;
            return head;
            break;
        }
        temp = temp->next;
    }
    return head;
}

struct node* deleteAfter(struct node* head, int after) {
    if (head == nullptr) {
        return nullptr;
    }

    struct node* temp = head;
    while (temp != nullptr && temp->next != nullptr) {
        if (temp->data == after) {
            struct node* delPtr = temp->next;
            temp->next = temp->next->next;
            delete delPtr;
            return head;
        }
        temp = temp->next;
    }

    return head;
}

struct node* deleteBefore(struct node* head, int before) {
    if (head == nullptr || head->next == nullptr ||
        head->next->next == nullptr) {
        return head;
    }

    struct node* temp1 = head->next->next;
    struct node* temp2 = head->next;
    struct node* temp3 = head;

    if (head->next->data == before) {
        struct node* toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }

    while (temp1 != nullptr) {
        if (temp1->data == before) {
            temp3->next = temp1;
            delete temp2;
            return head;
        }
        temp3 = temp2;
        temp2 = temp1;
        temp1 = temp1->next;
    }
    return head;
}

struct node* deleteFirst(struct node* head) {
    if (head == nullptr) {
        return head;
    }

    struct node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

struct node* deleteLast(struct node* head) {
    if (head == nullptr) {
        return head;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    struct node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    struct node* delNode = temp->next;
    temp->next = nullptr;
    delete delNode;
    return head;
}

struct node* deleteNthElement(struct node* head, int n) {
    if (head == nullptr) {
        return head;
    }
    if (n == 0) {
        struct node* delNode = head;
        head = head->next;
        delete delNode;
        return head;
    }
    int index = 0;
    struct node* prev = nullptr;
    struct node* temp = head;
    while (temp != nullptr) {
        if (index == n) {
            struct node* delNode = temp;
            prev->next = temp->next;
            delete delNode;
            return head;
        }
        prev = temp;
        temp = temp->next;
        index++;
    }
    return head;
}

struct node* insertBeforeFirst(struct node* head, int data) {
    struct node* temp = new node{data, nullptr};
    temp->next = head;
    return temp;
}

struct node* insertAfterLast(struct node* head, int data) {
    if (head == nullptr) {
        head = new node{data, nullptr};
        return head;
    }
    struct node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    struct node* newNode = new node{data, nullptr};
    temp->next = newNode;
    return head;
}

void printLinkedList(struct node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

struct node* concat(struct node* head1, struct node* head2) {
    struct node* head = nullptr;
    struct node* tail = nullptr;
    if (head1->data < head2->data) {
        head = tail = head1;
        head1 = head1->next;
    } else {
        head = tail = head2;
        head2 = head2->next;
    }
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data < head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    if (head1 != nullptr) {
        tail->next = head1;
    } else {
        tail->next = head2;
    }
    return head;
}

struct node* removeAlternate(struct node* head) {
    struct node* tail = head;

    while (tail != nullptr && tail->next != nullptr) {
        struct node* delNode = tail->next;  // The node to be deleted
        tail->next = delNode->next;         // Bypass the node
        delete delNode;  // Free the memory of the deleted node

        tail = tail->next;  // Move to the next node
    }
    return head;
}

struct node* removeDuplicates(struct node* head) {
    struct node* tail = head;

    while (tail->next != nullptr) {
        if (tail->data == tail->next->data) {
            struct node* delNode = tail->next;
            tail->next = delNode->next;
            delete delNode;
        }

        tail = tail->next;
    }
    return head;
}

struct node* reverseLinkedList(struct node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    struct node* newHead = nullptr;
    struct node* current = head;

    while (current != nullptr) {
        struct node* newNode = new node{current->data, nullptr};
        newNode->next = newHead;
        newHead = newNode;
        current = current->next;
    }

    return newHead;
}

bool isPalindrome(struct node* head) {
    struct node* reversed = reverseLinkedList(head);
    struct node* temp = head;
    while (reversed != nullptr) {
        if (reversed->data != temp->data) {
            return false;
        }

        reversed = reversed->next;
        temp = temp->next;
    }
    return true;
}
int lengthOfLinkedList(struct node* head, int n = 0) {
    if (head == nullptr) {
        return n;
    }
    return lengthOfLinkedList(head->next, n + 1);
}
node* middleNode(node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    node* slow = head;
    node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main() {
    int arr[] = {1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct node* head = linkedList(arr, n);
    middleNode(head);
    printLinkedList(head);

    return 0;
}
