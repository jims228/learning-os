class SimpleList implements Aggregate {
    private SimpleNode nil;

    public SimpleList(){
        nil = new SimpleNode();
        nil.setNext(nil);
        nil.setPrev(nil);
    }

    public SimpleNode getNil(){ return nil; }

    public void insert(int key){
        SimpleNode n = new SimpleNode(key);
        n.setNext(nil.getNext());
        n.setPrev(nil);
        nil.getNext().setPrev(n);
        nil.setNext(n);
    }

    public void delete(int key){
        SimpleNode cur = nil.getNext();
        while(cur != nil){
            if(cur.getKey() == key){
                cur.getPrev().setNext(cur.getNext());
                cur.getNext().setPrev(cur.getPrev());
                return;
            }
            cur = cur.getNext();
        }
    }

    public Iterator forwardIterator(){
        return new SimpleListForwardIterator(this);
    }

    public Iterator backwardIterator(){
        return new SimpleListBackwardIterator(this);
    }
}
