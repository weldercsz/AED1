import java.awt.*;

public class Solid extends SceneObject{

    private int X, Y;

    private boolean colliding;

    private Gate gate;

    public Solid(int x, int y, int xaxis, int yaxis, int width, int height, Color color){
        this.X = x;
        this.x = x + xaxis;
        this.Y = y;
        this.y = y + yaxis;
        this.width = width;
        this.height = height;
        this.color = color;
        this.colliding = true;
    }

    public Solid(int x, int y, int xaxis, int yaxis, int width, int height, Color color, boolean colliding){
        this.X = x;
        this.x = x + xaxis;
        this.Y = y;
        this.y = y + yaxis;
        this.width = width;
        this.height = height;
        this.color = color;
        this.colliding = colliding;
    }

    @Override
    public void render(Graphics2D g2d) {
        g2d.setColor(color);
        g2d.fillRect(x, y, width, height);
    }

    public void move(int xaxis, int yaxis){
        /*
        if (EventHandler.isUp()) {
            //y += yaxis;
            y = Y + yaxis;
        }

        if (EventHandler.isDown()) {
            //if(!Camera.getCollisionStatus()) y -= yaxis;
            //else y += yaxis;
            y = Y - yaxis;
        }

        if (EventHandler.isLeft()) {
            //x += xaxis;
            x = X + xaxis;
        }

        if (EventHandler.isRight()) {
            //if(!Camera.getCollisionStatus()) x -= xaxis;
            //else x += xaxis;
            x = X - xaxis;
        }*/
        y = Y + yaxis;
        x = X + xaxis;


        if(gate != null){
            checkGateStatus(Camera.getPlayerX(), Camera.getPlayerY(), Camera.getPlayerXOffset(), Camera.getPlayerYOffset());
        }
    }

    private void checkGateStatus(int x, int y, int xoffset, int yoffset){
        if(x < getXOffset() && xoffset > getX() && y < getYOffset() && yoffset > getY()){
            Gate.going_to[0] = Gate.now[0].equals(gate.getSide1()[0]) ? gate.getSide2()[0] : gate.getSide1()[0];
            Gate.going_to[1] = Gate.now[1].equals(gate.getSide1()[1]) ? gate.getSide2()[1] : gate.getSide1()[1];

            Gate.instance = gate.hashCode();

            if (EventHandler.isUp()) {
                Gate.direction = ObjectStatus.NORTH;
            }
            else if (EventHandler.isDown()) {
                Gate.direction = ObjectStatus.SOUTH;
            }
            else if (EventHandler.isLeft()) {
                Gate.direction = ObjectStatus.WEST;
            }
            else if (EventHandler.isRight()) {
                Gate.direction = ObjectStatus.EAST;
            }
        }


    }



    public int[] isCollided(int x, int y, int xoffset, int yoffset){

        int[] results = new int[3];

        if(EventHandler.isUp() && x < getXOffset() && xoffset > getX()){

          if(y-10 < getYOffset() && yoffset > getY()){

            results[0] = 1;
            results[1] = getYOffset();
            results[2] = 1;
          }
          else{
            results[0] = 0;
            results[2] = 0;
          }
            
        }
        else if(EventHandler.isDown() && x < getXOffset() && xoffset > getX()){
          if(y < getYOffset() && yoffset+10 > getY()){

            results[0] = 1;
            results[1] = getY();
            results[2] = 3;
          }
          else{
            results[0] = 0;
            results[2] = 0;
          }
          
        }
        else if(EventHandler.isLeft() && y < getYOffset() && yoffset > getY()){
          if(x-10 < getXOffset() && xoffset > getX()){

            results[0] = 1;
            results[1] = getXOffset();
            results[2] = 4;
          }
          else{
            results[0] = 0;
            results[2] = 0;
          }
          
        }
        else if(EventHandler.isRight() && y < getYOffset() && yoffset > getY()){
          if(x < getXOffset() && xoffset+10 > getX()){

            results[0] = 1;
            results[1] = getX();
            results[2] = 2;
          }
          else{
            results[0] = 0;
            results[2] = 0;
          }
          
        }

        return results;
    }



    public boolean isColliding() {
        return colliding;
    }

    public void addGate(Gate gate){
        this.gate = gate;
    }

    public Gate getGate(){
        return gate;
    }


    public int getAbsoluteX() {
        return X;
    }

    public int getAbsoluteY() {
        return Y;
    }

    public int getAbsoluteXOffset() {
        return X + width;
    }

    public int getAbsoluteYOffset() {
        return Y + height;
    }
}
