public class AddMapManipulation extends ArrayManipulation {
    private int additionValue;

    public AddMapManipulation(ArrayOperation arrayOperation, int additionValue) {
        super(arrayOperation);
        this.additionValue = additionValue;
    }

    public int[] operate(int[] array) {
        int[] result = arrayOperation.operate(array);
        for (int i = 0; i < result.length; i++) {
            result[i] += additionValue;
        }
        return result;
    }
}
