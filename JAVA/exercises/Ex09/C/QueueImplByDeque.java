class QueueImplByDeque implements Queue {
    private Deque deque;

    QueueImplByDeque() {
        this.deque = new DequeImplByDLL();
    }

    public void enqueue(int key) {
        deque.insertBack(key);
    }

    public int dequeue() {
        int v = deque.front();
        deque.removeFront();
        return v;
    }

    public int front() {
        return deque.front();
    }

    public int size() {
        return deque.size();
    }

    public boolean empty() {
        return deque.empty();
    }
}
