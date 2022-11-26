#include <iostream>

using namespace std;

struct Node {
    int cnt = 1;
    int value;
    Node *next;
};

struct List {
    Node *head;
};

void list_print(List L);

bool find_node(List L, int item);

void CreateNewElement(List &l, int item);

void merge(List &list3, List list1, List list2);

void init(List &List1);

void clear_list(List &l);

void delete_node(List &l, int item);


void merge(List &list3, List list1, List list2) {
    Node *currList1 = list1.head;
    Node *currList2 = list2.head;
    Node *currList3 = list3.head;
    if (list2.head == nullptr && list1.head == nullptr) {
    } else if (list2.head == nullptr) {
        list3.head = list1.head;
    } else if (list1.head == nullptr) {
        list3.head = list2.head;
    } else {
        do {
            Node *node = new Node;
            if (list1.head->next == list1.head && list2.head->next == list2.head) {
                currList1 = list1.head;
                currList2 = list2.head;
            } else if (list1.head->next == list1.head) {
                list3.head = list1.head;
                currList1 = list1.head;
                currList2 = list2.head;
            } else if (list2.head->next == list2.head) {
                list3.head = list2.head;
                currList1 = list1.head;
                currList2 = list2.head;
            }
            if (currList1->value < currList2->value) {
                node->value = currList1->value;
                node->cnt = currList1->cnt;
                currList1 = currList1->next;
            } else if (currList1->value == currList2->value) {
                node->value = currList1->value;
                node->cnt = currList1->cnt + currList2->cnt;
                currList1 = currList1->next;
                currList2 = currList2->next;
            } else if (currList1->value > currList2->value) {
                node->value = currList2->value;
                node->cnt = currList2->cnt;
                currList2 = currList2->next;
            }

            if (currList1 != list1.head && currList2 == list2.head && currList3 == currList2) {
                node->value = currList1->value;
                node->cnt = currList1->cnt;
                currList1 = currList1->next;
                cout << "'" << node->value << "'";
            } else if (currList1 == list1.head && currList2 != list2.head && currList3 == currList1) {
                node->value = currList2->value;
                node->cnt = currList2->cnt;
                currList2 = currList2->next;
            }

            if (list3.head == nullptr) {
                list3.head = new Node;
                list3.head->value = node->value;
                list3.head->cnt = node->cnt;
                list3.head->next = list3.head;
                currList3 = list3.head;
            } else {
                currList3->next = new Node;
                currList3 = currList3->next;
                currList3->value = node->value;
                currList3->cnt = node->cnt;
                currList3->next = list3.head;
            }

        } while ((currList2 != list2.head) && (currList1 != list1.head));
    }

}

bool find_node(List L, int item) {
    Node *curr = L.head;
    do {
        if (curr->value == item) {
            return true;
        }
        curr = curr->next;
    } while (curr != L.head);
    return false;
}

void CreateNewElement(List &l, int item) {
    Node *node = new Node;
    node->value = item;

    if (l.head == nullptr) {
        l.head = node;
        l.head->next = l.head;
    } else {
        Node *curr = l.head;
        do {
            if (curr->value == item) {
                curr->cnt++;
                curr = l.head;
            } else if (curr == curr->next) {
                if (curr->value <= item) {
                    node->next = l.head;
                    curr->next = node;
                } else {
                    node->next = curr;
                    curr->next = node;
                    l.head = node;
                }
                curr = l.head;
            } else if (curr->value >= item) {

                node->value = curr->value;
                node->next = curr->next;
                curr->value = item;
                curr->next = node;
                curr = l.head;

            } else if (curr->next == l.head) {
                curr->next = node;
                node->next = l.head;
                curr = l.head;
            } else {
                curr = curr->next;
            }
        } while (curr != l.head);


    }


}


void clear_list(List &l) {
    if (l.head == nullptr) {
        cout << "список уже пуст";
    } else {
        Node *node = l.head;
        while (node) {
            l.head = node->next;
            delete (node);
            node = l.head;
        }
    }
}

void delete_node(List &l, int item) {

    Node *curr = l.head;
    Node *currNext = curr->next;
    do {
        if (l.head->cnt > 1 && l.head->value == item) {
            l.head->cnt--;
        } else if (curr->next->cnt >= 2 && curr->next->value == item) {
            curr->next->cnt--;
            curr = l.head;
        } else if (curr == l.head && curr->value == item) {
            Node *tail = l.head;
            while (tail->next != l.head) {
                tail = tail->next;
            }
            Node *buff = l.head->next;
            delete curr;
            l.head = buff;
            tail->next = buff;

            curr = l.head;
        } else if (currNext->value == item && currNext != l.head) {
            curr->next = curr->next->next;
            delete currNext;
        } else {
            curr = curr->next;
            currNext = curr->next;
        }

    } while (curr != l.head);

}

void list_print(List L) {
    Node *curr = L.head;
    do {
        cout << curr->value << "(" << curr->cnt << ")" << " ";
        curr = curr->next;
    } while (curr != L.head && L.head != nullptr);
    cout << "\n";
}

void init(List &List1) {
    List1.head = nullptr;
}

int main() {
    List list1;
    init(list1);

    List list2;
    init(list2);

    List list3;
    init(list3);

    CreateNewElement(list1, 12);
    CreateNewElement(list1, 1);
    CreateNewElement(list1, 10);
    CreateNewElement(list1, 30);
    CreateNewElement(list1, 30);
    list_print(list1);
    
    merge(list3, list1, list2);
    list_print(list3);

    find_node(list1, 101) ? cout << "Элемент найден" : cout << "Элемент не найден<<"\n";
    return 0;
}
