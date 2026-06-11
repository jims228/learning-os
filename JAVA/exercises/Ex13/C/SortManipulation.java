import java.util.Arrays;

public class SortManipulation extends ArrayManipulation {
    public SortManipulation(ArrayOperation arrayOperation) {
        super(arrayOperation);
    }

    public int[] operate(int[] array) {
        int[] result = arrayOperation.operate(array);
        Arrays.sort(result);
        return result;
    }
}
