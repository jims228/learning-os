package impl;

import template.BinaryTreeTraverser;
import template.BinaryTreeNode;

public class PreOrderTraversal extends BinaryTreeTraverser {
    public void initialize() {
        System.out.println("Begin Pre-order Traversal");
    }

    public void finalize() {
        System.out.println("\nEnd Pre-order Traversal");
    }

    public void performPre(BinaryTreeNode u) {
        System.out.print(u.getKey() + " ");
    }
}
