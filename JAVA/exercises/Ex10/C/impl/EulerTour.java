package impl;

import template.BinaryTreeTraverser;
import template.BinaryTreeNode;

public class EulerTour extends BinaryTreeTraverser {
    public void initialize() {
        System.out.println("Begin Euler Tour");
    }

    public void finalize() {
        System.out.println("\nEnd Euler Tour");
    }

    public void performPre(BinaryTreeNode u) {
        System.out.print(u.getKey() + " ");
    }

    public void performPost(BinaryTreeNode u) {
        System.out.print(u.getKey() + " ");
    }
}
