#include "devices.hpp"
#include "autons.hpp"
#include "drivercontrol.hpp"

void doNothing() {}

// function definitions

//       chassis.setPose(x, y, theta); 
//       chassis.turnTo(x, y, timeout);    
//       chassis.follow(path file, timeout, lookahead distance, isAsynchronous, forwards (false makes the robot run the path backwards));
//
//       chassis.waitUntil(inches); use this to have your bot wait until the path is finished
//       a really big number means just wait until the path has finished


const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;

void skills() {


    intake = -127; //Drop intake


   //Start slightly angled along matchload bar with back facing goal

    EzTempChassis.drive_angle_set(-60);
    EzTempChassis.pid_drive_set(-30, 120, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-28);

    intake=0;

    EzTempChassis.pid_drive_set(12, 120, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(10);

    EzTempChassis.pid_turn_set(13, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(11);

    //Back into matchload bar
    EzTempChassis.pid_drive_set(-5, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    // Matchloading segment
    // setSlapHang(-100);
    // // intake = 100;

    // Code for degree
    // while(slapHang1.get_position() < 16560 + 90) {
    //     setSlapHang(-63);
    //     pros::delay(10); // Small delay to prevent hogging CPU
    // }
    // setSlapHang(0);

    // Code for delay
    setSlapHang(-80);
    pros::delay(27000);
    setSlapHang(0);


    // // Redudant Check
    // EzTempChassis.drive_angle_set(19);


    intake=-127;


    EzTempChassis.pid_drive_set(25, DRIVE_SPEED, true);
    pros::delay(100);
    EzTempChassis.pid_wait_until(23);

    //Swing to first triball
    EzTempChassis.pid_swing_set(RIGHT_SWING, -42, 110, 55);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-37);

    EzTempChassis.pid_drive_set(-19, DRIVE_SPEED, true);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-17);

    //Swing parallel to barrier
    EzTempChassis.pid_swing_set(LEFT_SWING, 85, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(83);

    //set right wing true
    horzwing2.set_value(true);
    intake = 127;

    //ram into short barrier
    EzTempChassis.pid_drive_set(64, DRIVE_SPEED, true);
    pros::delay(100);
    EzTempChassis.pid_wait_until(62);

    //ram again
    EzTempChassis.pid_drive_set(-13, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-10);
    horzwing2.set_value(false);
    EzTempChassis.pid_drive_set(15, 40, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(13);

    pros::delay(100);

    EzTempChassis.pid_turn_set(181, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(179);

    intake = 0;

    horzwing2.set_value(true);
    

    //Swing around into aisle
    EzTempChassis.pid_swing_set(ez::RIGHT_SWING, 0, SWING_SPEED, 28);
    pros::delay(100);
    EzTempChassis.pid_wait_until(5);

    intake = 127;

    // Go down aisle
    EzTempChassis.pid_drive_set(70, DRIVE_SPEED, true);
    pros::delay(100);
    EzTempChassis.pid_wait_until(68);
    
    horzwing2.set_value(false);
    horzwing1.set_value(true);

    EzTempChassis.pid_swing_set(ez::RIGHT_SWING, -90, SWING_SPEED, 40);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-85);

    // Push into side goal
    EzTempChassis.pid_drive_set(12, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(10);
    
    EzTempChassis.pid_drive_set(-15, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-13);
    
    //Repush
    EzTempChassis.pid_drive_set(15, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(13);

   EzTempChassis.pid_drive_set(-7, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-5);

    horzwing1.set_value(false);


    // Turn towards center
    EzTempChassis.pid_turn_set(-157, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(48, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(44);

    EzTempChassis.pid_turn_set(-205, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-200);

    intake = 0;
    //----------------
    //FIRST FRONT PUSH
    //----------------
    toggleVertWings();
    
    //Push
    EzTempChassis.pid_drive_set(-37, 100, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-35);

    //Back up
    EzTempChassis.pid_drive_set(14, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(12);

    //Repush
    EzTempChassis.pid_drive_set(-14, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-12);
    toggleVertWings();


    //MANUEVER TO 2nd PUSH
    EzTempChassis.pid_drive_set(30, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(28);
    
    //Turn
    EzTempChassis.pid_turn_set(-270, DRIVE_SPEED,false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-265);
    toggleVertWings();

    EzTempChassis.pid_drive_set(-25, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-22);

    //-----------------
    //SECOND FRONT PUSH (Half push)
    //-----------------
    //Point to goal
    EzTempChassis.pid_turn_set(-180, -DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(177);
    //PUSH
    EzTempChassis.pid_drive_set(-32, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-30);
    //REPUSH
    EzTempChassis.pid_drive_set(15, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(12);
    EzTempChassis.pid_drive_set(-15, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-12);
    toggleVertWings(); //off

    // Maneuver to Third FULL push
    EzTempChassis.pid_drive_set(32, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(30);

    EzTempChassis.pid_turn_set(-95, DRIVE_SPEED, 40);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-90);

    EzTempChassis.pid_drive_set(35, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(33);

    EzTempChassis.pid_turn_set(-160, -DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-143);


    //-----------------
    //THIRD FRONT PUSH
    //-----------------

    //Push
    toggleVertWings();
    EzTempChassis.pid_drive_set(-35, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-33);

    //Repush
    EzTempChassis.pid_drive_set(16, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(14);
    EzTempChassis.pid_drive_set(-16, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-14);


    // Maneuver to C push
    EzTempChassis.pid_drive_set(20, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(18);
    toggleVertWings(); //off
    toggleHorzWings(); //off

    EzTempChassis.pid_turn_set(-60, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-65);

    EzTempChassis.pid_drive_set(22, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(20);
    toggleHorzWings(); //on

    intake = 20;

    //------------
    //C PUSH
    //------------
    EzTempChassis.pid_swing_set(ez::LEFT_SWING, 90, DRIVE_SPEED, 40);
    pros::delay(100);
    EzTempChassis.pid_wait_until(133);

    intake = 0;

    EzTempChassis.pid_drive_set(15, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(12);

    EzTempChassis.pid_drive_set(-15, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(12);

    EzTempChassis.pid_drive_set(-15, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-12);


    
    



    // Old Route
    // EzTempChassis.pid_turn_set(-45, DRIVE_SPEED);
    // pros::delay(100);
    // EzTempChassis.pid_wait();

    // EzTempChassis.pid_drive_set(10, DRIVE_SPEED, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait();

    // EzTempChassis.pid_turn_set(-180, DRIVE_SPEED);
    // pros::delay(100);
    // EzTempChassis.pid_wait();

    // //Old code for front side down aisle:
    // // EzTempChassis.pid_swing_set(ez::LEFT_SWING, 0, DRIVE_SPEED, 75);
    // // pros::delay(100);
    // // EzTempChassis.pid_wait_until(0);


    // //Go down aisle
    // EzTempChassis.pid_drive_set(-70, DRIVE_SPEED, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait();

    // vertwing1.set_value(true);

    // EzTempChassis.pid_swing_set(ez::RIGHT_SWING, 90, DRIVE_SPEED);
    // pros::delay(100);
    // EzTempChassis.pid_wait_until(0);

    // EzTempChassis.pid_drive_set(-10, DRIVE_SPEED, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait();

    // EzTempChassis.pid_drive_set(8, DRIVE_SPEED, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait();

    // EzTempChassis.pid_turn_set(145, DRIVE_SPEED);
    // pros::delay(100);
    // EzTempChassis.pid_wait();

    // EzTempChassis.pid_drive_set(43, DRIVE_SPEED, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait_until(10);
    // vertwing2.set_value(true);
    // EzTempChassis.pid_wait();

    // toggleVertWings();

    // //V push 1
    // EzTempChassis.pid_turn_set(205, DRIVE_SPEED);
    // pros::delay(100);
    // EzTempChassis.pid_wait();

    // toggleVertWings();

    // EzTempChassis.pid_drive_set(-48, DRIVE_SPEED, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait();

    // EzTempChassis.pid_turn_set(180, DRIVE_SPEED);
    // pros::delay(100);
    // EzTempChassis.pid_wait();

    // EzTempChassis.pid_drive_set(19, DRIVE_SPEED, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait_until(3);
    // toggleVertWings();
    // EzTempChassis.pid_wait();


    // //V Push 2
    // EzTempChassis.pid_swing_set(ez::RIGHT_SWING, 90, DRIVE_SPEED);
    // pros::delay(100);
    // EzTempChassis.pid_wait();

    // EzTempChassis.pid_drive_set(36, DRIVE_SPEED, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait();

    // EzTempChassis.pid_turn_set(147.5, DRIVE_SPEED);
    // pros::delay(100);
    // EzTempChassis.pid_wait();

    // toggleVertWings();

    // EzTempChassis.pid_drive_set(-48, DRIVE_SPEED, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait();

    // toggleVertWings();

    // EzTempChassis.pid_turn_set(180, DRIVE_SPEED);
    // pros::delay(100);
    // EzTempChassis.pid_wait();

    // EzTempChassis.pid_drive_set(6, DRIVE_SPEED, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait_until(3);
    // toggleVertWings();
    // EzTempChassis.pid_wait();

    // EzTempChassis.pid_turn_set(90, DRIVE_SPEED);
    // pros::delay(100);
    // EzTempChassis.pid_wait();

    // EzTempChassis.pid_drive_set(48, DRIVE_SPEED, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait();



}

// example auto for clearing matchload area and touching pole
void leftSideQual() {
    intake = 127;
    EzTempChassis.pid_drive_set(-13, DRIVE_SPEED,false);
    pros::delay(400);
    intake = 0;
    EzTempChassis.pid_wait_until(-12);

    EzTempChassis.pid_swing_set(ez::RIGHT_SWING, 45, DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait();
    //push in preload
    EzTempChassis.pid_drive_set(-12.45, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait();


    EzTempChassis.pid_drive_set(11.15, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_turn_set(-135, 60, true);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(-4, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_swing_set(ez::LEFT_SWING, -180, 80);
    pros::delay(200);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(-18, 80, false);
    vertwing1.set_value(true);
    pros::delay(100);
    EzTempChassis.pid_wait();


    EzTempChassis.pid_drive_set(4, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();
    vertwing1.set_value(false);

    //Sweep matchload ball
    EzTempChassis.pid_swing_set(ez::LEFT_SWING, -225, 60); //Turns and pushes the ball out
    pros::delay(100);
    EzTempChassis.pid_wait();


    // //Go down aisle
    EzTempChassis.pid_drive_set(-35, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(30);
    EzTempChassis.pid_drive_set(9.5, DRIVE_SPEED, false);
    EzTempChassis.pid_wait_until(6);
    EzTempChassis.pid_turn_set(-45, TURN_SPEED, false);
    EzTempChassis.pid_wait();
    pros::delay(400);
    //touch bar
    EzTempChassis.pid_drive_set(14, DRIVE_SPEED, false);
    EzTempChassis.pid_wait();
    intake = 127;

    pros::delay(5000);
    intake = 0;
}

void leftSideElims() {
    // Get mid ball 
    // horzwing.set_value(true);
    intake = -10;
    setSlapHang(35);
    EzTempChassis.pid_drive_set(51.7, 127, false);

    EzTempChassis.pid_wait_until(25);
    intake = -127;
    setSlapHang(0);
    // horzwing.set_value(false);
    // EzTempChassis.pid_wait_until(42);
    // EzTempChassis.pid_drive_set(15, 127, false);
    EzTempChassis.pid_wait();

    //Back
    EzTempChassis.pid_drive_set(-51.7, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-50);

    EzTempChassis.pid_turn_set(77, TURN_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(75);

    intake = 127;
    pros::delay(500);

    // EzTempChassis.pid_drive_set(-2, DRIVE_SPEED, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait();


//BAR
    EzTempChassis.pid_swing_set(ez::RIGHT_SWING, 115, -DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(-18, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-16);

    EzTempChassis.pid_swing_set(ez::RIGHT_SWING, 161, -DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait_until(159);
    
    //score alliance triball
    EzTempChassis.pid_drive_set(-11.25, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait();
    pros::delay(200);

    // EzTempChassis.pid_drive_set(3, DRIVE_SPEED, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait();

    // EzTempChassis.pid_drive_set(-6, 127, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait();
    // pros::delay(200);

    EzTempChassis.pid_drive_set(7, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_swing_set(ez::RIGHT_SWING, 115, -DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(17, 70, false);
    pros::delay(100);
    EzTempChassis.pid_wait();
    intake = 127;

    EzTempChassis.pid_swing_set(ez::RIGHT_SWING, 75, -DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait();
//Go down aisle
    EzTempChassis.pid_drive_set(34.8, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(-40, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    // EzTempChassis.pid_swing_set(ez::RIGHT_SWING, -15, -DRIVE_SPEED);
    // pros::delay(100);
    // EzTempChassis.pid_wait();

    // EzTempChassis.pid_drive_set(30, DRIVE_SPEED, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait();

    pros::delay(5000);
    intake = 0;

}





void rightSideQuals() {
    // lower intake
    intake = -127;

    EzTempChassis.pid_drive_set(-12, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_swing_set(ez::LEFT_SWING, -45, DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(-17, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(13, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_swing_set(ez::LEFT_SWING, 0, DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(20, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_swing_set(ez::LEFT_SWING, 45, DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(40, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(-30, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_turn_set(225, DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(8, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    toggleVertWings();
    EzTempChassis.pid_swing_set(ez::RIGHT_SWING, 180, DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(12, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_turn_set(135, TURN_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait();
    toggleVertWings();

    EzTempChassis.pid_drive_set(-6, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_turn_set(180, TURN_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait();

    intake = 127;
    EzTempChassis.pid_drive_set(20, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_swing_set(ez::RIGHT_SWING, 135, DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(16, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_swing_set(ez::RIGHT_SWING, 180, DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(-22, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-20);

    EzTempChassis.pid_turn_set(97, TURN_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait_until(95);

    intake = -127;
    EzTempChassis.pid_drive_set(57, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(55);

    EzTempChassis.pid_turn_set(227, TURN_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait_until(225);

    EzTempChassis.pid_drive_set(48, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(12);
    intake = 127;
    EzTempChassis.pid_wait();
}

void rightSideQualsTouchBar() {
    // lower intake
    intake = -127;

    EzTempChassis.pid_drive_set(-12, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_swing_set(ez::LEFT_SWING, -45, DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(-17, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(13, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_swing_set(ez::LEFT_SWING, 0, DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(20, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_swing_set(ez::LEFT_SWING, 45, DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(40, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(-30, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_turn_set(225, DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(8, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    toggleVertWings();
    EzTempChassis.pid_swing_set(ez::RIGHT_SWING, 180, DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(12, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_turn_set(135, TURN_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait();
    toggleVertWings();

    EzTempChassis.pid_drive_set(-6, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_turn_set(180, TURN_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait();

    intake = 127;
    EzTempChassis.pid_drive_set(20, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_swing_set(ez::RIGHT_SWING, 137, DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait_until(135);

    EzTempChassis.pid_drive_set(16, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(-12, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-10);


    EzTempChassis.pid_turn_set(47, TURN_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait_until(45);

    intake = 0;
    EzTempChassis.pid_drive_set(52, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(50);

    toggleVertWings();
    EzTempChassis.pid_turn_set(92, TURN_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait_until(90);
}

void rightSideFarRush() {
    EzTempChassis.drive_angle_set(60);
    toggleHorzWings();
    intake = -127;
    EzTempChassis.pid_drive_set(63, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(10);
    toggleHorzWings();
    EzTempChassis.pid_wait_until(61);

    EzTempChassis.pid_turn_set(180, 127);
    pros::delay(100);
    EzTempChassis.pid_wait_until(178);

    toggleHorzWings();

    EzTempChassis.pid_drive_set(30, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(12);
    intake = 127;
    EzTempChassis.pid_wait_until(28);
    

    EzTempChassis.pid_drive_set(-6, DRIVE_SPEED, false);
    EzTempChassis.pid_wait_until(-4);
    toggleHorzWings();

    EzTempChassis.pid_turn_set(-32, -DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-30);

    intake = -127;

    EzTempChassis.pid_drive_set(28, DRIVE_SPEED, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(26);

    EzTempChassis.pid_drive_set(-18, 110, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-16);

    EzTempChassis.pid_turn_set(132, TURN_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait_until(130);

    intake=127;
    // toggleVertWings();
    EzTempChassis.pid_drive_set(18, 127, false);
    EzTempChassis.pid_wait();
    // toggleVertWings();

    EzTempChassis.pid_drive_set(-7, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-5);

    EzTempChassis.pid_turn_set(90, TURN_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait_until(88);

    EzTempChassis.pid_drive_set(-47, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-44);

    EzTempChassis.pid_swing_set(ez::RIGHT_SWING, 180, -DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait_until(178);

    EzTempChassis.pid_turn_set(0, -DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_drive_set(34, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(10);
    intake = -127;
    EzTempChassis.pid_wait_until(32);

    EzTempChassis.pid_drive_set(-48, 110, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(46);

    toggleVertWings();
    EzTempChassis.pid_swing_set(ez::LEFT_SWING, -45, -DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-43);

    EzTempChassis.pid_drive_set(-14, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    EzTempChassis.pid_swing_set(ez::LEFT_SWING, -90, -DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-88);

    EzTempChassis.pid_drive_set(-3, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-1);
    toggleVertWings();

    EzTempChassis.pid_turn_set(90, DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait_until(88);
    
    intake = 127;

    EzTempChassis.pid_drive_set(36, 127, false);
    EzTempChassis.pid_wait_until(10);
    toggleHorzWings();
    pros::delay(100);
    EzTempChassis.pid_wait();

    toggleHorzWings();
}

void rightSide6Ball() {
    // toggleHorzWings();
    // intake = 127;
    // EzTempChassis.pid_drive_set(66, 127, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait_until(10);
    // toggleHorzWings();
    // EzTempChassis.pid_wait_until(64);

    // EzTempChassis.pid_turn_set(122, TURN_SPEED);
    // pros::delay(100);
    // EzTempChassis.pid_wait_until(120);

    // toggleVertWings();
    // EzTempChassis.pid_drive_set(40, 127, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait_until(4);
    // intake = 127;
    // EzTempChassis.pid_wait();
    // toggleVertWings();

    // EzTempChassis.pid_swing_set(ez::LEFT_SWING, 72, -DRIVE_SPEED);
    // pros::delay(100);
    // EzTempChassis.pid_wait_until(70);

    // EzTempChassis.pid_drive_set(-26, 127, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait_until(-24);

    // intake = -127;
    // EzTempChassis.pid_turn_set(-62, TURN_SPEED);
    // pros::delay(100);
    // EzTempChassis.pid_wait_until(-60);

    // EzTempChassis.pid_drive_set(11, DRIVE_SPEED, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait_until(9);

    // EzTempChassis.pid_turn_set(-22, TURN_SPEED);
    // pros::delay(100);
    // EzTempChassis.pid_wait_until(-20);

    // EzTempChassis.pid_drive_set(-28, 127, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait_until(-26);

    // EzTempChassis.pid_swing_set(ez::RIGHT_SWING, 122, -DRIVE_SPEED);
    // pros::delay(100);
    // EzTempChassis.pid_wait_until(120);

    // EzTempChassis.pid_drive_set(-22, 127, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait_until(2);
    // intake = 127;
    // EzTempChassis.pid_wait_until(20);

    // EzTempChassis.pid_turn_set(-62, TURN_SPEED);
    // pros::delay(100);
    // EzTempChassis.pid_wait_until(-60);

    // intake = -127;

    // EzTempChassis.pid_drive_set(12, 127, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait_until(10);

    // EzTempChassis.pid_drive_set(-32, 127, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait_until(-30);

    // EzTempChassis.pid_turn_set(122, 127);
    // pros::delay(100);
    // EzTempChassis.pid_wait_until(120);

    // EzTempChassis.pid_drive_set(8, 127, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait_until(6);

    // toggleVertWings();
    // EzTempChassis.pid_swing_set(ez::RIGHT_SWING, 75, DRIVE_SPEED);
    // pros::delay(100);
    // EzTempChassis.pid_wait();

    // EzTempChassis.pid_drive_set(10, 127, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait();

    // EzTempChassis.pid_turn_set(32, 127);
    // pros::delay(100);
    // EzTempChassis.pid_wait_until(26);
    // toggleVertWings();
    // EzTempChassis.pid_wait_until(30);

    // intake = 127;
    // EzTempChassis.pid_turn_set(57, TURN_SPEED);
    // pros::delay(100);
    // EzTempChassis.pid_wait_until(54.5);

    // EzTempChassis.pid_drive_set(48, 127, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait();

    // EzTempChassis.pid_drive_set(-12, 127, false);
    // pros::delay(100);
    // EzTempChassis.pid_wait();


    // // New 6 ball
    intake=-127;
    EzTempChassis.pid_drive_set(3, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(1);
    

    EzTempChassis.pid_drive_set(-46, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-44);
    

    EzTempChassis.pid_swing_set(ez::LEFT_SWING, -45, DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-43);

    // Get Matchload

    toggleVertWings();
    EzTempChassis.pid_drive_set(-18, 88, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-16);


    EzTempChassis.pid_swing_set(ez::LEFT_SWING, -90, DRIVE_SPEED);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-88);
    toggleVertWings();

    // Put in goal
    EzTempChassis.pid_drive_set(-14, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-12);

    EzTempChassis.pid_drive_set(7, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(5);

    // Turn and put other in goal
    EzTempChassis.pid_turn_set(90, 110, false);
    EzTempChassis.pid_wait_until(88);

    intake = 127;
    pros::delay(150);
    EzTempChassis.pid_drive_set(12, 127, false);
    EzTempChassis.pid_wait();

    intake = 0;
    
    // Turn towards middle
    EzTempChassis.pid_drive_set(-12, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-10);
    EzTempChassis.pid_swing_set(ez::RIGHT_SWING, 15, -127, -90);
    pros::delay(100);
    EzTempChassis.pid_wait_until(13);

    // Get the side middle
    intake=-127;
    EzTempChassis.pid_drive_set(62, 127, true);
    pros::delay(100);
    EzTempChassis.pid_wait_until(60);
    intake=0;

    EzTempChassis.pid_turn_set(165, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(163);
    intake=127;
    pros::delay(100);

    EzTempChassis.pid_turn_set(82, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(80);

    intake=-127;

    EzTempChassis.pid_drive_set(26, 90, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(24);

    EzTempChassis.pid_turn_set(0, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait();

    toggleVertWings();

    EzTempChassis.pid_drive_set(-36, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(-34);

    toggleVertWings();


    EzTempChassis.pid_drive_set(8, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(6);

    EzTempChassis.pid_turn_set(180, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(178);

     EzTempChassis.pid_drive_set(12, 127, false);
    pros::delay(100);
    EzTempChassis.pid_wait_until(10);
    



    







}

