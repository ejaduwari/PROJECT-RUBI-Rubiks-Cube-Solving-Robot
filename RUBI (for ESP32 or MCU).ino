#define RX 16
#define TX 17

class StepperMotor {
public:
    StepperMotor(int stepPin, int dirPin, int enablePin)
        : stepPin(stepPin), dirPin(dirPin), enablePin(enablePin) {}

    void begin() {
        pinMode(stepPin, OUTPUT);
        pinMode(dirPin, OUTPUT);
        pinMode(enablePin, OUTPUT);
        disable(); // Start disabled
    }

    void enable() {
        digitalWrite(enablePin, LOW); // A4988: LOW = enabled
    }

    void disable() {
        digitalWrite(enablePin, HIGH); // HIGH = disabled
    }

    void setDirection(bool dir) {
        digitalWrite(dirPin, dir ? HIGH : LOW);
    }

    void step(int steps, int delayMicros = 250) { //DELAY
        for (int i = 0; i < steps; i++) {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(delayMicros);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(delayMicros);
        }
    }

private:
    int stepPin;
    int dirPin;
    int enablePin;
};
///////////////////////////////////////////////////////////////////////////// CLASS END /////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////// CONFIGURE /////////////////////////////////////////////////////////////////////////////
// -------- CREATE MOTORS WITH YOUR PIN MAPPING --------
StepperMotor motor1(15, 2, 23);     // STEP D15, DIR D2, ENABLE D23
StepperMotor motor2(4, 5, 22);      // STEP D4, DIR D5, ENABLE D22
StepperMotor motor3(18, 19, 14);     // STEP D18, DIR D19, ENABLE 
StepperMotor motor4(33, 32, 14);     // STEP D33, DIR D32, ENABLE 
StepperMotor motor5(25, 26, 21);    // STEP D25, DIR D26, ENABLE D21
StepperMotor motor6(13, 12, 27);    // STEP D13, DIR D12, ENABLE D27

int stepCount[6] = {100, 100, 100, 100, 100, 100}; //adjust per motor 
const int align = 15;

bool isInverted[6] = {true, true, true, true, false, false}; //FRONT, BACK, LEFT, RIGHT, UP, DOWN; because of the orientation (if wired backwards) of each stepper motor, the face turns may be inverted. (e.g. 'F' may turn clockwise on the cube where as 'D' may turn counterclockwise on the device)

void face_F(bool clockwise, int turns = 1){
    motor1.enable();
    //delay(align);
    motor1.setDirection(clockwise ^ isInverted[0]); //takes motor orientation inversion into account using the bitwise XOR operation
    for(int i = 0; i < turns; i++){
        motor1.step(stepCount[0]);
    }
    delay(align);
    motor1.disable();
}

void face_B(bool clockwise, int turns = 1){
    motor2.enable();
    //delay(align);
    motor2.setDirection(clockwise ^ isInverted[1]);
    for(int i = 0; i < turns; i++){
        motor2.step(stepCount[1]);
    }
    delay(align);
    motor2.disable();
}

void face_L(bool clockwise, int turns = 1){
    motor3.enable();
    //delay(align);
    motor3.setDirection(clockwise ^ isInverted[2]);
    for(int i = 0; i < turns; i++){
        motor3.step(stepCount[2]);
    }
    delay(align);
    motor3.disable();
}

void face_R(bool clockwise, int turns = 1){
    motor4.enable();
    //delay(align);
    motor4.setDirection(clockwise ^ isInverted[3]);
    for(int i = 0; i < turns; i++){
        motor4.step(stepCount[3]);
    }
    delay(align);
    motor4.disable();
}

void face_U(bool clockwise, int turns = 1){
    motor5.enable();
    //delay(align);
    motor5.setDirection(clockwise ^ isInverted[4]);
    for(int i = 0; i < turns; i++){
        motor5.step(stepCount[4]);
    }
    delay(align);
    motor5.disable();
}

void face_D(bool clockwise, int turns = 1){
    motor6.enable();
    //delay(align);
    motor6.setDirection(clockwise ^ isInverted[5]);
    for(int i = 0; i < turns; i++){
        motor6.step(stepCount[5]);
    }
    delay(align);
    motor6.disable();
}
///////////////////////////////////////////////////////////////////////////// CONFIGURE END /////////////////////////////////////////////////////////////////////////////

void processMove(String move){
    move.trim(); // in case there is a whitespace at the beginning or end
    char face = move.charAt(0); //charAt(index) returns the character at the given position
    // for these next two, we assume (based on frequency occurence) that the face called is to be turned clockwise for one turn (unless specified with an " ' " and/or " 2 ")
    bool clockwise = true; 
    int turns = 1; 

    if(move.indexOf('2') != -1){ //if the move string does not contain a '2' to indicate double turns (max number of repetitive turns for the same face we expect to receive from the algorithm)
        turns = 2;
    }
    // **NOTE** that " \' " tells the compuler that the following single quote is part of the character literal's value, not the closing delimiter of the literal as is commonly used
    if(move.indexOf('\'') != -1){ //if the move string does not contain a '2' to indicate double turns (max number of repetitive turns for the same face we expect to receive from the algorithm)
        clockwise = false;
    }

    // Debug (optional)
    Serial.print("Move: "); Serial.print(face);
    Serial.print(", Turns: "); Serial.print(turns);
    Serial.print(", CW: "); Serial.println(clockwise);

    //execute the move
    switch(face){
        case 'F': face_F(clockwise, turns); break;
        case 'B': face_B(clockwise, turns); break;
        case 'L': face_L(clockwise, turns); break;
        case 'R': face_R(clockwise, turns); break;
        case 'U': face_U(clockwise, turns); break;
        case 'D': face_D(clockwise, turns); break;
        default: Serial.println("Invalid move"); // incase we receive an invalid face or something is wrong somewhere mayber with the parser
    }
    //delay(500); // DELAY BETWEEN MOVES
}

void parseMoves(String input){
    int start = 0; //We’ll track where each move starts in the string. Initially, that’s position 0 — the first character
    int spaceIndex = input.indexOf(' ', start); //indexOf() searches for the first occurrence of ' ' (a space) in the string, starting from start and returns the position (index number), else it returns -1 (default behavior)

    while(spaceIndex != -1){ //loop runs as long as we can see spaces
        String move = input.substring(start, spaceIndex); //create a substring from the start of the string to the first space (whose index number has been saved in "spaceIndex")
        move.trim(); //remove any extra spaces or newlines
        if(move.length() > 0){
           //Serial.println("Move found: " + move);
           processMove(move); //send this extracted move string (string or characters before the space) to the function to map face motor, turns and direction
        }

        start = spaceIndex + 1; // next time we start from the character position after the space (the next move)
        spaceIndex = input.indexOf(' ', start); // find the next space from the 'new' start position which is the next move. when we get to the last move, **NOTE** there is no space after it so '-1' gets thrown
    }

    String lastMove = input.substring(start); //take the remaining string from the last start position, which is the last move
    lastMove.trim(); //remove any extra spaces or newlines
    if(lastMove.length() > 0){
        processMove(lastMove); 
        //Serial.println("Move found: " + lastMove);
    }
}

/////////////////////////////////////////////////////////////////////////////
void setup() {
    motor1.begin();
    motor2.begin();
    motor3.begin();
    motor4.begin();
    motor5.begin();
    motor6.begin();

    Serial.begin(115200);
    Serial2.begin(115200, SERIAL_8N1, RX, TX);
}



void loop() {
    // The sequence is to scan for commands, parse the commands, call motor control function
    if(Serial2.available()){
        String input = Serial2.readStringUntil('\n'); // this reads until a newline
        input.trim(); // this removes any leading or trailing spaces, cleans up the string
        parseMoves(input);
        Serial.println("Received from Pi: " + input);
    }
}
