import java.util.Random;

public class ShuffleManipulation extends ArrayManipulation {
    public ShuffleManipulation(ArrayOperation arrayOperation) {
        super(arrayOperation);
    }

    public int[] operate(int[] array) {
        int[] result = arrayOperation.operate(array);
        Random random = new Random();
        for (int i = result.length - 1; i > 0; i--) {
            int j = random.nextInt(i + 1);
            int temp = result[i];
            result[i] = result[j];
            result[j] = temp;
        }
        return result;
    }
}
