#include <iostream>
#include <string>
#include <sstream>

template <typename T>
class BinarySearchTree {
private:
    struct Node {
        T data;                
        int index;             
        Node* parent;         
        Node* left;            
        Node* right;          

        Node(const T& value, int idx, Node* parentNode = nullptr) : data(value), index(idx), parent(parentNode), left(nullptr), right(nullptr) {}
    };

    Node* root;                
    int size;                   
    int currentIndex;          

    Node* add(Node* node, const T& value, Node* parentNode) {
        if (!node) {
            return new Node(value, currentIndex++, parentNode);
        } 
        if (value < node->data) {
            node->left = add(node->left, value, node);
        }
        else if (value > node->data) {
            node->right = add(node->right, value, node);
        }
        return node;
    }

    Node* find(Node* node, const T& value) const {
        if (!node || node->data == value) {
            return node;
        } 
        if (value < node->data) {
            return find(node->left, value);
        } 
        return find(node->right, value);
    }

    Node* findMin(Node* node) const {
        while (node && node->left) {
            node = node->left;
        } 
        return node;
    }

    Node* remove(Node* node, const T& value) {
        if (!node) {
            return nullptr;
        } 
        if (value < node->data) {
            node->left = remove(node->left, value);
        }
        else if (value > node->data) {
            node->right = remove(node->right, value);
        }
        else {
            if (!node->left) {
                Node* temp = node->right;
                if (temp) {
                    temp->parent = node->parent;
                } 
                delete node;
                --size;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                if (temp) {
                    temp->parent = node->parent;
                } 
                delete node;
                --size;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->index = temp->index;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    void inOrder(Node* node) const {
        if (node) {
            inOrder(node->left);
            std::cout << "(" << node->data << ", index: " << node->index << ") ";
            inOrder(node->right);
        }
    }

    void preOrder(Node* node) const {
        if (node) {
            std::cout << "(" << node->data << ", index: " << node->index << ") ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    int height(Node* node) const {
        if (!node) {
            return 0;
        } 
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + std::max(leftHeight, rightHeight);
    }

    void toString(Node* node, std::ostringstream& os) const {
        if (node) {
            os << "(" << node->data << ", index: " << node->index << ") ";
            toString(node->left, os);
            toString(node->right, os);
        }
    }

public:
    BinarySearchTree() : root(nullptr), size(0), currentIndex(0) {}

    ~BinarySearchTree() {
        clear(root);
    }

    void add(const T& value) {
        root = add(root, value, nullptr);
        ++size;
    }

    bool find(const T& value) const {
        return find(root, value) != nullptr;
    }

    void remove(const T& value) {
        root = remove(root, value);
    }

    void inOrder() const {
        inOrder(root);
        std::cout << std::endl;
    }

    void preOrder() const {
        preOrder(root);
        std::cout << std::endl;
    }

    void clear() {
        clear(root);
        root = nullptr;
        size = 0;
        currentIndex = 0;
    }

    int height() const {
        return height(root);
    }

    std::string toString() const {
        std::ostringstream os;
        toString(root, os);
        return os.str();
    }

    int getSize() const {
        return size;
    }
};


