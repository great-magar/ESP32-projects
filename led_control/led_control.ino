#include <WiFi.h>

const char* ssid = "Ryoiki Tenkai";   // enter your home wifi ssid
const char* password = "L3louch_25C0d3"; // enter your wifi password

WiFiServer server(80);
const int ledPin = 2;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected.");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  String currentLine = "";
  String request = "";
  while (client.connected()) {
    if (client.available()) {
      char c = client.read();
      request += c;
      if (c == '\n') {
        // end of HTTP request line

        // Handle AJAX requests:
        if (request.indexOf("GET /led/on") >= 0) {
          digitalWrite(ledPin, HIGH);
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/plain");
          client.println("Connection: close");
          client.println();
          client.println("LED ON");
          break;
        }
        else if (request.indexOf("GET /led/off") >= 0) {
          digitalWrite(ledPin, LOW);
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/plain");
          client.println("Connection: close");
          client.println();
          client.println("LED OFF");
          break;
        }

        // Serve the main page
        if (request.indexOf("GET / ") >= 0) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println();

          client.println("<!DOCTYPE html><html>");
          client.println("<head><title>ESP32 LED Control</title>");
          client.println("<meta name='viewport' content='width=device-width, initial-scale=1'>");
          client.println("<style>");
          client.println("button {font-size: 24px; padding: 15px; margin: 10px;}");
          client.println("#status {font-size: 20px; margin-top: 20px;}");
          client.println("</style>");
          client.println("</head><body>");
          client.println("<h2>ESP32 LED Control</h2>");
          client.println("<button onclick='ledOn()'>Turn ON</button>");
          client.println("<button onclick='ledOff()'>Turn OFF</button>");
          client.println("<div id='status'>LED Status: <span id='ledState'>Unknown</span></div>");

          client.println("<script>");
          client.println("function ledOn() {");
          client.println("  fetch('/led/on').then(response => response.text()).then(data => {");
          client.println("    document.getElementById('ledState').innerText = data;");
          client.println("  });");
          client.println("}");
          client.println("function ledOff() {");
          client.println("  fetch('/led/off').then(response => response.text()).then(data => {");
          client.println("    document.getElementById('ledState').innerText = data;");
          client.println("  });");
          client.println("}");
          client.println("</script>");

          client.println("</body></html>");
          break;
        }
      }
      if (c == '\n') {
        currentLine = "";
      } else if (c != '\r') {
        currentLine += c;
      }
    }
  }
  delay(1);
  client.stop();
}
