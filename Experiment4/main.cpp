//Circular Insert
class Solution {
  public:
    Node* insertInEmptyList(Node* last, int data) {
        Node* res = new Node(data);
        res->next = res;
        return res;
    }
};
//Circular delete (could not find only delete in gfg)
class Solution {
  public:
    Node* reverse(Node* head) {
        if (!head || head->next == head) return head;

        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        Node* first = head;

        do {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } while (curr != head);

        head->next = prev;
        head = prev;

        return head;
    }

    Node* deleteNode(Node* head, int key) {
        if (!head) return nullptr;

        Node* curr = head;
        Node* prev = nullptr;

        if (head->data == key) {
            if (head->next == head) {
                delete head;
                return nullptr;
            }

            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }

            last->next = head->next;
            Node* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        do {
            prev = curr;
            curr = curr->next;

            if (curr->data == key) {
                prev->next = curr->next;
                delete curr;
                return head;
            }
        } while (curr != head);

        return head;
    }
};

//Double insert
class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        Node* newNode = new Node(x);
        if (!head) return newNode;
        Node* temp = head;
        for (int i = 0; i < p && temp; i++) {
            temp = temp->next;
        }
        if (!temp) return head;
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
        return head;
    }
};

//Doubly delete
class Solution {
  public:
    Node* delPos(Node* head, int x) {
        if (!head) return nullptr;
        if (x == 1) {
            Node* temp = head;
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
            return head;
        }
        Node* curr = head;
        for (int i = 1; curr && i < x; i++) curr = curr->next;
        if (!curr) return head;
        if (curr->prev) curr->prev->next = curr->next;
        if (curr->next) curr->next->prev = curr->prev;
        delete curr;
        return head;
    }
};
