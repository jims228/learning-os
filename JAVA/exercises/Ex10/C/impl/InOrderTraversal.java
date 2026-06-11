package impl;

import template.BinaryTreeTraverser;
import template.BinaryTreeNode;

public class InOrderTraversal extends BinaryTreeTraverser {
    public void initialize() {
        System.out.println("Begin In-order Traversal");
    }

    public void finalize() {
        System.out.println("\nEnd In-order Traversal");
    }

    public void performIn(BinaryTreeNode u) {
        System.out.print(u.getKey() + " ");
    }
}
