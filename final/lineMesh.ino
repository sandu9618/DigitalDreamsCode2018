//----------------Mesh Solve----------------------------------------------------------------------------------------------------------------------
  void lineMazeSolve(void)
  {
    while (!status)
    {
      LineJunction();
      switch (mode)
      {
        case NO_LINE:
          brake();
          delay(50);
          LineJunction();
          if(mode != NO_LINE ){break;}
          centerAtJunction();
          if(roboInWall()){    
            //wall mesh
          }
          else{ turnInLine('B');}         
          recIntersection('B');
          delay(20);
          followingLine();
          break;

        case CONT_LINE:
          brake();
          delay(50);
          LineJunction();
          if(mode != CONT_LINE ){break;}
          centerAtJunction(200);
          LineJunction();
          delay(20);
          if (mode!=CONT_LINE) {
          recIntersection('L');
          turnInLine('T');
//            /*90 degrees*/ recIntersection('L'); Serial.print("L"); // or it is a "T" or "Cross"). In both cases, goes to LEFT
          }
          else mazeEnd();
          break;

        case RIGHT_TURN:
          brake();
          delay(50);
          LineJunction();
          if(mode != RIGHT_TURN ){break;}
          centerAtJunction();
          LineJunction();
          if (mode == NO_LINE) {
            turnInLine('R');
            recIntersection('R');
 //           /*90 degrees*/ recIntersection('R'); Serial.print("R");
          }
          else {
            followingLine();
            recIntersection('S');
          }
          break;

        case LEFT_TURN:
          brake();
          delay(50);
          LineJunction();
          if(mode != LEFT_TURN ){break;}
          centerAtJunction(200);
          delay(20);
          turnInLine('T');
          recIntersection('L');
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







  //------------------------------------------------------------------------
  void recIntersection(char direction)
  {
    path[pathLength] = direction; // Store the intersection in the path variable.
    pathLength ++;
    simplifyPath(); // Simplify the learned path.
  }
  //--------------------------------------------------------------------------

  void mazeEnd(void)
  {
    mode = STOPPED;
    beep();
    delay(3000);
    motorStop();
    for (int i = 0; i < pathLength; i++)
    status = 1;

  }
  void gohome(void)
  {
    motorStop();
    for (int i = 0; i < pathLength; i++)
      Serial.print(path[i]);
    Serial.print("  pathLenght ==> ");
    Serial.println(pathLength);
    a = 1;
    mode = STOPPED;
  }
  //--------------------------------------------------------------------------

  void simplifyPath()
  {
    // only simplify the path if the second-to-last turn was a 'B'
    if (pathLength < 3 || path[pathLength - 2] != 'B')
      return;

    int totalAngle = 0;
    int i;
    for (i = 1; i <= 3; i++)
    {
      switch (path[pathLength - i])
      {
        case 'R':
          totalAngle += 90;
          break;
        case 'L':
          totalAngle += 270;
          break;
        case 'B':
          totalAngle += 180;
          break;
      }
    }

    // Get the angle as a number between 0 and 360 degrees.
    totalAngle = totalAngle % 360;

    // Replace all of those turns with a single one.
    switch (totalAngle)
    {
      case 0:
        path[pathLength - 3] = 'S';
        break;
      case 90:
        path[pathLength - 3] = 'R';
        break;
      case 180:
        path[pathLength - 3] = 'B';
        break;
      case 270:
        path[pathLength - 3] = 'L';
        break;
    }

    // The path is now two steps shorter.
    pathLength -= 2;

  }

  //------------------------------------------------------------------------------

  void mazeOptimization (void)
  {
    while (!a)
    {
      //readLFSsensors();
      LineJunction();
      switch (mode)
      {
        case FOLLOWING_LINE:
          followingLine();
          break;
        case CONT_LINE:
          if (pathIndex >= pathLength) gohome ();
          else {
            mazeTurn (path[pathIndex]);
            pathIndex++;
          }
          break;
        case LEFT_TURN:
          if (pathIndex >= pathLength) gohome ();
          else {
            mazeTurn (path[pathIndex]);
            pathIndex++;
          }
          break;
        case RIGHT_TURN:
          if (pathIndex >= pathLength) gohome ();
          else {
            mazeTurn (path[pathIndex]);
            pathIndex++;
          }
          break;
      }
    }
  }




  void mazeTurn (char dir)
  {
    switch (dir)
    {
      case 'L': // Turn Left
//        brake();
//        centerAtJunction();
//        brake();
//        turnInLine('L');
//        break;
          brake();
          delay(50);
          LineJunction();
          if(mode != LEFT_TURN ){break;}
          centerAtJunction(200);
          delay(20);
          turnInLine('T');
          delay(20);
          brake();

      case 'R': // Turn Right
//        brake();
//        centerAtJunction();
//        brake();
////        junctionDT();
//        if (mode == NO_LINE) {
//          turnInLine('R');
//          break;
          brake();
          delay(50);
          LineJunction();
          if(mode != RIGHT_TURN ){break;}
          centerAtJunction();
          LineJunction();
          if (mode == NO_LINE) {
            turnInLine('R');
          }
          else {
            followingLine();
          }
          break;

        case 'B': // Turn Back
          brake();
          delay(50);
          LineJunction();
          if(mode != NO_LINE ){break;}
          centerAtJunction();
          if(roboInWall()){    
            //wall mesh
          }
          else{ turnInLine('B');}         
          delay(20);
          followingLine();
          break;

        case 'S': // Go Straight
          followingLine();
          break;
        }
    }
  

