class ContainerApplication{
    public ContainerApplication(){
        Stack st = new Stack(5);
        showState(st);
        for ( int i = 0; i < 5; i++ ) {
            st.push(i);
            showState(st);
        }
        for ( int i = 0; i < 5; i++ ) {
            st.pop();
            showState(st);
        }
    }
    private void showState(Container con){
        if ( con.isEmpty() ) System.out.println("empty");
        else if ( con.isFull() ) System.out.println("full");
        else System.out.println(con.size());
    }
    public static void main(String[] args){
        new ContainerApplication();
    }
}
