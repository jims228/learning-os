class SimpleList{
    private SimpleNode nil;
    SimpleList(){ init(); }
    void init(){
        nil = new SimpleNode();
        nil.setNext(nil);
        nil.setPrev(nil);
    }
    
    SimpleNode listSearch(int key){
        SimpleNode x = nil.getNext();
        while (x != nil){
            if(x.getKey() == key){
                return x;
            }else{
                x = x.getNext();
            }
        }
        return nil;
    }

    void printList(){
        SimpleNode x = nil.getNext();
        while(x != nil){
            System.out.print(x.getKey() + " ");
            x = x.getNext();
        }
        System.out.println();
    }

    void delete(int key){
        SimpleNode x = listSearch(key);
        if(x != nil){
            x.getPrev().setNext(x.getNext());
            x.getNext().setPrev(x.getPrev());
        }
    }

    void insert(int key){
        SimpleNode x = new SimpleNode();
        x.setKey(key);
        x.setNext(nil.getNext());
        x.setPrev(nil);
        nil.getNext().setPrev(x);
        nil.setNext(x); 
    }
}