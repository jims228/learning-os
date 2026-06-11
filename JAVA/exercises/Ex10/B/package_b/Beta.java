package package_b;

import package_a.Alpha;
import package_a.Gamma;

public class Beta extends Alpha {
    private int y = 30;

    public void show(Gamma g) {
        System.out.println("Beta");
        System.out.println("u: " + u);
        System.out.println("v: " + g.v);
        System.out.println("y: " + y);
        System.out.println();
    }
}
