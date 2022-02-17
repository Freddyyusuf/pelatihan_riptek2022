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
#define WIFI_SSID "nama wifi"
#define WIFI_PASSWORD "password"
 
/* Masukan Web API Key */
#define API_KEY "key"
 
/* Masukan Firebase Realtime Database URL */
#define DATABASE_URL "url"
 
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
 
bool signupOK = false;
 
void setup()
{     
    Serial.begin(115200);
 
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
    }
    delay(5000); // program akan berjalan secara berulang (loop) dengan interval 5 detik
}
