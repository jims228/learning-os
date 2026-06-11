public class FileManagerApplication{
    public FileManagerApplication(){
        File file1 = new File("memo", 80);
        File file2 = new File("Robot.java", 322);
        File file3 = new File("RobotSimulator.java", 548);
        File file4 = new File("p1", 288);
        File file5 = new File("p2", 331);
        File file6 = new File("p3", 20);
        Directory dir1 = new Directory("Java1");
        Directory dir2 = new Directory("Ex01");
        Directory dir3 = new Directory("Ex02");
        Directory dir4 = new Directory("BACKUP");
        dir1.add(file1);
        dir1.add(dir2);
        dir1.add(dir3);
        dir2.add(file2);
        dir2.add(file3);
        dir2.add(dir4);
        dir4.add(file4);
        dir4.add(file5);
        dir4.add(file6);
        dir1.display();
        dir2.display();
        file2.rename("SuperRobot.java");
        dir1.add(new File("score", 100));
        dir1.display();
        dir2.display();
    }
    public static void main(String[] args){
        new FileManagerApplication();
    }
}
