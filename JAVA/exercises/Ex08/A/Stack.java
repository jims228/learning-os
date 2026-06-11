class Stack implements OpenList {
    private int[] data = new int[100];
    private int top = 0;

    public void push(int x){
        data[top++] = x;
    }

    public int pop(){
        return data[--top];
    }

    public boolean isEmpty(){
        return top == 0;
    }
}
