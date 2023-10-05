#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *createparentmapping(Node *root, int target, map<Node *, Node *> &nodetoparent) // create mapping and returns target node
{
    Node *res = NULL;
    queue<Node *> q;
    q.push(root);
    nodetoparent[root] = NULL;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front->data == target)
            res = front;
        if (front->left)
        {
            nodetoparent[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            nodetoparent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}
int burntree(Node *root, map<Node *, Node *> &nodetoparent)
{
    map<Node *, bool> visited;
    queue<Node *> q;
    q.push(root);
    visited[root] = true;
    int ans = 0;
    while (!q.empty())
    {
        int size = q.size();
        bool flag = false;
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();
            if (front->left && !visited[front->left])
            {
                flag = true;
                q.push(front->left);
                visited[front->left] = true;
            }
            if (front->right && !visited[front->right])
            {
                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }
            if (nodetoparent[front] && !visited[nodetoparent[front]])
            {
                flag = true;
                q.push(nodetoparent[front]);
                visited[nodetoparent[front]] = true;
            }
        }
        if (flag)
            ans++;
    }
    return ans;
}
int mintime(Node *root, int target)
{
    int ans = 0;
    map<Node *, Node *> nodetoparent;
    Node *targetnode = createparentmapping(root, target, nodetoparent);
    ans=burntree(targetnode, nodetoparent);
    return ans;
}
void buildfrom_levelorder(Node *&root)
{
    queue<Node *> q;
    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << "Enter left node for " << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }
        cout << "Enter right node for: " << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
    }
}
int main()
{
    Node* root=NULL;
    buildfrom_levelorder(root);
    cout<<"minimum time required is "<<mintime(root,8)<<endl;
}