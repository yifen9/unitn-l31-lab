public class Test {
    public static void main(String[] args) {
        Bike bk01 = new Bike("SCOTT Performance",60,Bike.bikeType.MTB);
        Ebike bk02 = new Ebike("FOCUS",80,Bike.bikeType.MTB,250);
        Bike bk03 = new Ebike("SCOTT SuperElect",76,Bike.bikeType.ROAD,150);

        System.out.println(bk01);
        System.out.println(bk02);
        System.out.println(bk03);
    }
}