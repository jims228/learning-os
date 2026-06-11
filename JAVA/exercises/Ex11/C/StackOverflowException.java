public class StackOverflowException extends Exception {
    public StackOverflowException(int x) {
        super("Overflow. " + x + " can not be pushed.");
    }
}
