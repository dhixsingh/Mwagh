#include <iostream>

using namespace std;


struct Node {
    long long i;
    long long j;
    long long value;
    struct Node *right;
    struct Node *down;
};

//Creating link or incrementing value of link
void addLink(struct Node *sparse, long long num1, long long num2) {
    
    Node *columnhead; //adding a new header for a column
    columnhead = new (struct Node);
    Node *curr; // for traversing the linkedlist
    Node *cpoint; //points to column where we're adding node
    Node *rpoint; //points to row where we're adding node
    Node *element; //adding a new element
    element = new (struct Node);
    Node *rowhead; //adding a new header for a row
    rowhead = new (struct Node);
    //  If sparse matrix is empty
    if (sparse->right->value == -1)  {
        Node *leadcolumn;
        leadcolumn = new (struct Node); //leadcolumn is the first column header
        leadcolumn->right = sparse->right;
        sparse->right = leadcolumn;
        sparse->right->value = num1;
        sparse->right->j = sparse->right->value;
        sparse->right->i = -1;
        sparse->right->down = sparse->right;
        cpoint = sparse->right;
    }
    else {
        if (sparse->right->value > num1) {
            columnhead->right = sparse->right;
            sparse->right = columnhead;
            sparse->right->value = num1;
            sparse->right->i = -1;
            sparse->right->down = sparse->right;
            cpoint = columnhead;
        } else if (sparse->right->value == num1) {
            cpoint = sparse->right;
            cpoint->i = -1;
        } else {
            curr = sparse;
            while (curr->right->value < num1 && curr->right->value != -1) {
                curr = curr->right;
            }
            //Adding the last column header
            if (curr->right->value == -1) {
                columnhead->value = num1;
                curr->right = columnhead;
                columnhead->right = sparse;
                columnhead->down = columnhead;
                columnhead->i = -1;
                cpoint = columnhead;
            } else if (curr->right->value == num1) {
                cpoint = curr->right;
            } else {
                columnhead->value = num1;
                columnhead->right = curr->right;
                curr->right = columnhead;
                columnhead->down = columnhead;
                columnhead->i = -1;
                cpoint = columnhead;
            }
            columnhead->j = columnhead->value;
        }
    }
    //Now we have either created a new column header, or just pointed cpoint at the point where we need to add the element
    //Doing the same for the rows
    if (sparse->down->value == -1) {
        Node *leadrow;
        leadrow = new (struct Node);
        leadrow->down = sparse->down;
        sparse->down = leadrow;
        sparse->down->value = num2;
        sparse->down->i = sparse->down->value;
        sparse->down->j = -1;
        sparse->down->right = sparse->down;
        rpoint = sparse->down;
    } else {
        if (sparse->down->value > num2) {
            rowhead->down = sparse->down;
            sparse->down = rowhead;
            sparse->down->value = num2;
            sparse->down->j = -1;
            sparse->down->right = sparse->down;
            rpoint = rowhead;
        } else if (sparse->down->value == num2) {
            rpoint = sparse->down;
            rpoint->j = -1;
        } else {
            curr = sparse;
            while (curr->down->value < num2 && curr->down->value != -1) {
                curr = curr->down;
            }
            if (curr->down->value == -1) {
                rowhead->value = num2;
                curr->down = rowhead;
                rowhead->down = sparse;
                rowhead->right = rowhead;
                rowhead->j = -1;
                rpoint = rowhead;
            } else if (curr->down->value == num2) {
                rpoint = curr->down;
            } else {
                rowhead->value = num2;
                rowhead->down = curr->down;
                curr->down = rowhead;
                rowhead->right = rowhead;
                rowhead->j = -1;
                rpoint = rowhead;
            }
            rowhead->i = rowhead->value;
        }
    }
    //If a node already exists, increment the value by 1.
    //Otherwise, create a new element node
    if (rpoint->right == rpoint) {
        element->right = rpoint->right;
        rpoint->right = element;
        element->value = 1;
        element->right = rpoint;
        element->j = num1;
    } else {
        curr = rpoint;
        while (curr->right->j < num1 && curr->right->j != -1) {
            curr = curr->right;
        }
        if (curr->right->j == -1) {
            element->right = rpoint;
            curr->right = element;
            element->j = num1;
            element->value = 1;
        } else if (curr->right->j == num1) {
            curr->right->value = curr->right->value + 1;
        } else {
            element->j = num1;
            element->right = curr->right;
            curr->right = element;
            element->value = 1;
        }
    }
    //Connecting the created node to the horizontally linked list
    if (cpoint->down == cpoint) {
        element->down = cpoint->down;
        cpoint->down = element;
        element->i = num2;
    } else {
        curr = cpoint;
        while (curr->down->i < num2 && curr->down->i != -1) {
            curr = curr->down;
        }
        if (curr->down->i == -1) {
            element->down = curr->down;
            curr->down = element;
            element->i = num2;
        } else if (curr->down->i == num2) {
        } else {
            element->i = num2;
            element->down = curr->down;
            curr->down = element;
        }
    }
}
//Deleting link or decrementing value
void deleteLink(struct Node *sparse, long long a, long long b) {
    Node *currcol;
    Node *currel;
    Node *currro;
    Node *currel2;
    Node *temp;
    currcol = sparse;
    
    while (currcol->right->value != a && currcol->right->value != -1) {
        currcol = currcol->right;
    }
    //Reaching given element
    if (currcol->right->value == a) {
        currel = currcol->right;
        while (currel->down->i != b && currel->down->i != -1) {
            currel = currel->down;
        }
        //If value>1 decrement
        //Otherwise delete
        if (currel->down->i == b) {
            if (currel->down->value != 1) {
                currel->down->value--;
            } else {
                temp = currel->down;
                currel->down = temp->down;
                
                currro = sparse;
                while (currro->down->value != b) {
                    currro = currro->down;
                }
                currel2 = currro->down;
                while (currel2->right->j != a) {
                    currel2 = currel2->right;
                }
                temp = currel2->right;
                currel2->right = temp->right;
                free(temp);
                //if a column/row points to itself, delete column/row
                if (currcol->right->down == currcol->right) {
                    temp = currcol->right;
                    currcol->right = temp->right;
                    free(temp);
                }
                if (currro->down->right == currro->down) {
                    temp = currro->down;
                    currro->down = temp->down;
                    free(temp);
                }
            }
        }
    }
}
//Displaying value
long long retrieveValue(struct Node *sparse, long long a, long long b) {
    Node *currel;
    Node *currcol;
    long long value = 0;
    currcol = sparse->right;
    
    while (currcol->value != a && currcol->value != -1) {
        currcol = currcol->right;
    }
    
    if (currcol->value == a) {
        currel = currcol->down;
        while (currel->i != b && currel->i != -1) {
            currel = currel->down;
        }
        if (currel->i == b)
        value = currel->value;
        else if (currel->i == -1) {
            value = 0;
        }
    } else if (currcol->value == -1)
    value = 0;
    
    return value;
}
//sum of linked elements in a row
long long rowSum(struct Node *sparse, long long a, long long b) {
    Node *currro;
    currro = sparse->down;
    long long tot = 0;
    
    while (currro->value != a && currro->value != -1) {
        currro = currro->down;
    }
    
    if (currro->value == -1) {
        tot = 0;
    } else {
        Node *currel;
        currel = currro->right;
        while (currel->j < b && currel->j != -1) {
            tot = tot + currel->value;
            currel = currel->right;
        }
    }
    return tot;
}
//sum of linked elements in a column
long long columnSum(struct Node *sparse, long long a, long long b) {
    Node *currcol;
    currcol = sparse->right;
    long long tot = 0;
    
    while (currcol->value != a && currcol->value != -1) {
        currcol = currcol->right;
    }
    
    if (currcol->value == -1) {
        tot = 0;
    } else {
        Node *currel;
        currel = currcol->down;
        while (currel->i < b && currel->i != -1) {
            tot = tot + currel->value;
            currel = currel->down;
        }
    }
    return tot;
}
//Matrix multiplication
void multiplyVector(struct Node *sparse, long long size, long long arr[], long long arr2[]) {
    Node *currro;
    Node *currel;
    currro = sparse->down;
    //Updating arr2 based on product between sparse matrix and inputed arr
    while (currro->value < size && currro->value != -1) {
        long long p = currro->value;
        currel = currro->right;
        while (currel->j < size && currel->j != -1) {
            long long q = currel->j;
            arr2[p] = arr2[p] + currel->value * arr[q];
            currel = currel->right;
        }
        currro = currro->down;
    }
    
}

int main() {
    long long num;
    //Number of operations
    cin >> num;
    //Initializing and assigning sparse matrix
    Node *sparse;
    sparse = new(struct Node);
    sparse->value = -1;
    sparse->i = -1;
    sparse->j = -1;
    sparse->right = sparse;
    sparse->down = sparse;
    
    
    for (long long z = 0; z < num; z++) {
        long long a, i, j, k;
        cin >> a;
        if (a == 1) {
            cin >> i;
            cin >> j;
            addLink(sparse, i, j);
        } else if (a == 2) {
            cin >> i;
            cin >> j;
            deleteLink(sparse, i, j);
        } else if (a == 3) {
            cin >> i;
            cin >> j;
            cout << retrieveValue(sparse, i, j) << endl;
        } else if (a == 4) {
            cin >> i;
            cin >> k;
            cout << rowSum(sparse, i, k) << endl;
        } else if (a == 5) {
            cin >> i;
            cin >> k;
            cout << columnSum(sparse, i, k) << endl;
        } else if (a == 6) {
            long long size;
            cin >> size;
            if (size == 0) {
                cout << size << endl;
            } else {
                long long arr[size];
                long long arr2[size];
                for (long long z = 0; z < size; z++) {
                    cin >> arr[z];
                    arr2[z] = 0;
                }
                multiplyVector(sparse, size, arr, arr2);
                for (long long i = 0; i < size; i++) {
                    cout << arr2[i] << " ";
                }
                cout << endl;
            }
            
        }
    }
    
    return 0;
}

