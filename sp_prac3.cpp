using namespace std;

#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_front(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if (!head) {
            std::cout << "список пуст" << std::endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            std::cout << "список пуст" << std::endl;
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
        delete temp;
    }

    void display() {
        Node* temp = head;
        if (!temp) {
            std::cout << "список пуст" << std::endl;
            return;
        }
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void sort() {
        if (!head || !head->next) return;

        bool temp2;
        do {
            temp2 = false;
            Node* temp = head;
            while (temp->next) {
                if (temp->data > temp->next->data) {
                    std::swap(temp->data, temp->next->data);
                    temp2 = true;
                }
                temp = temp->next;
            }
        } while (temp2);
    }

    void remove_duplicates() {
        if (!head) return;

        Node* temp = head;
        while (temp && temp->next) {
            Node* value = temp->next;
            while (value) {
                if (value->data == temp->data) {
                    std::cout << "удаление дубликата: " << value->data << std::endl;
                    Node* duplicate = value;
                    if (value->prev) value->prev->next = value->next;
                    if (value->next) value->next->prev = value->prev;
                    if (value == tail) tail = value->prev;
                    value = value->next;
                    delete duplicate;
                }
                else {
                    value = value->next;
                }
            }
            temp = temp->next;
        }
    }

};

int main() {
    DoublyLinkedList list;
    int n, value;

    do {
        cout << "1 — Добавить элемент в начало\n2 — Добавить элемент в конец.\n3 — Удалить элемент с начала\n4 — Удалить элемент с конца\n5 — Отобразить список\n6 — Сортировать список\n7 — Удалить дубликаты\n8 — Выйти" << endl;
        std::cin >> n;

        switch (n) {
        case 1:
            std::cout << "введите: ";
            std::cin >> value;
            list.push_front(value);
            break;
        case 2:
            std::cout << "введите: ";
            std::cin >> value;
            list.push_back(value);
            break;
        case 3:
            list.pop_front();
            break;
        case 4:
            list.pop_back();
            break;
        case 5:
            list.display();
            break;
        case 6:
            list.sort();
            break;
        case 7:
            list.remove_duplicates();
            break;
        case 8:
            std::cout << "выход...";
            break;
        default:
            std::cout << "error";
        }
    } while (n != 8);
}