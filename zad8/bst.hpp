#ifndef BST_H
#define BST_H

#include "compare.hpp"

template<class T, class Trait = compare_types<T>>
class bst {
    public:
        bst() : root(nullptr) {}
        bst(const bst &tree);
        ~bst() { if(root) delete root; }
        void wstaw(T v);
        void usun(T v);
        bool szukaj(T v);
        
        friend std::ostream& operator << (std::ostream &wy, const bst<T, Trait> &tree) {
            if(tree.root == nullptr) wy<<"Puste drzewo.";
            else print(wy, tree.root);
            wy<<"\n";
            return wy;
        }
        bst& operator = (const bst &tree);
        
    private:
        class node {
            public:
            T val;
            node* left;
            node* right;
            node(T v) : val(v), left(nullptr), right(nullptr) {}
        };
        node *root;
        static void print(std::ostream &wy, node *tree) {
            if (tree) {
                print(wy, tree->left);
                wy<<tree->val<<" ";
                print(wy, tree->right);
            }
        }
        static T find_min(node* treeNd);
        static node* copy_tree(node* tree);
        void initialize_tree(std::initializer_list<T> nodes, int start, int end);
};

template <class T, class Trait>
bst<T, Trait>::bst(const bst &tree) {
    *this = tree;
}

template <class T, class Trait>
void bst<T, Trait>::wstaw(T v) {
    bst::node *newNode = new node(v);
    bst::node *tmp=root, *prev=nullptr;
    if(root==nullptr) {
        root = newNode;
        return;
    }
    
    while (tmp != nullptr) {
        prev = tmp;
        if(Trait::compare(tmp->val, newNode->val)) {;
            tmp = tmp->right;
        } 
        else {
           tmp = tmp->left;
        }
    }
    
    if(Trait::compare(prev->val, newNode->val))
        prev->right = newNode;
    else prev->left = newNode;
}

template <class T, class Trait>
T bst<T, Trait>::find_min(bst::node *treeNd) {
    if(!treeNd) throw std::string("Blad.");
    if(treeNd->left==nullptr) return treeNd->val;
    else find_min(treeNd->left);
}

template <class T, class Trait>
typename bst<T, Trait>::node* bst<T, Trait>::copy_tree(bst::node *tree) {
    if(tree==nullptr) return nullptr;
    bst::node *newNode = new node(tree->val);
    newNode->left = copy_tree(tree->left);
    newNode->right = copy_tree(tree->right);
    return newNode;
}

template <class T, class Trait>
void bst<T, Trait>::usun(T v) {
    bst::node *prev=root, *tmp=root;
    T w = root->val;
    if(root==nullptr) throw std::string("Puste drzewo.");
    
    if(Trait::equal(w, v)) {
        //std::cout<<"";
        if(root->left==nullptr && root->right==nullptr) {
            delete tmp;
            root=nullptr;
        }
        else if(root->left==nullptr) {
            root=root->right;
            delete tmp;
        }
        else if(root->right==nullptr) {
            root=root->left;
            delete tmp;
        }
        else {
            T wartosc = find_min(root->right);
            usun(wartosc);
            root->val=wartosc;
        }
        return;
    }
    
    while (tmp != nullptr) {
        if(Trait::equal(tmp->val, v)) {
            
            if(tmp->left==nullptr && tmp->right==nullptr) {
                if(prev->left == tmp) 
                    prev->left=nullptr;
                    
                else if(prev->right==tmp)
                    prev->right=nullptr;
            }
            
            else if(tmp->left==nullptr) {
                if(prev->left==tmp) 
                    prev->left = tmp->right;

                else 
                    prev->right=tmp->right;
            }
            
            else if(tmp->right==nullptr) {
                if(prev->left==tmp) 
                    prev->left=tmp->left;
                else 
                    prev->right=tmp->left;
            }
            
            else {
                T wartosc = find_min(tmp->right);
                this->usun(wartosc);
                tmp->val=wartosc;
                break;
            }
            delete tmp;
            break;
        }
        prev = tmp;
        if(Trait::compare(tmp->val, v)) tmp = tmp->right;
        else tmp = tmp->left;
    }
}

template <class T, class Trait>
bool bst<T, Trait>::szukaj(T v) {
    bst::node *tmp=root;
    
    while (tmp && !Trait::equal(tmp->val, v)) {
        if(Trait::compare(tmp->val, v))
            tmp=tmp->right;
        else 
            tmp=tmp->left;
    }
    
    return tmp ? true : false;
}

template<class T, class Trait>
bst<T, Trait>& bst<T, Trait>::operator=(const bst<T, Trait> &tree) {
    if(this==&tree) return *this;
    this->~bst();
    this->root = copy_tree(tree.root);
    return *this;
}

#endif


