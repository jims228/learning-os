public class StackUnderflowException extends Exception {
    public StackUnderflowException() {
        super("Underflow. There is no element in the stack.");
    }
}
