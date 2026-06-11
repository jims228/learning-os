public class AssertOperation implements ArrayOperation {
    public int[] operate(int[] array) {
        if (array == null || array.length == 0) {
            throw new IllegalArgumentException("Array cannot be null or empty.");
        }
        return array.clone();
    }
}
