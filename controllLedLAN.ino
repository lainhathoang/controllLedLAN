#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiClient.h>

MDNSResponder mdns;

ESP8266WebServer server(80);
// WiFiServerServer(80);
String webPage;

const char *ssid = "TP-LINK_4D6276";
const char *password = "Hoangdeptrai";

void setup() {
  pinMode(16, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  //  pinMode(4, OUTPUT);
  //  pinMode(0, OUTPUT);
  //  Serial.println("Connected to esp8266");

  webPage += "<h1>Bat tat led</h1>";
  webPage +=
    "<p>Led 1 <a href=\"led1On\"><button>ON</button></a>&nbsp;<a "
    "href=\"led1Off\"><button>OFF</button></a></p>";
  webPage +=
    "<p>Led 2 <a href=\"led2On\"><button>ON</button></a>&nbsp;<a "
    "href=\"led2Off\"><button>OFF</button></a></p>";
  webPage +=
    "<p>Led 3 <a href=\"led3On\"><button>ON</button></a>&nbsp;<a "
    "href=\"led3Off\"><button>OFF</button></a></p>";
  webPage +=
    "<p>Led 4 <a href=\"led4On\"><button>ON</button></a>&nbsp;<a "
    "href=\"led4Off\"><button>OFF</button></a></p>";

//  Serial.begin(115200);
  Serial.begin(9600);
  delay(100);

  Serial.println();
  Serial.println();
  Serial.print("Ket noi vao mang:  ");
  Serial.print(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Da ket noi wifi");
  Serial.print("Dia chi ip: ");
  Serial.print(WiFi.localIP());

  // if (mdns.begin("esp8266", WiFi.localIP()))
    // Serial.println("MDNS responder started");

  server.on("/", []() {
    server.send(200, "text/html", webPage);
  });

  server.on("/led1On", []() {
    server.send(200, "text/html", webPage);
    digitalWrite(16, HIGH);
  });

  server.on("/led1Off", []() {
    server.send(200, "text/html", webPage);
    digitalWrite(16, LOW);
  });

  server.on("/led2On", []() {
    server.send(200, "text/html", webPage);
    digitalWrite(5, HIGH);
  });

  server.on("/led2Off", []() {
    server.send(200, "text/html", webPage);
    digitalWrite(5, LOW);
  });

  server.on("/led3On", []() {
    server.send(200, "text/html", webPage);
    digitalWrite(4, HIGH);
  });

  server.on("/led3Off", []() {
    server.send(200, "text/html", webPage);
    digitalWrite(4, LOW);
  });

  server.on("/led4On", []() {
    server.send(200, "text/html", webPage);
    digitalWrite(0, HIGH);
  });

  server.on("/led4Off", []() {
    server.send(200, "text/html", webPage);
    digitalWrite(0, LOW);
  });

  server.begin();
  Serial.println();
  Serial.println("Hay vao dia chi ip tren de dieu khien led.");
}

void loop() {
  server.handleClient();
}
