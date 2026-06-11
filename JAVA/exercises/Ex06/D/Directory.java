public class Directory extends Entity {
    private Entity[] entities = new Entity[100];
    private int numberOfEntity = 0;

    public Directory(String name){
        super(name, 0);
    }

    public int getSize(){
        int total = 0;
        for(int i = 0; i < numberOfEntity; i++){
            total += entities[i].getSize();
        }
        return total;
    }

    public void add(Entity e){
        entities[numberOfEntity++] = e;
    }

    public void display(){
        for(int i = 0; i < numberOfEntity; i++){
            System.out.print(entities[i].getName() + " ");
        }
        System.out.println();
        System.out.println(this.getSize() + " bytes");
    }
}
