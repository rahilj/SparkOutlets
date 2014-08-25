
//Spark controlled outlet switches ver1.0
//Initialize
#define ON 1
#define OFF 0


int Outlet1State = 0;
int Outlet2State = 0;
int Outlet3State = 0;
int Outlet4State = 0;
int Outlet5State = 0;

//Pin descriptions - see schematic
//Outlet 1 D0 HIGH D1 LOW - ON
//		 D0 LOW D1 HIGH - OFF

//Outlet 2 D1 HIGH D2 LOW - ON
//		 D1 LOW D2 HIGH - OFF
		 
//Outlet 3 D2 HIGH D3 LOW - ON
//		 D2 LOW D3 HIGH - OFF

//Outlet 4 D0 HIGH D2 LOW - ON
//		 D0 LOW D2 HIGH - OFF

//Outlet 5 D1 HIGH D3 LOW - ON
//		 D1 LOW D3 HIGH - OFF
int O1_PINS[] = {D0,D1};
int O2_PINS[] = {D1,D2};
int O3_PINS[] = {D2,D3};
int O4_PINS[] = {D0,D2};
int O5_PINS[] = {D1,D3};

uint32_t UPDATE_INTERVAL = 10; // in milliseconds
uint32_t FIFTEEN_MINUTES = 60*15*1000; // in milliseconds

uint32_t lastTime = 0; // in milliseconds
uint32_t startTime = 0; // in milliseconds

void setup() {
	//Initialize all input as ionputs for tristating unless switched
    pinMode(O1_PINS[0],INPUT); 
    pinMode(O1_PINS[1],INPUT);
    pinMode(O2_PINS[1],INPUT);
    pinMode(O3_PINS[1],INPUT);

    digitalWrite(O1_PINS[0],LOW);
    digitalWrite(O1_PINS[1],LOW);
    digitalWrite(O2_PINS[1],LOW);
    digitalWrite(O3_PINS[1],LOW);
    
    Spark.function("out1", outlet5);
    Spark.function("out2", outlet1);
    Spark.function("out3", outlet2);
    Spark.function("out4", outlet3);
    Spark.function("out5", outlet4);
	
    Spark.variable("Outlet1State", &Outlet1State, INT);
    Spark.variable("Outlet2State", &Outlet2State, INT);
    Spark.variable("Outlet3State", &Outlet3State, INT);
	Spark.variable("Outlet4State", &Outlet4State, INT);
    Spark.variable("Outlet5State", &Outlet5State, INT);
}

void loop() {
    // Update the filter every 10ms (default)
    if(millis() - lastTime > UPDATE_INTERVAL) {
        // Set a new last time
        lastTime = millis();
    
        //if(startState == ON) {
        //    if(millis() - startTime > FIFTEEN_MINUTES) {
        //        startState = OFF;
        //    }
        //}        
    }
}

int outlet1(String args) {
    if(Outlet1State == OFF) {
		//Do thrice just to be sure
        for (int i = 0; i < 2; i = i + 1) {
		    pinMode(O1_PINS[0],OUTPUT); 
			pinMode(O1_PINS[1],OUTPUT);
			digitalWrite(O1_PINS[0], LOW); // Assert low on both pins
			digitalWrite(O1_PINS[1], LOW);
			delay(500);
			digitalWrite(O1_PINS[0], HIGH); //Action
			delay(500);
			digitalWrite(O1_PINS[0], LOW); //Go low again
			delay(500);
		}
		//Tristate output by setting back as input
		pinMode(O1_PINS[0],INPUT); 
		pinMode(O1_PINS[1],INPUT);
		Outlet1State = ON; // Outlet 1 started
        return 200; // This is checked in the web app controller for validation
    }
    else {
		//Do thrice just to be sure
        for (int i = 0; i < 2; i = i + 1) {
		    pinMode(O1_PINS[0],OUTPUT); 
			pinMode(O1_PINS[1],OUTPUT);
			digitalWrite(O1_PINS[0], LOW); // Assert low on both pins
			digitalWrite(O1_PINS[1], LOW);
			delay(500);
			digitalWrite(O1_PINS[1], HIGH); //Action
			delay(500);
			digitalWrite(O1_PINS[1], LOW); //Go low again
			delay(500);
		}
		//Tristate output by setting as input
		pinMode(O1_PINS[0],INPUT); 
		pinMode(O1_PINS[1],INPUT);
        Outlet1State = OFF; // engine stopped
        return 200; // This is checked in the web app controller for validation
    }
}

int outlet2(String args) {
    if(Outlet2State == OFF) {
		//Do thrice just to be sure
        for (int i = 0; i < 2; i = i + 1) {
		    pinMode(O2_PINS[0],OUTPUT); 
			pinMode(O2_PINS[1],OUTPUT);
			digitalWrite(O2_PINS[0], LOW); // Assert low on both pins
			digitalWrite(O2_PINS[1], LOW);
			delay(500);
			digitalWrite(O2_PINS[0], HIGH); //Action
			delay(500);
			digitalWrite(O2_PINS[0], LOW); //Go low again
			delay(500);
		}
		//Tristate output by setting back as input
		pinMode(O2_PINS[0],INPUT); 
		pinMode(O2_PINS[1],INPUT);
		Outlet2State = ON; // Outlet 1 started
        return 200; // This is checked in the web app controller for validation
    }
    else {
		//Do thrice just to be sure
        for (int i = 0; i < 2; i = i + 1) {
		    pinMode(O2_PINS[0],OUTPUT); 
			pinMode(O2_PINS[1],OUTPUT);
			digitalWrite(O2_PINS[0], LOW); // Assert low on both pins
			digitalWrite(O2_PINS[1], LOW);
			delay(500);
			digitalWrite(O2_PINS[1], HIGH); //Action
			delay(500);
			digitalWrite(O2_PINS[1], LOW); //Go low again
			delay(500);
		}
		//Tristate output by setting as input
		pinMode(O2_PINS[0],INPUT); 
		pinMode(O2_PINS[1],INPUT);
        Outlet2State = OFF; // engine stopped
        return 200; // This is checked in the web app controller for validation
    }
}

int outlet3(String args) {
    if(Outlet3State == OFF) {
		//Do thrice just to be sure
        for (int i = 0; i < 2; i = i + 1) {
		    pinMode(O3_PINS[0],OUTPUT); 
			pinMode(O3_PINS[1],OUTPUT);
			digitalWrite(O3_PINS[0], LOW); // Assert low on both pins
			digitalWrite(O3_PINS[1], LOW);
			delay(500);
			digitalWrite(O3_PINS[0], HIGH); //Action
			delay(500);
			digitalWrite(O3_PINS[0], LOW); //Go low again
			delay(500);
		}
		//Tristate output by setting back as input
		pinMode(O3_PINS[0],INPUT); 
		pinMode(O3_PINS[1],INPUT);
		Outlet3State = ON; // Outlet 1 started
        return 200; // This is checked in the web app controller for validation
    }
    else {
		//Do thrice just to be sure
        for (int i = 0; i < 2; i = i + 1) {
		    pinMode(O3_PINS[0],OUTPUT); 
			pinMode(O3_PINS[1],OUTPUT);
			digitalWrite(O3_PINS[0], LOW); // Assert low on both pins
			digitalWrite(O3_PINS[1], LOW);
			delay(500);
			digitalWrite(O3_PINS[1], HIGH); //Action
			delay(500);
			digitalWrite(O3_PINS[1], LOW); //Go low again
			delay(500);
		}
		//Tristate output by setting as input
		pinMode(O3_PINS[0],INPUT); 
		pinMode(O3_PINS[1],INPUT);
        Outlet3State = OFF; // engine stopped
        return 200; // This is checked in the web app controller for validation
    }
}


int outlet4(String args) {
    if(Outlet4State == OFF) {
		//Do thrice just to be sure
        for (int i = 0; i < 2; i = i + 1) {
		    pinMode(O4_PINS[0],OUTPUT); 
			pinMode(O4_PINS[1],OUTPUT);
			digitalWrite(O4_PINS[0], LOW); // Assert low on both pins
			digitalWrite(O4_PINS[1], LOW);
			delay(500);
			digitalWrite(O4_PINS[0], HIGH); //Action
			delay(500);
			digitalWrite(O4_PINS[0], LOW); //Go low again
			delay(500);
		}
		//Tristate output by setting back as input
		pinMode(O4_PINS[0],INPUT); 
		pinMode(O4_PINS[1],INPUT);
		Outlet4State = ON; // Outlet 1 started
        return 200; // This is checked in the web app controller for validation
    }
    else {
		//Do thrice just to be sure
        for (int i = 0; i < 2; i = i + 1) {
		    pinMode(O4_PINS[0],OUTPUT); 
			pinMode(O4_PINS[1],OUTPUT);
			digitalWrite(O4_PINS[0], LOW); // Assert low on both pins
			digitalWrite(O4_PINS[1], LOW);
			delay(500);
			digitalWrite(O4_PINS[1], HIGH); //Action
			delay(500);
			digitalWrite(O4_PINS[1], LOW); //Go low again
			delay(500);
		}
		//Tristate output by setting as input
		pinMode(O4_PINS[0],INPUT); 
		pinMode(O4_PINS[1],INPUT);
        Outlet4State = OFF; // engine stopped
        return 200; // This is checked in the web app controller for validation
    }
}

int outlet5(String args) {
    if(Outlet5State == OFF) {
		//Do thrice just to be sure
        for (int i = 0; i < 2; i = i + 1) {
		    pinMode(O5_PINS[0],OUTPUT); 
			pinMode(O5_PINS[1],OUTPUT);
			digitalWrite(O5_PINS[0], LOW); // Assert low on both pins
			digitalWrite(O5_PINS[1], LOW);
			delay(500);
			digitalWrite(O5_PINS[0], HIGH); //Action
			delay(500);
			digitalWrite(O5_PINS[0], LOW); //Go low again
			delay(500);
		}
		//Tristate output by setting back as input
		pinMode(O5_PINS[0],INPUT); 
		pinMode(O5_PINS[1],INPUT);
		Outlet5State = ON; // Outlet 1 started
        return 200; // This is checked in the web app controller for validation
    }
    else {
		//Do thrice just to be sure
        for (int i = 0; i < 2; i = i + 1) {
		    pinMode(O5_PINS[0],OUTPUT); 
			pinMode(O5_PINS[1],OUTPUT);
			digitalWrite(O5_PINS[0], LOW); // Assert low on both pins
			digitalWrite(O5_PINS[1], LOW);
			delay(500);
			digitalWrite(O5_PINS[1], HIGH); //Action
			delay(500);
			digitalWrite(O5_PINS[1], LOW); //Go low again
			delay(500);
		}
		//Tristate output by setting as input
		pinMode(O5_PINS[0],INPUT); 
		pinMode(O5_PINS[1],INPUT);
        Outlet5State = OFF; // engine stopped
        return 200; // This is checked in the web app controller for validation
    }
}

