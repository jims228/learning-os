class SimpleNode{
    private int key;
    private SimpleNode next;
    private SimpleNode prev;

    void setKey(int k){
        key=k;
    }
    int getKey(){
        return key;
    }

    void setNext(SimpleNode n){
        next=n;
    }
    SimpleNode getNext(){
        return next;
    }

    void setPrev(SimpleNode p){
        prev=p;
    }
    SimpleNode getPrev(){
        return prev;
    }
}