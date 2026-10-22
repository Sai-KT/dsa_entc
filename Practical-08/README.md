# Practical 08: Binary Search Tree (BST) Contact Directory

## 1. Practical Number
Practical 08

## 2. Practical Title / Aim
Implement a Contact Directory using a Binary Search Tree (BST) in C to perform dynamic insertion, tree depth traversals (Inorder, Preorder, Postorder), and logarithmic search by contact name.

## 3. Objective
- Understand non-linear hierarchical data structures and BST ordering properties.
- Implement recursive node insertion maintaining the invariant: $\text{left} < \text{root} < \text{right}$.
- Implement depth-first tree traversal algorithms: Inorder (yielding sorted output), Preorder, and Postorder.
- Evaluate search efficiency in a Binary Search Tree compared to linear search structures.

## 4. Algorithm / Logic Used

### A. BST Insertion (`insert`)
1. **Start**
2. If `root == NULL`:
   - Return newly allocated node with name and phone.
3. Compare `name` with `root->name` (case-insensitive):
   - If `name < root->name`: `root->left = insert(root->left, name, phone)`.
   - If `name > root->name`: `root->right = insert(root->right, name, phone)`.
   - If `name == root->name`: update existing phone number.
4. Return `root`.
5. **End**

### B. BST Traversals
- **Inorder (`inorderTraversal`):** Traverse Left Subtree $\rightarrow$ Visit Root $\rightarrow$ Traverse Right Subtree (alphabetical order).
- **Preorder (`preorderTraversal`):** Visit Root $\rightarrow$ Traverse Left Subtree $\rightarrow$ Traverse Right Subtree.
- **Postorder (`postorderTraversal`):** Traverse Left Subtree $\rightarrow$ Traverse Right Subtree $\rightarrow$ Visit Root.

### C. BST Search (`search`)
1. If `root == NULL`: return `NULL` (Not Found).
2. Increment comparison count.
3. If `key == root->name`: return `root`.
4. If `key < root->name`: recursively search `root->left`.
5. Else: recursively search `root->right`.

## 5. Code Implementation
Source code: [practical-08.c](practical-08.c)

```c
BSTNode* insert(BSTNode *root, const char *name, const char *phone) {
    if (root == NULL) return createNode(name, phone);
    int cmp = strcasecmp(name, root->name);
    if (cmp < 0) root->left = insert(root->left, name, phone);
    else if (cmp > 0) root->right = insert(root->right, name, phone);
    return root;
}
```

## 6. Complexity Analysis

| Operation | Best Case Time | Average Case Time | Worst Case Time (Skewed) | Auxiliary Space (Recursion) |
| :--- | :---: | :---: | :---: | :---: |
| **Insertion** | $O(1)$ | $O(\log n)$ | $O(n)$ | $O(h)$ where $h = \text{height}$ |
| **Search** | $O(1)$ | $O(\log n)$ | $O(n)$ | $O(h)$ |
| **Inorder Traversal** | $\Theta(n)$ | $\Theta(n)$ | $\Theta(n)$ | $O(h)$ |
| **Preorder Traversal** | $\Theta(n)$ | $\Theta(n)$ | $\Theta(n)$ | $O(h)$ |
| **Postorder Traversal** | $\Theta(n)$ | $\Theta(n)$ | $\Theta(n)$ | $O(h)$ |

## 7. Input / Output & Test Cases

### Test Case 1: Contact Insertion & Inorder Traversal
**Inserted Contacts:**
- `David` (9988776655)
- `Alice` (9123456780)
- `Bob` (9876543210)
- `Emily` (9554433221)

**Output (Inorder Traversal - Alphabetical):**
```text
Alice              : 9123456780     
Bob                : 9876543210     
David              : 9988776655     
Emily              : 9554433221     
```

### Test Case 2: Successful Search
**Input:**
```text
Search Target: Bob
```
**Output:**
```text
[FOUND] Contact Details:
Name        : Bob
Phone Number: 9876543210
Comparisons : 3
```

### Test Case 3: Search Non-Existent Contact
**Input:**
```text
Search Target: Zara
```
**Output:**
```text
[NOT FOUND] Contact 'Zara' does not exist in the directory (Comparisons: 2).
```

## 8. Conclusion
Successfully implemented the Binary Search Tree ADT for a contact directory in C. Verified that Inorder traversal visits nodes in natural alphabetical order and average search takes $O(\log n)$ time on balanced tree structures.
