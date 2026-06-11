class SimpleNode {
    private int key;
    private SimpleNode next;
    private SimpleNode prev;

    public int getKey() { return key; }
    public void setKey(int key) { this.key = key; }

    public SimpleNode getNext() { return next; }
    public void setNext(SimpleNode next) { this.next = next; }

    public SimpleNode getPrev() { return prev; }
    public void setPrev(SimpleNode prev) { this.prev = prev; }
}
