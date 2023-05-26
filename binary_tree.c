#include <stdio.h>
#include <stdlib.h>


typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
}tree_node;

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

int height(tree_node *root)
{
    printf("a");
    int *left_height=malloc(sizeof(int));
    int *right_height=malloc(sizeof(int));
    if(root->left==NULL)
    {
        (*left_height)=0;
    }
    else
    {
        (*left_height)=height(root->left);
    }

    if(root->right==NULL)
    {
        (*right_height)=0;
    }
    else
    {
        (*right_height)=height(root->right);
    }

    if((*left_height)>(*right_height))
    {
        return (*left_height)+1;
    }
    else
    {
        return (*right_height)+1;
    }



}

int avl_height_balance(tree_node *root)
{
    return height(root->left)-height(root->right);
}

tree_node* rightRotation(tree_node *root)
{
    tree_node *B = malloc(sizeof(tree_node));
    B=root->left;
    //free(root->left)
    root->left=B->right;
    B->right=root;
    return B;
}

tree_node* leftRotation(tree_node *root)
{
    tree_node *B=malloc(sizeof(tree_node));
    B=root->right;
    //free(root->right);
    root->right=B->left;
    B->left=root;
}


int main()
{
    tree_node test_node;
    test_node.data=5;
    test_node.left=NULL;
    test_node.right=NULL;
    add_tree_node(&test_node,3);
    add_tree_node(&test_node,6);
    add_tree_node(&test_node,2);
    add_tree_node(&test_node,1);
    inorder(&test_node);
    printf("\n");
    tree_node *rotation=rightRotation(&test_node);
    inorder(rotation);
    printf("%d",rotation->data);
    return 0;
}