package impl;

import template.BinaryTreeTraverser;
import template.BinaryTreeNode;

public class BinaryTreeTraverseApplication {
    public void run() {
        SimpleTreeNode[] T = new SimpleTreeNode[9];
        for (int i = 0; i < 9; i++) T[i] = new SimpleTreeNode(i);

        T[0].addLeftChild(T[1]);
        T[0].addRightChild(T[2]);
        T[1].addLeftChild(T[5]);
        T[1].addRightChild(T[7]);
        T[2].addLeftChild(T[3]);
        T[2].addRightChild(T[4]);
        T[3].addLeftChild(T[6]);
        T[3].addRightChild(T[8]);

        BinaryTreeTraverser[] traversers = {
            new PreOrderTraversal(),
            new InOrderTraversal(),
            new PostOrderTraversal(),
            new EulerTour()
        };

        for (BinaryTreeTraverser t : traversers) {
            t.run(T[0]);
            System.out.println();
        }
    }

    public static void main(String[] args) {
        new BinaryTreeTraverseApplication().run();
    }
}
