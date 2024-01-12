#include <iostream>
class BST
{
public:
// default constructor
    BST(int usr_key)
    {
        node* newroot = new node(usr_key);
        m_root = newroot;
    }
// default destructor
    ~BST()
    {
        tree_destroy_rec(m_root);
    }
// insert a new node
    void insert(int key)
    {
        m_root = insertRec(m_root, key);
    }
// search and check if a key is in BST
    bool search(int key) const
    {
        return search_rec(m_root, key);
    }
// in-order print of BST
    void print() const
    {
        inorder_print(m_root);
        std::cout << '\n';
    }

    int size() const
    {
        return count_rec(m_root);
    }

private:
    struct node 
    {
        int key;
        node* left;
        node* right;

        node(int key) : key{key}, left{nullptr}, right{nullptr}
        {}
    };

    node* m_root{};

// recursive algorithms

// insert a node inside BST recursively
    node* insertRec(node* tree_node, int key)
    {
        if(tree_node == nullptr)
        {
            node* temp = new node(key);
            return temp;
        }

        if(tree_node->key == key) return tree_node;

        if(key > tree_node->key)
        {
            tree_node->right = insertRec(tree_node->right, key);
        }
        else if (key < tree_node->key)
        {
            tree_node->left = insertRec(tree_node->left, key);
        }
        return tree_node;
    }

    void inorder_print(node* tree) const
    {
        if(!tree) return;
        inorder_print(tree->left);
        std::cout << tree->key << ' ';
        inorder_print(tree->right);
    }
// destroy tree recursively, used by the destructor
    void tree_destroy_rec(node* tree_node)
    {
        if(!tree_node) return;
        tree_destroy_rec(tree_node->left);
        tree_destroy_rec(tree_node->right);
        delete tree_node;
    }
// search BST for a number
    bool search_rec(node* tree_node, int key) const
    {
        if(!tree_node) return false;
        if(tree_node->key == key) return true;

        return search_rec(tree_node->left, key) || search_rec(tree_node->right, key);
    }
// count number of nodes recursively
    int count_rec(node* tree_node) const
    {
        if(!tree_node) return 0;

        return (1 + count_rec(tree_node->left) + count_rec(tree_node->right));
    }
};

int main()
{
    BST bstree{8};
    bstree.insert(6);
    bstree.insert(8);
    bstree.insert(9);
    bstree.insert(1);
    bstree.insert(3);
    bstree.insert(-8);
    bstree.print();

    std::cout << "Enter a number to check if it is in BST(0 to quit): \n";
    while(true)
    {
        int x;
        std::cout << "Entry: ";
        std::cin >> x;
        if(x == 0)
        {
            break;
        }

        bool exists{bstree.search(x)};
        
        if(exists)
        {
            std::cout << "Number is in BST\n";
        }
        else
        {
            std::cout << "Number is not in BST\n";
        }
    }

    std::cout << bstree.size() << '\n';
    return 0;
}