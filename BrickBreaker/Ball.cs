using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace BrickBreaker
{
    public class Ball
    {
        public string futureCollision = "safe";
        Rectangle futureRectCol;

        public int x, y, xSpeed, ySpeed, size;
        public Color colour;
      

        public static Random rand = new Random();

        public Ball(int _x, int _y, int _xSpeed, int _ySpeed, int _ballSize)
        {
            x = _x;
            y = _y;
            xSpeed = _xSpeed;
            ySpeed = _ySpeed;
            size = _ballSize;
        }

        public void Move()
        {
            x = x + xSpeed;
            y = y + ySpeed;

            if (futureCollision != "safe")
            {
                if (futureCollision == "left")
                {
                    xSpeed = -Math.Abs(xSpeed);
                    x = futureRectCol.X - size;
                }
                else if (futureCollision == "right")
                {
                    xSpeed = Math.Abs(xSpeed);
                    x = futureRectCol.X + futureRectCol.Width;
                }
                else if (futureCollision == "top")
                {
                    ySpeed = -Math.Abs(ySpeed);
                    y = futureRectCol.Y - size;
                }
                else if (futureCollision == "bottom")
                {
                    ySpeed = Math.Abs(ySpeed);
                    y = futureRectCol.Y + futureRectCol.Height;
                }
                futureCollision = "safe";
            }
        }

        public string Collision(Rectangle collisionRec, Rectangle blockRec)
        {
            // Check what side the collision is on
            if (collisionRec.IntersectsWith(new Rectangle(blockRec.X, blockRec.Y + blockRec.Height - 5, blockRec.Width, 5)))
            {
                return "bottom";
            }
            else if (collisionRec.IntersectsWith(new Rectangle(blockRec.X, blockRec.Y, blockRec.Width, 5)))
            {
                return "top";
            }
            else if (collisionRec.IntersectsWith(new Rectangle(blockRec.X, blockRec.Y, 5, blockRec.Height)))
            {
                return "left";
            }
            else if (collisionRec.IntersectsWith(new Rectangle(blockRec.X + blockRec.Width - 5, blockRec.Y, 5, blockRec.Height)))
            {
                return "right";
            }
            return "safe";
        }

        public bool BlockCollision(Block b, bool krabbyPatty)
        {
            Rectangle blockRec = new Rectangle(b.x, b.y, b.width, b.height);
            Rectangle futureBallRec = new Rectangle(x + xSpeed, y + ySpeed, size, size);
            if (!krabbyPatty)
            {   
                if (Collision(futureBallRec, blockRec) != "none")
                {
                    futureCollision = Collision(futureBallRec, blockRec);
                    futureRectCol = new Rectangle(x, y, size, size);
                }
            }
            return futureBallRec.IntersectsWith(blockRec);
        }

        public void PaddleCollision(Paddle p, bool left, bool right)
        {
            Rectangle ballRec = new Rectangle(x, y, size, size);
            Rectangle paddleRec = new Rectangle(p.x, p.y, p.width, p.height);

            if (ballRec.IntersectsWith(paddleRec) && ySpeed >= 0)
            {
                ySpeed *= -1;
                xSpeed += rand.Next(-3, -1);

                if (left) { xSpeed = -Math.Abs(xSpeed); }
                if (right) { xSpeed = Math.Abs(xSpeed); }             
            }
            if (ballRec.IntersectsWith(paddleRec) && GameScreen.rightArrowDown == false && GameScreen.leftArrowDown == false)
            {
                var ballPosition = x - p.x;
                var hitPercent = (ballPosition / (p.width - size)) - .5;
                xSpeed = (int)(hitPercent * 10);
                ySpeed *= 1;
            }
        }

        public void WallCollision(UserControl UC)
        {
            // Collision with left wall
            if (x <= 0)
            {
                xSpeed *= -1;
                ySpeed += rand.Next(1, 4);
            }
            // Collision with right wall
            if (x >= (UC.Width - size))
            {
                xSpeed *= -1;
                ySpeed += rand.Next(1, 4);
            }
            // Collision with top wall
            if (y <= 1)
            {
                ySpeed *= -1;
                y = 2;
                xSpeed += rand.Next(-3, -1);
            }
        }

        public bool BottomCollision(UserControl UC)
        {
            Boolean didCollide = false;

            if (y >= UC.Height)
            {
                didCollide = true;
            }

            return didCollide;
        }
    }
}
