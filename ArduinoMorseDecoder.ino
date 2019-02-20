 #define LIGHT_SENSOR A0

void setup(){
    pinMode(LIGHT_SENSOR, INPUT);
    Serial.begin(9600);
}
void loop(){
    long light_intensity = analogRead(LIGHT_SENSOR);
    Serial.println(light_intensity);
    delay(10);
}