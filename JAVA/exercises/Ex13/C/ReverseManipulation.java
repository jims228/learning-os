public class ReverseManipulation extends ArrayManipulation {
    public ReverseManipulation(ArrayOperation arrayOperation) {
        super(arrayOperation);
    }

    public int[] operate(int[] array) {
        int[] result = arrayOperation.operate(array);
        for (int i = 0; i < result.length / 2; i++) {
            int oppositeIndex = result.length - 1 - i;
            int temp = result[i];
            result[i] = result[oppositeIndex];
            result[oppositeIndex] = temp;
        }
        return result;
    }
}
