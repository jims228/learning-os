public abstract class ArrayManipulation implements ArrayOperation {
    protected ArrayOperation arrayOperation;

    public ArrayManipulation(ArrayOperation arrayOperation) {
        this.arrayOperation = arrayOperation;
    }
}
