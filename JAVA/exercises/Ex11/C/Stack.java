public class Stack implements OpenList {
    private int[] data;
    private int top;
    private int capacity;

    public Stack(int capacity) {
        this.capacity = capacity;
        this.data = new int[capacity];
        this.top = 0;
    }

    public void push(int x) throws StackOverflowException {
        if (top >= capacity) {
            throw new StackOverflowException(x);
        }
        data[top++] = x;
    }

    public int pop() throws StackUnderflowException {
        if (top == 0) {
            throw new StackUnderflowException();
        }
        return data[--top];
    }

    public boolean isEmpty() {
        return top == 0;
    }
}
