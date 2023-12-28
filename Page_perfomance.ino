void handle_performance()
{
  String html = R"(
    <html>
      <head>
        <style>
          .widget {
            background-color: black;
            color: green;
            font-size: 20px;
          }
        </style>
      </head>
      <body>
        <div class="widget">
          <p>Free RAM: )" + String(ESP.getFreeHeap()) + R"( bytes</p>
          <p>Flash Size: )" + String(ESP.getFlashChipSize() / 1024) + R"( KB</p>
          <p>Used Space: )" + String(ESP.getSketchSize() / 1024) + R"( KB</p>
          <p>Free Space: )" + String(ESP.getFreeSketchSpace() / 1024) + R"( KB</p>
        </div>
      </body>
    </html>
  )";
  Serial.println("Received request for /performance, 200");
  server.send(200, "text/html", html);
}