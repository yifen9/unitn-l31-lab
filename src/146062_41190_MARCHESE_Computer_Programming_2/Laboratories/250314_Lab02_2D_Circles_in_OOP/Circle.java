/** This is a Class to define a Circle in 2D space
 */
public class Circle {
    private String name;
    private double x;
    private double y;
    private double r;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double getR() {
        return r;
    }

    public void setR(double r) {
        this.r = r;
    }

    public Circle(String name, double x, double y, double r) {
        this.x = x;
        this.y = y;
        this.r = r;
        this.name = name;
        //name.compareToIgnoreCase(str:"camera");
    }

    /** Compute the distance between the current circle and the Circle c2
     *
     * @param c2 the other circle
     * @return the distance between the centers
     */
    private double centerDistance(Circle c2){
        double dist = Math.sqrt(
                Math.pow((this.x - c2.getX()),2) + Math.pow((this.y - c2.getY()),2)
        );
        return dist;
    }

    /** Checks if the current circle intersects the other
     *
     * @param c2 the other circle
     * @return true/false intersection
     */
    public boolean isIntersecting(Circle c2){
        double dist = this.centerDistance(c2);

        if(dist <= (this.r + c2.getR())){
            return true;
        }

        return false;
    }

    /** Check if current circle is inside c2
     *
     * @param c2 the other circle
     * @return true/false if the current is inside the c2
     */
    public boolean isInside(Circle c2){
        double dist = this.centerDistance(c2);

        if(dist <= (c2.getR() - this.r)){
            return true;
        }

        return false;
    }

    public boolean isTouching(Circle c2){
        double dist = this.centerDistance(c2);

        if(dist == (c2.getR() + this.r)){
            return true;
        }

        return false;
    }

    public void checkAll(Circle c2){
        System.out.println("intersect between " + this.getName() + " and " + c2.getName() + " is " + this.isIntersecting(c2));
        System.out.println("check for inside between " + this.getName() + " and " + c2.getName() + " is " + this.isInside(c2));
        System.out.println("check for touching between " + this.getName() + " and " + c2.getName() + " is " + this.isTouching(c2));
    }

    @Override
    public String toString() {
        return "Circle{" +
                "name='" + name + '\'' +
                ", x=" + x +
                ", y=" + y +
                ", r=" + r +
                '}';
    }

    public static void main(String[] args) {
        Circle c1 = new Circle("Particle01",0,0,1);
        Circle c2 = new Circle("Particle02",2,0,1);
        Circle c3 = new Circle("Particle03",2,2,1.3);
        Circle c4 = new Circle("Particle04",2,2,2);

        System.out.println(c1);
        System.out.println(c2);
        System.out.println(c3);
        System.out.println(c4);

        c1.checkAll(c2);
        c1.checkAll(c3);
        c1.checkAll(c4);
        c2.checkAll(c3);
        c2.checkAll(c4);
        c3.checkAll(c4);
    }
}