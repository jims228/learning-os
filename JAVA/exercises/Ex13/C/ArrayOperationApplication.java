import java.util.Arrays;

public class ArrayOperationApplication {
    public void run() {
        int[] array = {5, 18, 7, 10, 5, 11, 26, 5};
        int[] empty = {};
        try {
            ArrayOperation op1 = new AssertOperation();
            ArrayOperation op2 = new SortManipulation(
                    new AssertOperation()
            );
            ArrayOperation op3 = new ReverseManipulation(
                    new SortManipulation(
                            new AssertOperation()
                    )
            );
            ArrayOperation op4 = new AddMapManipulation(
                    new ReverseManipulation(
                            new SortManipulation(
                                    new AssertOperation()
                            )
                    ),
                    1000
            );
            ArrayOperation op5 = new ShuffleManipulation(op4);

            System.out.println(Arrays.toString(op1.operate(array)));
            System.out.println(Arrays.toString(op2.operate(array)));
            System.out.println(Arrays.toString(op3.operate(array)));
            System.out.println(Arrays.toString(op4.operate(array)));
            System.out.println(Arrays.toString(op5.operate(array)));
            System.out.println(Arrays.toString(op1.operate(empty)));
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }

    public static void main(String[] args) {
        new ArrayOperationApplication().run();
    }
}
