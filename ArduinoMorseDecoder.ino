#define LIGHT_SENSOR A0

const char long_signal = '-';
const char short_signal = '.';

const long long_signal_interval = 50;
const long short_signal_interval = 20;

const long letter_space_interval = 70;

void setup()
{
    pinMode(LIGHT_SENSOR, INPUT);
    Serial.begin(9600);
}

unsigned long signal_interval = 0;

unsigned long previous_millis = 0;

char code;

void loop()
{
    int light_intensity = analogRead(LIGHT_SENSOR);

    unsigned long current_millis = millis();

    if (light_intensity > 100)
    {
        while (light_intensity >= 100)
        {
            signal_interval++;
            light_intensity = analogRead(LIGHT_SENSOR);
            delay(10);
        }

        if (signal_interval >= long_signal_interval)
        {
            code = long_signal;
        }
        else if (signal_interval < long_signal_interval && signal_interval >= short_signal_interval)
        {
            code = short_signal;
        }

        Serial.println(code);
        signal_interval = 0;
    }
    else{
        
    }

    delay(10);
}
