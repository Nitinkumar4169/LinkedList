#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
  int data;
  Node* next;

  // constructor
  Node(int data1, Node* next1)
  {
    data = data1;
    next = next1;
  }

  // constructor for a Node with only data provided next intialized to nullptr
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

// Array to LinkedList
//Node* convertArr2LL(vector<int> &arr)
// {

//   if (arr.empty())
//   {
//     return nullptr;
//   }

 // Node* Head = new Node(arr[0]);
//   Node* mover = Head;
//   for (int i = 1;  arr.size(); i++)
//   {
//     Node* temp = new Node(arr[i]);
//     mover->next = temp;
//     mover = temp;
//   }
//   return Head;
// }

Node* deleteTail(Node* Head)
{
  if (Head == NULL || Head->next == NULL)
    return NULL;
  Node* temp = Head;
  while (temp->next->next != NULL)
  {
    temp = temp->next;
  }
  delete temp->next;
  temp->next = nullptr;

  return Head;
}

int main()
{
  vector<int> arr = {12, 5, 8, 7};
  // Create a linked list with the values from the vector
  Node* Head = new Node(arr[0]);
  Head->next = new Node(arr[1]);
  Head->next->next = new Node(arr[2]);
  Head->next->next->next = new Node(arr[3]);
  // Call the deleteTail function to delete the last node
  Head = deleteTail(Head);
  // Print the linked list after deletion
  printList(Head);
}