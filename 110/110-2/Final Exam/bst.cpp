#include <iostream>
#include <queue>
using namespace std;
 
/* A binary tree node has data, pointer to left child
and a pointer to right child */
 
struct Node {
    int data;
    Node* left;
    Node* right;
};

struct NodeDetails
{
    int data;
    int min, max;
};
 
/* Function to create a new node */
 
Node* CreateNode(int data)
{
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
 
/* Function to insert element in binary tree */
 
Node* InsertNode(Node* root, int data)
{
    // If the tree is empty, assign new node address to root
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }
 
    // Else, do level order traversal until we find an empty
    // place, i.e. either left child or right child of some
    // node is pointing to NULL.
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = CreateNode(data);
            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = CreateNode(data);
            return root;
        }
    }
}

bool levelOrderIsOfBST(int arr[], int n)
{
    // if tree is empty
    if (n == 0)
        return true;
     
    // queue to store NodeDetails
    queue<NodeDetails> q;
     
    // index variable to access array elements
    int i=0;
     
    // node details for the
    // root of the BST
    NodeDetails newNode;
    newNode.data = arr[i++];
    newNode.min = INT_MIN;
    newNode.max = INT_MAX;
    q.push(newNode);
     
    // until there are no more elements
    // in arr[] or queue is not empty
    while (i != n && !q.empty())       
    {
        // extracting NodeDetails of a
        // node from the queue
        NodeDetails temp = q.front();
        q.pop();
         
        // check whether there are more elements
        // in the arr[] and arr[i] can be left child
        // of 'temp.data' or not
        if (i < n && (arr[i] < temp.data &&
                     arr[i] > temp.min))
        {
            // Create NodeDetails for newNode
            /// and add it to the queue
            newNode.data = arr[i++];
            newNode.min = temp.min;
            newNode.max = temp.data;
            q.push(newNode);               
        }
         
        // check whether there are more elements
        // in the arr[] and arr[i] can be right child
        // of 'temp.data' or not
        if (i < n && (arr[i] > temp.data &&
                      arr[i] < temp.max))
        {
            // Create NodeDetails for newNode
            /// and add it to the queue
            newNode.data = arr[i++];
            newNode.min = temp.data;
            newNode.max = temp.max;
            q.push(newNode);           
        }       
    }
     
    // given array represents level
    // order traversal of BST
    if (i == n)
        return true;
         
    // given array do not represent
    // level order traversal of BST   
    return false;       
}
 
/* Inorder traversal of a binary tree */
 
void inorder(Node* temp)
{
    if (temp == NULL)
        return;
 
    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}
 
// Driver code
int main(void)
{
    Node* root = NULL;
    int arr[] = {3, 2, 5, 1,4};

    int n = sizeof(arr) / sizeof(arr[0]);

    if (levelOrderIsOfBST(arr, n)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}