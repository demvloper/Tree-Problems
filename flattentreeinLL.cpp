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
void flatten(Node* root)
{
    Node* curr=root;
    while (curr!=NULL)
    {
        if(curr->left)
        {
            Node* predessor=curr->left;
            while (predessor->right)
            {
                predessor=predessor->right;
            }
            predessor->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }
        curr=curr->right;
    }
    curr=root;

    /*while (curr!=NULL) //this while loop or line number 30 serves the same making the left pointer NULL
    {
        curr->left=NULL;
        curr=curr->right;
    }*/  
}
int main()
{
}