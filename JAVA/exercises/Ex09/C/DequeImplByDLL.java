class DequeImplByDLL implements Deque {
    private SimpleDoublyLinkedList list;
    private int n;

    DequeImplByDLL() {
        list = new SimpleDoublyLinkedList();
        n = 0;
    }

    public void insertFront(int key) {
        list.addFront(key);
        n++;
    }

    public void insertBack(int key) {
        list.addBack(key);
        n++;
    }

    public void removeFront() {
        list.removeFront();
        n--;
    }

    public void removeBack() {
        list.removeBack();
        n--;
    }

    public int front() {
        return list.front();
    }

    public int back() {
        return list.back();
    }

    public int size() {
        return n;
    }

    public boolean empty() {
        return n == 0;
    }
}
