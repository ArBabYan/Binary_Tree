#include <iostream>
#include <stack>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* New_Node(int data) {
    Node* node = new struct Node;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return (node);
}

void Inorder_Traversal(Node* root) {
    std::stack<Node*> Stack_In;
    Node* current = root;

    while (current != nullptr || !Stack_In.empty()) {
        while (current != nullptr) {
            Stack_In.push(current);
            current = current->left;
        }

        current = Stack_In.top();
        Stack_In.pop();

        std::cout << current->data << " ";

        current = current->right;
    }
}

void Preorder_Traversal(Node* root) {
    std::stack<Node*> Stack_Pre;
    Stack_Pre.push(root);

    while (!Stack_Pre.empty()) {
        struct Node* node = Stack_Pre.top();
        std::cout << node->data << " ";
        Stack_Pre.pop();

        if (node->right)
            Stack_Pre.push(node->right);
        if (node->left)
            Stack_Pre.push(node->left);
    }
}

void Postorder_Traversal(Node* root) {
    std::stack<Node*> Stack_Post;
    Node* current = root;
    Node* Check = nullptr;

    while (current != nullptr || !Stack_Post.empty()) {
        while (current != nullptr) {
            Stack_Post.push(current);
            current = current->left;
        }

        current = Stack_Post.top();

        if (current->right == nullptr || current->right == Check) {
            std::cout << current->data << " ";
            Stack_Post.pop();
            Check = current;
            current = nullptr;
        }
        else {
            current = current->right;
        }
    }
}

int main() {
    struct Node* root = New_Node(17);
    root->left = New_Node(8);
    root->right = New_Node(5);
    root->left->left = New_Node(26);
    root->left->right = New_Node(1);
    root->right->left = New_Node(5);
    std::cout << "Inorder traversal: ";
    Inorder_Traversal(root);
    std::cout << std::endl;
    std::cout << "Preorder traversal: ";
    Preorder_Traversal(root);
    std::cout << std::endl;
    std::cout << "Postorder traversal: ";
    Postorder_Traversal(root);

    return 0;
}
