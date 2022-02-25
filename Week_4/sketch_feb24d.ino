#if defined(ESP32)
#include <WiFi.h>
#include <FirebaseESP32.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#endif
 
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>
 
/* Masukan Nama Wifi dan Password*/
#define WIFI_SSID "A20"
#define WIFI_PASSWORD "tujuhpangkat5"
 
/* Masukan Web API Key */
#define API_KEY "AIzaSyBLpjUY7GqoSToPllwPVK2Z-Y6kU5IyOJQ"
 
/* Masukan Firebase Realtime Database URL */
#define DATABASE_URL "https://coba-firebase-6e579-default-rtdb.asia-southeast1.firebasedatabase.app/"
 
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
 
bool signupOK = false;

const int trigPin = 12;
const int echoPin = 14;
const int lampPin = 17;

#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;
 
void setup()
{     
    Serial.begin(115200);

    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
      pinMode(lampPin, OUTPUT);
 
    /* Connect to Wifi*/  
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD); 
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(300);
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();
 
    Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);
 
    config.api_key = API_KEY;
    config.database_url = DATABASE_URL;
    
 
    Firebase.reconnectWiFi(true);
 
    /* Sign Up Anonymous User*/
    Serial.print("Sign up new user... ");
    if (Firebase.signUp(&config, &auth, "", ""))
    {
        Serial.println("ok");
        signupOK = true;
    }
    else
        Serial.printf("%s\n", config.signer.signupError.message.c_str());
 
    config.token_status_callback = tokenStatusCallback;
 
    Firebase.begin(&config, &auth);
}
 
void loop()
{
    /* code akan jalan jika signup success dan firebase siap*/
    if (signupOK && Firebase.ready())
    {
        /* Store data (integer) to DB*/
        String path = "contoh-set/nilai-integer";
        int value = 100;
        Firebase.setInt(fbdo, path, value);
 
        /* Store data (string) to DB */
        Firebase.setString(fbdo, "contoh-set/nilai-string", "Hallo RIPTEK");
 
        /* Syntax lainnya: setFloat, setDouble, setBool */    
           
 
        /* Get data (integer) from DB */
        Firebase.getInt(fbdo, "contoh-get/nilai-integer");
        int dataInteger = fbdo.to<int>();
        Serial.println(dataInteger);
 
        /* Get data (string) from DB */
        Firebase.getString(fbdo, "contoh-get/nilai-string");
        String dataString = fbdo.to<String>();
        Serial.println(dataString);
 
        /* Syntax lainnya: getFloat, getDouble, getBool */


        // ultra sonic
        // Clears the trigPin
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        // Sets the trigPin on HIGH state for 10 micro seconds
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        
        // Reads the echoPin, returns the sound wave travel time in microseconds
        duration = pulseIn(echoPin, HIGH);
        
        // Calculate the distance
        distanceCm = duration * SOUND_VELOCITY/2;
        
        // Convert to inches
        distanceInch = distanceCm * CM_TO_INCH;
        
        // Prints the distance on the Serial Monitor
        Serial.print("Distance (cm): ");
        Serial.println(distanceCm);
        Serial.print("Distance (inch): ");
        Serial.println(distanceInch);

        Firebase.setInt(fbdo, "jarak (cm)", distanceCm);
        Firebase.setInt(fbdo, "jarak (inch)", distanceInch);

        Firebase.getBool(fbdo, "lamp");
        bool dataLamp = fbdo.to<bool>();
        Serial.println(dataLamp);
        digitalWrite(lampPin, dataLamp);
    }
    delay(100); // program akan berjalan secara berulang (loop) dengan interval 5 detik
}
