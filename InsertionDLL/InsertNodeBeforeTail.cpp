#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *back;
  Node *next;

public:
  Node(int data1, Node *next1, Node *back1)
  {
    data = data1;
    next = next1;
    back = back1;
  }

public:
  Node(int data1)
  {
    data = data1;
    next = nullptr;
    back = nullptr;
  }
};
Node *convertArr2DLL(vector<int> &arr)
{
  Node *head = new Node(arr[0]);
  Node *prev = head;
  for (int i = 1; i < arr.size(); i++)
  {
    Node *temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = temp;
  }
  return head;
}
void print(Node *head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
}
Node *deleteHead(Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return NULL;
  }
  Node *prev = head;
  head = head->next;

  head->back = nullptr;
  prev->next = nullptr;

  delete prev;
  return head;
}
Node *deleteTail(Node *head)
{

  // If the head is NULL
  if (head == NULL || head->next == NULL)
  {
    return NULL;
  }

  // 1st method to delete the tail
  //  Node* temp = head;
  //  while(temp->next != nullptr){
  //    temp = temp->next;
  //  }

  // temp->back->next = nullptr;
  // delete temp;
  // return head;

  // 2nd Method to delete the tail;
  Node *tail = head;
  while (tail->next != nullptr)
  {
    tail = tail->next;
  }
  Node *newTail = tail->back;
  newTail->next = nullptr;
  tail->back = nullptr;
  delete tail;
  return head;
}

Node *removeKthElement(Node *head, int k)
{
  if (head == NULL)
  {
    return NULL;
  }

  Node *kNode = head;
  int cnt = 0;
  while (kNode != NULL)
  {
    cnt++;
    if (cnt == k)
      break;
    kNode = kNode->next;
  }

  Node *prev = kNode->back;
  Node *front = kNode->next;

  if (prev == NULL && front == NULL)
  {
    delete kNode;
    return NULL;
  }
  else if (prev == NULL)
  {
    return deleteHead(head);
  }
  else if (front == NULL)
  {
    return deleteTail(head);
  }
  prev->next = front;
  front->back = prev;

  kNode->next = NULL;
  kNode->back = NULL;

  return head;
}
void deleteNode(Node *temp)
{
  Node *prev = temp->back;
  Node *front = temp->next;

  if (front == NULL)
  {
    prev->next = nullptr;
    temp->back = nullptr;
  }

  prev->next = front;
  front->back = prev;
  temp->next = temp->back = nullptr;
  free(temp);
}
Node *insertBeforeHead(Node *head, int val)
{
  Node *newHead = new Node(val, head, nullptr);
  head->back = newHead;

  return newHead;
}

Node *insertBeforeTail(Node *head, int val)
{
  if (head->next == NULL)
  {
    return insertBeforeTail(head, val);
  }

  Node *tail = head;
  while (tail->next != nullptr)
  {
    tail = tail->next;
  }
  Node* prev = tail->back;
  Node* newNode = new Node(10, tail, prev);
  prev->next = newNode;
  tail->back = newNode;
  return head;
}
int main()
{
  vector<int> arr = {12, 5, 8, 7};
  Node *head = convertArr2DLL(arr);
  head = insertBeforeTail(head, 10);
  print(head);
  return 0;
}