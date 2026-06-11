package impl;

import template.BinaryTreeTraverser;
import template.BinaryTreeNode;

public class PostOrderTraversal extends BinaryTreeTraverser {
    public void initialize() {
        System.out.println("Begin Post-order Traversal");
    }

    public void finalize() {
        System.out.println("\nEnd Post-order Traversal");
    }

    public void performPost(BinaryTreeNode u) {
        System.out.print(u.getKey() + " ");
    }
}
