#ifndef rak5010
#error "Please select WisTrio Cellular RAK5010 Board and compile again"
#endif

#include <Arduino.h>
#include <Wire.h>

void setup();
void loop();
void publish_routine();
void bg96_read();
void bg96_write(const char *command);
void check_response(const char* expected, const char* action);

String command; // String to store BG96 commands
char last_resp[256]; // Buffer for last BG96 response

void setup() {
    Serial.begin(115200);
    delay(5000);
    Serial.println("RAKwireless RAK5010 MQTT with SSL Example");
    Serial.println("------------------------------------------------------");

    Wire.begin();

    command = "ATE0\r";
    bg96_write(command.c_str());
    bg96_read();

    command = "at&f0\r";
    bg96_write(command.c_str());
    bg96_read();

    Serial.println("Enable extended time zone and local time:");
    command = "AT+CTZR=2\r";
    bg96_write(command.c_str());
    bg96_read();

    command = "AT+CTZR?\r"; // Get the local time
    bg96_write(command.c_str());
    bg96_read();

    setupCertificates();
    configureMQTT();
}

void setupCertificates() {
    Serial.println("Setting up certificates...");

    // Upload CA Certificate
    uploadCertificate("cacert.pem", pem_CA, strlen(pem_CA));

    // Upload Client Certificate
    uploadCertificate("client.pem", pem_cert, strlen(pem_cert));

    // Upload Client Private Key
    uploadCertificate("user_key.pem", pem_pkey, strlen(pem_pkey));
}

void uploadCertificate(const char* filename, const char* data, size_t size) {
    command = String("AT+QFDEL=\"") + filename + "\"\r";
    bg96_write(command.c_str());
    bg96_read();

    command = String("AT+QFUPL=\"") + filename + "\",";
    command += size;
    command += ",100\r";
    bg96_write(command.c_str());
    bg96_write(data);
    bg96_read();
}

void configureMQTT() {
    Serial.println("Configuring MQTT...");

    // Other MQTT configuration commands...
    command = "AT+QMTCFG=\"ssl\",0,1,2\r";
    bg96_write(command.c_str());
    bg96_read();

    // More commands as required
}

void publish_routine() {
    // Your MQTT publish routine, ensure to include proper error checks
}

void bg96_read() {
    memset(last_resp, 0, sizeof(last_resp));
    size_t len = 0;

    while (Serial1.available() == 0) {
        delay(10); // Give some time for data to arrive
    }

    while (Serial1.available() > 0) {
        char c = (char)Serial1.read();
        if (len < sizeof(last_resp) - 1) {
            last_resp[len++] = c;
        }
        delay(1); // Brief pause to allow buffer to fill up
    }

    Serial.print(last_resp);
}

void bg96_write(const char *command) {
    Serial1.print(command);
    delay(1000); // Wait for command to be processed
}

void loop() {
    publish_routine();
    delay(180000); //
