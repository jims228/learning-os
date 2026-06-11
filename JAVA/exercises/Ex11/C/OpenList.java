public interface OpenList {
    public void push(int x) throws StackOverflowException;
    public int pop() throws StackUnderflowException;
    public boolean isEmpty();
}
