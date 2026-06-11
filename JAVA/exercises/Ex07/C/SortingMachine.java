public class SortingMachine {
    public void sort(Relatable[] r){
        for ( int i = 0; i < r.length - 1; i++ ) {
            for ( int j = r.length - 1; j > i; j-- ) {
                if ( r[j].isSmallerThan(r[j - 1]) ) {
                    Relatable tmp = r[j];
                    r[j] = r[j - 1];
                    r[j - 1] = tmp;
                }
            }
        }
    }
}
