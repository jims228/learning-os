import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

class ReverseString {
    ReverseString() {
        try {
            FileInputStream in = new FileInputStream("input.txt");
            FileOutputStream out = new FileOutputStream("output.txt");
            int n = 0;
            int[] chs = new int[10000];
            int ch;
            while ((ch = in.read()) != -1) {
                chs[n++] = ch;
            }
            for (int i = n - 1; i >= 0; i--) {
                out.write(chs[i]);
            }
            in.close();
            out.close();
        } catch (IOException e) {
        }
    }

    public static void main(String[] args) {
        new ReverseString();
    }
}
