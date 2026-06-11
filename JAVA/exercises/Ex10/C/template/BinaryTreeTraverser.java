package template;

public abstract class BinaryTreeTraverser {
    public abstract void initialize();
    public abstract void finalize();
    public void performPre(BinaryTreeNode u)  { /* hook */ }
    public void performIn(BinaryTreeNode u)   { /* hook */ }
    public void performPost(BinaryTreeNode u) { /* hook */ }

    public void run(BinaryTreeNode s) {
        initialize();
        parse(s);
        finalize();
    }

    private void parse(BinaryTreeNode u) {
        if (u == null) return;
        performPre(u);
        parse(u.getLeftChild());
        performIn(u);
        parse(u.getRightChild());
        performPost(u);
    }
}
