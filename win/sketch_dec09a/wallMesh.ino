//----------------Mesh Solve----------------------------------------------------------------------------------------------------------------------
  void wallMazeSolve(void)
  {  
    while (!status)
    {
      if( roboInLine()  ) {    
        centerAtJunction(20);
        if( !colorSeted() ){ lineMazeSolve();break; }    
        }
      else {
      wallJunction();
        if( (L) && (!R) && (!T) ) { // L
          brake();
          delay(500);
          if( !((L) && (!R) && (!T)) ){wallMazeSolve();}
          centerAtWall(540);
          brake();
          checkColor();
          delay(500);
          turnInWall('L');                                               // turned to left
          delay(500);
          goToWall();
          delay(500);
          followingWall();
          }
          
        else if( (!L) && (R) && (!T) ){ //R
          brake();
          delay(500);
          if( !((!L) && (R) && (!T)) ){wallMazeSolve();}
          centerAtWall();
          checkColor();
          delay(500);
          findWall();
          if(!FW){goToWall();delay(500);followingWall();}                        //go in strate line
          else{ turnInWall('R');delay(500); goToWall();delay(500);followingWall(); }        // turned to right
          }
          
        else if ( (!L) && (!R) && (T) ){ // T
         
          brake();
          delay(50);
          delay(500);
       
          if( !((!L) && (!R) && (T) )){wallMazeSolve();}


          goToWall(230);
          checkColor();
          turnInWall('L');
          delay(500);
          goToWall(550);delay(500);
          if(roboInWall()){ followingWall(); }                           // turned to left
          else{
             turnInWall('B');                                            // ded end
             delay(50);
             goToWall();
             delay(50);
             turnInWall('R');
             goToWall();
             delay(50);
             followingWall();
            }
          }
          
        else{ // nor junction
          followingWall();
          } 
        } 
    }
  }

