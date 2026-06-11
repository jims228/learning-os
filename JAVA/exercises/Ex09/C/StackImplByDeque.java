class StackImplByDeque implements Stack {
    private Deque deque;

    StackImplByDeque() {
        this.deque = new DequeImplByDLL();
    }

    public void push(int x) {
        deque.insertFront(x);
    }

    public int pop() {
        int v = deque.front();
        deque.removeFront();
        return v;
    }

    public int top() {
        return deque.front();
    }

    public int size() {
        return deque.size();
    }

    public boolean empty() {
        return deque.empty();
    }
}
