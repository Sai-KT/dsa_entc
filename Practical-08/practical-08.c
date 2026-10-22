/**
 * Practical 08: Binary Search Tree (BST) Contact Directory
 * Roll Number: 13 | Division: SE A
 * Academic Year: 2026-27
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef struct BSTNode {
    char name[30];
    char phone[20];
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

/**
 * Creates and allocates a new BST node.
 */
BSTNode* createNode(const char *name, const char *phone) {
    BSTNode *node = (BSTNode*)malloc(sizeof(BSTNode));
    if (!node) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strncpy(node->name, name, sizeof(node->name) - 1);
    node->name[sizeof(node->name) - 1] = '\0';
    strncpy(node->phone, phone, sizeof(node->phone) - 1);
    node->phone[sizeof(node->phone) - 1] = '\0';
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * Inserts a new contact into the BST ordered alphabetically by name.
 */
BSTNode* insert(BSTNode *root, const char *name, const char *phone) {
    if (root == NULL) {
        return createNode(name, phone);
    }

    int cmp = strcasecmp(name, root->name);
    if (cmp < 0) {
        root->left = insert(root->left, name, phone);
    } else if (cmp > 0) {
        root->right = insert(root->right, name, phone);
    } else {
        printf("\n[NOTE] Contact '%s' already exists! Updating phone number.\n", name);
        strncpy(root->phone, phone, sizeof(root->phone) - 1);
    }

    return root;
}

/**
 * Inorder Traversal (Left, Root, Right) - produces alphabetically sorted output.
 */
void inorderTraversal(const BSTNode *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%-18s : %-15s\n", root->name, root->phone);
        inorderTraversal(root->right);
    }
}

/**
 * Preorder Traversal (Root, Left, Right).
 */
void preorderTraversal(const BSTNode *root) {
    if (root != NULL) {
        printf("%-18s : %-15s\n", root->name, root->phone);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

/**
 * Postorder Traversal (Left, Right, Root).
 */
void postorderTraversal(const BSTNode *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%-18s : %-15s\n", root->name, root->phone);
    }
}

/**
 * Searches for a contact by name in the BST.
 */
BSTNode* search(BSTNode *root, const char *key, int *comparisons) {
    if (root == NULL) {
        return NULL;
    }

    (*comparisons)++;
    int cmp = strcasecmp(key, root->name);
    if (cmp == 0) {
        return root;
    } else if (cmp < 0) {
        return search(root->left, key, comparisons);
    } else {
        return search(root->right, key, comparisons);
    }
}

/**
 * Recursively frees all allocated nodes in the BST.
 */
void freeTree(BSTNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void) {
    BSTNode *root = NULL;
    int choice;
    char name[30], phone[20], search_key[30];

    do {
        printf("\n============================================\n");
        printf("    BINARY SEARCH TREE (BST) DIRECTORY\n");
        printf("============================================\n");
        printf("1. Insert Contact\n");
        printf("2. Display All Traversals (Inorder, Preorder, Postorder)\n");
        printf("3. Search Contact by Name\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1: {
                int more = 1;
                do {
                    printf("\nEnter Contact Name: ");
                    scanf("%29s", name);
                    printf("Enter Phone Number: ");
                    scanf("%19s", phone);
                    root = insert(root, name, phone);
                    printf("Add another contact? (1 for Yes, 0 for No): ");
                    if (scanf("%d", &more) != 1) more = 0;
                } while (more == 1);
                break;
            }

            case 2:
                if (root == NULL) {
                    printf("\n[INFO] Tree is empty! Please insert contacts first.\n");
                } else {
                    printf("\n--- INORDER TRAVERSAL (ALPHABETICAL) ---\n");
                    inorderTraversal(root);

                    printf("\n--- PREORDER TRAVERSAL (ROOT FIRST) ---\n");
                    preorderTraversal(root);

                    printf("\n--- POSTORDER TRAVERSAL (BOTTOM UP) ---\n");
                    postorderTraversal(root);
                }
                break;

            case 3:
                if (root == NULL) {
                    printf("\n[INFO] Tree is empty! Please insert contacts first.\n");
                } else {
                    printf("\nEnter Contact Name to Search: ");
                    scanf("%29s", search_key);
                    int comparisons = 0;
                    BSTNode *result = search(root, search_key, &comparisons);
                    if (result != NULL) {
                        printf("\n[FOUND] Contact Details:");
                        printf("\nName        : %s", result->name);
                        printf("\nPhone Number: %s", result->phone);
                        printf("\nComparisons : %d\n", comparisons);
                    } else {
                        printf("\n[NOT FOUND] Contact '%s' does not exist in the directory (Comparisons: %d).\n", 
                               search_key, comparisons);
                    }
                }
                break;

            case 4:
                freeTree(root);
                printf("\nBST memory deallocated. Exited successfully.\n");
                break;

            default:
                printf("\nInvalid option! Please enter a choice between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}
