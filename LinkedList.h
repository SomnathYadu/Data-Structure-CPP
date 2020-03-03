#pragma once

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

class SinglyLinkedList {
private:
    int length;
    SinglyLinkedListNode* head;

public: 
    SinglyLinkedList();
    SinglyLinkedListNode* CreateNode(int);
    void InsertAtLast(int);
    void InsertAtPosition(int, int);
    void TraverseLinkedList();
    void DeleteNode(int);
};

SinglyLinkedList::SinglyLinkedList() {
    length = 0;
    head = nullptr;
}
SinglyLinkedListNode* SinglyLinkedList::CreateNode(int data) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode();
    newNode->data = data;
    if (head == nullptr)
        head = newNode;
    return newNode;
}
void SinglyLinkedList::InsertAtLast(int data)
{
    SinglyLinkedListNode* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = CreateNode(data);
    temp->next->next = nullptr;
}
void SinglyLinkedList::InsertAtPosition(int pos, int data)
{
    SinglyLinkedListNode* newNode = CreateNode(data);
    if (head == nullptr) return;

    int cnt = 0;
    if (pos == 0) {// which means first position of Linked List
        newNode->next = head;
        head = newNode;
        return;
    }
    SinglyLinkedListNode* cur = head;
    while (cur->next && --pos)
        cur = cur->next;
    newNode->next = cur->next;
    cur->next = newNode;
    return;
}
void SinglyLinkedList::TraverseLinkedList() {
    SinglyLinkedListNode* cur = head;
    std::cout << "_________________________________ " << std::endl;
    while (cur != nullptr) {
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
    std::cout << "_________________________________ " << std::endl;
}
void SinglyLinkedList::DeleteNode(int position) {
    if (head == nullptr)
        return;
    SinglyLinkedListNode* temp = head;
    if (position == 0) {
        head = head->next;
        free(temp);
        return;
    }
    SinglyLinkedListNode* cur = head;
    while (--position) {
        cur = cur->next;
        if (cur == nullptr) {
            std::cout << "The position does not exist";
            return;
        }
    }
    temp = cur->next;
    cur->next = cur->next->next;

    free(temp);
    return;
}
