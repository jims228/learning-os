public class Stack implements Container {
    private int[] data;
    private int top;
    private int capacity;

    public Stack(int capacity){
        this.capacity = capacity;
        this.data = new int[capacity];
        this.top = 0;
    }

    public void push(int x){
        if ( top < capacity ) data[top++] = x;
    }

    public int pop(){
        return data[--top];
    }

    public int size(){
        return top;
    }

    public boolean isEmpty(){
        return top == 0;
    }

    public boolean isFull(){
        return top == capacity;
    }
}
