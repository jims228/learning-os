class XYComparator implements PointComparator {
    public int compare(Point p1, Point p2){
        if(p1.getX() < p2.getX()) return -1;
        if(p1.getX() > p2.getX()) return 1;
        if(p1.getY() < p2.getY()) return -1;
        if(p1.getY() > p2.getY()) return 1;
        return 0;
    }
}
