package impl;

import template.BinaryTreeNode;

public class SimpleTreeNode implements BinaryTreeNode {
    private SimpleTreeNode leftChild;
    private SimpleTreeNode rightChild;
    private Integer key;

    public SimpleTreeNode(int key) {
        this.key = key;
    }

    public BinaryTreeNode getLeftChild()  { return leftChild; }
    public BinaryTreeNode getRightChild() { return rightChild; }
    public Integer getKey() { return key; }

    public void addLeftChild(SimpleTreeNode c)  { leftChild = c; }
    public void addRightChild(SimpleTreeNode c) { rightChild = c; }
}
