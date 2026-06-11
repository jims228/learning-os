import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Lane {
    Queue<Integer> cars = new LinkedList<>();
    void enqueue(int car){ cars.add(car); }
    int dequeue(){ return cars.poll(); }
    int size(){ return cars.size(); }
}

class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int Q = sc.nextInt();
        Lane[] lanes = new Lane[N];
        for(int i = 0; i < N; i++) lanes[i] = new Lane();

        for(int i = 0; i < Q; i++){
            int type = sc.nextInt();
            int x = sc.nextInt();
            if(type == 1){
                int minLane = 0;
                for(int j = 1; j < N; j++){
                    if(lanes[j].size() < lanes[minLane].size()) minLane = j;
                }
                lanes[minLane].enqueue(x);
            } else {
                System.out.println(lanes[x-1].dequeue());
            }
        }
    }
}
