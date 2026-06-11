class Queue implements OpenList {
    private int[] data = new int[100];
    private int head = 0;
    private int tail = 0;

    public void push(int x){
        data[tail++] = x;
    }

    public int pop(){
        return data[head++];
    }

    public boolean isEmpty(){
        return head == tail;
    }
}
