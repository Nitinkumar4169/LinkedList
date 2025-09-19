#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
  int data;
  Node* next;

  Node(int data1, Node* next1)
  {
    data = data1;
    next = next1;
  }
  // Constructor for a node with only data provided, next initialized to nullptr
  Node(int data1)
  {
    data = data1;
    next = nullptr;
  }
};

// Function to print the list
void printList(Node* Head)
{
  while (Head != NULL)
  {
    cout << Head->data << " ";
    Head = Head->next;
  }
  cout << endl;
}

// Convert array to linked list
Node* convertArr2LL(vector<int> &arr)
{
  if (arr.empty())
    return nullptr;

  Node* Head = new Node(arr[0]);
  Node* mover = Head;
  for (int i = 1; i < arr.size(); i++)
  {
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return Head;
}
// Function to delete Head node
Node* removeHead(Node* Head)
{

  if (Head == nullptr)
  {
    return nullptr; // Empty list
  }
  Node* temp = Head;
  Head = Head->next;
  delete temp; // or free(temp)
  return Head;
}

int main()
{
  vector<int> arr = {10, 20, 30, 40, 50};
  Node *Head = convertArr2LL(arr);
  Head = removeHead(Head);
  printList(Head);
}
