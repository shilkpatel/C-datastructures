#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
    int data;
    struct tree_node *left;
    struct tree_node *right;
}tree_node;


int main()
{
    tree_node test_node;
    test_node.data=5;
    test_node.left=NULL;
    test_node.right=NULL;
    add_tree_node(&test_node,3);
    add_tree_node(&test_node,6);
    add_tree_node(&test_node,2);
    inorder(&test_node);
    return 0;
}


void add_tree_node(tree_node *root,int data)
{
    //printf("a");
    if(data<(root->data))
    {
        if(root->left==NULL)
        {
            tree_node *new_node=malloc(sizeof(tree_node));
            new_node->data=data;
            new_node->left=NULL;
            new_node->right=NULL;
            root->left=new_node;
        }
        else
        {
            add_tree_node(root->left,data);
        }
    }
    else
    {
        if(root->right==NULL)
        {
            tree_node *new_node=malloc(sizeof(tree_node));
            new_node->data=data;
            new_node->left=NULL;
            new_node->right=NULL;
            root->right=new_node;
        }
        else
        {
            add_tree_node(root->right,data);
        }
    }
}

void inorder(tree_node *root)
{
    if(root->left!=NULL)
    {
        inorder(root->left);
    }
    printf("%d",root->data);
    if(root->right!=NULL)
    {
        inorder(root->right);
    }
}
