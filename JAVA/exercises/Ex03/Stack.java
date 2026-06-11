class Stack {
    private int[] data = new int[100];
    private int top = 0;

    void push(int x){
        data[top++] = x;
    }

    int pop(){
        return data[--top];
    }
}
