//----------------Mesh Solve----------------------------------------------------------------------------------------------------------------------
  void wallMazeSolve(void)
  {
# define NO_WALL 8
# define CONT_WALL 9
# define RIGHT_TURN_IN_WALL 10
# define LEFT_TURN_IN_WALL 11
    
    while (!status)
    {
      if(roboInLine()){
        lineMazeSolve();
        break;
        }
        
      wallJunction();
      switch (mode)
      {
        case NO_WALL:
          brake();
          delay(50);
          wallJunction();
          if(mode != NO_WALL ){break;}
          centerAtWall();
          turnInWall('B');
          centerAtWall();
         // recIntersection('B');
          delay(20);
          followingWall();
          break;

        case CONT_WALL:
          brake();
          delay(50);
          wallJunction();
          if(mode != CONT_WALL ){break;}
          centerAtJunction(200);
          turnInWall('L');
          centerAtJunction(200);
          followingWall();
          break;

        case RIGHT_TURN_IN_WALL:
          brake();
          delay(50);
          wallJunction();
          if(mode != RIGHT_TURN_IN_WALL ){break;}
          centerAtJunction();
          LineJunction();
          if (mode == NO_LINE) {
            turnInLine('R');
 //           /*90 degrees*/ recIntersection('R'); Serial.print("R");
          }
          else {
            followingLine();
//            recIntersection('S');
          }
          break;

        case LEFT_TURN_IN_WALL:
          brake();
          delay(50);
          LineJunction();
          if(mode != LEFT_TURN ){break;}
          centerAtJunction(200);
          delay(20);
          turnInLine('T');
          delay(20);
          brake();
//          recIntersection('L'); Serial.print("L");
          break;

        case FOLLOWING_LINE:
          followingLine();
          break;

      }
    }
  }

