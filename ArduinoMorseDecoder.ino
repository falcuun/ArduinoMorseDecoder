#define LIGHT_SENSOR A0

const char long_signal = '-';
const char short_signal = '.';

const long long_signal_interval = 30;
const long letter_space_interval = 70;

void setup()
{
    pinMode(LIGHT_SENSOR, INPUT);
    Serial.begin(9600);
}

unsigned long signal_interval = 0;
char code;

void loop()
{
    int light_intensity = analogRead(LIGHT_SENSOR);

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
        else
        {
            code = short_signal;
        }

        Serial.println(code);
        pause = 0;
    }
    delay(10);
}
