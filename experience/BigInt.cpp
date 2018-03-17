//
// Created by bunguang on 2018/3/7.
//
#include <iostream>
#include <cstring>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class BunList {

public:

    Node *head;

    BunList(int val) {
        head = new Node(val);
    }

    BunList(Node *val) {
        head = val;
    }

    void reverse_print() {
        reverse_print_re(head->next);
        cout << endl;
    }

    void reverse_print_re(Node *head) {
        if (head != NULL) {
            reverse_print_re(head->next);
            cout << head->data;
        }
    }

    void direct_print() {
        Node *tmp = head->next;
        while (tmp != NULL) {
            cout << tmp->data;
            tmp = tmp->next;
        }
        cout << endl;
    }

    void direct_insert() {
        int data_size = 0;
        cin >> data_size;
        for (int i = 0; i < data_size; i++) {
            int tmp;
            cin >> tmp;
            Node *tmp_node = new Node(tmp);
            Node *tail = head;
            while (tail->next != NULL) tail = tail->next;
            tail->next = tmp_node;
        }
    }

    void reverse_insert() {
        int data_size = 0;
        cin >> data_size;
        for (int i = 0; i < data_size; i++) {
            int tmp;
            cin >> tmp;
            Node *tmp_node = new Node(tmp);
            Node *ptr = head->next;
            head->next = tmp_node;
            tmp_node->next = ptr;
        }
    }

    void reverse_insert(char *strint) {
        int index = 0;
        char tmp = strint[index];
        while (tmp != '\0') {
            Node *tmp_node = new Node(tmp - '0');
            Node *ptr = head->next;
            head->next = tmp_node;
            tmp_node->next = ptr;
            index = index + 1;
            tmp = strint[index];
        }
    }

};

class Bigint {
public:
    BunList *list1 = new BunList(0);

    Bigint(char *strint) {
        list1->reverse_insert(strint);
    }

    Node * add(Bigint otherInt) {
        Node *num1 = this->list1->head->next;
        Node *num2 = otherInt.list1->head->next;
        Node *num3 = new Node(0);
        int update = 0;
        int sum = 0;
        int result = 0;
        while (num1 != NULL || num2 != NULL) {
            if (num1 != NULL && num2 != NULL) {
                sum = num1->data + num2->data + update;
                num1 = num1->next;
                num2 = num2->next;
            }
            else if (num1 == NULL) {
                sum = num2->data + update;
                num2 = num2->next;
            }
            else if (num2 == NULL) {
                sum = num1->data + update;
                num1 = num1->next;
            }
            result = sum % 10;
            update = sum / 10;
            Node *tmp_node = new Node(result);
            Node *tail = num3;
            while (tail->next != NULL) tail = tail->next;
            tail->next = tmp_node;
        }
        if (update == 1) {
            sum = 1;
            result = sum % 10;
            update = sum / 10;
            Node *tmp_node = new Node(result);
            Node *tail = num3;
            while (tail->next != NULL) tail = tail->next;
            tail->next = tmp_node;
        }
        return num3;
    }

};




//int main() {
//    char *str1 = new char[1024];
//    char *str2 = new char[1024];
//    cin >> str1 >> str2;
//
//    Bigint bi1(str1);
//    Bigint bi2(str2);
//    Node *result = bi1.add(bi2);
//    BunList bunList(result);
//
//    bunList.reverse_print();
//
//    return 0;
//}


