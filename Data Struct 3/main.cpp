//	Maged Mahmoud
//  main.cpp
//  HOME4


#include <iostream>
using namespace std;


class Tree{
    
private:
    
    class TreeNode
    {
        friend class Tree;
        int value;
        TreeNode *left;
        TreeNode *right;
        TreeNode( int value1,
                 TreeNode *left1 = NULL,
                 TreeNode *right1 = NULL)
        {
            value = value1;
            left = left1;
            right = right1;
        }
    };
    
    TreeNode *root;
    
   
    
    void insert( TreeNode*&, int);
    void remove( TreeNode*&, int);
    void deleteSubtree( TreeNode *);
    void makeDeletion(TreeNode *&);
    void displayInorder(TreeNode *) const;
    void displayPreOrder(TreeNode *) const;
    void displayPostOrder(TreeNode *) const;
    void freeTree(TreeNode *);
    int countNodes(TreeNode *) const;
    int countChildren(TreeNode *) const;
    
public:
    
    
    Tree()
    { root = NULL; }
    
    void insert(int num)
    { insert(root, num); }
    
    void remove(int num)
    { remove(root, num); }
    
    void free(void)
    {freeTree(root);}
    
    int ShowNodes(void) const
    { return countNodes(root);  }
    
    int ShowChildren(void) const
    { return countChildren(root); }
    
    void ShowInorder(void) const
    { displayInorder(root); }
    
    void ShowPreOrder(void) const
    { displayPreOrder(root); }
    
    void ShowPostOrder(void) const
    { displayPostOrder(root); }
    
};



void Tree::freeTree(TreeNode *tree)
{
    if(!tree) return;
    freeTree(tree->left);
    freeTree(tree->right);
    delete tree;
}
int Tree::countNodes(TreeNode *tree) const
{
    if(tree != NULL)
        return 1 + countNodes(tree->left) + countNodes(tree->right);
    else
        return 0;
}

int Tree::countChildren(TreeNode * tree) const
{
    if(tree == NULL)
        return 0;
    
    if(tree->left != NULL || tree->right != NULL)
        return 1 + countChildren(tree->left) + countChildren(tree->right);
    return 0;
}


void Tree::displayInorder(TreeNode *tree) const
{
    if(tree){
        displayInorder(tree->left);
        cout << tree->value << " ";
        displayInorder(tree->right);
    }
}

void Tree::displayPreOrder(TreeNode *tree) const
{
    if(tree){
        cout << tree->value << " ";
        displayPreOrder(tree->left);
        displayPreOrder(tree->right);
    }
}

void Tree::displayPostOrder(TreeNode *tree) const
{
    if(tree){
        displayPostOrder(tree->left);
        displayPostOrder(tree->right);
        cout << tree->value << " ";
    }
}

void Tree::insert( TreeNode *&tree, int num)
{
    if(!tree){
        tree = new TreeNode(num);
        return;
    }
    
    if(tree->value == num){
        cout << num << " is a duplicate Value!" << endl;
        return;
    }
    
    if(num < tree->value)
        insert(tree->left, num);
    else
        insert(tree->right, num);
}

void Tree::remove(TreeNode *&tree, int num)
{
    
    if(tree == NULL)
        return;
    if(num < tree-> value)
        remove(tree->left, num);
    else if(num > tree->value)
        remove(tree->right, num);
    else
        makeDeletion(tree);
}

void Tree::makeDeletion(TreeNode *&tree)
{
    TreeNode *nodeToDelete = tree;
    TreeNode *attachPoint;
    
    if(tree->right == NULL)
        tree = tree->left;
    else if(tree->left == NULL)
        tree = tree->right;
    
    else{
        attachPoint = tree->right;
        
        while(attachPoint->left != NULL)
            attachPoint = attachPoint->left;
        
        attachPoint->left = tree->left;
        
        tree = tree->right;
    }
    
    delete nodeToDelete;
}
void Tree::deleteSubtree(TreeNode *tree)
{
    if(!tree) return;
    deleteSubtree(tree->left);
    deleteSubtree(tree->right);
    delete tree;
}



int main(){
   
    
    cout << endl << "Set #1" << endl;
    
    Tree Set1, Set2, Set3, Set4, Set5, Set6, Set7;
    
    for(int i = 0; i < 20; i++)
    {
        Set1.insert(i + 1);
    }
    Set1.insert(-999);
    
    cout << "\n\nInorder Traversal: " << endl;
    Set1.ShowInorder();
    cout << "\n\nPreOrder Traversal: " << endl;
    Set1.ShowPreOrder();
    cout << "\n\nPostOrder Traversal: " << endl;
    Set1.ShowPostOrder();
    
    cout << "\n\n Node Count: ";
    cout << Set1.ShowNodes() << " nodes found"<< endl;
    cout << "Node Children: ";
    cout << Set1.ShowChildren() << endl;
    
    Set1.insert(21);
    Set1.remove(1);
    Set1.insert(0);
    Set1.remove(10);
    Set1.remove(11);
    Set1.remove(5);
    Set1.remove(2);
    Set1.insert(10);
    
    cout << "\n\nInorder Traversal: " << endl;
    Set1.ShowInorder();
    cout << "\n\nPreOrder Traversal: " << endl;
    Set1.ShowPreOrder();
    cout << "\n\nPostOrder Traversal: " << endl;
    Set1.ShowPostOrder();
    
    cout << "\n\n Node Count: ";
    cout << Set1.ShowNodes() << " nodes found"<< endl;
    cout << "Node Children: ";
    cout << Set1.ShowChildren() << endl;
  
    Set1.free();
    
    /////////////////////////////////////////////2
    
    cout << endl << "Set #2" << endl;
    
    Set2.insert(3);
    Set2.insert(1);
    Set2.insert(5);
    Set2.insert(-999);
    
    cout << "\n\nInorder Traversal: " << endl;
    Set2.ShowInorder();
    cout << "\n\nPreorder Traversal: " << endl;
    Set2.ShowPreOrder();
    cout << "\n\nPostorder Traversal: " << endl;
    Set2.ShowPostOrder();
    
    cout << "\n\n Node Count: ";
    cout << Set2.ShowNodes() << " nodes found"<< endl;
    cout << "Node Children: ";
    cout << Set2.ShowChildren() << endl;
    
    Set2.remove(3);
    Set2.remove(1);
    
    cout << "\n\nInorder Traversal: " << endl;
    Set2.ShowInorder();
    cout << "\n\nPreorder Traversal: " << endl;
    Set2.ShowPreOrder();
    cout << "\n\nPostorder Traversal: " << endl;
    Set2.ShowPostOrder();
    
    cout << "\n\n Node Count: ";
    cout << Set2.ShowNodes() << " nodes found"<< endl;
    cout << "Node Children: ";
    cout << Set2.ShowChildren() << endl;
    
    ///////////////////////////////////////////////3
    
    cout << endl << "Set #3" << endl;
    
    Set3.insert(-999);
    
    cout << "\n\nInorder Traversal: " << endl;
    Set3.ShowInorder();
    cout << "\n\nPreorder Traversal: " << endl;
    Set3.ShowPreOrder();
    cout << "\n\nPostorder Traversal: " << endl;
    Set3.ShowPostOrder();
    
    cout << "\n\n Node Count: ";
    cout << Set3.ShowNodes() << " nodes found"<< endl;
    cout << "Node Children: ";
    cout << Set3.ShowChildren() << endl;
    
    Set3.remove(15);
    Set3.insert(30);
    Set3.insert(5);
    Set3.insert(10);
    Set3.insert(20);
    Set3.remove(20);
    
    cout << "\n\nInorder Traversal: " << endl;
    Set3.ShowInorder();
    cout << "\n\nPreorder Traversal: " << endl;
    Set3.ShowPreOrder();
    cout << "\n\nPostorder Traversal: " << endl;
    Set3.ShowPostOrder();
    
    cout << "\n\n Node Count: ";
    cout << Set3.ShowNodes() << " nodes found"<< endl;
    cout << "Node Children: ";
    cout << Set3.ShowChildren() << endl;
    cout << endl;
    
    /////////////////////////////////////////////4
    
    cout << endl << "Set #4" << endl;
    
    Set4.insert(2);
    Set4.insert(-999);
    
    cout << "\n\nInorder Traversal: " << endl;
    Set4.ShowInorder();
    cout << "\n\nPreorder Traversal: " << endl;
    Set4.ShowPreOrder();
    cout << "\n\nPostorder Traversal: " << endl;
    Set4.ShowPostOrder();
    
    cout << "\n\n Node Count: ";
    cout << Set2.ShowNodes() << " nodes found"<< endl;
    cout << "Node Children: ";
    cout << Set2.ShowChildren() << endl;
    
    Set4.remove(2);
    
    cout << "\n\nInorder Traversal: " << endl;
    Set4.ShowInorder();
    cout << "\n\nPreorder Traversal: " << endl;
    Set4.ShowPreOrder();
    cout << "\n\nPostorder Traversal: " << endl;
    Set4.ShowPostOrder();
    
    cout << "\n\n Node Count: ";
    cout << Set4.ShowNodes() << " nodes found"<< endl;
    cout << "Node Children: ";
    cout << Set4.ShowChildren() << endl;
    
    ////////////////////////////////////////////////5
    
    cout << endl << "Set #5" << endl;
    
    Set5.insert(10);
    Set5.insert(25);
    Set5.insert(16);
    Set5.insert(12);
    Set5.insert(37);
    Set5.insert(60);
    Set5.insert(3);
    Set5.insert(19);
    Set5.insert(33);
    Set5.insert(35);
    Set5.insert(55);
    Set5.insert(67);
    Set5.insert(87);
    Set5.insert(95);
    Set5.insert(-999);
    
    cout << "\n\nInorder Traversal: " << endl;
    Set5.ShowInorder();
    cout << "\n\nPreorder Traversal: " << endl;
    Set5.ShowPreOrder();
    cout << "\n\nPostorder Traversal: " << endl;
    Set5.ShowPostOrder();
    
    cout << "\n\n Node Count: ";
    cout << Set5.ShowNodes() << " nodes found"<< endl;
    cout << "Node Children: ";
    cout << Set5.ShowChildren() << endl;
    
    Set5.remove(37);
    Set5.remove(13);
    Set5.insert(40);
    Set5.insert(99);
   
    
    cout << "\n\nInorder Traversal: " << endl;
    Set5.ShowInorder();
    cout << "\n\nPreorder Traversal: " << endl;
    Set5.ShowPreOrder();
    cout << "\n\nPostorder Traversal: " << endl;
    Set5.ShowPostOrder();
    
    cout << "\n\n Node Count: ";
    cout << Set5.ShowNodes() << " nodes found"<< endl;
    cout << "Node Children: ";
    cout << Set5.ShowChildren() << endl;
    cout << endl;
    
    /////////////////////////////////////////////////6
    
    cout << endl << "Set #6" << endl;
    
    Set6.insert(50);
    Set6.insert(40);
    Set6.insert(60);
    Set6.insert(30);
    Set6.insert(70);
    Set6.insert(20);
    Set6.insert(80);
    Set6.insert(10);
    Set6.insert(90);
    Set6.insert(-999);
    
    cout << "\n\nInorder Traversal: " << endl;
    Set6.ShowInorder();
    cout << "\n\nPreorder Traversal: " << endl;
    Set6.ShowPreOrder();
    cout << "\n\nPostorder Traversal: " << endl;
    Set6.ShowPostOrder();
    
    cout << "\n\n Node Count: ";
    cout << Set6.ShowNodes() << " nodes found"<< endl;
    cout << "Node Children: ";
    cout << Set6.ShowChildren() << endl;
    
    Set6.remove(30);
    Set6.remove(20);
    Set6.remove(10);
    Set6.remove(50);
  
    
    cout << "\n\nInorder Traversal: " << endl;
    Set6.ShowInorder();
    cout << "\n\nPreorder Traversal: " << endl;
    Set6.ShowPreOrder();
    cout << "\n\nPostorder Traversal: " << endl;
    Set6.ShowPostOrder();
    
    cout << "\n\n Node Count: ";
    cout << Set6.ShowNodes() << " nodes found"<< endl;
    cout << "Node Children: ";
    cout << Set6.ShowChildren() << endl;
    cout << endl;
    
    
    /////////////////////////////////////////7
    
    cout << endl << "Set #7" << endl;
    
    Set7.insert(30);
    Set7.insert(40);
    Set7.insert(20);
    Set7.insert(10);
    Set7.insert(50);
    Set7.insert(-999);
    
    cout << "\n\nInorder Traversal: " << endl;
    Set7.ShowInorder();
    cout << "\n\nPreorder Traversal: " << endl;
    Set7.ShowPreOrder();
    cout << "\n\nPostorder Traversal: " << endl;
    Set7.ShowPostOrder();
    
    cout << "\n\n Node Count: ";
    cout << Set7.ShowNodes() << " nodes found"<< endl;
    cout << "Node Children: ";
    cout << Set7.ShowChildren() << endl;
    
    Set7.insert(30);
    Set7.remove(55);
    Set7.remove(40);
    Set7.insert(50);
    Set7.insert(40);
    Set7.remove(40);
    Set7.insert(15);
    Set7.insert(25);
    Set7.remove(30);
    Set7.remove(15);
    
    cout << "\n\nInorder Traversal: " << endl;
    Set7.ShowInorder();
    cout << "\n\nPreorder Traversal: " << endl;
    Set7.ShowPreOrder();
    cout << "\n\nPostorder Traversal: " << endl;
    Set7.ShowPostOrder();
    
    cout << "\n\n Node Count: ";
    cout << Set7.ShowNodes() << " nodes found"<< endl;
    cout << "Node Children: ";
    cout << Set7.ShowChildren() << endl;
    cout << endl;
    
    return 0;
}

