#include <iostream>
#include <math.h>

using namespace std;


struct stock {
    long long id;
    long long price;
};

void conquer(stock arr[], long long p, long long q, long long r) {
    long long n1 = q - p + 1;
    long long n2 = r - q;

    stock A[n1], B[n2];

    for (long long i = 0; i < n1; i++)
        A[i] = arr[p + i];
    for (long long j = 0; j < n2; j++)
        B[j] = arr[q + 1 + j];

    long long i = 0;
    long long j = 0;
    long long k = p;
    while (i < n1 && j < n2) {
        if (A[i].id <= B[j].id) {
            arr[k] = A[i];
            i++;
        } else {
            arr[k] = B[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = A[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = B[j];
        j++;
        k++;
    }
}

void divide(stock arr[], long long y, long long z) {
    if (y < z) {
        long long x = y + (z - y) / 2;

        divide(arr, y, x);
        divide(arr, x + 1, z);

        conquer(arr, y, x, z);
    }
}

void printarr(stock arr[], long long size) {
    for (long long i = 0; i < size; i++) {
        cout << arr[i].id << " " << arr[i].price << endl;
    }
}

struct Node {
    stock key;
    struct Node *left = nullptr;
    struct Node *right = nullptr;
    long long height;
};

long long height(struct Node *N) {
    if (N == nullptr)
        return 0;
    else
        return N->height;
}

long long maximum(long long a, long long b) {
    if (a > b)
        return a;
    else
        return b;
}

struct Node *newNode(stock key) {
    struct Node *node = new (struct Node);
    node->key = key;
    node->height = 1;
    node->left = nullptr;
    node->right = nullptr;// new node is initially added at leaf
    return (node);
}

struct Node *rRot(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = maximum(height(y->left), height(y->right)) + 1;
    x->height = maximum(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node *lRot(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = maximum(height(x->left), height(x->right)) + 1;
    y->height = maximum(height(y->left), height(y->right)) + 1;

    return y;
}

long long balance(struct Node *node) {
    if (node == nullptr) {
        return 0;
    } else
        return height(node->left) - height(node->right);
}

struct Node *min(struct Node *rand) {
    struct Node *pointer = rand;
    while (pointer->left != nullptr)
        pointer = pointer->left;

    return pointer;
}

struct Node *reg(struct Node *node, stock key) {
    if (node == nullptr)
        return (newNode(key));
    if (key.id < node->key.id) {
        node->left = reg(node->left, key);
    } else if (key.id > node->key.id) {
        node->right = reg(node->right, key);
    } else
        return node;
    node->height = 1 + maximum(height(node->left), height(node->right));
    long long bal = balance(node);

    if (bal > 1 && key.id < node->left->key.id)
        return rRot(node);

    if (bal < -1 && key.id > node->right->key.id)
        return lRot(node);

    if (bal > 1 && key.id > node->left->key.id) {
        node->left = lRot(node->left);
        return rRot(node);
    }

    if (bal < -1 && key.id < node->right->key.id) {
        node->right = rRot(node->right);
        return lRot(node);
    }

    return node;
}

struct Node *dereg(struct Node *node, stock key) {
    if (node == nullptr)
        return node;
    if (key.id < node->key.id) {
        node->left = dereg(node->left, key);
    } else if (key.id > node->key.id) {
        node->right = dereg(node->right, key);
    } else {
        struct Node *temp1;
        if (node->left == nullptr && node->right == nullptr) {
            node = nullptr;
        } else if (node->left == nullptr) {
            temp1 = node;
            node = node->right;
            free(temp1);
        } else if (node->right == nullptr) {
            temp1 = node;
            node = node->left;
            free(temp1);
        } else {
            struct Node *temp = min(node->right);
            node->key = temp->key;
            node->right = dereg(node->right, temp->key);
        }
    }
    if (node == nullptr)
        return node;
    long long bal = balance(node);
    node->height = 1 + maximum(height(node->left), height(node->right));
    if (bal > 1 && balance(node->left) >= 0)
        return rRot(node);
    if (bal > 1 && balance(node->left) < 0) {
        node->left = lRot(node->left);
        return rRot(node);
    }
    if (bal < -1 && balance(node->right) <= 0)
        return lRot(node);
    if (bal < -1 && balance(node->right) > 0) {
        node->right = rRot(node->right);
        return lRot(node);
    }
    return node;
}

struct Node *update(struct Node *root, stock input, long long threshold) {
    Node *current = root;
    while (current != nullptr && current->key.id != input.id) {
        if (current->key.id > input.id) {
//            if (current->left == nullptr)
//                return root;
//            else
                current = current->left;
        } else if (current->key.id < input.id) {
//            if (current->right == nullptr)
//                return root;
//            else
                current = current->right;
        }
    }
    if (current == nullptr)
        return root;
    else {
        if (abs(current->key.price - input.price) > threshold) {
            current->key.price = input.price;
            cout << current->key.id << " " << current->key.price << endl;
        }
    }
    return root;
}


struct Node *split(struct Node *root, stock input, long long threshold, long long y, long long z) {
    Node *current = root;
    while (current->key.id != input.id && current != nullptr) {
        if (current->key.id > input.id) {
            if (current->left == nullptr)
                return root;
            else
                current = current->left;
        } else if (current->key.id < input.id) {
            if (current->right == nullptr)
                return root;
            else
                current = current->right;
        }
    }
    if (current == nullptr)
        return root;
    else {

        current->key.price = (current->key.price * z) / y;
        cout << current->key.id << " " << current->key.price << endl;
    }
    return root;
}

void printlist(struct Node *root) {
    if (root != nullptr) {
        cout << root->key.id << " " << root->key.price << endl;
        printlist(root->left);
        printlist(root->right);
    }
}

struct Node *transfer(stock arr[], long long a, long long b) {
    if (a > b)
        return nullptr;
    long long mid = (a + b) / 2;

    struct Node *root = newNode(arr[mid]);
    root->left = transfer(arr, a, mid - 1);
    root->right = transfer(arr, mid + 1, b);
    root->height = 1 + max(height(root->left), height(root->right));
    return root;
}

int main() {
    long long size;
    cin >> size;
    stock arr[size];
    long long i;
    struct Node *root = nullptr;
    for (i = 0; i < size; i++) {
        cin >> arr[i].id;
        cin >> arr[i].price;
    }
    divide(arr, 0, size - 1);
//    printarr(arr, size);
    long long currheight;
    root = transfer(arr, 0, size - 1);
//   printlist(root);
    long long operations;
    cin >> operations;
    long long threshold;
    cin >> threshold;
    for (i = 0; i < operations; i++) {
        long long a;
        cin >> a;
        if (a == 1) {
            stock p;
            cin >> p.id;
            cin >> p.price;
            cout << p.id << " " << p.price << endl;
            root = reg(root, p);
//            printlist(root);
        } else if (a == 2) {
            stock p;
            cin >> p.id;
            root = dereg(root, p);
            //       printlist(root);
        } else if (a == 3) {
            stock p;
            cin >> p.id;
            cin >> p.price;
            update(root, p, threshold);
        } else if (a == 4) {
            stock p;
            long long y, z;
            char random;
            cin >> p.id;
            cin >> y;
            cin >> random;
            cin >> z;
            split(root, p, threshold, y, z);
        } else if (a == 5) {
            printlist(root);
        }

//        else if (a == 2){
//            deletion;
//        }
//        else if (a == 3){
//            update;
//        }
//        else if (a == 4){
//            split;
//        }
//    }
    }
    return 0;
}